/**
 * author: DespicableMonkey
 * created: 11.13.2021 12:49:45
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
int a[MX], cc[MX];
vt<int> adj[MX];
int e = 1;
void dfs(int u, int val = 1, int parent = -1) {
    cc[u] = (val ? val : ++e);
    for(auto v : adj[u]) {
        if(v != parent) {
            if(a[u] == a[v]) dfs(v, cc[u], u);
            else dfs(v, 0, u);
        }
    }
}

void test_case() {
    string s;
    cin >> N >> M >> s;
    FOR(i, 0, N) {
        a[i+1] = s[i] == 'G';
        if(i != N-1) {
            int u, v; cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
    }
    dfs(1);
    string ans = "";
    FOR(i, 0, M) {
        int u, v; char c;
        cin >> u >> v >> c;
        ans += ((cc[u] == cc[v] && ((a[u] == 1 && c == 'H') || (a[u] == 0 && c == 'G'))) ? '0' : '1');
    }
    put(ans);

    
}

int main () {
    CP::IO().SetIO("milkvisits")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
