/**
 * 
 * author: DespicableMonkey
 * created: 05.22.2021 18:00:35
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

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}

void ff() { fflush(stdout); }

template<typename T> void dbg(T arg) {cout << arg << '\n';}
template<typename T> void dbg(T arg, T arg2) {cout << arg << " " << arg2 << " " << '\n';}
template<typename T> void dbg(T arg, T arg2, T arg3) {cout << arg << " " << arg2 << " " << arg3 << " " << '\n';}
template<typename T> void dbg(T arg, T arg2, T arg3, T arg4) {cout << arg << " " << arg2 << " " << arg3 << " " << arg4 << " " << '\n';}
template<typename T> void dbg(T arg, T arg2, T arg3, T arg4, T arg5) {cout << arg << " " << arg2 << " " << arg3 << " " << arg4 << " " << arg5 << '\n';}
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
|||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| 
|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| 
|||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| |||||||||||||||||| 
*/

struct pt{
    int x, y;
};
/*
    Check if 4 points make a square of area > 0
*/
int distSq(pt p, pt q){ return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);}
bool isSquare(pt p1, pt p2, pt p3, pt p4){
    int d2 = distSq(p1, p2), d3 = distSq(p1, p3), d4 = distSq(p1, p4); 
    if (d2 == 0 || d3 == 0 || d4 == 0)    return false;
    if (d2 == d3 && 2 * d2 == d4 && 2 * distSq(p2, p4) == distSq(p2, p3)) return true;
    if (d3 == d4 && 2 * d3 == d2  && 2 * distSq(p3, p2) == distSq(p3, p4)) return true;
    if (d2 == d4 && 2 * d2 == d3 && 2 * distSq(p2, p3) == distSq(p2, p4))  return true; 
    return false;
}
pt loc[4][2];
int go(int a, int b, int c, int d) {
    int mov[4]{a, b, c, d};
    pt newloc[4];
    FOR(i, 0, 4)
        newloc[i] = loc[i][0];

    FOR(i, 0, 4) {
         /*
            Rotate a point 90 degres CC around another point(home) move[i] number of times
        */
        FOR(j, 0, mov[i]){
            int xx = newloc[i].x;
            int yy = newloc[i].y;

            newloc[i].x = (-(yy - loc[i][1].y)) + loc[i][1].x;
            newloc[i].y = (xx - loc[i][1].x) + loc[i][1].y;
        }
    }

    if(isSquare(newloc[0], newloc[1], newloc[2], newloc[3]))
        return a+b+c+d;
    else
        return -1;
}

void solve() {
    FOR(i, 0, 4) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        loc[i][0] = pt{a, b};
        loc[i][1] = pt{c, d};
    }
    int ans = 1000000;
    FOR(i, 0, 4) {
        FOR(j, 0, 4) {
            FOR(k, 0, 4) {
                FOR(l, 0, 4) {
                    if(i + j + k + l < ans) {
                        int val = go(i, j, k, l);
                        ans = (val != -1 ? val : ans);
                    }
                }
            }
        }
    }
    cout << (ans == 1000000 ? -1 : ans) nl
    vi a;
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