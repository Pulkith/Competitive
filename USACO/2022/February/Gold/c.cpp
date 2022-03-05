/*
  Author: DespicableMonkey
*/
 
#include<bits/stdc++.h>
using namespace std;
 
int N;
map<int, pair<int,int>> ids;
map<pair<int, int>, int> rev_ids;
set<pair<long long, int>> closest;
map<int, long long> dists;
set<int> cols[50];
 
long long calc() {
  long long res = 0;
 
  for(int cow = 0; cow < N; ++cow) {
    auto cur_cow = *closest.begin();
    closest.erase(closest.begin());
    int x = ids[cur_cow.second].first, y = ids[cur_cow.second].second;
    res += cur_cow.first;
 
    cols[y].erase(x);
 
    for(int col = 0; col < 11; ++col) {
      auto above = cols[col].upper_bound(x);
      if(above != cols[col].end()) {
        long long xdis = pow(*above - x, 2);
        long long ydis = pow(col - y, 2);
        int id = rev_ids[{*above, col}];
        if(xdis + ydis < dists[id]) {
          closest.erase({dists[id], id});
          dists[id] = xdis + ydis;
          closest.insert({dists[id], id});
        }
      }
 
      if(above != cols[col].begin()) {
        --above; //below now
        long long xdis = pow(*above - x, 2);
        long long ydis = pow(col - y, 2);
        int id = rev_ids[{*above, col}];
        if(xdis + ydis < dists[id]) {
          closest.erase({dists[id], id});
          dists[id] = xdis+ydis;
          closest.insert({dists[id], id});
        }
      }
 
    }
 
 
  }
  return res;
}
 
int main() {
  cin >> N;
  for(int i = 0; i < N; ++i) {
    int u, v; cin >> u >> v;
    cols[v].insert(u);
    ids[i] = {u, v};
    rev_ids[{u, v}] = i;
    dists[i] = (1e16);
    closest.insert({dists[i], i});
  }
 
  auto beg = *closest.begin();
  closest.erase(closest.begin());
  dists[beg.second] = 0;
  beg.first = 0;
  closest.insert(beg);
 
  cout << calc() << '\n';
 
 
 
 
  return 0;
}
 

