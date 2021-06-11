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

#define vi vector<int>
#define pb push_back

#define nl << "\n";

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a,b;
    cin >> a >> b;
    vector<vector<int>> dp(sz(a), vector<int>(sz(b)));
    //assert(sz(a) == sz(b));
    //fill top row of matrix . common character == 1
    for(int i = 0; i < sz(a); ++i) {
        if(a[i] == b[0]) dp[i][0] = 1;
        if(i != 0) dp[i][0] = max(dp[i][0], dp[i-1][0]);
    }
    

    for(int i = 0; i < sz(b); ++i){
        if(a[0] == b[i]) dp[0][i] = 1;
        if(i != 0) dp[0][i] = max(dp[0][i], dp[0][i-1]);
    }

    for(int i = 1; i < sz(a); ++i) {
        for(int j = 1; j < sz(b); ++j) {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[sz(a)-1][sz(b)-1];


}