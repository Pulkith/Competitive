/**
 * author: DespicableMonkey
 * created: 06.01.2021 16:23:01
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

using pii = pair<int, int>;
using pll = pair<long long, long long>;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
#define pb emplace_back
#define f first
#define s second

#define nl '\n'
#define CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420 int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FR(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = a; i >= b; --i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)
#define each(a,x) for (auto& a: x)

template<typename T, typename U> using p = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
const int INF = (1e7+7), MOD = (1e7+7);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

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
        #define cur_t std::chrono::high_resolution_clock::now() /* 64 mil =  ~1 second */
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
    void ff() { 
        fflush(stdout); 
        #if LOCAL 
            fflush(stderr);
        #endif
    }
    #define dbg1(arg) cerr << " [" << #arg << ": " << arg << "] " << '\n';
    #define dbg2(arg, arg2) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << "] " << '\n';
    #define dbg3(arg, arg2, arg3) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << "] " << '\n';
    #define dbg4(arg, arg2, arg3, arg4) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << "] " << '\n';
    #define dbg5(arg, arg2, arg3, arg4, arg5) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << ", " << #arg5 << ": " << arg5 << "] " << '\n';
    #define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
    #define dbg(...) GET_MACRO(__VA_ARGS__, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)
    void lower(std::string& s){transform(s.begin(), s.end(), s.begin(), ::tolower);}
    template<typename T, typename U> ostream& operator<<(ostream& is, pair<T, U> &v){is << "{" << v.first << " " << v.second << "}"; return is;}
    template<class T> void outv(vector<T> v) {
    for(T& i : v) cout << i << " "; cout << '\n'; }
    template<class T> void outarr(T a[], int N) {
        for(int i = 0; i < N; ++i) cout << a[i] << " "; cout << '\n'; }
    template<class T> void put(T s) {
        cout << s << '\n'; }
}

struct pred { bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) { 
    return l.s < r.s; } };

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

template<class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ex = 0;
    if(x1 != x2 && y1 != y2) ex = 2;
    cout << (abs(x2-x1) + abs(y2-y1) + ex) << endl;
}

int main () {
    CP::IO::setIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
    #endif

    CoMpIlAtIoN_ErRoR_oN_TeSt_CaSe_69420
    cin >> T;

    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        solve();
    }

    CP::ExecTime::log_time(0);
    return 0;
}