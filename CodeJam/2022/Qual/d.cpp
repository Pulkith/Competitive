/**
 * author: DespicableMonkey
 * created: 04.02.2022 14:04:15
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
int adj[MX];
int dis[MX];
int par[MX];
vt<int> child[MX];



  cin >> N;
  FORE(i, 1, N) {
    cin >> a[i];
    dis[i] = 0;
    child[i] = vt<int>();
  }

  vt<int> abyss;
  FORE(i, 1, N) {
    int u; cin >> u;
    if(u == 0) {
      abyss.pb(i);
      par[i] = i;
    }
    else {
      adj[i] = u;
      dis[i] = dis[u] + 1;
      par[i] = par[u];
      child[par[i]].pb(i);
    }
  }
  ll ans = 0;
  for(auto center : abyss) {
    int mxdis = 0;
    map<int, vt<int>> users;
    for(auto c : child[center]){
      cmax(mxdis, dis[c]);
      users[dis[c]].pb(c);
    }

    while(mxdis > 0) {
      map<int, vt<int>> nxt;

      for(auto v : users[mxdis]) {
        nxt[adj[v]].pb(a[v]);
      }
      for(auto &[x, y] : nxt) {
        sort(all(y));
        for(auto yy : y) ans += yy;
        if(sz(y) > 0) {
          ans -= y[0];
          cmax(a[x], y[0]);
        }
      }

      mxdis--;
    }
    ans += a[center];
  }

  cout << ans << '\n';




}

int main () {
  CP::IO().SetIO()->FastIO().Input(0);

  my_brain_hurts
  cin >> Test_Cases;

  for(int tt = 1; tt <= Test_Cases; ++tt){
      // print_test_case(tt);
    cout << "Case #" << tt <<": ";
      test_case();
  }

  return 0;
}
