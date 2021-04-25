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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string in;
    getline(cin, in);
    int T = stoi(in);
    while(T--) {
        string s;
        getline(cin, s);
        string shif;
        getline(cin, shif);
        string dir;
        getline(cin, dir);

        vector<vector<int>> a(2, vi());
        int siz = sz(s);
        string x = "";
        int cnt = 0;

        //in rotate
        istringstream iss(shif);
        while(iss >> x) {
            int num = stoi(x);
            a[0].pb(num);
            ++cnt;
        }
        int ar1max = cnt;

        //in dif
        istringstream iss2(dir);
        cnt = 0;
        while(iss2 >> x) {
            int num = stoi(x);
            a[1].pb(num);
            ++cnt;
        }
        int ar2max = cnt;

        //int result;
        vector<char> word(siz);
        cnt = 0;
        FOR(i, 0, siz) {
            if(!isalpha(s[i])) {
                word[i] = s[i];
                continue;
            }
            int move = a[0][cnt%ar1max] * (a[1][cnt%ar2max] == 1 ? -1 : 1);
            int c = (s[i] - 'A') + move;
            if(c < 0)
                c = 26 + (c%26);
            word[i] = c%26 + 97;
            ++cnt;
        }
        string inn(word.begin(), word.end());
        cout << inn nl
    }
}