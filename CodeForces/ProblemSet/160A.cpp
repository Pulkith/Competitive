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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vi x;
    int sum = 0;
    while(N--) {
        int in;
        cin >> in;
        x.pb(in);
        sum += in;
    }
    sort(x.begin(), x.end());
    int cur = 0;
    int cnt = 0;
    int index = sz(x)-1;
    while(cur <= sum && index >= 0) {
        cur += x[index];
        sum -= x[index--];
    }
    cout << (sz(x) - index - 1) nl;
    
}