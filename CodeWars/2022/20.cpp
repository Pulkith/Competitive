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

unsigned nChoosek( unsigned n, unsigned k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int N; cin >> N;
  int R, B, G;
  cin >> R >> B >> G;
  int ans = 0;
  FOR(a, 0, 4) {
    FOR(b, 0, 4) {
      FOR(c, 0, 4) {
        FOR(d, 0, 4) {
          int r = 0, bb = 0, g = 0;
          vt<int> v = {a, b, c, d};
          int on = 0;
          for(auto k : v) {
            if(k == 0) ++r;
            if(k == 1) ++ bb;
            if(k == 2) ++g;
            if(k == 0 ||k == 1 || k == 2) ++on; 
          }
          ans += (on == N && r <= R && bb <= B && g <= G);
        }
      }
    }
  }
  cout << ans << '\n';
  

  return 0;
}
