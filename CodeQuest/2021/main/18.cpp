#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
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
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int same(vector<char>& a, vector<char>& b) {
    for(int i = 0; i < sz(a); ++i)
        if(a[i] != b[i])
            return a[i]-b[i];
    return 0;
} 

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tt;
    getline(cin, tt);
    int T = stoi(tt);
    while(T--) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        string str;

        vector<pair<int, char > > v;

        while(iss >> str) {
            char let = str[0];
            char val = stoi(str.substr(2));
            v.pb({val, let});
        }

        sort(all(v));
        vector<char> result; 
        int maxxx = 0;
        for(int i = 0; i < sz(v); ++i) {
            vector<char> cur;
            cur.pb(v[i].s);
            int minn = v[i].f, maxx = v[i].f;
            for(int j = i+1; j < sz(v); ++j) {
                int val = v[j].f;
                if(max(maxx, val)-min(minn, val) > 10) break;
                minn = min(minn, val);
                maxx = max(maxx, val);
                cur.pb(v[j].s);
            }
            if(cur.size() > maxxx) {
                maxxx = cur.size();
                result.clear();
                for(char c : cur)
                    result.pb(c);
            }
            if(cur.size() == maxxx) {

                sort(all(result));
                sort(all(cur));
                if(same(cur, result) < 0) {
                    result.clear();
                    for(char c : cur)
                        result.pb(c);
                }
            }
        }

        for(int i = 0; i < result.size(); ++i) {
            cout << result[i] << (i != result.size()-1 ? " " : "");
        }
        cout nl
    }
}