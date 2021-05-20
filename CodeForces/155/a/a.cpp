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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int in;
    cin >> in;
    int maxx = in, minn = in;
    int cnt = 0;
    for(int i = 0; i < N-1; ++i) {
        cin >> in;
        if(in > maxx) {
            maxx = in;
            ++cnt;
        }
        if(in < minn) {
            minn = in;
            ++cnt;
        }
    }
    cout << cnt nl
}
