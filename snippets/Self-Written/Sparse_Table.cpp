#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
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
//STATIC Minimum Range Queries. O(NLogN + Q)
//Source: https://www.youtube.com/watch?v=0jWeUdxrGm4
//inclusive queries ( [a, b] ), 0-indexed

//works for min, max, gcd;
//doesnt work for sum(becuase of possible overlapping middle)

//ar[N][Log[N]]
//For every power of 2,x, x < N, compute seqeunces of size x
const int MAX_N = 200005;
const int LOG = 18;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int n, q;

int mrq_query(int L, int R) { // O(1)
	int len = R - L + 1;
    int k = 31 - __builtin_clz(len); //bit trick to find log2(N)
	return min(m[L][k], m[R-(1<<k)+1][k]);
}

void clac_sparse_table() { //    preprocessing, O(N*log(N))
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}
}

int main() {
	cin >> n >> q;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
        m[i][0] = a[i];
    }

    clac_sparse_table();

	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		cout << mrq_query(L-1, R-1) << "\n";
	}
}