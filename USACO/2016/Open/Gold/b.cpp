/**
 * author: DespicableMonkey
 * created: 09.29.2021 22:52:34
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
int order[MX];
bool ans[MX];

struct DSU {
    vector<int> e;
    DSU(int _N) { e = vector<int>(_N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } // get representive component (uses path compression)
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return true;
    }
};



void test_case() {
    cin >> N >> M;
    FOR(i, 0, M) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 0, N) {
        cin >> order[i];
        --order[i];
    }
    set<int> open;
    DSU d(N);
    vt<pr<int, int>> ununited;

    for(int i = N-1; i >= 0; --i) {
        open.insert(order[i]);
        for(auto v : adj[order[i]]) 
            if(has(open, v))
                d.unite(order[i], v);
        if(!d.same_set(order[i], order[N-1]))
            ununited.pb({order[i], order[N-1]});
        while(sz(ununited) && d.same_set(ununited.back().first, ununited.back().s)) ununited.pop_back();
        ans[i] = !sz(ununited);
    }

    FOR(i, 0, N) cout << (ans[i] ? "YES" : "NO") << '\n';
}

int main () {
    CP::IO().SetIO("closing")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
