/**
 * author: DespicableMonkey
 * created: 11.13.2021 13:21:43
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
int N, M;
vt<int> adj[MX];
pr<int, int> a[MX];
vt<vt<int>> nets;
bool vis[MX];

void dfs(int u) {
    vis[u] = 1;
    nets.back().pb(u);
    for(auto v : adj[u])
        if(!vis[v])
            dfs(v);
}


void test_case() {
    cin >> N >> M;
    FOR(i, 0, N) {
        int x, y; cin >> x >> y;
        a[i+1] = {x, y};
    }
    FOR(i, 0, M) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    FORE(i, 1, N) {
        if(!vis[i]){
            nets.pb({});
            dfs(i);
        }
    }

    int ans = (1e9);

    for(auto net : nets) {
        auto k = a[net[0]];
        int l = k.f, r = k.f, u = k.s, d = k.s;
        for(auto e : net) {
            k = a[e];
            cmin(l, k.f);
            cmax(r, k.f);
            cmin(d, k.s);
            cmax(u, k.s);
        }
        cmin(ans, (r - l) * 2 + (u - d) * 2);
    }

    put(ans);


}

int main () {
    CP::IO().SetIO("fenceplan")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
