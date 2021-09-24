
//1-Indexed
const int MX = (2e5+43); //Check the limits idiot
int N, Q;
vector<int> graph[MX];
int timer = 0, first[MX], euler_tour[MX * 2];
int segtree[MX * 4]; // Segment tree for RMQ
void dfs(int node = 0, int parent = -1) {
    first[node] = timer; // The time when we first visit a node
    euler_tour[timer++] = node;
    for (int i : graph[node]) {
        if (i != parent) {
            dfs(i, node);
            euler_tour[timer++] = node;
        }
    }
}
int min_first(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    return (first[x] < first[y] ? x : y);
}
// Build the segment tree: run `build()` after running dfs`
void build(int node = 1, int l = 0, int r = timer - 1) {
    if (l == r) segtree[node] = euler_tour[l];
    else {
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        segtree[node] = min_first(segtree[node * 2], segtree[node * 2 + 1]);
    }
}
int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
    if (l > b || r < a) return -1;
    if (l >= a && r <= b) return segtree[node];
    int mid = (l + r) / 2;
    return min_first(query(a, b, node * 2, l, mid), query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run `dfs` and `build()` before you run this
int lca(int a, int b) {
    if (first[a] > first[b]) swap(a, b);
    return query(first[a], first[b]);
}

