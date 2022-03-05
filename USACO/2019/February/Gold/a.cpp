/**
 * author: DespicableMonkey
 * created: 01.03.2022 17:15:25
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
int N, Q;
int a[MX];
vt<int> adj[MX];
int st[MX], en[MX];
int tim = 0;
int up[MX][20];
void dfs(int u, int p) {
  up[u][0] = p;
  FOR(i, 1, 20)
    up[u][i] = up[up[u][i-1]][i-1];

  st[u] = tim++;
  for(auto v : adj[u])
    if(v != p)
      dfs(v, u);
  en[u] = tim - 1;
}

bool isancestor(int u, int v) {
  return st[u] <= st[v] && en[u] >= en[v];
}

int LCA(int u, int v) {
  if(isancestor(u, v)) return u;
  if(isancestor(v, u)) return v;

  for(int i = 20-1; i >= 0; --i) {
    if(!isancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void upd(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] ^= dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1)
      res ^= s[pos-1];
    return res;
  }
  ll query(int pos1, int pos2) { //inclusive
    return query(pos2+1) - query(pos1);
  }
};



void test_case() {
    cin >> N >> Q;

    FORE(i, 1, N) cin >> a[i];
    FOR(i, 0, N-1) {
      int u, v; cin >> u >>v;
      adj[v].pb(u);
      adj[u].pb(v);
    }

    dfs(1, 1);

    FT f(N + 3);
    FORE(i, 1, N) {
      f.upd(st[i], a[i]);
      f.upd(en[i]+1, a[i]);
    }
    while(Q--) {
      int u; cin >> u;
      if(u == 1) {
        int o, v;
        cin >> o >> v;
        FOR(k, 0, 2) {
          if(k) a[o] = v;
          f.upd(st[o], a[o]);
          f.upd(en[o]+1, a[o]);
        }
      } else {
        int o, v;
        cin >> o >> v;
        cout << (f.query(0, st[o]) ^ f.query(0, st[v]) ^ a[LCA(o, v)]) << '\n';
      }
    }
}



int main () {
  CP::IO().SetIO("cowland")->FastIO().Input(0);

  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
