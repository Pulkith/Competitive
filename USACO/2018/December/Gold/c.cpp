/**
 * author: DespicableMonkey
 * created: 02.03.2022 15:25:45
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


struct SparseTable {
  static const int MAX_N = 10005;
  static const int LOG = 18;
  int a[MAX_N];
  int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]

  int query(int L, int R) { // O(1) [L..R]
    int len = R - L + 1;
      int k = 31 - __builtin_clz(len); //bit trick to find log2(N)
    return max(m[L][k], m[R-(1<<k)+1][k]);
  }
  void calc() { // O(N*log(N))
    for(int k = 1; k < LOG; k++) {
      for(int i = 0; i + (1 << k) - 1 < MAX_N; i++) {
        m[i][k] = max(m[i][k-1], m[i+(1<<(k-1))][k-1]);
      }
    }
  }
  void set(int i, int val) {
    m[i][0] = val;
  }
};


int N, K;
int a[100000];
ll dp[10005];

void test_case() {
    cin >> N >> K;

    SparseTable s;

    FORE(i, 1, N) {
      cin >> a[i];
      s.set(i, a[i]);
    }

    s.calc();

    FORE(i, 1, N) {
      dp[i] = dp[i-1] + a[i];
      FORE(j, 1, K) {
        long long sum = (i - j > 0) ? dp[i-j] : 0;
        int l = max(i - j + 1, 1);
        cmax(dp[i], s.query(l, i) * (i-l+1) + sum);
      }
    }

    cout << dp[N] << '\n';

}

int main () {
  CP::IO().SetIO("teamwork")->FastIO().Input(0);

  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
