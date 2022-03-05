#include<bits/stdc++.h>


using namespace std;

bool works(vector<int> n, int num) {
  int loss = 0;
  for(int i = 0; i < n.size(); ++i) {
    n[i] -= loss;
    if(n[i] < num) return 0;
    loss = n[i] - num;
  }
  return (loss == 0);
}

int toget(vector<int>& n, int num) {
  int res = 0;
  for(int i = 0; i < n.size(); ++i)
    res += n[i] - num;
  return res;
}

int main () {
  int T; cin >> T;
  while(T --) {
    int N; cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    if(N & 1) {
      long long odd = 0, even = 0;
      for(int i = 0; i < N; ++i) {
        if(i & 1) odd += a[i];
        else even += a[i];
      }

      long long t = abs(even - odd);
      int r = works(a, t);
      if(works(a, t)) {
        cout << toget(a, t) << '\n';
      } else cout << "-1" << '\n';
    } else {
      int lo = 0, hi = 1000000000;
      while(lo != hi) {
        int mid = (lo + hi) / 2;
        if(works(a, mid)) {
          lo = mid + 1;
        } else {
          hi = mid;
        }
      }
      if(lo == 0) cout << -1 << '\n';
      else cout << toget(a, lo - 1) << '\n';
    }
  }
}
