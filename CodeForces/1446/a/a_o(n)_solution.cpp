/**
 * 
 * author: DespicableMonkey
 * created: 05.15.2021 03:20:41
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
#include <numeric> 

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

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        ll mn = 0;
        ll n, w;
        cin >> n >> w;
        vi a(n);
        FOR(i, 0, n) {
            cin >> a[i];
            if(i == 0) mn = a[i];
            else mn = min(mn, (ll)a[i]);
        }
        if(mn > w) {
            cout << -1 nl
            continue;
        }
        vi sol;
        ll cur = 0;
        bool ok = 0;
        FOR(i, 0, n) {
            if((a[i] <= w ) && ((w&1 && a[i] > w/2) || (w%2==0&&a[i]>=w/2))) {
                cout << 1 nl
                cout << (i+1) nl;
                ok = 1;
                break;
            }
        }
        if(ok) continue;

        FOR(i, 0, n) {
            if(a[i] < w) {
                cur += a[i];
                sol.pb(i+1);
            }
            if((w&1 && cur > w/2) || (w%2==0 && cur >= w/2)) {
                ok = 1;
                break;
            }
        }

        if(!ok) cout << -1 nl
        else {
            cout << (sz(sol)) nl
            cout << sol nl
        }

    }

    return 0;
}