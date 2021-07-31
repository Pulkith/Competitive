vt<int> in_degree;
vt<int> adj[MX];
vt<int> top_sort;
bool init_sort(int n) {
  top_sort.clear();top_sort.resize(n+5);
  in_degree.clear();in_degree.resize(n+5);
  for(int u = 1; u <= n; ++u) {
      for(auto v : adj[u])
          ++in_degree[v];
  }

  queue<int> q;
  for(int i = 1 ; i <= n; ++i)
      if(in_degree[i] == 0)
          q.push(i);

  int cnt = 0;
  while(!q.empty()) {
      int u = q.front();
      q.pop();
      top_sort.pb(u);

      for(auto v : adj[u])
          if(--in_degree[v] == 0)
              q.push(v);
      ++cnt;
  }

  return (cnt == n);
}