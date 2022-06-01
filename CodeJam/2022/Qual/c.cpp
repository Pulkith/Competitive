/**
 * author: DespicableMonkey
 * created: 04.02.2022 13:40:10
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

const int MX = (2e5+43);
int N;
int a[MX];

bool works(int num) {
  int cur = 0;
  int need = 1;
  FOR(i, 0, N) {
    if(a[i] >= need) {
      ++need;
      ++cur;
    }
  }
  return cur >= num;
}

void test_case() {
    cin >> N;
    FOR(i, 0, N) cin >> a[i];
    sort(a, a+N);

    int lo = 0, hi = (5e5);

    while(lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if(works(mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    if(works(lo+1)) ++lo;
    cout << lo << '\n';

}

int main () {
  CP::IO().SetIO()->FastIO().Input(0);

  my_brain_hurts
  cin >> Test_Cases;

  for(int tt = 1; tt <= Test_Cases; ++tt){
      cout << "Case #" << tt << ": ";
      test_case();
  }

  return 0;
}
