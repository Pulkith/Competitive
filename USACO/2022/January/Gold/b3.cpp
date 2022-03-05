#include<bits/stdc++.h>

using namespace std;


const int MX = (2e5+43);
int N, Q;
int a[MX], ans[MX];

map<pair<int, int>, int> lastconnected;
vector<int> adj[MX];

char op[MX];
int offtime[MX];
bool finalized[MX];
vector<pair<int, int>> edges;


int main () {
  cin >> N >> Q;
  for(int i = 1; i <= N; ++i) offtime[i] = Q;
  for(int i = 0; i < Q; ++i){
    char c; cin >> c;
    if(c == 'D') {
      int u; cin >> u;
      offtime[u] = i;
    } else if(c == 'A') {
      int u, v; cin >> u >> v;
      lastconnected[{u, v}] = -1;
      lastconnected[{v, u}] = -1;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges.push_back({u, v});
    } else {
      int ix; cin >> ix;
      int u = edges[ix-1].first, v = edges[ix-1].second;
      lastconnected[{u, v}] = i;
      lastconnected[{v, u}] = i;
    }
  }

  for(auto& [x, y] : lastconnected) {
    if(y < 0) y = Q;
  }

  set<pair<int, int>> dis;
  map<int, int> prdis;

  for(int i = 1; i <= N; ++i) {
    prdis[i] = offtime[i];
    dis.insert({offtime[i], i});
  }


  while(dis.size()) {
    auto ls = *dis.rbegin();
    dis.erase(--dis.end());
    ans[ls.second] = ls.first;
    finalized[ls.second] = 1;

    for(auto v : adj[ls.second]) {
      if(!finalized[v] && min(ans[ls.second], lastconnected[{ls.second, v}]) > prdis[v]) {
        dis.erase({prdis[v], v});
        prdis[v] = min(ans[ls.second], lastconnected[{ls.second, v}]);
        dis.insert({prdis[v], v});
      }
    }
  }

  for(int i = 1; i <= N; ++i)
    cout << ans[i] << '\n';
}
