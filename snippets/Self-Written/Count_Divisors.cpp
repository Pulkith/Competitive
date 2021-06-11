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

int max_div[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    //precompute primes with eve of E
	for (int i = 2; i <= 1000000; i++) {
		if (!max_div[i]) {
			for (int j = i; j <= 1000000; j += i) {
				max_div[j] = i;
			}
		}
	}
	int n;
	cin >> n;
    //calculate max divisors
	while (n--) {
		int x; cin >> x;
		int ans = 1;
		while (x != 1) {
			int prime = max_div[x], count = 0;
			while (x % prime == 0) {
				count++;
				x /= prime;
			}
			ans *= count + 1;
		}
		cout << ans << '\n';
	}
}