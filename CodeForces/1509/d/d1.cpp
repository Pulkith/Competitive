/**
 * 
 * author: DespicableMonkey
 * created: 05.21.2021 12:01:22
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
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
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
	void setIO(string s = "") {
		cin.tie(nullptr)->sync_with_stdio(0);
		cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
    void setIO(string s, string t) {
        cin.tie(nullptr)->sync_with_stdio(0);
        setIn(s); 
        setOut(t);
    }
}

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}
void ff() { fflush(stdout); }

struct pred {
    bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) {
        return l.s < r.s;
    }
};

string a[3];
int freq[3];
int n;

void go(string a, string b, char f) {
    string ans = "";
    int fp = 0;
    FOR(i, 0, sz(a)) {
        if(a[i] != f)
            ans += a[i];
        else {
            while(fp < sz(b) && b[fp] != f)
                ans += b[fp++];
            ans += f;
            ++fp;
        }
    }
    while(fp < sz(b))
        ans += b[fp++];
    cout << ans nl

} 
void solve() {
    int ind[3]{0, 1, 2};
    cin >> n >> a[0] >> a[1] >> a[2];
    memset(freq, 0, sizeof(freq));
    FOR(i, 0, 3) {
        FOR(j, 0, n*2)
            freq[i] += (a[i][j] == '0' ? 1 : -1);
    }
    do {  
            if(freq[ind[0]] >= 0 && freq[ind[1]] >= 0){
                go(a[ind[0]], a[ind[1]], '0');
                break;
            }
            else if(freq[ind[0]] <= 0 && freq[ind[1]] <= 0){
                go(a[ind[0]], a[ind[1]], '1');
                break;
            }
    } while(next_permutation(ind, ind+3));
}

int main () {
    setIO();
    debug(2,2,"abc");
    int T = 1; 
    cin >> T;

    TC(T){
        //cout << "Case #" << tt << ": "
        solve();
    }

    return 0;
}