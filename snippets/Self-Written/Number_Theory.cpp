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

lcm(a, b) * gcd(a, b) = a*b
gcd(a, b) = gcd(b, a%b)


ux + vy = gcd(u, v) -> Extended Elucidian Algorithim. Has infinite pairs

Euler characteristic: V - E + F = 2
//where v = vertices, f = faces, and e = edges

Handshake Thereom: In any graph...
sum of degrees of all nodes = 2 * # of edges
sum of degrees is always even
the sum of degrees in vertices of odd degrees is always even
the number of vertices with odd degree is always even

Picks Theoroem: 
a polygon with only lattice points(integer vertices) then the area of the polygon is:
number of vertices inside polygon + 1/2(number of vertices on perimeter) - 1

shoelace theorem: area of a polygon = 
1/2 * |(sum(x_i * y_i+1) for 1...N-1) + (x_N * y_1) - (sum(x_i+1 * y_i) for 1...N-1) - (x_1 * y_N) |

Pigenhole Theroem(Handshake example): In a graph with >1 vertices, 2 nodes will have the same degree

Wilsons Theorem: For any prime number, p, (p-1)! == some multiple of (p-1)

Zeckendorf's theorem: Every positive integer, can be represented uniquely as the sum of as 1 or more fibonacci numbers
in a way that no two consecutive fibaonnci numbers are included

Linearality of Expecatation:
expected value of the sum of random variables is equal to their sum of their indiviual expected values, regardless
of independence 

(a mod b > b mod a) if (a < b)

Numbers with exactly 4 divisors: p*q, for some prime p, and some prime q, and p^3, for some prie p

*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);


}