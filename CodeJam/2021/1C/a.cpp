/**
 * 
 * author: DespicableMonkey
 * created: 05.01.2021 03:40:02
 * 
 * Potatoes FTW!
 * 
 **/ 


#include <iostream>
#include <iomanip>
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

    int T; cin >> T;
    TC(T){
        cout << fixed << showpoint; cout << setprecision(7);
        int n, k; cin >> n >> k;
        set<int> a;
        FOR(i, 0, n){
            int x; cin >> x; a.insert(x);
        }
        int lst = -1;
        double both = 0;
        priority_queue<int> mx;
        mx.push(0); mx.push(0);
           for(auto i : a) {
                if(i == *a.rbegin()) mx.push(k - i);
                if(lst == -1) mx.push(i-1);
                else{
                    mx.push((i - lst) / 2);
                    both = max(both, (double)i - lst - 1);
                }
                lst = i;
           }
            double max1 = mx.top(); mx.pop(); double max2 = mx.top();
            double sum = max1+max2;
            // double sum = max(both, max1+max2);
            cout << "Case #"<<tt<<": " << (sum / (double)k) nl
        } 
    return 0;
}