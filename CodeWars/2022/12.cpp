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

int a[100005], b[100005];

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int N;
  cin >> N;
  FOR(i, 0,N) cin >> a[i];
  FOR(i, 0, N) cin >> b[i];
  int mx = 0;
  FOR(i, 0, N) {
    if(a[i] > 0) {
      int nd = b[i] / a[i];
      if(nd * a[i] != b[i]) ++nd;
      cmax(mx, nd);
    }
  }
  vt<int> ans;
  FOR(i, 0, N)
    ans.pb(a[i] * mx - b[i]);
  FOR(i, 0, sz(ans)) 
    cout << ans[i] << " \n"[i == sz(ans) - 1];

}
