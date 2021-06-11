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
/*
 * dp[N]=dp[N−1]+dp[N−2]+dp[N−3]+dp[N−4]+dp[N−5]+dp[N−6].
 */
int main() {
	int n;
	cin >> n;
	ll dp[n+1]{}; dp[0] = 1;
	for (int i = 1; i<= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i-j >= 0) {
				dp[i] += dp[i-j];
				dp[i] %= 1000000007;
			}
		}
	}
	cout << dp[n] << "\n";

    
}
