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
int minCost(int N)
{
    int cost = 0;
    if(N==1)
        return 1;
    if (N <= 3)
        return 0;
    for (int a = 0; a < INF; ++a, cost+=2, N += 2)
    {
        if (N % 2 == 0)
        {
            --N;
            --cost;
            continue;
        }
        bool ok = true;
        for (int i = 3; i <= sqrt(N) && ok; i += 2)
        {
            if (N % i == 0)
                ok = false;
        }
        if(!ok) continue;
        return cost;
    }
    return INF;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int grid[N][M];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
    }
    int cost[N][M];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cost[i][j] = minCost(grid[i][j]);
    int minn = INF;
    for (int i = 0; i < N; ++i)
    {
        int sum = 0;
        for (int j = 0; j < M; ++j)
            sum += cost[i][j];
        minn = min(minn, sum);
    }
    for (int i = 0; i < M; ++i)
    {
        int sum = 0;
        for (int j = 0; j < N; ++j)
            sum += cost[j][i];
        minn = min(minn, sum);
    }

    cout << minn nl;
}
