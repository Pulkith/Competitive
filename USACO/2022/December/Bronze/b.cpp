#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define sz(x) (int)(x).size()

int a[100005];
int b[100005];

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int N;
  cin >> N;
  FOR(i, 0, N) cin >> a[i];
  FOR(i, 0, N) cin >> b[i];
  long long ans = 0;
  FOR(k, 0, 2) {
    set<int> soonest;
    map<int, vector<int>> soon_to_index;
    vector<int> alive(N);
    FOR(i, 0, N) {
      if((k == 0 && a[i] > b[i]) || (k && a[i] < b[i])) {
        soonest.insert(abs(a[i] - b[i]));
        soon_to_index[abs(a[i] - b[i])].push_back(i);
        alive[i] = 1;
      }
    }
    int segs = 0;

    FOR(i, 0, N) {
      if((k == 0 && a[i] > b[i]) || (k && a[i] < b[i])) {
        if(i == 0) ++segs;
        else if ((k == 0 && a[i-1] <= b[i-1]) || (k && a[i-1] >= b[i-1])) ++segs;
      }
    }
    int cur = 0;
    while(sz(soonest)) {
      int nxt = *(soonest.begin());
      soonest.erase(soonest.begin());

      ans += (nxt - cur) * 1LL * segs;
      cur = nxt;

      vector<vector<int>> deadsegs;
      for(auto c : soon_to_index[nxt]) {
        if(!sz(deadsegs) || deadsegs.back().back() + 1 < c)
          deadsegs.push_back({c});
        else
          deadsegs.back().push_back(c);
      }
      for(auto s : deadsegs) {
        int lft = s[0];
        int right = s.back();
        if((lft == 0 || !alive[lft-1]) && (right == N-1 || !alive[right+1])) --segs;
        if((lft > 0 && alive[lft-1]) && (right < N-1 && alive[right+1])) ++segs;
      }
      for(auto c : soon_to_index[nxt])
        alive[c] = 0;
      }
  }

  cout << ans << '\n';

  return 0;
}