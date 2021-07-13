/**
 * author: DespicableMonkey
 * created: 07.06.2021 23:28:32
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <cassert>
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
            if(sz(__t)) setIn(__s), setOut(__t);
            else if (sz(__s)) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+43); //Check the limits idiot

    vt<int> in_degree;
    vt<int> adj[200005];
    vt<int> top_sort;
    bool init(int N) {
      top_sort.clear();top_sort.resize(N+5);
      in_degree.clear();in_degree.resize(N+5);
      for(int u = 1; u <= N; ++u) {
          for(auto v : adj[u])
              ++in_degree[v];
      }

      queue<int> q;
      for(int i = 1 ; i <= N; ++i)
          if(in_degree[i] == 0)
              q.push(i);

      int cnt = 0;
      while(!q.empty()) {
          int u = q.front();
          q.pop();
          top_sort.pb(u);

          for(auto v : adj[u])
              if(--in_degree[v] == 0)
                  q.push(v);
          ++cnt;
      }

      return (cnt == N);
    }

void test_case() {
    int N, M;
    cin >> N >> M;
    FORE(i, 1, N) adj[i].clear();
    vt<pr<int, int>> undir;
    FOR(i, 0, M) {
        int x, y, t;
        cin >> t >> x >> y;
        if(t == 1) {
            adj[x].pb(y);
        }
        else undir.pb({x, y});
    }
    if(!init(N)) putr("NO");
    put("YES");
    map<int, int> ind;
    FOR(i,0,sz(top_sort)) ind[top_sort[i]] = i;

    for(auto e : undir) {
        int u = ind[e.f];
        int v = ind[e.s];

        if(u < v)
            cout << e.f << ' ' << e.s << '\n';
        else
            cout << e.s << ' ' << e.f << '\n';
    }

    FORE(i,1,N)
        for(auto v : adj[i])
            cout << i << ' ' << v << '\n';





    
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
