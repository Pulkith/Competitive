/**
 * 
 * author: DespicableMonkey
 * created: 05.11.2021 10:01:45
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
        int a, b;
        string s;
        cin >> a >> b >> s;
        int x[2];
        x[0] = a;
        x[1] = b;
        bool ok = true;
        for(int i = 0; i < sz(s) / 2 && ok; ++i) {
            int opp = sz(s) -1 - i;
            if(s[i] == s[opp] && s[i] != '?')
                x[s[i] - '0'] -= 2;
            else if(s[i] == s[opp] && s[i] == '?'){}
            else if((s[i] == '1' || s[i] == '0') && s[opp] == '?' || (s[opp] == '1' || s[opp] == '0') && s[i] == '?'){
                if(s[i] == '?') {
                    x[s[opp] - '0'] -= 2;
                    s[i] = s[opp];
                } else {
                    x[s[i] - '0'] -=2;
                    s[opp] = s[i];
                }
            } else {
                ok = false;
            }
        }
        if(sz(s) % 2 != 0 && ok) {
            int md = sz(s) / 2;
            if(s[md] != '?') x[s[md]-'0']--;
            else {
                if(x[0] % 2 == 1 ) {
                    --x[0];
                     s[md] = '0';
                } else if( x[1] % 2 == 1){ 
                    --x[1];
                     s[md] = '1';
                } else {
                    ok = false;
                }
            }
         }
         FOR(i, 0, sz(s) / 2) {
            int opp = sz(s) -1 - i;
             if(!(s[i] == '?' && s[opp] == '?')) continue;
                if(x[1] > x[0]){ 
                    x[1] -= 2;
                    s[i] = '1'; s[opp] = '1';
                }
                else{
                    s[i] = '0';
                    s[opp] = '0';
                    x[0] -=2;
                }
         }
        if(!ok || x[0] != 0 || x[1] != 0)
            cout << "-1" nl
        else
            cout << s nl
    }

    return 0;
}