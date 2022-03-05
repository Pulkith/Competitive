#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int N = 3e5 + 10; 

int p[N], sz[N], ans; 
stack<int> st; 

int n, k, u[N << 1], v[N << 1], o[N << 1], on[N << 1], des[N << 1];
vector<pair<int, int>> edgeeorder;
char op[N << 1]; 
map<ii, int> mp; 

int find(int x) {
    while(p[x] != x) x = p[x];
    return x; 
}
void Union(int x, int y) {
    x = find(x); y = find(y); 
    if(x == y) return; 
    if(sz[x] > sz[y]) swap(x, y);
    p[x] = y; 
    sz[y] += sz[x];
    st.push(x); // this means u was attached to p[u] 
}
void rollbax(int t) { 
    while(st.size() > t) {
        int x = st.top(); st.pop(); 
        sz[p[x]] -= sz[x]; 
        p[x] = x; ans++;
    }
}
void solve(int l, int r) {
    if(l == r) {
        if(op[l] == 'D') 
            printf("%d\n", ans);
        return; 
    } 
    int m = (l + r) >> 1, now = st.size(); 
    
    for(int i = m + 1; i <= r; i++) 
        if(o[i] < l) Union(u[i], v[i]); 
    solve(l, m); 
    rollbax(now); 
    
    for(int i = l; i <= m; i++) 
        if(o[i] > r) Union(u[i], v[i]);
    solve(m + 1, r);
    rollbax(now); 
}

int main() {
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
        p[i] = i, sz[i] = 1, on[i] = 1; 

    if(!k) return 0;

    for(int i = 1; i <= k; i++) {
        scanf(" %c", &op[i]);
        if(op[i] == 'D') {
          cin >> des[i];
          continue;
        } else if(op[i] == 'A') {
          cin >> u[i] >> v[i];
          if(u[i] > v[i]) swap(u[i], v[i]);
          mp[{u[i], v[i]}] = i;
          edgeeorder.push_back({u[i], v[i]});
        } else {
          int index; cin >> index;
          o[i] = mp[edgeeorder[index-1]];
          o[o[i]] = i;
          u[i] = edgeeorder[index-1].first, v[i] = edgeeorder[index-1].second;
          mp.erase(edgeeorder[index-1]);
        }
    }
    solve(1, k); 
}