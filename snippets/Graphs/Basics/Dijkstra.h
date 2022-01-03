/**
 * Description: shortest path
 * Source: own
 * Verification: http://www.usaco.org/index.php?page=viewproblem2&cpid=899
 */

vt<pr<int, int>> adj[MX];
priority_queue<pair<int, int>, vt<pair<int,int>>, greater<pair<int, int>>> pq;
int dis[MX];
int parent[MX];
void dijkstra(int src) {
    pq.push({src, 1});
    dis[src] = 0;
    parent[src] = src;

    while(sz(pq)) {
      int u = pq.top().s;
      pq.pop();
      for(auto e : adj[u]) {
        int v = e.f;
        int w = e.s;
        if(dis[v] == dis[u] + w && u < parent[v]) //unnecessary if parent not needed
          parent[v] = u;
        if(cmin(dis[v], dis[u] + w)) {
          pq.push({dis[v], v});
          parent[v] = u;
        }
      }
    }
}
