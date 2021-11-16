/**
 * author: DespicableMonkey
 * created: 10.21.2021 22:39:54
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

const int MX = (1e3+43);
int N, M;
string a[MX][MX];
const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

void test_case() {
    cin >> N >> M;
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            int c; cin >> c;
            a[i][j] = ts((c & 8) == 8) + ts((c & 4) == 4) + ts((c & 2) == 2) + ts(c & 1);
        }
    }
    vt<int> sizes;
    vt<vt<bool>> vis(N, vt<bool>(M));

    function<int(int, int)> dfs = [&](int i, int j) -> int{
        vis[i][j] = 1;
        int sz = 1;
        FOR(k, 0, 4) {
            int ni = i + dx[k];
            int nj = j  + dy[k];

            if(ni >= 0 && ni < N && nj >= 0 && nj < M && !vis[ni][nj] && (
                ni > i && a[i][j][2] == '0' ||
                ni < i && a[i][j][0] == '0' ||
                nj > j && a[i][j][1] == '0' ||
                nj < j && a[i][j][3] == '0'
            ))
                sz += dfs(ni, nj);

        }
        return sz;
    };



    FOR(i, 0, N) {
        FOR(j, 0, M) {
            if(!vis[i][j])
                sizes.pb(dfs(i, j));
        }
    }

    sort(all(sizes)); reverse(all(sizes));
    outv(sizes);
    
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
