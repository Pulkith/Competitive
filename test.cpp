/**
 * author: $%U%$
 * created: $%M%$.$%D%$.$%Y%$ $%h%$:$%m%$:$%s%$
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



const int MX = 50005;
vector<pair<int, int>> adj[MX];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
int dis[MX];
void dijkstra(int src) {
    pq.push({1, src});
    dis[src] = 0;
    while(sz(pq)) {
      int u = pq.top().s;
      pq.pop();
      for(auto e : adj[u]) {
        int v = e.f;
        int w = e.s;
        if(cmin(dis[v], dis[u] + w)) {
          pq.push({dis[v], v});
        }
      }
    }
}

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL
int main() {
    int N; cin >> N;
    while(N -- > 0) {
        int r, c; cin >> r >> c;
        int s; cin >> s;
        vector<string> a(r);
        for(int i = 0; i < r; ++i) cin >> a[i];
        int sloc = -1, mloc = -1;
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j) {
                dis[i * r + j] = 1000000000;
                if(a[i][j] == 'S') sloc = i * r + j;
                if(a[i][j] == 'M') mloc = i * r + j;
            }
        if(mloc == -1) cout << "Spidey's having marital problems." << '\n';
        else {
            for(int i = 0; i < r; ++i) {
                for(int j = 0; j < c; ++j) {
                    for(int k = 0; k < 4; ++k) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
                            int cur = i * r + j;
                            int nxt = ni * r + nj;
                            int w = 0;
                            if(a[ni][nj] == '.') w = 1;
                            else if(a[ni][nj] == '#') w = 3;
                            else if(a[ni][nj] == 'D' || a[ni][nj] == 'V' || a[ni][nj] == 'C') w = 8;
                            else if(a[ni][nj] == 'M') w = 1;
                            else if(a[ni][nj] == 'S') continue;
                            else w = 5;
                            adj[cur].push_back({nxt, w});
                        }
                    }
                }
            } 
            dijkstra(sloc);
            if(dis[mloc] < s) {
                cout << "Everything's peachy, Spidey escaped in " << dis[mloc] << " seconds." << '\n';
            } else {
                cout << "Spidey's having marital problems." << '\n';
            }
        }
    }
    return 0;
}