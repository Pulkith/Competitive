/**
 * Description: stack
 * Source: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
 * Verification: VT HSPC 2019 D
 */

template<int SZ> struct DirCyc {
    vt<int> adj[SZ], st, cyc; vt<bool> inSt, vis; 
    void dfs(int x) {
        st.pb(x); inSt[x] = vis[x] = 1;
        for(auto i : adj[x]) {
            if (inSt[i]) cyc = {find(all(st),i),end(st)};
            else if (!vis[i]) dfs(i); 
            if (sz(cyc)) return;
        }
        st.pop_back(); inSt[x] = 0;
    }
    vt<int> init(int N) {
        inSt.resize(N), vis.resize(N); 
        FOR(i, 0, N) if (!vis[i] && !sz(cyc)) dfs(i);
        return cyc;
    }
};