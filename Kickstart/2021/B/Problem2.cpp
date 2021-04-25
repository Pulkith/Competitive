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
    int T;
    cin >> T;

    for(int tt = 1; tt <= T; ++tt) {
    int maxx = 0;
    int n = 0;
    cin >> n;
    ll ar[n];
    for(int i = 0; i < n; ++i) 
        cin >> ar[i];
    ll prefix[n];
    prefix[0] = prefix[1] = ar[1] - ar[0];

    for(int i = 2; i < n; ++i) {
        prefix[i] = ar[i] - ar[i-1];
    }
    int cur = 1;
    for(int i = 0; i < n; ++i)
        cout << prefix[i];
    cout nl
    bool changed = false;
    for(int i = 1; i < n; ++i) {
        if(prefix[i] == prefix[i-1])
            ++cur;
        else{
            if(i < n - 2 && i > 0 &&  prefix[i-1] == prefix[i+2] && ((ar[i-1] + ar[i+2]) % 2 == 0) && !changed)  {
                i += 2;
                cur += 3;
                changed = true;
                cout << i nl
            } else {
                changed = false;
                cur = 1;
            }
        }
        maxx = max(maxx, cur);
    }
    if(maxx < n)
        ++maxx;

    cout << "Case #" << tt << ": " << (maxx) nl
    }
}