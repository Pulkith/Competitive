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

const int INF = 1000000000;
const int MOD = 1000000000;
/*

    Check if an LCM exists between L and R, where the 2 numbers x, and y follow:
    L <= x < y <= R
    and
    L <= lcm(x, y) <= R

*/
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int tt = 0; tt < T; ++tt) {
        int l, r;
        cin >> l >> r;
        cout << ((2*l <= r) ? (ts(l) + " " + ts(2*l) ) : "-1 -1 ") nl
    }
}   
