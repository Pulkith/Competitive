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

int ar[5];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        for(int i  = 0; i < 5; ++i)
            cin >> ar[i];
 
    sort(ar, ar+5);;
    int cnt = 0;
    for (int i = 4; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (ar[l] + ar[r] > ar[i]) 
                cnt += (r--) - l;
            else
                l++;
        }
    }
    cout << cnt nl
    }
}