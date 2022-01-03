#include <bits/stdc++.h>

using namespace std;

const int MX = 100043;
int N, M;
int c_id[MX];
vector<int> c[MX], a[MX];

void tour(int source, int id){
  c_id[source] = id;
  c[id].push_back(source);
  for(int e : a[source])
    if(!c_id[e]) tour(e, id);
}

void test_case(){
  cin >> N >> M;
  for(int i = 0; i <= N; ++i){
     c_id[i] = 0;
     c[i] = a[i] = {};
  }

  for(int i = 0; i < M; ++i) {
    int e1, e2;
    cin >> e1 >> e2;
    a[e1].push_back(e2);
    a[e2].push_back(e1);
  }
  for(int i = 1; i <= N; ++i) {
    if(!c_id[i]){
      tour(i, i);
      sort(c[i].begin(), c[i].end());
    }
  }
  long long res = N * 1LL * N;

  auto dis = [&](vector<int>& la, int t) -> int {
    if(t <= la[0]) return abs(la[0] - t);
    if(t >= la.back()) return abs(la.back() - t);
    int l = 0, r = la.size(), m = 0;
    while(l < r) {
      m = (l + r) / 2;
      if(la[m] == t) return abs(la[m] - t);
      if(t < la[m]) {
        if(m > 0 && t > la[m-1])
          return min(abs(t - la[m]), abs(t - la[m-1]));
        r = m;
      } else {
        if(m < ((int)la.size()) - 1 && t < la[m + 1])
          return min(abs(t - la[m]), abs(t - la[m+1]));
        l = m + 1;
      }
    }
    return abs(la[m] - t);
  };

  if(c_id[1] == c_id[N]) {
    cout << 0 << '\n';
    return;
  }

  int smallest1 = N;

  for(int right : c[c_id[N]]) smallest1 = min(smallest1, dis(c[c_id[1]], right));
  res = min(res, smallest1 * 1LL * smallest1);

  set<int> unique;
  for(int i = 1; i <= N; i++)
    unique.insert(c_id[i]);
  unique.erase(c_id[1]);
  unique.erase(c_id[N]);
  for(int id : unique) {
    int disTo1 = N, disToN = N;
    for(int node : c[id]) {
      disTo1 = min(disTo1, dis(c[c_id[1]], node));
      disToN = min(disToN, dis(c[c_id[N]], node));
    }
    res = min(res, disToN * 1LL * disToN + disTo1 * 1LL * disTo1);
  }
  cout << res << '\n';

}

int main () {
  int T; cin >> T;
  for(int i = 0; i < T; ++i) {
    test_case();
  }
  
  return 0;
}
