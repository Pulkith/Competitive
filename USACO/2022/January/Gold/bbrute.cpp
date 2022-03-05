/**
 * author: DespicableMonkey
 * created: 01.30.2022 19:14:22
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


void test_case() {
    int N, Q;
    cin >> N >> Q;
    vt<int> ans(N+1);
    vt<bool> on(N+2, true);
    vt<set<int>> adj(N+2);
    vt<pr<int, int>> lf;
    for(int q = 1; q <= Q; ++q) {
      char c; cin >> c;
      if(c == 'A') {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        lf.pb({u, v});
      }
      else if(c == 'R') {
        int in; cin >> in;
        int x = lf[in-1].f, y = lf[in-1].s;
        adj[x].erase(y);
        adj[y].erase(x);
      } else {
        int u; cin >> u;
        on[u] = false;
      }
      vt<bool> vis(N+1);
      vt<int> nums;
      function<bool(int)> dfs = [&](int u) -> bool{
        vis[u] = 1;
        nums.pb(u);
        bool good = on[u]; 
        for(auto v : adj[u]) {
          if(!vis[v]) 
            good |= dfs(v);
        }
        return good;
      };

      for(int i = 1; i <= N; ++i) {
        if(!vis[i]) {
          nums = {};
          bool ons = dfs(i);
          if(ons)
            for(auto v : nums)
              ans[v] = q;
        }
      }
    } 
    for(int i = 0; i < N; ++i)
      cout << ans[i+1] << " ";

}

int main () {
  CP::IO().SetIO()->FastIO().Input(0);

  my_brain_hurts
  // /cin >> Test_Cases;

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
