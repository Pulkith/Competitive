/**
 * author: DespicableMonkey
 * created: 05.26.2021 19:06:01
 * 
 * Potatoes FTW!
 **/ 

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>
#include <cstring>
#include <numeric> 
#include <cassert>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define ll long long
#define ld long double
#define ull unsigned long long

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define vi vector<int>
#define vll vector<ll>
#define vb = vector<bool>
#define pb push_back

#define f first
#define s second

#define nl << '\n';
#define nn '\n'
#define cnl cout nl


#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)
#define rall(x) x.rbegin(), x.rend()
#define sortt(x) sort(all(x))
#define rtn return

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FR(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = a; i >= b; --i)
#define RF(i,a) ROF(i,a,0)
#define TC(i) for(int tt = (1); tt <= (i); ++tt)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const long long LLNF = (ll)10e17+7;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

/* 64 mil =  ~1 second */
inline namespace FileIO {
	void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
    void setDefault() {
        	cin.tie(nullptr)->sync_with_stdio(0);
            std::cout << std::fixed << std::showpoint;
            std::cout << std::setprecision(14);
    }
	void setIO(string s = "") {
        setDefault();
		cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
    void setIO(string s, string t) {
        setDefault();
        setIn(s); 
        setOut(t);
    }
}

inline namespace ExecTime {
    #define cur_t chrono::high_resolution_clock::now()
    auto _start_time = cur_t;
    bool use = 0;
    void use_clock() { use = 1; }
    void log_time(bool start = true) {
        if(use) {
            if(!start) {
                auto _stop_time = cur_t;
                auto duration = duration_cast<milliseconds>(_stop_time - _start_time);
                cerr << '\n' << "[Time: " << to_string(duration.count()) << " ms] " << '\n' << '\n'; 
            }
            else
                _start_time = cur_t;
        }
    }
}

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T, typename U> ostream& operator<<(ostream& is, pair<T, U> &v){is << v.first << " " << v.second; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}

void ff() { fflush(stdout); }
#define dbg1(arg) cerr << " [" << #arg << ": " << arg << "] " << '\n';
#define dbg2(arg, arg2) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << "] " << '\n';
#define dbg3(arg, arg2, arg3) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << "] " << '\n';
#define dbg4(arg, arg2, arg3, arg4) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << "] " << '\n';
#define dbg5(arg, arg2, arg3, arg4, arg5) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << "] " << ", " << #arg4 << ": " << arg4 << ", " << #arg5 << ": " << arg5 << '\n';
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define dbg(...) GET_MACRO(__VA_ARGS__, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)

struct pred { bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) { return l.s < r.s; } };

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

#define setbits(X)  __builtin_popcountll(X) //number of "on" bits in num

#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))

template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

template<class T> void outv(vector<T> v) {
    for(T& i : v) cout << i << " "; cout << '\n'; }
template<class T> void outarr(T a[], int N) {
    for(int i = 0; i < N; ++i) cout << a[i] << " "; cout << '\n'; }
template<class T> void put(T s) {
    cout << s << '\n'; }
/*
|||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| 
|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| 
|||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| 
*/

void solve() {
    int N; cin >> N;
    vi a(N);
    cin >> a;

    int maxx = 0;
    int index = 0;
   
    //A number can be minimized if a[i-1] < a > a[i+1] or a[i-1] > a < a[i+1]
    FOR(i, 1, N-1) {
        if(a[i] > a[i-1] && a[i] > a[i+1] || a[i] < a[i-1] && a[i] < a[i+1]) {
            //we have to substract the range between a[i+1] and a[i-1], becuase any number
            //within that range wont decrease the total sum
            int cur = abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]) - abs(a[i+1] - a[i-1]);
            if(cur > maxx)
                maxx = cur;
        }
    }
    ll ans = 0;
    FOR(i, 0, N-1)
        ans += abs(a[i] - a[i+1]);
        //we have to check the minimum between the above, and if we change the first number or last number,
        //becuase those numbers arent included in the for loop above
    ans = min(ans - maxx, min(ans - abs(a[0] - a[1]), ans - abs(a[N-1] - a[N-2])));

    put(ans);
}

int main () {
    setIO();

    #if LOCAL
        //setIn("in1.txt");
        use_clock();
    #endif

    int T = 1; 
    cin >> T;

    TC(T){
        //cout << "Case #" << tt << ": ";
        solve();
    }

    log_time(0);

    return 0;
}