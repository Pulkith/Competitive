#include<iostream>
#include<algorithm>
#include<vector>
#include<set>


using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define sz(x) (int)(x).size()

int K, M, N;
int cows[200005];
pair<int, int> grass[200005];
int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> K >> M >> N;
  vector<pair<int, int>> grass;
  FOR(i, 0, K) {
    int u, v; cin >> u >> v;
    grass[i] = {u, v};
  }

  sort();

  FOR(i, 0, M) cin >> cows[i];
  sort(cows, cows+M);

  long long ans = 0;
  vector<int> singles, doubles;
  FOR(i, 0, K)
    if(grass[i].f )

  cout << ans << '\n';
  return 0;
}
