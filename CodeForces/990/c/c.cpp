/**
 * 
 * author: DespicableMonkey
 * created: 05.19.2021 09:40:47
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

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}
void ff() { fflush(stdout); }
void IO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
struct pred {
    bool operator()(const std::pair<int, int> &l, const std::pair<int, int> &r) {
        return l.s < r.s;
    }
};
string rev(string s) {
    string res = s;
    reverse(res.begin(), res.end());
    FOR(i, 0, sz(s))
        res[i] = (res[i] == '(' ? ')' : '(');
    return res;
}
int RBS(string s) {
    int bal = 0;
    for(char c : s) {
        bal += (c == '(' ? 1 : -1);
        if(bal < 0) return -1;
    }
    return bal;
}

int cnt[(int)(3e5+7)];

int main () {
    IO();

    int n; cin >> n;
    vector<string> a(n);

    FOR(i, 0, n) {
        string s;
        cin >> s;
        
        int x = RBS(s);
        if(x != -1)
            ++cnt[x];
        a[i] = s;
    }

    ll ans = 0;
    FOR(i, 0, n) {
        int x = RBS(rev(a[i]));
        if(x != -1){
            ans += cnt[x];
        }
    }

    cout << ans nl

    return 0;
}