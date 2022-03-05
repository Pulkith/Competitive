int st[MX], en[MX];
int tim = 0;
int up[MX][20];
void dfs(int u, int p) {
  up[u][0] = p;
  FOR(i, 1, 20)
    up[u][i] = up[up[u][i-1]][i-1];
  st[u] = tim++;
  for(auto v : adj[u])
    if(v != p)
      dfs(v, u);
  en[u] = tim - 1;
}

bool isancestor(int u, int v) {
  return st[u] <= st[v] && en[u] >= en[v];
}

int LCA(int u, int v) {
  if(isancestor(u, v)) return u;
  if(isancestor(v, u)) return v;

  for(int i = 20-1; i >= 0; --i) {
    if(!isancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}
