#include <bits/stdc++.h>
#include <set>
using namespace std;

const int N = 2e5 + 10; 

int n, k, p[N], sz[N], on[N], ans[N]; 
vector<pair<int, int>> edges;

map<pair<int, int>, int> bridges;

int find(int x) {
    while(p[x] != x) x = p[x]; // Notice: No path compression. Path Compression will make the algorithm O(n^2) 
    return x; 
}

void disactivate(int x, int t) {
  --on[x];
  while(x != p[x]) {
    x = p[x];
    --on[x];
  }
  if(on[x] == 0) ans[x] = t-1;
}

map<pair<int, int>, int> oldparent;
void Union(int x, int y) {
    int u = x, v = y;
    x = find(x); y = find(y); 
    if(x == y) return; 
    if(sz[x] > sz[y]) {
      swap(x, y); 
      swap(u, v);
    }
    oldparent[{min(x, y), max(x, y)}] = x;
    p[x] = v; 
    sz[y] += sz[x];
    on[y] += on[x];
    ++bridges[{min(x, y), max(x, y)}];
}
void unmerge(int x, int y, int t) {
  if(x > y) swap(x, y);
  int par1 = find(x);
  int par2 = oldparent[{x, y}];

  if(!on[par1]) return; //if already all off, then skip cuz theres no point

  --bridges[{min(par1, par2), max(par1, par2)}];
  if(bridges[{min(par1, par2), max(par1, par2)}]) return;

  sz[par1] -= sz[par2];
  on[par1] -= on[par2];
  if(p[par2] == par1) p[par2] = par2;

  if(!on[par1]) ans[par1] = t-1;
  if(!on[par2]) ans[par2] = t-1;
}


int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
        p[i] = i, sz[i] = 1, on[i] = 1, ans[i] = k;

    for(int i = 1; i <= k; ++i) {
      char c; cin >> c;
      if(c == 'A') {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
        Union(u, v);
      } else if(c == 'R') {
        int ind; cin >> ind;
        unmerge(edges[ind-1].first, edges[ind-1].second, i);
      } else {
        int d; cin >> d;
        disactivate(d, i);
      }
    }
   
    for(int i = 1; i <= n; ++i)
      ans[i] = ans[find(i)];
    for(int i = 1; i <= n; ++i){
      cout << ans[i] << '\n';
    }
}