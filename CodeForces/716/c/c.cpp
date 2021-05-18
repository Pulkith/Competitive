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

bool ok[100005];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    ll res = 1;
    for(int i = 1; i < N; ++i) {
        if(gcd(N, i) == 1) {
            ok[i] = true;
            res = (res*i)%N;
        }
    }
    if(res != 1)
        ok[res] = false;
    cout << count(ok+1, ok+N, 1) nl
    for(int i = 1; i < N; ++i) 
        if(ok[i])
            cout << i << " ";
}