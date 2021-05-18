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

    int N;
    cin >> N;
    vector<vector<int> > grid(N, vector<int>(N, 0));
    vi index(N+1);
    for(int i = 0; i < N; ++i) {
        int in;cin >> in;
        grid[i][i] = in;
    }

    for(int i = 0; i < N; ++i) {
        int num = grid[i][i];
        pair<int, int> pnt = {i, i};
        int cnt = 1;
        int down = true;
        while(cnt < num) {
            if(down) {
                while(cnt < num && pnt.first < N-1 && ((pnt.second == 0) || (pnt.second > 0 && grid[pnt.first][pnt.second-1] != 0))) {
                    ++pnt.first;
                    grid[pnt.first][pnt.second] = num;
                    ++cnt;
                }
            } else {
                while(cnt < num && pnt.second > 0 && grid[pnt.first][pnt.second-1] == 0) {
                    --pnt.second;
                    grid[pnt.first][pnt.second] = num;
                    ++cnt;
                 }
            }
            down = !down;
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << (grid[i][j] != 0 ? ts(grid[i][j]) + " " : "");
        }
        cout nl
    }

}