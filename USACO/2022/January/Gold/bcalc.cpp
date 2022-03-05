/**
 * author: DespicableMonkey
 * created: 01.30.2022 19:38:50
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <ctime>
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
int num(int lo, int hi) {
  return (rand() % hi) + lo;
}

void test_case() {
     srand( unsigned(time(0)));
     int N = num(10, 20);
     int M = num(1, N);

     cout << N << " " << M << '\n';
     vt<int> on;

     for(int i = 1; i <= N; ++i)
      on.pb(i);

     vt<int> bridges;
     int count = 1;
     for(int i = 0; i < M; ++i) {
      int g = num(1, 3);
      if(g == 1) {
        cout << "A ";
        int op = on[num(1, sz(on)) - 1];
        int u = on[op];
        on.erase(on.begin() + op);

        op = on[num(1, sz(on)) - 1];
        int v = on[op];
        on.erase(on.begin() + op);

        cout << u << " " << v << '\n'; 
        bridges.push_back(count++);
      }
      if(g == 2) {
        int u = num(1, sz(bridges))-1;
        cout << "R " << bridges[u] << '\n';
        bridges.erase(bridges.begin() + u);
      } else {
        
      }
     }


}

int main () {
  CP::IO().SetIO()->FastIO().Input(0);

  my_brain_hurts
  cin >> Test_Cases;

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
