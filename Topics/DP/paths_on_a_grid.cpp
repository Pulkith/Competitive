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

    //paths on a grid from bottom right, to top left. Starred grids cannot be trqaversed. Can only move down and right
    int N, M;
    //final coordinates;
    cin >> N;
    M = N;

    vector<vector<int>> dp(N, vector<int>(M));
    vector<vector<char>> grid(N, vector<char>(M));

    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < M; ++j) 
            grid[i][j] = s[j];
    }
    dp[0][0] = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(grid[i][j] != '.')
                dp[i][j] = 0;
            else{
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[N-1][M-1];
    
}