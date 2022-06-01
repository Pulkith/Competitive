/**
 * author: DespicableMonkey
 * created: 3/4/2022
 **/ 

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ll long long
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void put(T output) { cout << output << '\n'; }
#define putr(__output) return void(put(__output))
string g[15];
int p[15][15];
int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int N;
  cin >> N;
  FOR(i, 0, N) cin >> g[i];
  int ans = 0;

  for(int s = 1; s <= N; ++s) {
    for(int tr = 0; tr < N * N; ++tr) {
      int x1 = tr / N;
      int y1 = tr % N;
      int x2 = x1 + s - 1;
      int y2 = y1  + s - 1;
      int cnt = 0;
      if(x2 >= N || y2 >= N) continue;
      for(int r = x1; r <= x2; ++r) {
        for(int j = y1; j <= y2; ++j) {
          cnt += g[r][j] == '#';
        }
      }
      ans += (cnt == 0);
    }
  }
  cout << ans << '\n';
  return 0;
}
