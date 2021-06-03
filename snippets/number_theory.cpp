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

//Binary Exponentation....Calculate x^n where n is large in O(logN) time
ll binpow(ll x, ll n) {
	assert(n >= 0);
	x %= MOD; //note: m*m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) //if n is odd
			res = res * x % MOD;
		x = x * x % MOD;
		n /= 2; //divide by two
	}
	return res;
}

/*

X * Y is only a perfect Square if Mask(X) == Mask(Y)
X can be prime factorized into a1^y1 * a2^y2...ak*yk
Mask(X) = (a1*(y1 mod 2)) * (a2 * (y2 mod 2)) * (ak * (yk mod 2))

Any Prime Number, p, can be described as the sum of 2 squares, x^2 + y^2

Chicken McNugget Theorem
For 2 coprime integers, m, n, any number that is greater than (m*n - m - n) can be written as the sum of mx + ny

coprime = gcd(a, b) = 1;


*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);


}