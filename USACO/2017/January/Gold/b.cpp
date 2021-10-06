/**
 * author: DespicableMonkey
 * created: 09.29.2021 23:39:05
 * Potatoes FTW!
 **/ 

#include <algorithm>
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

const int MX = (1e5+43);
int N, K;
int moves[MX];
int dp[MX][21][3];

void test_case() {
    cin >> N >> K;
    FOR(i, 0, N) {
        char c; cin >> c;
        moves[i] = (c== 'P' ? 0 : (c == 'S' ? 1 : 2));
    }
    // 0 beats 2, 1 beats 0, 2 beats 1
    FORE(i, 0, N) {
        FORE(j, 0, K) {
            FOR(k, 0, 3) {
                if(i == 0) dp[i][j][k] = 0;
                else {
                    if(j > 0) {
                        if(k != 0) cmax(dp[i][j][k], dp[i-1][j-1][0]);
                        if(k != 1) cmax(dp[i][j][k], dp[i-1][j-1][1]);
                        if(k != 2) cmax(dp[i][j][k], dp[i-1][j-1][2]);
                    }
                    cmax(dp[i][j][k], dp[i-1][j][k]);
                    if(moves[i-1] == 2 && k == 0) ++dp[i][j][k];
                    if(moves[i-1] == 0 && k == 1) ++dp[i][j][k];
                    if(moves[i-1] == 1 && k == 2) ++dp[i][j][k];
                }
            }
        }
    }


    put(max({dp[N][K][0], dp[N][K][1], dp[N][K][2]}));
}

int main () {
    CP::IO().SetIO("hps")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
