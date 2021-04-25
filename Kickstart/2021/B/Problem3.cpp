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

#define ll unsigned long long

#define vi vector<int>
#define pb push_back

#define nl << "\n";

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000000;
const int MOD = 1000000000;

vector<ll> SOE(int n, vector<bool> isPrime)
{
    vector<ll> x;
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= n / 2; i++)
        isPrime[i] = true;
 
    for (ll p = 2; p <= n / 2; p++) {
        if (isPrime[p] == true) {
            for (ll i = p * 2; i <= n; i += p)
                isPrime[i] = false;
            x.pb(p);
        }   
    }
    return x;
}


void solve() {
    ll n;
    cin >> n;
    vector<bool> isPrime(n+1);
    vector<ll> pr = SOE(n, isPrime);
    ll res = -1;
    for(int i = sz(pr)-1; i >= 1; --i) {
        if(pr[i] * pr[i-1] <= n) {
            res = pr[i] * pr[i-1];
            break;
        }
    }
    cout << res nl
    
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for(int tt=1; tt <= T; ++tt) {
        cout << "Case #" << tt << ": ";
        solve();
    }

}
