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

int arr[101][101];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Inclusion Exclusion Principle: https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle
    int n;
    cin >> n;
    int maxSubRect = -127*100*100; // lowest possible value for this problem
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
        if (i > 0) arr[i][j] += arr[i - 1][j]; // if possible, add values from top
        if (j > 0) arr[i][j] += arr[i][j - 1]; // if possible, add values from left
        if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1]; // to avoid double count
    } // inclusion-exclusion principle

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coord
        for (int k = i; k < n; k++) for (int l = j; l < n; l++) { // end coord
        int subRect = arr[k][l]; // this is sum of all items from (0, 0) to (k, l): O(1)
        if (i > 0) subRect -= arr[i - 1][l]; // O(1)
        if (j > 0) subRect -= arr[k][j - 1]; // O(1)
        if (i > 0 && j > 0) subRect += arr[i - 1][j - 1]; // inclusion-exclusion: O(1)
        maxSubRect = max(maxSubRect, subRect);
    }

    cout << maxSubRect nl
}