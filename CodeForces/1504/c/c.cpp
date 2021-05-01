/**
 * 
 * author: DespicableMonkey
 * created: 04.30.2021 17:24:01
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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        int n;
        string s;
        cin >> n >> s;
        if(s[0] == '0' || s.back() == '0') cout << "NO" nl
        else {
            int cnt = 0;
            FOR(i, 0, n) {
                if(s[i] == 49) ++ cnt;
            }
            if(cnt%2==1 || cnt == 0) cout << "NO" nl
            else {
                string a = "", b = "";
                bool flip = false;
                int k = 0;
                FOR(i, 0, n) {
                    if(s[i] == '1') {
                        a += (k*2 < cnt) ? '(' : ')';
                        b += (k*2 < cnt) ? '(' : ')';
                        ++k;
                    } else {
                        a += flip ? '(' : ')';
                        b += flip ? ')' : '(';
                        flip = !flip;
                    }
                }
                cout << "YES" << endl << a << endl << b nl
            }
        }
    }

    return 0;
}