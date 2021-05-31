/**
 * 
 * author: DespicableMonkey
 * created: 05.09.2021 01:44:00
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
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i nl; return is;}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

   int n;
   cin >> n;
   vi a(n);
   FOR(i, 0, n) cin >> a[i];


    vi ans(3, -1);

    int mnstart = a[0], mxstart = a[0]; multiset<int> mnend;
    multiset<int, greater<int>> mxend; 
    for(int i = n-1; i >= 1; --i){
        mxend.insert(a[i]);
        mnend.insert(a[i]);
    }

    FOR(i, 1, n-1) {
        mxend.erase(mxend.equal_range(a[i]).f);
        mnend.erase(mnend.equal_range(a[i]).f);
        if(a[i] > mnstart && a[i] > *mnend.begin()) {
            ans[1] = i+1;
            for(int k = i-1; k >= 0; --k)
                if(a[k] == mnstart)
                    ans[0] = k+1;
            for(int k = i+1; k < n; ++k)
                if(a[k] == *mnend.begin())
                    ans[2] = k+1;

            break;
        }
        else if(a[i] < mxstart && a[i] < *mxend.begin()) {
            ans[1] = i+1;

            for(int k = i-1; k >= 0; --k)
                if(a[k] == mxstart)
                    ans[0] = k+1;
            for(int k = i+1; k < n; ++k)
                if(a[k] == *mxend.begin())
                    ans[2] = k+1;
            break;
        }

        mnstart = min(mnstart, a[i]);
        mnstart = max(mnstart, a[i]);
    }
    if(ans[0] == -1) cout << "0" nl
    else {
        cout << "3" nl
        cout << ans[0] << " " << ans[1] << " " << ans[2] nl
    }

    return 0;
}