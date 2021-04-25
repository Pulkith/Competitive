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

    int lvl;
    cin >> lvl;
   vector<bool> a(lvl+1);
    int N;
    cin >> N;
    while(N--){
        int in;
        cin >> in;
        a[in] = 1;
    }
    cin >> N;
    while(N--) {
        int in;
        cin >> in;
        a[in] = 1;
    }
    bool ok = 1;
    for(int i = 1; i <= lvl && ok; ++i)
        if(!a[i])
            ok = 0; 
    cout << (ok? "I become the guy." : "Oh, my keyboard!");
}