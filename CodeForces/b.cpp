/**
 * author: DespicableMonkey
 * created: 09.25.2021 13:10:25
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




const int MX = (8e5+43);
int N;
pr<int, int> road[MX];
int freq[MX];
int val[MX], depth[MX];
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

void dfs2(int u, int p) {
    for(auto v : graph[u]) {
        if(v != p) {
            dfs2(v, u);
            val[u] += val[v];
        }
    }
}
void dfs3(int u, int p = -1, int d = 1) {
    depth[u] = d;
    for(auto v : graph[u]) 
        if(v != p)
            dfs3(v, u, d+1);
}

void test_case() {
    cin >> N;
    FORE(i, 1, N - 1) cin >> road[i].f >> road[i].s;
    FORE(i, 1, N) cin >> freq[i];
    map<int, vt<int>> freq_mp;
    FORE(i, 1, N) {
        if(i != N){
            graph[road[i].f].pb(road[i].s);
            graph[road[i].s].pb(road[i].f);
        }
        freq_mp[freq[i]].pb(i);
        val[i] = 0;
    }

    dfs(1);
    build();

    FORE(i, 1, N) {
        if(sz(freq_mp[i]) > 1) {
            int low = lca(freq_mp[i][0], freq_mp[i][1]);
            ++val[freq_mp[i][0]]; ++val[freq_mp[i][1]];
            FOR(j, 2, sz(freq_mp[i])) {
                ++val[freq_mp[i][j]];
                low = lca(low, freq_mp[i][j]);
            }
            val[low] -= sz(freq_mp[i]);
        }
    }
    dfs2(1, -1);  
    dfs3(1);
    int ans = 0;
    FORE(i, 1, N-1) {
        ans += !val[max(depth[road[i].f], depth[road[i].s]) == depth[road[i].f] ? road[i].f : road[i].s];
    }
    put(ans);
    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        cout << "Case #" << tt << ": ";
        print_test_case(tt);
        test_case();
    }

    return 0;
}
