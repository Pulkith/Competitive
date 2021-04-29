/**
 * 
 * author: DespicableMonkey
 * created: 04.28.2021 14 43 41
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

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define TC(i) for(int tt = (1); tt <= (i); ++tt)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const long long LLNF = (ll)10e17+7;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s,a,b;
    cin >> s >> a >> b;
    bool l = false, r = false;
    bool first = true;
    FOR(i, 0, sz(s) + 1 - (first?sz(a):sz(b))) {
        if(first) {
            if(s.substr(i, sz(a)) == a) {
                first = false;
                i+=sz(a)-1;
            }
        } else {
            if(s.substr(i, sz(b)) == b){
                r = true;
                break;
            }
        }
    }
    first = true;
    reverse(all(s));
    FOR(i, 0, sz(s) + 1 - (first?sz(a):sz(b))) {
        if(first) {
            if(s.substr(i, sz(a)) == a) {
                first = false;
                i+=sz(a)-1;
            }
        } else {
            if(s.substr(i, sz(b)) == b){
                l = true;
                break;
            }
        }
    }


    cout << ((l==r&&r==false) ? "fantasy" : (l&&r)?"both":(r)?"forward":"backward") nl




    return 0;
}