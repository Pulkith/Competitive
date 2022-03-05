int depth[200005];
int up[200005][20];

void dfs(int v) {
  FOR(i, 0, 20)
    up[v][i] = up[up[v][i]][i-1];
  for(auto x : adj[v]) {
    if(x != up[v][0]) {
      depth[x] = depth[up[x][0] = v]+1;
      dfs(x);
    }
  }
}

int jump(int x, int d) {
  FOR(i, 0, 20) {
    if((d >> i) & 1) 
      x = up[x][i];
  }
  return x;
}

int LCA(int a, b) {
  if(depth[a] < depth[b]) swap(a, b);

  a = jump(a, depth[a] - depth[b]);
  if(b == a) return a;

  for(int i = 20-1; i >= 0; --i) {
    int aT = up[a][i], bT = up[b][i];
    if(aT != bT) a = aT, b = bT;
  }
  return up[a][0];
}
/*
MAIN

!!O-BASED NODES!!

up[0][0] = depth[0] = 0;
dfs(0);
*/