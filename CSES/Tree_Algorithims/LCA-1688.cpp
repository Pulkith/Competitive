/**
 * author: DespicableMonkey
 * created: 09.18.2021 20:36:19
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <cmath>
#include <ios>
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
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+43); //Check the limits idiot
int N, Q;
vector<int> graph[MX];
int timer = 0, first[MX], euler_tour[MX * 2];
int segtree[MX * 4]; // Segment tree for RMQ
void dfs(int node = 0, int parent = -1) {
    first[node] = timer; // The time when we first visit a node
    euler_tour[timer++] = node;
    for (int i : graph[node]) {
        if (i != parent) {
            dfs(i, node);
            euler_tour[timer++] = node;
        }
    }
}
int min_first(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return (first[x] < first[y] ? x : y);
}
// Build the segment tree: run `build()` after running dfs`
void build(int node = 1, int l = 0, int r = timer - 1) {
    if (l == r) segtree[node] = euler_tour[l];
    else {
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        segtree[node] = min_first(segtree[node * 2], segtree[node * 2 + 1]);
    }
}
int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
    if (l > b || r < a) return -1;
    if (l >= a && r <= b) return segtree[node];
    int mid = (l + r) / 2;
    return min_first(query(a, b, node * 2, l, mid), query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run `dfs` and `build()` before you run this
int lca(int a, int b) {
    if (first[a] > first[b]) swap(a, b);
    return query(first[a], first[b]);
}

void test_case() {
    cin >> N >> Q;
    FORE(i, 2, N) {
        int u; cin >> u;
        graph[i].pb(u);
        graph[u].pb(i);
    }

    dfs(1);
    build();

    while(Q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }    
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
