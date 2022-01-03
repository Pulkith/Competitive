#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)

vector<pair<int, int>> adj[100005];
int N, M;

const int INF = (1e9);

int main () {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) {
    cin >> N >> M;

    FORE(i, 1, N) {
      adj[i] = vector<pair<int, int>>();
    }
    set<pair<int, int>> found;
    FOR(i, 0, M) {
      int u, v; cin >> u >> v;
      adj[u].push_back({v, 0});
      adj[v].push_back({u, 0});
      found.insert({min(u, v), max(u, v)});
    }

    FORE(i, 1, N){
      if(i > 1 && found.find({i-1, i}) == found.end()) {
        adj[i].push_back({i-1, 1});
        adj[i-1].push_back({i, 1});
      }
      if(i < N && found.find({i, i+1}) == found.end()) {
        adj[i].push_back({i+1, 1});
        adj[i+1].push_back({i, 1});
      }
    }
    
    set<pair<int, int>> bfs; bfs.insert({0, 1});
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    while (!bfs.empty()){
      auto tmp = *(bfs.begin());
      bfs.erase(bfs.begin());
      int u = tmp.second;
      for (auto i : adj[u]){
        int v = i.first, weight = i.second;
        if (dist[v] > dist[u] + weight) {
          if (dist[v] != INF)
            bfs.erase(bfs.find({dist[v],v}));
          bfs.insert({dist[v] = dist[u] + weight, v});
        }
      }
    }
    cout << dist[N] << '\n';

  }

  return 0;
}
