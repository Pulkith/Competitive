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

int grid[26][26];
bool vis[26][26];
int N;
int cnt = 0;
unordered_map<int, tuple<int, int, int> > brd;

bool moo(char a, char b, char c) {
    if(string(""+a+b+c) == "MOO" || (string(""+a+b+c)) == "MOO") return true;
    return false;
}

bool win(char mp[3][3]) {
    if(string(mp[0]) == "MOO" || string(mp[0]) == "OOM") return true;
    if(string(mp[1]) == "MOO" || string(mp[1]) == "OOM") return true;
    if(string(mp[2]) == "MOO" || string(mp[2]) == "OOM") return true;
    if(moo(mp[0][0], mp[1][0], mp[2][0]) || moo(mp[0][1], mp[1][1], mp[2][1]) || moo(mp[0][2],mp[1][2], mp[2][2])) return true;
    if(moo(mp[0][0], mp[1][1], mp[2][2]) || moo(mp[0][2], mp[1][1], mp[2][0])) return true;
    return false;
}

void dfs(char mp[3][3]) {
    
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

   cin >> N;
   int cur = 1;
   FOR(i, 0, N) {
       string s; cin >> s;
       for(int j = 0; j < N*3; j += 3) {
           string in = s.substr(j, 3);
           if(in[0] == '#') grid[i][j/3] = -1;
           else if(in[1] == '.') grid[i][j/3] = 0;
           else if(in[2] == 'B');
           else {
            grid[i][j/3] = cur;
            brd.insert({cur++, make_tuple<int,int, int> (s[0], s[1]-'48', s[2]-'48')});
       }
   }



    cout << cnt nl;
    return 0;
}