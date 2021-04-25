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

bool distinct(int n) {
    unordered_set<int> s;
    int cnt = 0;
    while(n > 0) {
        s.insert(n%10);
        n /= 10;
        ++cnt;
    }
    return cnt == s.size();
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int in;
    cin >> in;
    int min = in;
    while(!distinct(++min)) {}
    cout << min nl
}