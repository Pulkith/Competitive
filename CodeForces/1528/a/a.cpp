/**
 * author: $%U%$
 * created: $%M%$.$%D%$.$%Y%$ $%h%$:$%m%$:$%s%$
 * Potatoes FTW!
 **/ 

#include "bits/stdc++.h"
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
    #define debug_active 1
#endif

using namespace std;

#define pb push_back
#define f                           first
#define s                           second
#define my_brain_hurts              int Test_Cases = 1;

#define all(c)                      (c).begin(), (c).end()
#define sz(x)                       (int)(x).size()
#define ts(x)                       to_string(x)

#define FOR(i,a,b)                  for (int i = (a); i < (b); ++i)
#define FORE(i, a, b)               for(int i = (a); i<= (b); ++i)

using ll = int64_t;
template<typename T, typename U>    using pr = pair<T, U>;
template<typename T> using vt =     vector<T>;
template<class T, class U> T        cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T>                   bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T>                   bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

inline namespace CP {
     inline namespace Output {
        string operator+(string str, int num){return str + ts(num);}
        string operator+(int num, string str) { return ts(num) + str; }
        //string to_string(const char* s) { return string(s);}
        #if !defined LOCAL
            #define dbg(...) ;
            #define print_test_case(...) ;
            #define debug_active 0
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T output) { cout << output << '\n'; }
        #define putr(__output) return put(__output), void();
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
ll a[MX][2];
ll dp[MX][2];
int vis[MX];



void test_case() {
    cin >> N;
    vt<vt<int>> adj(N+1);
    FORE(i, 1, N){
        cin >> a[i][0] >> a[i][1];
        vis[i] = 0;
    }
    FORE(i, 1, N-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        dp[v][0] = dp[v][1] = 0;
        for(auto u : adj[v]) {
            if(vis[u]) continue;
            dfs(u);
            dp[v][0] += max(dp[u][0] + abs(a[u][0] - a[v][0]), dp[u][1] + abs(a[u][1] - a[v][0]));
            dp[v][1] += max(dp[u][0] + abs(a[u][0] - a[v][1]), dp[u][1] + abs(a[u][1] - a[v][1]));
        }
    };
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    
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


// /**
//  * author: DespicableMonkey
//  * created: 06.16.2021 17:48:25
//  * Potatoes FTW!
//  **/ 

// #include "bits/stdc++.h"
// #if LOCAL
//     #include <DespicableMonkey/Execution_Time.h>
//     #include <DespicableMonkey/Debug.h>
// #endif

// using namespace std;

// #define pb push_back
// #define f first
// #define s second
// #define my_brain_hurts int T = 1;

// #define all(c) (c).begin(), (c).end()
// #define sz(x) (int)(x).size()
// #define ts(x) to_string(x)

// #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
// #define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

// using ll = int64_t;
// template<typename T, typename U> using pr = pair<T, U>;
// template<typename T> using vt = vector<T>;
// template<class T, class U> T cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
// template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
// template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
// const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

// inline namespace CP {
//     inline namespace IO {
//         void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
//         void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
//         void FastIO() { cin.tie(nullptr)->sync_with_stdio(0); }
//         void SetIO(string s = "", string t = "") {
//             cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
//             if(sz(t)) setIn(s), setOut(t);
//             else if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
//         }
//     }
//     inline namespace Output {
//         bool debug = 0;
//         string operator+(string str, int num){return str + ts(num);}
//         string operator+(int num, string str) { return str + ts(num); }
//         string to_string(const char* s) { return string(s);}
//         #if !defined LOCAL
//             #define dbg(...)
//         #endif
//         template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
//         template<class T> void put(T s) { cout << s << '\n'; }
//         #define putr(s) return put(s), 0
//     }
// }
// /*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

// const int MX = (2e5+5); //Check the limits idiot
// int N;
// vt<int> adj[MX];
// pr<int, int> value[MX];
// int color[MX];

// ll calc() {
//     ll score1 = 0, score2 = 0, score3 = 0, score4 = 0;

//     queue<int> q;
//     color[1] = 1;
//     q.push(1);

//     while(!q.empty()) {
//         int top = q.front(); q.pop();
//         int assign = (color[top] == 1 ? 2 : 1);
//         for(auto near : adj[top]) {
//             if(color[top] == 1) {
//                 score1 += abs(value[top].f - value[near].s);
//                 score3 += abs(value[top].s - value[near].s);
//             } else {
//                 score2 += abs(value[top].f - value[near].s);
//                 score4 += abs(value[top].f - value[near].f);
//             }

//             if(!color[near]) {
//                 color[near] = assign;
//                 q.push(near);
//             }
//         }
//     }





//     return max({score1, score2, score3, score4});
// }

// int test_case(int test_case = 0) {
//     cin >> N;
//     FOR(i, 0, N) adj[i] = {}, value[i] = {0, 0};
//     memset(color, 0, sizeof(color));
//     FOR(i, 0, N) {
//         int x, y;
//         cin >> x >> y;
//         value[i+1] = {x, y};
//     }

//     FORE(i, 1, N - 1) {
//         int a, b;
//         cin >>a  >> b;
//         adj[a].pb(b);
//         adj[b].pb(a);
//     }

//     cout << calc() << '\n';

//     return 0;
// }
