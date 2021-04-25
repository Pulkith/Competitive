#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
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
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vll> pl(2, vll(N));
    FOR(i, 0, 2)
        FOR(j, 0, N)
            cin >> pl[i][j];

    vector<vll> dp(N+1, vll(4, 0));
    dp[0][1] = pl[0][0];
    dp[0][2] = pl[1][0];
    dp[0][3] = 0;

    FOR(i, 1, N) {
        dp[i][1] = max(dp[i-1][2] + pl[0][i], dp[i-1][3] +pl[0][i]);
        dp[i][2] = max(dp[i-1][1] + pl[1][i], dp[i-1][3] + pl[1][i]);
        dp[i][3] = max(dp[i-1][1], dp[i-1][2]);
    }
    cout << max(max(dp[N-1][1], dp[N-1][2]), dp[N-1][3]) nl
}