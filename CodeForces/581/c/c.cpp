/**
 * 
 * author: DespicableMonkey
 * created: 05.18.2021 16:42:02
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
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}
struct pred {
    bool operator()(const int &l, const int &r) {
        int ldis = (l / 10) * 10 + 10;
        int rdis  = (r / 10) * 10 + 10;
        if(l == 100 ) return true;
        if(r == 100) return false;
        return (ldis - l > rdis - r );
    }
};

int main () {
    IO();

   int n, k;
   cin >> n >> k;
   priority_queue<int, vi, pred> pq;
    FOR(i, 0, n)    {
        int x; cin >> x;
        pq.push(x);
    }
   while(k > 0 && pq.top() < 100) {
       int x = pq.top();
       pq.pop();
       int dif = min(k, ((x / 10) * 10 + 10) - x);
       pq.push(x+dif);
       k -= dif;
   }
   ll sum = 0;
   while(pq.size() > 0) {
       sum += pq.top() / 10;
       pq.pop();
   }
   cout << sum nl;

    return 0;
}