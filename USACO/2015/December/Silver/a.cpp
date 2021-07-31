/**
 * author: DespicableMonkey
 * created: 07.25.2021 01:38:23
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

const int MX = (1e2+43); //Check the limits idiot
int N, M, ans = 0;
bool lit[MX][MX], vis[MX][MX];
map<pr<int, int>, vt<pr<int, int>>> rooms;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

void dfs(int x, int y) {
    lit[x][y] = vis[x][y] = 1;
    for(auto v : rooms[{x, y}]) {
        lit[v.f][v.s] = 1;
        if(!vis[v.f][v.s]) {
            FOR(k, 0, 4) {
                int nx = v.f + dx[k], ny = v.s + dy[k];
                if(nx >= 1 && ny >= 1 && vis[nx][ny] && !vis[v.f][v.s])
                    dfs(v.f, v.s);
            }
        }
    }
    FOR(k, 0, 4) {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && !vis[nx][ny] && lit[nx][ny]) dfs(nx, ny);
    }
}

void test_case() {
    cin >> N >> M;

    FOR(i, 0, M) {
        pr<int, int> u, v;
        cin >> u.f >> u.s >> v.f >> v.s;
        rooms[u].pb(v);
    }

    dfs(1, 1);

    FORE(i, 1, N) FORE(j, 1, N) ans += lit[i][j];
    put(ans);
    
}



int main () {
    CP::IO().SetIO("lightson")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
