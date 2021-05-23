/**
 * 
 * author: DespicableMonkey
 * created: 05.21.2021 00:17:12
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

#define nl << "\n";
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
int n;
int x1,x2;
char calc(string s, bool o) {
    int z = 0;
    for(auto c : s)
        if(c == '0')
            ++z;
    char c = (z <= n ? '1' : '0');
    if(o)
        x1 = ('0' == c ? z : (n*2 - z));
    else
        x2 = ('0' == c ? z : (n*2 - z));
    return c;
}

bool verify(string a, string b) {
    int pt1 = 0, pt2 = 0;
    bool ok = true;
    while(pt2 < sz(b)) {
        if(pt1 >= sz(a)){ ok = false; break;}
         if(a[pt1] == b[pt2]) {
             ++pt1;
             ++pt2;
         } else {
             ++pt1;
         }
    }
    return ok;
}


void solve() {
    cin >> n;
    FOR(i, 0, 3)
        cin >> a[i];
    vector<char> ans;
    bool ok = true;
    FOR(i, 0, 3) {
        if(!ok) continue;
        FOR(j, 0, 3) {
            if(i == j) continue;
            char f = calc(a[i], true);
            if(f == calc(a[j], false)) {
                if(x2 > x1) {
                    swap(x1, x2);
                    swap(a[i], a[j]);
                }
                for(char c: a[i]){
                    ans.pb(c);
                }
                int fp = 0;
                for(int k = 0; k < n*2; ++k){
                    if(fp > sz(ans)) {
                        for(int x = k; x < n*2; ++x)
                            ans.pb(a[j][x]);
                        break;
                    }
                    if(a[j][k] == f)
                        while(ans[fp++] != f);
                    else
                        ans.insert(ans.begin() + fp++, a[j][k]);
                }
                ok = false;
                break;
            }
        }
    }
    string res = "";
    for(char c : ans)
        res += c;
    cout << res nl
}    

int main () {
    setIO();
    int T = 1; 
   cin >> T;
    TC(T){
        //cout << "Case #" << tt << ": "
        solve();
    }

    return 0;
    /*
    1000 -> 0
    1010 -> 1
    1110 -> 1
    11010

    001111
    111100

    */
}