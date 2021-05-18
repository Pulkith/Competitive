/**
 * 
 * author: DespicableMonkey
 * created: 05.18.2021 04:20:20
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

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}
void ff() { fflush(stdout); }

int n, m;
vector<int> a;

bool works(int k) {
    int last = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; ++i) {
        if(sz(pq) == k) {
            last = pq.top(); pq.pop();
        }
        if(last + a[i] > m) return false;
        pq.push(last + a[i]);
    }
    return true;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> n >> m;
    FOR(i, 0, n){
        int x;
        cin >> x;
        a.pb(x);
    }

    int lo = 1, hi = n;

    while(lo != hi) {
        int mid = (lo+hi) / 2;
        if(works(mid)) 
            hi = mid;
        else
            lo = mid + 1;
    }


    cout << lo nl

    return 0;
}
/*


6
3
4
1
7


*/