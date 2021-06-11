/**
 * 
 * author: DespicableMonkey
 * created: 04.30.2021 00:43:52
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

int a[200005];
map<int, vector<pair<int, int>>> values;
bool chk(pii a, pii b) {
    return a.f == b.f || a.s == b.s || a.f == b.s || a.s == b.f;
}
/*
    Check if in an array 4 unique indexes exist where ai + aj = ak + aw
    
    My (slow) solution
    - For every pair of indicies push the pair into a map where their sum is the key
    - Note: if there is 4 pair for a sum, there is ALWAYS a solution(which is the solve2 method)
    - Otherwise there might be a solution(which is the solve1 method)
*/
bool solve() {
    for (auto &[x, y] : values)
    {
        if (sz(y) > 1)
        {
            do{
                if(!chk(y[0], y[1])) {
                    cout << "YES\n" << y[0].f +1<< " " << y[0].s+1 << " " << y[1].f+1 << " " << y[1].s+1 << '\n';
                    return true;
                }
            }while(next_permutation(y.begin(), y.end()));
        }
    }
    return false;
}

bool solve2(int index) {
    vector<pii> x = values[index];
    set<int> indx;
    for(auto &[a, b] : x)
        indx.insert(a), indx.insert(b);
    vector<int> y(indx.begin(), indx.end());
    cerr << sz(y) << endl;
    do{
       if(a[y[0]] + a[y[1]] == a[y[2]] + a[y[3]]) {
           cout << "Yes\n" << y[0]+1 << " " <<  y[1] +1 << " " << y[2]+1 << " " << y[3]+1 << '\n';
           return 1;
       }
    }while(next_permutation(y.begin(), y.end()));
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    FOR(i, 0, N)
    cin >> a[i];
    bool ok = 0;
    FOR(i, 0, N)
    FOR(j, i + 1, N){
        values[a[i] + a[j]].push_back({i, j});
        if (sz(values[a[i] + a[j]]) >= 4)
        {
            solve2(a[i] + a[j]);
            return 0;
        }
    }
    
    if(!solve())
        cout << "NO" << endl;

    return 0;
}