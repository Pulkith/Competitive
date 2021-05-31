/**
 * author: DespicableMonkey
 * created: 05.29.2021 00:35:02
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

/* 64 mil =  ~1 second */
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
inline namespace Output {
    void ff() { fflush(stdout); }
    #define dbg1(arg) cerr << " [" << #arg << ": " << arg << "] " << '\n';
    #define dbg2(arg, arg2) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << "] " << '\n';
    #define dbg3(arg, arg2, arg3) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << "] " << '\n';
    #define dbg4(arg, arg2, arg3, arg4) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << "] " << '\n';
    #define dbg5(arg, arg2, arg3, arg4, arg5) cerr << " [" << #arg << ": " << arg << ", " << #arg2 << ": " << arg2 << ", " << #arg3 << ": " << arg3 << ", " << #arg4 << ": " << arg4 << ", " << #arg5 << ": " << arg5 << "] " << '\n';
    #define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
    #define dbg(...) GET_MACRO(__VA_ARGS__, dbg5, dbg4, dbg3, dbg2, dbg1)(__VA_ARGS__)

    template<typename T, typename U> ostream& operator<<(ostream& is, pair<T, U> &v){is << "{" << v.first << " " << v.second << "}"; return is;}
    template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}
    template<typename T, typename U> void dbgcon(vector<T> v, U desc = "") {
        cerr << desc << '\n';
        for(T& i : v) cerr << i << " ";
        cerr << '\n';
    }
    template<class T> void outv(vector<T> v) {
    for(T& i : v) cout << i << " "; cout << '\n'; }
    template<class T> void outarr(T a[], int N) {
        for(int i = 0; i < N; ++i) cout << a[i] << " "; cout << '\n'; }
    template<class T> void put(T s) {
        cout << s << '\n'; }
}

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}

struct pred { bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) { return l.s < r.s; } };

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

#define cntbits(X)  __builtin_popcountll(X) //number of "on" bits in num

#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))

template<class T> bool chmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool chmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
/*
|||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| 
|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| 
|||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| 
*/
bool pal(string s) {
    for(int i = 0; i < sz(s); ++i)  
        if(!(s[i] == s[sz(s) - 1 - i])) return 0;
    return 1;
}
void solve() {
    int N, M;
    cin >> N >> M;
    map<string, int> mp;

    FOR(i, 0, N) {
        string s; cin >> s;
        ++mp[s];
    }   
    set<string> used;
    string res = "";
    for(auto [x, y] : mp) {
        string xx = x; reverse(xx.begin(), xx.end());
        if(xx != x && mp.find(xx) != mp.end() && used.find(xx) == used.end()) {
            int dif = min(mp[xx], y);
            mp[x] -= dif;
            mp[xx] -= dif;
            used.insert(x); used.insert(xx);
            FOR(i, 0, dif)
                res = xx + res + x;
        }
    }


    string maxx = "";
    for(auto [x, y] : mp) {
        if(y > 0) {
            if(pal(x) && sz(x) > sz(maxx)) {
                maxx = x;
            }
        }
    }
    if(sz(maxx) && sz(res)%2==0) {
        res = res.substr(0, sz(res) / 2) + maxx + res.substr(sz(res) / 2);
    }
    cout << (sz(res)) nl
    if(sz(res)) put(res);
}

int main () {
    setIO();

    #if LOCAL
        //setIn("in1.txt");
        use_clock();
    #endif

    int T = 1; 
    //cin >> T;

    TC(T){
        //cout << "Case #" << tt << ": ";
        solve();
    }

    log_time(0);

    return 0;
}