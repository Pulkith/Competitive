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
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    }
};
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> grid(N, vector<int>(M));
        for(int i = 0; i < N; ++i) 
            for(int j = 0; j < M; ++j)
                cin >> grid[i][j];
        vector<pair<int, int>> ru(M);
        map<int, vi> mp;
        for(int i = 0; i < M; ++i) {
            mp[i].pb(grid[0][i]);
            ru[i] = {i, grid[0][i]};
        }

        for(int i = 1; i < N; ++i) {
            sort(ru.begin(), ru.end(), sort_pred());
            sort(grid[i].begin(), grid[i].end(),  greater<>());
            for(int j = 0; j < M; ++j) {
                ru[j].second = min(ru[j].second, grid[i][j]);
                mp[ru[j].first].pb(grid[i][j]);
            }
        }

        vector<vector<int>> fin;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        fin.pb(it->second);
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j)
            cout << fin[j][i] << " ";
        cout nl
    }


    }
}