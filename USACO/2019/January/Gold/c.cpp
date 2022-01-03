/**
 * author: DespicableMonkey
 * created: 12.25.2021 19:56:05
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

const int MX = (1e4+43);
int N, M, T;
int cows[MX];
vt<pr<ll, ll>> adj[MX];
priority_queue<pair<ll, ll>, vt<pair<ll,ll>>, greater<pair<ll, ll>>> pq;
ll dis[MX];
ll par[MX];
ll passthrough[MX];
void dijkstra(int src) {
    pq.push({src, 1});
    dis[src] = 0;
    par[src] = src;

    while(sz(pq)) {
      int u = pq.top().s;
      pq.pop();
      for(auto e : adj[u]) {
        int v = e.f;
        int w = e.s;
        if(dis[v] == dis[u] + w && u < par[v]) 
          par[v] = u;
        if(cmin(dis[v], dis[u] + w)) {
          pq.push({dis[v], v});
          par[v] = u;
        }
      }
    }
}

void test_case() {
    cin >> N >> M >> T;
    FORE(i, 1, N) {
      cin >> cows[i];
      par[i] = MX;
      dis[i] = 1000000007;
    }
    FOR(i, 0, M) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].pb({v, w});
      adj[v].pb({u, w});
    }

    dijkstra(1);

    FORE(i, 1, N) {
      int cur = i;
      while(cur != 1) {
        passthrough[cur] += cows[i];
        cur = par[cur];
      }
    }

    ll ans = 0;

    FORE(i, 1, N) 
        cmax(ans, dis[i] * 1LL * passthrough[i] - T * 1LL * passthrough[i]);

    put(ans);
}

int main () {
  CP::IO().SetIO("shortcut")->FastIO().Input(0);

  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
