/**
 * author: DespicableMonkey
 * created: 01.26.2022 03:47:13
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

const int MX = (1e5+43);
int N, T;
long a[150][150];
vt<pr<int, long>> adj[MX];

int dx[16] = {-3, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2, -1, 0, 1, 0};
int dy[16] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 0, -1};

priority_queue<pair<long, int>, vt<pair<long,int>>, greater<pair<long, int>>> pq;
long dis[MX];
void dijkstra(int src) {
    pq.push({src, 0});
    dis[src] = 0;

    while(sz(pq)) {
      int u = pq.top().s;
      pq.pop();
      for(auto e : adj[u]) {
        int v = e.f;
        long w = e.s;
        if(cmin(dis[v], dis[u] + w)) {
          pq.push({dis[v], v});
        }
      }
    }
}




void test_case() {
    cin >> N >> T;
    FOR(i, 0, N) 
      FOR(j, 0, N)
        cin >> a[i][j];
    FOR(i, 0, N) {
      FOR(j, 0, N) {
        FOR(k, 0, 16) {
          int di = i + dx[k];
          int dj = j + dy[k];

          if(di >= 0 && di < N && dj >= 0 && dj < N) {
            adj[i * N + j].pb({di * N + dj, a[di][dj] + 3 * T});
          }
        }
      } 
    }

    auto val = [&](int i, int j) -> int {
      return i * N + j;
    };  

    int n = N-1;
    int C = N*n+n;
    adj[val(n, n-1)].pb({C, T});
    adj[val(n-1, n)].pb({C, T});
    adj[val(n-1, n-1)].pb({C, T * 2});
    adj[val(n-2, n)].pb({C, T * 2});
    adj[val(n, n-2)].pb({C, T * 2});


    FOR(i, 0, N * N + N)
      dis[i] = (1e9) * 1LL * (1e9);


    dijkstra(0);
    cout << dis[C] << '\n';
}

int main () {
  CP::IO().SetIO("visitfj")->FastIO().Input();

  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
