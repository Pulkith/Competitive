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
string a[MX][MX];
bool vis[MX][MX][20000];
const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

map<string, int> ids;
set<int> wins;
int pow3[10];
bool iswin(int n) {
    int g[3][3];
    FOR(i, 0, 3) FOR(j, 0, 3) {g[i][j] = (n % 3); n /= 3;}
    bool win = 0;
    FOR(i, 0, 3) win |= g[i][1] == 2 && ((g[i][0] == 1 && g[i][2] == 2) || (g[i][0] == 2 && g[i][2] == 1));
    FOR(i, 0, 3) win |= g[1][i] == 2 && ((g[0][i] == 1 && g[2][i] == 2) || (g[0][i] == 2 && g[2][i] == 1));
    win |= g[1][1] == 2 && (((g[0][0] == 1 && g[2][2] == 2) || (g[0][0] == 2 && g[2][2] == 1)) ||
                            ((g[0][2] == 1 && g[2][0] == 2) || (g[0][2] == 2 && g[2][0] == 1)));
    return win;
}

void dfs(int i, int j, int state) {
    vis[i][j][state] = true;
    if(a[i][j][0] > '0') {
        int ni = a[i][j][1] - '1', nj = a[i][j][2] - '1'; 
        int idx = ni * 3 + nj;
        if((state / pow3[idx]) % 3 == 0) {
            state += (a[i][j][0] - '0') * pow3[idx]; //only works if idx == 0
            // state = (state % pow3[idx]) + (a[i][j][0] - '0') * pow3[idx] + (state - state % pow3[idx+1]);
            // ^ other way to add a[i][j][0] to index idx while keeping other values
            if(iswin(state)) {
                wins.insert(state);
                return;
            }
        }
    }

    for(int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if(ni >= 0 && ni < N && nj >= 0 && nj < N && a[ni][nj][0] > '-' && !vis[ni][nj][state])
            dfs(ni, nj, state);
    }

}

void test_case() {
    cin >> N;
    int sti = 0, stj = 0;
    FOR(i, 0, N) {
        string s; cin >> s;
        for(int j = 0; j < N; ++j){
            FOR(k, 0, 3) a[i][j] += s[j * 3 + k];
            if(a[i][j][0] == 'O') a[i][j][0] = '2';
            else if(a[i][j][0] == 'B') {
                a[i][j][0] = '0'; sti = i; stj = j;
            }
            else if(a[i][j][0] == 'M') a[i][j][0] = '1';
            else if(a[i][j][0] == '.') a[i][j][0] = '0';
            else a[i][j][0] = '-';
        }

    }
    dfs(sti, stj, 0);
    put(sz(wins));
}
int main () {
    CP::IO().SetIO()->FastIO().Input(0);
    pow3[0] = 1;
    FORE(i, 1, 9) pow3[i] = pow3[i-1] * 3;
    my_brain_hurts
    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
