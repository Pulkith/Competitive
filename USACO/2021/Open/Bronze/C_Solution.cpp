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

using namespace std;

#define ll long long;

#define vi vector<int>
#define pb push_back

#define nl << endl;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

const int INF = 1000000000;
const int MOD = 1000000000;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int N,M; cin >> N >> M;
	vector<string> G(N); for (string& row: G) cin >> row;
	auto exists_cow = [&](int i, int j) { 
		return 0 <= i && i < N && 0 <= j && j < M && G[i][j] == 'C';
	};
	set<vector<pair<int,int>>> pairs;
	int ans = 0;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) if (G[i][j] == 'G') {
			vector<pair<int,int>> v;
			int dx[]{1,0,-1,0};
			int dy[]{0,1,0,-1};
			for (int d = 0; d < 4; ++d) {
				int ii = i+dx[d], jj = j+dy[d];
				if (exists_cow(ii,jj)) v.emplace_back(ii,jj);
			}
			if (v.size() > 2) {
				++ans;
				continue;
			}
			if (v.size() == 2) {
				sort(begin(v),end(v));
				pairs.insert(v);
			}
		}
	cout << pairs.size()+ans << "\n";

}