/**
 * author: DespicableMonkey
 * created: 12.12.2021 18:46:00
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
pr<int, int> a[MX];
int extra;
queue<pr<int, int>> fix;
bool cows[3000][3000];
const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[5] = {1, 0, -1, 0, 0}, dy[5] = {0, 1, 0, -1, 0}; //DRUL



void ev(pr<int, int> p) {
  FOR(j, 0, 5) {
    pr<int, int> e = {p.f + dx[j], p.s + dy[j]};
    if(cows[e.f][e.s]){
      vt<pr<int, int>> neighs;
      FOR(i, 0, 4) {
        pr<int, int> po = {e.f + dx[i], e.s + dy[i]};
        if(!cows[po.f][po.s]) neighs.pb(po);
      }
      if((sz(neighs) == 1)) fix.push(neighs[0]);
    }
  }
}

void test_case() {
    cin >> N;
    FOR(i, 0, N) {
      pr<int, int> p; cin >> p.f >> p.s; p.f += 1000; p.s += 1000;
      if(cows[p.f][p.s]) --extra;
      cows[p.f][p.s] = true;
      ev(p);
      while(sz(fix)) {
        auto e = fix.front(); fix.pop();
        if(cows[e.f][e.s]) continue;
        cows[e.f][e.s] = true; ++extra;
        ev(e);
      }
      put(extra);
    } 
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
