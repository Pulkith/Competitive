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

#define vi vector<int>
#define pb push_back

#define nl << "\n";

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;

bool ar[26];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll l, cn;
    cin >> l >> cn;
    string s;
    cin >> s;
    for(ll i = 0; i < cn; ++i) {
        char c;
        cin >> c;
        ar[c-'a'] = 1;
    }

    ll cur = 0;
    ll maxx = 0;
    for(int i = 0; i < l; ++i) {
        if(ar[s[i]-'a']) {
            ++cur;
            maxx += 1 + (cur-1);
        } else {
            cur = 0;
        }
    }
    cout << maxx nl
}
