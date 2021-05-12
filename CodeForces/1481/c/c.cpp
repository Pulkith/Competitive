/**
 * 
 * author: DespicableMonkey
 * created: 05.10.2021 21:45:43
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
        int n, p;
        cin >> n >> p;

        unordered_map<int, vi> mp;
        vi a(n),b(n), first_index(n+2, INF), pnt(p), chk, res(p);

        FOR(i, 0, n)  cin >> a[i]; FOR(j,0, n) cin >> b[j]; FOR(i, 0, p)  cin >> pnt[i];

        FOR(i, 0, n) {
            if(a[i] != b[i])
                mp[b[i]].pb(i+1);
            first_index[b[i]] = min(first_index[b[i]], i+1 );
        }
        FOR(i, 0, p) {
            int ind; bool rem = true;
            if(sz(mp[pnt[i]])) {
                ind = *(mp[pnt[i]].rbegin());
                res[i] = ind;
                mp[pnt[i]].pop_back();
           } else {
                if(first_index[pnt[i]] != INF)
                    ind = res[i] = first_index[pnt[i]];
                else
                    chk.pb(i), rem = false;
            }
            if(sz(chk) && rem){
                for(int j : chk)
                    res[j] = ind;
                chk.clear();
            }
        }
        int ok = true;
        for(auto k : mp)
            if(sz(k.s)) 
                ok = false;
        if(!ok || sz(chk)) cout << "NO" nl 
        else cout << "YES\n" << res nl


    }

    return 0;
}
