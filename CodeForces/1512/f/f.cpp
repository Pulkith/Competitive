/**
 * 
 * author: DespicableMonkey
 * created: 05.11.2021 14:34:29
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

int dp[200005][3];

int solve(int cur, int increment, int goal) {
    if(cur >= goal) return 0;
    if(cur + increment > goal) return 1;
    if((goal - cur) % increment)
        return (goal - cur) / increment + 1;
    return (goal - cur) / increment;
}


int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        int n, c;
        cin >> n >> c;
        vi a(n), b(n-1);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n-1) cin >> b[i];
        dp[0][0] = solve(0, a[0], c); //0 : days to get comp at cur job
        dp[0][1] = solve(0, a[0], b[0]); //1: days to get to next job
        dp[0][2] = dp[0][1] * a[0] - b[0]; //2: left over money from last promotion;
        FOR(i, 1, n) {
            dp[i][0] = solve(dp[i-1][2], a[i], c);
            if(i == n-1) break;
            dp[i][1] = solve(dp[i-1][2], a[i], b[i]);
            dp[i][2] = dp[i-1][2] + (dp[i][1]) * a[i] - b[i];
        }

        ll mn = dp[0][0];
        ll dys = dp[0][1] + 1;
        FOR(i, 1, n){
            mn = min(mn, dys + dp[i][0]);
            dys += dp[i][1] + 1;
        }
        cout << mn nl
     }

    return 0;
}