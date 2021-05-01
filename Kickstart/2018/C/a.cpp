/**
 * 
 * author: DespicableMonkey
 * created: 04.30.2021 09:38:57
 * solved:             12:03:00
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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define TC(i) for (int tt = (1); tt <= (i); ++tt)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)

#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const long long LLNF = (ll)10e17 + 7;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool vis[1005];
int adj[1005][1005];
bool cycle[1005];
int n;

/** Distance from node n to closest cycle node. Only works if there is one cycle in graph */ 
int dist(int from, int last) {
    if(from >= n) return -1;
    FOR(i, 0, n){
        if(i != from && adj[from][i] && i!=last){
           if(cycle[i])  return 1;
           int x = dist(i, from);
           if(x > 0)
            return 1+x;
            
        }
    }
    return -1;
}
/** Find one and only one cycle present in graph */ 
int dfs(int parent, int last){
    for (int i = 0; i < n; ++i){
        if (i == parent || i == last)
            continue;
        if (adj[parent][i] && !vis[i]){
            vis[i] = 1;
            int res = dfs(i, parent);
            if (res > -1 && parent != res) {
                cycle[parent] = 1;
                return res;
            }
            else if (res > -1)
                return -1;
        }
        else if (adj[parent][i] && vis[i]){
            cycle[i] = 1;
            cycle[parent] = 1;
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        cin >> n;
        
        memset(vis, 0, sizeof(vis));
        memset(adj, 0, sizeof(adj));
        memset(cycle, 0, sizeof(cycle));

        FOR(i, 0, n){
            int a, b;
            cin >> a >> b;
            --a; --b;
            adj[a][b] = 1, adj[b][a] = 1;
        }

        vis[0] = 1;
        dfs(0, 0);
        cout << "Case #"<<tt<<": ";
      //  cout << "HELLO?" << adj[1][1] nl
        FOR(i,0, n)
            cout << (cycle[i]?0:dist(i, i)) << (i != n-1?" ":"");
        cnl

    }

    return 0;
}