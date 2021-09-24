

// Include Min-Seg Tree

int N, Q;
int val[MX];
Seg<ll> seg;
vt<int> adj[MX];
int st[MX], en[MX];
int cur = 0;

void dfs(int u, int p) {
    st[u] = cur++;
    for(auto v : adj[u]) {
        if(v != p) {
            dfs(v, u);
        }
    }
    en[u] = cur - 1;
}

//Example
void test_case() {
    cin >> N >> Q;
    FOR(i, 0, N) cin >> val[i];
    FOR(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }


    dfs(1, 0);

    seg.init(N+1);
    FORE(i, 1, N) {
        seg.upd(st[i], val[i-1]);
    }

    while(Q--) {
        int o; cin >> o;
        if(o == 1) {
            //update
            int s, x; cin >> s >> x;
            seg.upd(st[s], x);
        } else {
            //sum
            int u; cin >> u;
            put(seg.query(st[u], en[u]));
        }
    }
    
}