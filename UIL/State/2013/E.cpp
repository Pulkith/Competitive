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

const int INF = 1000000000;
const int MOD = 1000000000;
int shortestPath(vector<vector<char>>& grid, int inX, int inY)
{
    queue<vector<int>> q;
    vector<vector<int>> vis(10, vector<int>(10, -1));
    q.push({inX, inY});
    vis[inX][inY] = 1;

    int dirX[8] = {-1, -1, -1, 0, 1, 1, 1, 0 }, dirY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int steps = 0;

    while (!q.empty()){
        int qsz = sz(q);
        while (qsz--) {
            auto f = q.front(); q.pop();
            int i = f[0], j = f[1];
            if (grid[i][j] == 'E')
                return steps;
            for (int d = 0; d < 8; ++d){
                int x = i + dirX[d], y = j + dirY[d];
                if (x < 0 || x >= 10 || y < 0 || y >= 10 || grid[i][j] == 'B' || grid[i][j] == 'M')
                    continue;
                q.push({x, y});
                vis[x][y] = 1;
            }
        }
        steps++;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> grid(10, vector<char>(10, ' '));
        for(int i = 0; i < 10; ++i) {
            string s;
            cin >> s;
            for(int j = 0; j < 10; ++j) 
                grid[i][j] = s[j];
        }
        cout << shortestPath(grid, r-1, c-1) nl
    }
}