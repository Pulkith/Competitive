/**
 * author: DespicableMonkey
 * created: 08.15.2021 12:42:44
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
#define has(container, element) container.find(element) != container.end()

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
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (1e3+43); //Check the limits idiot
int N, M1, M2;
set<int> f1_adj[MX], f2_adj[MX];

struct DSU {
    vector<int> e;
    DSU(int n) { e = vector<int>(n, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};


void test_case() {
    cin >> N >> M1 >> M2;

    DSU f1(N+1), f2(N+1);

    FOR(i, 0, M1) {
        int u, v; cin >> u >> v;
        f1_adj[u].insert(v);
        f1_adj[v].insert(u);
        f1.unite(u, v);
    }

    FOR(i, 0, M2) {
        int u, v; cin >> u >> v;
        f2_adj[u].insert(v);
        f2_adj[v].insert(u);
        f2.unite(u, v);
    }
    vt<pr<int, int>> ans;
    FORE(i, 1, N) {
        FORE(j, 1, N) {
            if(i == j) continue;
            if(f1_adj[i].find(j) != f1_adj[i].end() || f2_adj[i].find(j) != f2_adj[i].end()) continue;
            if(f1.same_set(i, j) || f2.same_set(i, j)) continue;
            f1.unite(i, j);
            f2.unite(i, j);
            f1_adj[i].insert(j); f1_adj[j].insert(i);
            f2_adj[i].insert(j); f2_adj[j].insert(i);
            ans.pb({i, j});
        }
    }

    put(sz(ans));
    FOR(i, 0, sz(ans))
        cout << ans[i].f << " " << ans[i].s << "\n";
    
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
