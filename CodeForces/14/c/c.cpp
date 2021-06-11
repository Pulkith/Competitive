/**
 * author: DespicableMonkey
 * created: 06.11.2021 00:28:00
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;

typedef int64_t ll;

#define pb push_back
#define f first
#define s second
#define x first
#define y second

#define nl '\n'
#define CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420 int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> T cdiv(T a, T b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int read() {int element; cin >> element; return element;}
#define re(var) int var = read();

[[maybe_unused]] const int MOD = 1'000'000'007;
[[maybe_unused]] const double EPS = (1e-9);
[[maybe_unused]] const int INF = 2'000'000'000; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
[[maybe_unused]] const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

namespace CP {
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
    inline namespace ExecTime {
        #define cur_t std::chrono::high_resolution_clock::now() /* 100 mil =  ~1 second */
        auto __start_time = cur_t;
        bool use = 0;
        void use_clock() { use = 1; }
        void log_time(bool start = true) {
            if(use) {
                if(!start) {
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(cur_t - __start_time);
                    cerr << '\n' << "[Time: " << to_string(duration.count()) << " ms] " << '\n' << '\n';
                }
                else  __start_time = cur_t;
            }
        }
    }
}
inline namespace Output {
    bool debug = 0;
    string operator+(string str, int num){return str + ts(num);}
    string operator+(int num, string str) { return str + ts(num); }
    string to_string(char c) { return string(1, c); }
    string to_string(const char* s) { return string(s);}
    const string RESET = "\033[0m", GREEN="\033[32m", BLACK="\033[30m", RED="\033[31m", YELLOW="\033[33m";    
    #define dbg1(arg) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << "] " << RESET << '\n';}}
    #define dbg2(arg, arg2) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << "] " << RESET << '\n';}}
    #define dbg3(arg, arg2, arg3) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << "] " << RESET << '\n';}}
    #define dbg4(arg, arg2, arg3, arg4) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << "] " << RESET << '\n';}}
    #define dbg5(arg, arg2, arg3, arg4, arg5) {if(debug){cerr << GREEN << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << ", " << #arg5 << ": " << arg5 << "] " << RESET << '\n';}}
    #define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
    #define dbg(...) GET_MACRO(__VA_ARGS__, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)
    template<typename T, typename U> ostream& operator<<(ostream& is, pair<T, U> &v){is << "(" << v.first << " " << v.second << ")"; return is;}
    template<class T> void outv(vector<T> v, bool standard = 1) {
    for(T& i : v) (standard?cout:cerr) << i << " "; cout << '\n'; }
    template<class T> void put(T s) {
        cout << s << '\n'; }
}

/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

//check if 4 line segments can make a rectangle
void solve() {
    vt<pr<int, int>> horizontal_top, horizontal_bottom, vertical_right, vertical_left;
    bool ok = 1;
    FOR(i, 0, 4) {
        re(x1); re(y1); re(x2); re(y2);
        ok&=(x1==x2||y1==y2);

        if(x1 == x2) {
            if(y2 > y1) swap(x2, x1), swap(y2, y1);

            vt<pr<int,int>> cur = {{x1, y1}, {x2, y2}};

            if(sz(vertical_left)) {
                if(vertical_left[0].x > cur[0].x) swap(vertical_left, cur);
                vertical_right = cur;
            } else
                vertical_left = cur;

            
        } else {
            if(x2 < x1) swap(x2, x1), swap(y2, y1);

            vt<pr<int, int>> cur = {{x1, y1}, {x2, y2}};

            if(sz(horizontal_top)) {
                if(horizontal_top[0].y < cur[0].y) swap(horizontal_top, cur);
                horizontal_bottom = cur;
            }
            else horizontal_top = cur;
        }
    }


    if(ok) {
        if(sz(horizontal_top) && sz(horizontal_bottom) && sz(vertical_left) && sz(vertical_right)) {
            if(horizontal_top[0] == vertical_left[0] &&
                horizontal_top[1] == vertical_right[0] &&
                horizontal_bottom[0] == vertical_left[1] &&
                horizontal_bottom[1] == vertical_right[1] &&
                horizontal_top[0].y - horizontal_bottom[0].y > 0 &&
                vertical_right[1].x - vertical_left[1].x > 0
            ) ok = 1;
            else ok = 0;

        } else ok = 0;
    }


    put(ok?"YES":"NO");
}
int main () {
    CP::IO::SetIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif

    CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420
    //cin >> T;

    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        if (debug) { cout << YELLOW << "\n[Test #" << (tt) << "]\n" << RESET; }
        solve();
    }

    CP::ExecTime::log_time(0);
    return 0;
}