#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include<vector>
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

#define ll long long;

#define vi vector<int>
#define pb push_back

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
const int INF = 1000000000;
const int MOD = 1000000000;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int x = 0;
    while(N--) {
        string s;
        cin >> s;
        x += (s[0] == '+' || s[sz(s)-1] == '+') ?  1 : -1;
    }
    cout << x;

}