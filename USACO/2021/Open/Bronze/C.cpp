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

using namespace std;

#define ll long long;

#define vi vector<int>
#define pb push_back

#define nl << endl;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

const int INF = 1000000000;
const int MOD = 1000000000;

bool make_pairs(vector<string> possible_cows, unordered_set<string>& pairs, unordered_map<string, int>& IDS)
{
    int permutations[2][6]{{0, 0, 1, 0, 1, 2}, {1, 2, 2, 3, 3, 3}};
    int size = possible_cows.size();
    int pos = (size * (size - 1)) / 2;
    for (int i = 0; i < pos; ++i)
    {
        string i1 = possible_cows[permutations[0][i]], i2 = possible_cows[permutations[1][i]];
        int cow1 = IDS[i1], cow2 = IDS[i2], c1 = max(cow1, cow2), c2 = min(cow1, cow2);
        int size = sz(pairs);
        pairs.insert(ts(c1) + " " + ts(c2));
        if(sz(pairs) != size)
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int pairs_found = 0;
    unordered_set<string> pairs;
    char grid[N][M];
    for (int i = 0; i < N; ++i){
        string in;
        cin >> in;
        for(int j = 0; j < M; ++j)
            grid[i][j] = in[j];
    }

    unordered_map<string, int> IDS;
    vector<pair<string, int>> grass;
    unordered_map<string,vector<string>> gCows;
    int perm[2][4] {{-1, 0, 1, 0}, {0, 1, 0, -1}};
    int num_on = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (grid[i][j] == 'C')
            {
                string cowPoint = ts(i) + " " + ts(j);
                IDS.insert({cowPoint, num_on++});
            }

            if (grid[i][j] == 'G')
            {
                int grass_count = 0;
                vector<string> cur_cows;
                for (int k = 0; k < 4; ++k)
                {
                    int x = i + perm[0][k], y = j + perm[1][k];
                    if (x >= 0 && x < N && y >= 0 && y < M)
                    {
                        if (grid[x][y] == 'C')
                        {
                            grass_count += 1;
                            cur_cows.pb(ts(x) + " " + ts(y));
                        }
                    }
                }
                if (grass_count > 1)
                {
                    grass.pb({ts(i) + " " + ts(j), grass_count});
                    gCows.insert({ts(i) + " " + ts(j), cur_cows});
                }
            }
        }
    }
    long total = (num_on * (num_on + 1)) / 2;
    sort(grass.begin(), grass.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    for (auto entry : grass)
    {
        string g = entry.first;
        vector<string> grassCows = gCows[g];
        pairs_found += make_pairs(grassCows, pairs, IDS) ? 1 : 0;
        if (pairs_found == total)
            break;
    }
    cout << pairs_found nl;
}
