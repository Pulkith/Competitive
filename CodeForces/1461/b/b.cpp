/**
 * author: DespicableMonkey
 * created: 06.08.2021 11:25:15
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;

typedef int64_t ll;

#define pb push_back
#define f first
#define s second

#define nl '\n'
#define CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420 int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = a; i >= b; --i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<class T> T cdiv(T a, T b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> T fdiv(T a, T b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int read() {int element; cin >> element; return element;}
#define re(var) int var = read();

[[maybe_unused]] const int MOD = 1'000'000'007;
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
        void setIO(string s = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
        }
        void setIO(string s, string t) {
            setIn(s);
            setOut(t);
        }
    }
    inline namespace ExecTime {
        #define cur_t std::chrono::high_resolution_clock::now() /* 100 mil =  ~1 second */
        auto _start_time = cur_t;
        bool use = 0;
        void use_clock() { use = 1; }
        void log_time(bool start = true) {
            if(use) {
                if(!start) {
                    auto _stop_time = cur_t;
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(_stop_time - _start_time);
                    cerr << '\n' << "[Time: " << to_string(duration.count()) << " ms] " << '\n' << '\n';
                }
                else
                    _start_time = cur_t;
            }
        }
    }
}
inline namespace Output {
    void ff() {  fflush(stdout); }
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
    void lower(std::string& s){transform(s.begin(), s.end(), s.begin(), ::tolower);}
    template<typename T, typename U> ostream& operator<<(ostream& is, pair<T, U> &v){is << "(" << v.first << " " << v.second << ")"; return is;}
    template<class T> void outv(vector<T> v) {
    for(T& i : v) cout << i << " "; cout << '\n'; }
    template<class T> void outarr(T a[], int N) {
        for(int i = 0; i < N; ++i) cout << a[i] << " "; cout << '\n'; }
    template<class T> void put(T s) {
        cout << s << '\n'; }
}

struct pred { bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) { 
    return l.s < r.s; } };

/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */
void solve() {
    int N, M;
    cin >> N >> M;
    vt<vt<int>> grid(N, vt<int>(M)), prefix(N, vt<int>(M));
    FOR(i, 0, N) {
        string s; cin >> s;
        FOR(j, 0, M)
            grid[i][j] = s[j] == '*', prefix[i][j] = s[j] == '*';
    }

    FOR(i, 0, N) partial_sum(prefix[i].begin(), prefix[i].end(), prefix[i].begin());

    ll ans = 0;
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            if(grid[i][j]) {
                int left_edge = j, right_edge = j, height = 1, center_height = i;
                while(left_edge >= 0 && right_edge < M && height + center_height - 1 < N) {
                    int left = (left_edge == 0 ? 0 : prefix[center_height + height - 1][left_edge-1]);
                    int right = prefix[center_height + height - 1][right_edge];
                    if(right - left != right_edge - left_edge + 1) {
                        break;
                    }
                    --left_edge;
                    ++right_edge;
                    ++height;
                    ++ans;
                }
            }
        }
    }

    put(ans);



}

int main () {
    CP::IO::setIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif

    CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420
    cin >> T;

    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        if (debug) { cout << YELLOW << "\n[Test #" << (tt) << "]\n" << RESET; }
        solve();
    }

    CP::ExecTime::log_time(0);
    return 0;
}