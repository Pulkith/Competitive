/**
 * 
 * author: DespicableMonkey
 * created: 05.11.2021 15:47:11
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
int rev(int n) {
    string s = ts(n);
    if(sz(s) < 2)
        s = "0" + s;
    string res = "";
    ROF(i, 0, sz(s)) {
        if(s[i] == '2')
            res.pb('5');
        else if(s[i] == '5')
            res.pb('2');
        else
            res.pb(s[i]);
    }
    return stoi(res);
}

int chk(int n) {
    while(n > 0) {
        int c = n%10;
        if(c != 0 && c !=1 && c!=2 && c!= 5 && c!= 8) return false;
        n/=10;
    }
    return true;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        int h, m;
        cin >> h >> m;
        string time;
        cin >> time;

        int curH = stoi(time.substr(0, 2)), curM = stoi(time.substr(3, 2));
        while(curH > 0 || curM > 0) {
            if(chk(curM) && chk(curH) && rev(curM) < h && rev(curH) < m) {
                break;
            } else {
                ++curM;
                if(curM == m) {
                    ++curH;
                    curM = 0;
                    if(curH == h)
                        curH = 0;
                }
            }
         }
         string nh = ts(curH), nm = ts(curM);
        if(sz(nh) < 2) nh = "0" + nh;
        if(sz(nm) < 2) nm = "0" + nm;
        cout << nh << ":" << nm nl


        

    }

    return 0;
}