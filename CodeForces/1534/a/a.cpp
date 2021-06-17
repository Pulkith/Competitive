/**
 * author: DespicableMonkey
 * created: 06.16.2021 00:15:02
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
#endif

using namespace std;

typedef int64_t ll;

#define pb push_back
#define f first
#define s second
#define x first
#define y second

#define my_brain_hurts int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T, class U> T cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

[[maybe_unused]] const int MOD = 1'000'000'007;
[[maybe_unused]] const double EPS = (1e-9);
[[maybe_unused]] const int INF = 2'000'000'000; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
[[maybe_unused]] const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

inline namespace CP {
    inline namespace IO {
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void FastIO() {
            cin.tie(nullptr)->sync_with_stdio(0);
            std::cout << std::fixed << std::showpoint;
            std::cout << std::setprecision(14);
        }
        void SetIO(string s = "", string t = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if(sz(t)) setIn(s), setOut(t);
            else if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
        }
    }
    inline namespace Output {
        bool debug = 0;
        string operator+(string str, int num){return str + ts(num);}
        string operator+(int num, string str) { return str + ts(num); }
        string to_string(const char* s) { return string(s);}
        #if !defined LOCAL
            #define dbg(...)
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T s) { cout << s << '\n'; }
        #define putr(s) return put(s), 0
    }
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

int N, M;
char a[51][51];




int test_case([[maybe_unused]] int test_case = 0) {
    cin >> N >> M;
    vector<vector<char>> ans(N, vt<char>(M)), ans2(N, vt<char>(M));

    FOR(i, 0, N) {
        string s; cin >> s;
        FOR(j, 0, M)
            a[i][j] = s[j];
    }
    auto try1 = [&]() -> bool {
        FOR(i, 0, N) {
            FOR(j, 0, M) {
                char color = ((i+j)&1) ? 'R' : 'W';
                if(a[i][j] != '.' && a[i][j] != color) {
                    return false;
                }
                ans[i][j] = color;
            }
        }
        return 1;
    };

    auto try2 = [&]() -> bool {
        FOR(i, 0, N) {
            FOR(j, 0, M) {
                char color = ((i+j)&1) ? 'W' : 'R';
                if(a[i][j] != '.' && a[i][j] != color) {
                    return false;
                }
                ans2[i][j] = color;
            }
        }
        return 1;
    };

    if(try1()) {
        cout << "YES" << '\n';
        FOR(i, 0, N) {
            FOR(j, 0, M) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
        return 0;
    }

    if(try2()) {
        cout << "YES" << '\n';
        FOR(i, 0, N) {
            FOR(j, 0, M) {
                cout << ans2[i][j];
            }
            cout << '\n';
        }
        return 0;
    }

    put("NO");






    return 0;   
}

int main () {
    CP::IO::SetIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif
    my_brain_hurts
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        if (debug) { cerr << "\033[33m" << "\n[Test #" << (tt) << "]\n" << "\033[0m"; }
        test_case(tt);
    }

    #if LOCAL
        CP::ExecTime::log_time(0);
    #endif

    return 0;
}