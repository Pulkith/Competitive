#include "bits/stdc++.h"
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> adj[100047];
vector<int> comps;
bool vis[100047];
int outset = 0;
int siz = 0;
int leaf = 0;
void dfs(int u) {
  outset += (int)(adj[u].size());
  vis[u] = 1;
  comps.push_back(u);
  ++siz;

  if(outset == 1) leaf = u;

  for(auto [v, x] : adj[u])
    if(!vis[v])
      dfs(v);
}
pair<int, int> a[300047];
int main () {
  int tt = 1;
  for(int t = 0; t < tt; ++t) {
    for(int i = 0; i <= M; ++i) {
      adj[i].clear();
      vis[i] = 0;
    }
    cin >> N >> M;
    set<int> used;
    for(int i = 0; i < N; ++i) {
      int u, v;
      cin >> u >> v;
      a[i] = {u, v};
      adj[a[i].first].push_back({a[i].second, i});
      adj[a[i].second].push_back({a[i].first, i});
      used.insert(i);
    }

    int ans = 0;

    vector<int> sec;


    int curr = N+1;

    map<int, int> weights;

    for(int i = 1; i <= M; ++i) {
      if(!vis[i]) {
        outset = siz = 0;
        comps = {};
        dfs(i);
        outset /= 2;
        int rs = min(outset, siz);
        if(outset > siz) ans += outset - siz;
        map<int, int> deg;
        set<pair<int, int>> nodes;
        for(auto v : comps) {
          nodes.insert({adj[v].size(), v});
          deg[v] = adj[v].size();
        }

        while(nodes.size()) {
          // cout << weights[10] << '\n';
          auto v = *nodes.begin();  nodes.erase(nodes.begin());
          bool found = false;

          for(int k = 0; k < 2 && !found; ++k) {

            for(auto u : adj[v.second]) {
              if((k && used.find(u.second) != used.end()) ||
                 (!k && a[u.second].first == v.second && used.find(u.second) != used.end())) {
                used.erase(u.second);


                if(!k) {
                  sec.push_back(u.second);
                  weights[u.second] = -(N * 2);
                }
                else {
                  sec.push_back(u.second);
                  weights[u.second] = -curr;

                  for(auto vu : adj[v.second]) {
                    if(a[vu.second].first == v.second)
                      weights[vu.second] = curr;
                  }
                  --curr;
                }

                
                int other = (a[u.second].first == v.second ? a[u.second].second : a[u.second].first);
                if(nodes.find({deg[other], other}) != nodes.end()) {
                  nodes.erase({deg[other], other});
                  --deg[other];
                  nodes.insert({deg[other], other});
                }


                found = true;
                break;
              }
            }

          }
        }

      }
    }
    vector<int> perm;

    sort(sec.begin(), sec.end(), [&](int l, int r) -> bool {
      return weights[l] < weights[r];
    });

    for(auto v : sec) perm.push_back(v);
    for(auto v : used) perm.push_back(v);

    for(auto v : perm)
      cout << v+1 << '\n';
  }
  return 0;
}
