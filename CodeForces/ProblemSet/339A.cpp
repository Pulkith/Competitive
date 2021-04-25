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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> digit(sz(s)/2+1);
    for(int i = 0; i < sz(s); i+=2)
        digit[i/2] = s[i] - '0';
    sort(digit.begin(), digit.end());
    for(int i = 0; i < sz(s)/2+1; ++i) {
        cout << digit[i] << (i != (sz(s)/2) ? "+" : "");
    }

}