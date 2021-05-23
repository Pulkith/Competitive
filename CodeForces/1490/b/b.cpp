/**
 * 
 * author: DespicableMonkey
 * created: 05.22.2021 13:48:18
 * 
 * Potatoes FTW!
 * 
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

using namespace std;

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

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}

void ff() { fflush(stdout); }

template<typename T> void debug(T arg) {cout << arg << '\n';}
template<typename T> void debug(T arg, T arg2) {cout << arg << " " << arg2 << " " << '\n';}
template<typename T> void debug(T arg, T arg2, T arg3) {cout << arg << " " << arg2 << " " << arg3 << " " << '\n';}
template<typename T> void debug(T arg, T arg2, T arg3, T arg4) {cout << arg << " " << arg2 << " " << arg3 << " " << arg4 << " " << '\n';}
template<typename T> void debug(T arg, T arg2, T arg3, T arg4, T arg5) {cout << arg << " " << arg2 << " " << arg3 << " " << arg4 << " " << arg5 << '\n';}
struct pred {
    bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) { return l.s < r.s; } };


ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

template<class T> void outv(vector<T> v) {
    for(T& i : v) cout << i << " "; cout << '\n'; }
template<class T> void outarr(T a[], int N) {
    for(int i = 0; i < N; ++i) cout << a[i] << " "; cout << '\n'; }
template<class T> void puts(T s) {
    cout << s << '\n';
}
/*
    64 mil =  ~1 second
*/

int n;
int a[30005];
int freq[3];

void solve() {
    cin >> n;
    FOR(i, 0, n)
        cin >> a[i];
    FOR(i, 0, n)
        ++freq[a[i] % 3];
    if(freq[0] == freq[1] && freq[1]  == freq[2])
        cout << 0 nl
    else {
        
    }
}

int main () {
    setIO();

    int T = 1; 
    cin >> T;

    TC(T){
        //cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}