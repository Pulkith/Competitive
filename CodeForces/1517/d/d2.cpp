/**
 * author: DespicableMonkey
 * created: 12.07.2021 23:15:20
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
  #include <DespicableMonkey/Execution_Time.h>
  #include <DespicableMonkey/Debug.h>
  #define debug_active 1
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define my_brain_hurts int Test_Cases = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)
#define has(container, element) ((bool)(container.find(element) != container.end()))

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define ll long long
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

inline namespace CP {
  inline namespace Output {
    #if !defined LOCAL
      #define dbg(...) ;
      #define print_test_case(...) ;
      #define debug_active 0
    #endif
    template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
    template<class T> void put(T output) { cout << output << '\n'; }
    #define putr(__output) return void(put(__output))
  }
  class IO { public:
    void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
    void Input(int __use_input = 0) {if(!!__use_input && debug_active){setIn("in"+to_string(__use_input)+".txt");}}
    IO FastIO() { cin.tie(nullptr)->sync_with_stdio(0); return *this; }
    IO* SetIO(string __s = "", string __t = "") {
      cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
      if(sz(__t) && !debug_active) setIn(__s), setOut(__t);
      else if (sz(__s) && !debug_active) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
      return this;
    }
  };
}

const int MX = (5e2+43);
int N, M, K;
int hor[MX][MX];
int ver[MX][MX];
int dp[MX][MX][11];
const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

void test_case() {
    cin >> N >> M >> K;
    FOR(i, 0, N)
      FOR(j, 0, M-1)
        cin >> hor[i][j];
    FOR(i, 0, N-1)
      FOR(j, 0, M)
        cin >> ver[i][j];

    if(K & 1) {
      FOR(i, 0, N)
        FORE(j,1, M)
          cout << -1 << " \n"[j==M];
      return;
    }
    FORE(d, 1, K / 2){
      FOR(i, 0, N) {
        FOR(j, 0, M) {
          dp[i][j][d] = (1e9);
          FOR(k, 0, 4) {
            int u = i + dx[k];
            int v = j + dy[k];
            if(u >= 0 && u < N && v >= 0 && v < M){
              if(u == i)
                cmin(dp[i][j][d], dp[u][v][d-1] + hor[i][j - 1 * (v < j)]);
              else
                cmin(dp[i][j][d], dp[u][v][d-1] + ver[i - 1 * (u < i)][j]);
            }
          }
        }
      } 
    }

    FOR(i, 0, N)  
      FOR(j, 0, M)
        cout << dp[i][j][K/2] * 2 << " \n"[j == M-1];

}

int main () {
  CP::IO().SetIO()->FastIO().Input(0);

  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
