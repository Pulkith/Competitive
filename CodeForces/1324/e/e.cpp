/**
 * 
 * author: DespicableMonkey
 * created: 05.08.2021 11:48:39
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

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}

int l, r;

bool check(int time) {
    return (time >= l && time <= r);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> h >> l >> r;

    vector<vector<vi>> dp(n+1, vector<vector<int>>(3, vi(2, 0)));
    vi a(n);
    FOR(i, 0, n)
        cin >> a[i];
    dp[0][0][0] = a[0]; dp[0][1][0] = a[0] - 1; dp[0][2][0] = (a[0] >= l && a[0] <= r) ? a[0] : a[0-1];
    dp[0][0][1] = check(dp[0][0][0]); dp[0][1][1] = check(dp[0][1][0]) ;dp[0][2][1] = check(dp[0][2][0]) ; 
    FOR(i, 1, n) {
        dp[i][0][0] = (dp[i-1][0][0] + a[i] - 1) % 24; 
        dp[i][0][1] = dp[i-1][0][1] + check(dp[i][0][0]);

        dp[i][1][1] = (dp[i-1][0][0] + a[i]) % 24;
        dp[i][0][1] = dp[i-1][0][1] + check(dp[i][0][0]);

        
        
    }

    cout << dp[n-1][2][1];

    return 0;
}