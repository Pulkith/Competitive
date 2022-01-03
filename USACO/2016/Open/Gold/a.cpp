/**
 * author: DespicableMonkey
 * created: 12.10.2021 01:29:58
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

const int MX = (5e4+43);
int N;
pr<int, int> a[MX];

const int LOG = 16;
int minn[MX][LOG]; 
int maxx[MX][LOG];

int q(int L, int R, bool gmax) {
  int len = R - L + 1;
  int k = 31 - __builtin_clz(len); 
  if(!gmax)
    return min(minn[L][k], minn[R-(1<<k)+1][k]);
  else
    return max(maxx[L][k], maxx[R-(1<<k)+1][k]);
}

void calc() { 
  for(int k = 1; k < LOG; k++) {
    for(int i = 0; i + (1 << k) - 1 < N; i++) {
      minn[i][k] = min(minn[i][k-1], minn[i+(1<<(k-1))][k-1]);
      maxx[i][k] = max(maxx[i][k-1], maxx[i+(1<<(k-1))][k-1]);
    }
  }
}

void test_case() {
    cin >> N;
    FOR(i, 0, N) cin >> a[i].f >> a[i].s;

    ll smallest, ans;
    FOR(Z, 0, 2) {
      sort(a, a+N);
      FOR(i, 0, N) {
        minn[i][0] = a[i].s;
        maxx[i][0] = a[i].s;
      }
      calc();
      if(!Z) {
        smallest = (a[N-1].f - a[0].f) * 1LL * (q(0, N-1, 1) - q(0, N-1, 0));
        ans = smallest;
      }

      FOR(i, 1, N) {
        if(a[i-1].f < a[i].f) {
          ll fir = (a[i-1].f - a[0].f) * 1LL * (q(0, i-1, 1) - q(0, i-1, 0));
          ll sec = (a[N-1].f - a[i].f) * 1LL * (q(i, N-1, 1) - q(i, N-1, 0));
          cmin(ans, fir + sec);
        }
      }
      FOR(i, 0, N) {
        swap(a[i].f, a[i].s);
      }
    }
    put(smallest - ans);
}

int main () {
  CP::IO().SetIO("split")->FastIO().Input(0);

  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
