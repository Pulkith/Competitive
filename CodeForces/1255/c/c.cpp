/**
 * 
 * author: DespicableMonkey
 * created: 05.22.2021 00:51:02
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

template<class T> void out_vector(vector<T> v) {
    for(T& i : v) cout << i << " "; cout << '\n'; }
template<class T> void out_arr(T a[], int N) {
    for(int i = 0; i < N; ++i) cout << a[i] << " "; cout << '\n'; }
/*
    64 mil =  ~1 second
*/


int freq[100005];
int third(int a, int b, int c, int x, int y) {
    if((x == a && b == y) || (a == y && b == x)) return c;
    if(x == a && y == c || x == c && y == a) return b;
    else return a;
}
void solve() {
    int n; cin >> n;
    multimap<string, vi> mp;
    FOR(i, 0, n-2) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = min(a, min(b, c));
        int y = max(a, max(b, c));
        int z = third(a, b, c, x, y);
        vi arr; arr.pb(x); arr.pb(z); arr.pb(y);
        ++freq[a]; ++freq[b]; ++freq[c];
        mp.insert({ts(x)+"|"+ts(y), arr});
        mp.insert({ts(x)+"|"+ts(z), arr});
        mp.insert({ts(z)+"|"+ts(y), arr});
    }

    vi nxt;
    for(auto& a : mp) {
        bool ok = false;
        for(auto& i : a.s)
            if(freq[i] == 1)
                ok = true;
        if(ok){
            nxt = a.s;
            break;
        }
    }
    vi ans;
    string key;
    
    for(int i = 0; i < 3; ++i) {
        if(freq[nxt[i]] == 1) {
            ans.pb(nxt[i]);
            for(int j = 0; j < 3; ++j) {
                if(i != j && freq[nxt[j]] == 2) {
                    ans.pb(nxt[j]);
                    int lst = (i==0) ? (j == 1) ? 2 : 1 : (i == 1) ? (j ==0) ? 2 : 0 : (j==1 ? 0 : 1);
                    ans.pb(nxt[lst]);
                    key = ts(min(nxt[lst], nxt[j])) + "|"+ ts(max(nxt[lst], nxt[j]));
                    auto it = mp.equal_range(key);
                    nxt = (((*it.f).s == nxt) ? (*it.s).s : (*it.f).s);
                    bool ok = true;
                    for(int x = 0; x < 3 && ok; ++x) {
                        FOR(y, 0, 3) {
                            if(x != y && nxt[x] != ans[0] && nxt[y] != ans[0]) {
                                 key = ts(min(nxt[x], nxt[y])) + "|"+ ts(max(nxt[x], nxt[y]));
                                 auto it2 = mp.equal_range(key); 
                                 if((*it2.f).s == nxt)
                                    mp.erase(it2.f);
                                else
                                    mp.erase(--it2.s);
                                ok = false;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    FOR(i, 1, n-2) {
        FOR(j, 0, 3) {
            if(nxt[j] != ans.back()) {
                key = ts(min(nxt[j], ans.back())) + "|"+ ts(max(ans.back(), nxt[j]));
                if(mp.find(key) != mp.end()) {
                    FOR(k, 0, 3) {
                        if(nxt[k] != ans.back() && nxt[k] != ans[sz(ans)-2]){
                            ans.pb(nxt[k]);
                            break;
                        }
                    }
                    if(!(i == n-3))
                        nxt = (*mp.find(key)).s;
                    debug(key);
                    out_vector(nxt);
                    out_vector(ans);
                    mp.erase(key);
                    break;
                }
            }
        }
    }
// 1 3 2 4 5 6 7 8
// (1,3, 2), (3, 2, 4), (2,4,5), (4,5,6), (5, 6, 7), (6, 7, 8);
    cout << ans nl
}

int main () {
    setIO();

    int T = 1; 
    //cin >> T;

    TC(T){
        //cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}