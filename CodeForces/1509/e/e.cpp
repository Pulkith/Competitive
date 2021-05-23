/**
 * 
 * author: DespicableMonkey
 * created: 05.21.2021 15:08:56
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
/*
    64 mil =  ~1 second
*/
ull N, Kin;

void recurs(ull base, ull amt, ull K, ull num) {
    if(num >= N) return;
    ull sum = 0;
    int cnt = 1;
    cout << amt;
    ff();
    while(sum + amt < K) {
       // cout << sum << " " << amt nl
        ff();
        ++cnt;
        sum += amt;
        if(cnt == N - base)
            amt = 1;
        else
            amt /= 2;
    }
    for(int i = (base+cnt); i > base; --i)
        cout << i << " ";
    num += ((base+cnt) - (base+1) + 1);
    recurs(base + cnt, amt == 1 ? 1 : amt / 2  , K - sum, num);
    
}
void solve() {
    cin >> N >> Kin;
    if(N<=63 && 1LL<<(N-1) < Kin){
        cout << -1 nl
        rtn;
    }
    if(N == 1) {
        cout << 1 nl
        rtn;
    }
    else if(N == 2) {
        if(Kin == 1)
            cout << "1 2" nl
        else
            cout << "2 1" nl
        rtn;
    }
    //recurs(0, 1ULL << (N-2), Kin, 0);
    recurs(0, N - 2, Kin, 0);
    cnl
    
}

int main () {
    setIO();

    int T = 1; 
    cin >> T;
    TC(T){
       // cout << "Case #" << tt << ": "
      solve();
    }

    return 0;
}
/*

N = 2; tot = 2;
1: 1
2: 1

N = 3; tot = 4
1: 2
2: 1
3: 1

N = 4; tot = 8
1: 4
2: 2
3: 1
4: 1

N = 5; tot = 16
1: 8
2: 4
3: 2
4: 1
5: 1

N = 6; tot = 32
1: 16
2: 8
3: 4
4: 2
5: 1
6: 1

*/