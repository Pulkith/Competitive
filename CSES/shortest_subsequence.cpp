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
#define ins(x) insert(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
#define TC(i) for(int tt = (1); tt <= (i); ++tt)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const long long LLNF = (ll)10e17+7;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int a[4];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for(char c : s)
        if(c == 'A') ++ a[0];
        else if(c == 'C') ++a[1];
        else if(c == 'G') ++ a[2];
        else if(c == 'T') ++ a[3];

    FOR(i, 0, 4) {
        if(a[i] == min(min(a[0], a[1]), min(a[2], a[3]))) {
            FOR(j, 0, a[i]+1)
                cout << (i == 0 ? 'A' : (i==1) ? 'C' : (i==2) ? 'G' : 'T');
            break;
        }
    }


    return 0;
}