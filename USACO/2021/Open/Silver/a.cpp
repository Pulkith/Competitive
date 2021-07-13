/**
 * author: DespicableMonkey
 * created: 07.11.2021 21:05:44
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
            if(sz(__t)) setIn(__s), setOut(__t);
            else if (sz(__s)) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = 30; //Check the limits idiot
int N;
pr<int, int> a[MX][MX];
map<pr<int, int>, char> lets;

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

void test_case() {
    cin >> N;
    FOR(i, 0, N) {
        string s; cin >> s;
        for(int j = 0; j < N * 3; j += 3) {
            if(s[j] == '#') a[i][j / 3] = {0, 0};
            else {
                lets[{i, j/3}] = (s[j] == 'M' ? '2' : '1');
                a[i][j / 3] = {s[j+1] - '0', s[j+2] - '0'};
            }
        }
    }



    set<string> wins;

    auto is_win = [&](string x) -> bool {
        FOR(i, 0, 3) 
            if(x.substr(i * 3, 3) == "211" || x.substr(i*3, 3) == "112") return 1;
        FOR(i, 0, 3)
            if((x[i] == '2' && x[i+3] == '1' && x[i+6] == '1') || (x[i] == '1' && x[i+3] == '1' && x[i+6] == '2')) return 1;


        if(x[0] == '2' && x[4] == '1' && x[8] == '1') return 1;
        if(x[0] == '1' && x[4] == '2' && x[8] == '2') return 1;

        if(x[2] == '2' && x[4] == '1' && x[6] == '1') return 1;
        if(x[2] == '1' && x[4] == '2' && x[6] == '2') return 1;

        return false;
    };

    vt<vt<bool>> vis(N, vt<bool>(N));

    function<void(int, int, string)> dfs = [&](int i, int j, string cur) {
        vis[i][j] = 1;
        pr<int, int> index = a[i][j];
        if(cur[(i-1) * 3 + (j-1)] == '0') cur[(i-1) * 3 + (j-1)] = lets[{i, j}];
        bool full = 1;

        if(is_win(cur)) {
            wins.insert(cur);
            return;
        }

        FOR(k, 0, 9) full &= (cur[k] != '0');

        if(full) return;

        FOR(k, 0, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < N && nj >= 0 && nj < N && !vis[ni][nj] && a[ni][nj].f != 0)
                dfs(ni, nj, cur);
        }

    };

    FOR(i, 0, N) {
        FOR(j, 0, N)
            if(a[i][j].f != 0){
                vis = vt<vt<bool>>(N, vt<bool>(N, false));
                dfs(i, j, string(9, '0'));
            }
    }

    put(sz(wins));
    
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
