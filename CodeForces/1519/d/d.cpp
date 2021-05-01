/**
 * 
 * author: DespicableMonkey
 * created: 04.29.2021 09:35:04
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

int n;
void p_a(vi& a) {
    for(int i  : a)
        cout << i << " ";
    cout nl
}
ll sum_array(vi& a, vi& b) {
    ll sum = 0;
    FOR(i, 0, n)
        sum += a[i] * b[i];
    return sum;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vi a(n);
    vi b(n);

    FOR(i, 0, n)
        cin >> a[i];
    FOR(i, 0, n)
        cin >> b[i];

    ll maxx = sum_array(a, b);
    FOR(i, 0, n){
        for(int j = i+1; j < n; ++j) {
            for(int k = j; k > i; --k)
                swap(a[k], a[k-1]);
            maxx =  max(maxx, sum_array(a, b));
        }
       reverse(a.begin()+i, a.end()); 
    }
    cout << maxx nl
    return 0;
}
// 1 2 3 4 5
// 2 1 3 4 5 
// 2 3 1 4 5
