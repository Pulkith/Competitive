/**
 * 
 * author: DespicableMonkey
 * created: 05.03.2021 00:32:57
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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        vll x,y;
        ll n;
        cin >> n;
        FOR(i, 0, n) {
            ll a,b;
            cin >> a >> b;
            x.pb(a), y.pb(b);
        }
        sort(all(x));
        sort(all(y));

        /**
         * (n+1)/2, and (n+2)/2 get indexes of the medians. If array is odd length it returns
         * the same index, otherwise it returns the left median and right median respectivelly
         */ 
        ll x_size = sz(x), y_size = sz(y);
        ll x_s = x[(x_size + 2) / 2  - 1] - x[(x_size + 1) / 2 - 1 ] + 1;
        ll y_s = y[(y_size + 2) / 2 - 1] - y[(y_size + 1) / 2 - 1] + 1;
        cout << (x_s*y_s) nl

    }

    return 0;
}