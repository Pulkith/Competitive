/**
 * author: DespicableMonkey
 * created: 06.11.2021 15:35:24
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
#endif

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
}

struct pred { 
    bool operator()(const std::vector<int> &l, const std::vector<int> &r) { 
        return r[1] < l[1];
    } 
};

using namespace CP;

/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */
int N, K;
int prefix_segs[200005];
vt<vt<int>> segs[200005];
int subtract[200005];
vt<int> ans;
multiset<vt<int>, pred> cur_segs;
namespace Solve {

    void test_case([[maybe_unused]] int test_case = 0) {
        
        cin >> N >> K;
        FOR(i, 0, N) {
            re(x); re(y);
            segs[x].pb({x, y, i+1});
            //count number of segments over every point
            ++prefix_segs[x];
            --prefix_segs[y+1];
        }
        int cur_sub = 0;
        partial_sum(prefix_segs, prefix_segs + (200002), prefix_segs);
        FOR(i, 1, 200001) {
            cur_sub += subtract[i];
            for(auto seg : segs[i])
                cur_segs.insert(seg);
            while(sz(cur_segs) && (*cur_segs.rbegin())[1] < i) 
                cur_segs.erase(--cur_segs.end());
            while(prefix_segs[i] - cur_sub > K) {
                assert(!empty(cur_segs));
                auto seg = *cur_segs.begin();
                ++cur_sub;
                --subtract[seg[1]+1];
                ans.pb(seg[2]);
                cur_segs.erase(cur_segs.begin());
                
            }
        }

        put(sz(ans));
        if(sz(ans)) outv(ans);

    }
}

using namespace Solve;
int main () {
    CP::IO::SetIO();
    CP::IO::FastIO();

    #if LOCAL
        CP::IO::setIn("in2.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif
    CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420
    //cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        if (debug) { cout << YELLOW << "\n[Test #" << (tt) << "]\n" << RESET; }
        Solve::test_case(tt);
    }

    #if LOCAL
        CP::ExecTime::log_time(0);
    #endif

    return 0;
}