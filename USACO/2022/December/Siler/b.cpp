#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define sz(x) (int)(x).size()

vector<int> adj[100005];
int connected[100005];
vector<vector<int>> circuits;
int N, M;

void dfs(int u, int circuit) {
  connected[u] = circuit;
  circuits[circuit].push_back(u);
  for(auto v : adj[u])
    if(!connected[v])
      dfs(v, circuit);
}


int closest(vector<int>& arr, int target){
    if (target <= arr[0]) return arr[0];
    if (target >= arr[sz(arr) - 1]) return arr[sz(arr) - 1];
    int lo = 0, hi = sz(arr), mid = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (arr[mid] == target) return arr[mid];
        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1])
              return (target - arr[mid-1] >= arr[mid] - target ? arr[mid] : arr[mid-1]);
            hi = mid;
        }
        else {
            if (mid < sz(arr) - 1 && target < arr[mid + 1])
              return (target - arr[mid] >= arr[mid+1] - target ? arr[mid+1] : arr[mid]);
            lo = mid + 1;
        }
    }
    return arr[mid];
}

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) {
    cin >> N >> M;

    FORE(i, 1, N) {
      connected[i] = 0;
      adj[i] = vector<int>();
      circuits = {{}};
    }

    FOR(i, 0, M) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int index = 1;
    FORE(i, 1, N) {
      if(!connected[i]){
        circuits.push_back({});
        dfs(i, index);
        index += 1;
      }
    }
    for(auto& c : circuits)
      sort(c.begin(), c.end());

    long long ans = N * 1LL * N;
    if(connected[1] == connected[N]) ans = 0;
    for(auto v : circuits[connected[1]]) {
      long long res = abs(v - closest(circuits[connected[N]], v));
      ans = min(ans, res * 1LL * res);
    }
    FOR(i, 1, index) {
      if(i == connected[1] || i == connected[N]) continue;
      long long closestleft = (100000000000), closestright = (100000000000);
      for(long long v : circuits[i]) {
        closestleft = min(closestleft, abs(v - closest(circuits[connected[1]], v)));
        closestright = min(closestright, abs(v - closest(circuits[connected[N]], v)));      }
      ans = min(ans, closestright * closestright + closestleft * closestleft);
    }

    cout << ans << '\n';
  }

  return 0;
}
