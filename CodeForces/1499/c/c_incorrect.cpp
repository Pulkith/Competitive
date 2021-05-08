/**
 * 
 * author: DespicableMonkey
 * created: 05.03.2021 01:04:42
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

struct double_min {
    int f = INF;
    int s = INF;

public: 
    void check() {
        if(s < f)
            swap(s, f);
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        int n;
        cin >> n;
        vi a(n);
        double_min dm;
        FOR(i, 0, n){
            cin >> a[i];
            if(i%2==0) dm.f = min(dm.f, a[i]);
            else dm.s = min(dm.s, a[i]);
        }
        int x = 0, y = 0;
        ll cost = 0;
        bool turn = true; //true = right;
        int index = 0;
        while(x < n || y < n) {
                if((a[index] == dm.f) && index%2==0) {
                    cost += dm.f * (n - x);
                    x = n;
                }
                else if((a[index] == dm.s) && index%2==1) {
                    cost += dm.s * (n - y);
                    y = n;
                }
                else {
                    if(turn)
                        x += 1;
                    else
                        y += 1;
                    cost += a[index];
                }
            ++index;
            if(x == n) turn = false;
            else if(y == n) turn = true;
            else turn = !turn;
        }




        printf("%lld\n", cost);
        
        
    }
    

    return 0;
}