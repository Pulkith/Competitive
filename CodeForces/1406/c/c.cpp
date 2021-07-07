/**
 * author: DespicableMonkey
 * created: 07.02.2021 23:28:26
 * Potatoes FTW!
 **/ 

#include <algorithm>
#include<bits/stdc++.h>
#include <iostream>
#include <numeric>
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

const int MX = (1e5+5); //Check the limits idiot
int N;
vt<int> adj[MX];
vt<int> centroids;
int centroid_value = (1e9);
int size_of_tree[MX];
int mx_connected[MX];
bool vis[MX];

void dfs(int u, int parent) {
    size_of_tree[u] = vis[u] = 1;
    vt<int> cur_cc;
    for(auto v : adj[u]) {
        if(v == parent) continue;
        if(!vis[v])
            dfs(v, u);
        size_of_tree[u] += size_of_tree[v];
        cur_cc.pb(size_of_tree[v]);
    }
    mx_connected[u] = (sz(cur_cc) == 0 ? 0 : *max_element(cur_cc.begin(), cur_cc.end()));
    cmax(mx_connected[u], N - size_of_tree[u]);
    if(mx_connected[u] < centroid_value) centroid_value = mx_connected[u], centroids.clear();
    if(mx_connected[u] == centroid_value) centroids.pb(u);
}

void test_case() {

    cin >> N;

    FORE(i, 1, N)
        adj[i].clear(), mx_connected[i] = 0, vis[i] = 0;
    centroid_value = (1e9);

    FOR(i, 0, N - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    if(sz(centroids) == 1) {
        FOR(i, 0, 2)
            cout << "1" << ' ' << adj[1][0] << '\n';
        return;
    }
    assert(sz(centroids) == 2);
    bool finished = 0;
    function<void(int, int)> dfs2 = [&](int u, int parent) {
        for(auto v : adj[u]) {
            if(finished) return;
            if(v == parent) continue;
            if(sz(adj[v]) == 1) {
                cout << u << ' ' << v << '\n';
                cout << centroids[1] << ' ' << v << '\n';
                finished = 1;
                return;
            } else
                dfs2(v, u);
        }

    };
    dfs2(centroids[0], centroids[1]);


    
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