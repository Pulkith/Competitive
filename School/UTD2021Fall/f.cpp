/**
 * author: DespicableMonkey
 * created: 6.19.2021 10:49:53
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,vector<pair<int,vector<int>>>>> Tree;
#define TREE_INIT 26, {-1, vector<pair<int,vector<int>>>(26, make_pair(-1, vector<int>(26,-1)))}

struct UnionFind {
    vector<int> p; 
    UnionFind(int n) : p(n, -1) { }
    int root(int x) {
        while (p[x] >= 0) {
            if (p[p[x]] >= 0) p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    bool connect(int x, int y) {
        int xp = root(x), yp = root(y);
        if (xp == yp) return false;
        if (p[xp] > p[yp]) swap(xp,yp);
        p[xp] += p[yp], p[yp] = xp;
        return true; 
    }
    bool are_connected(int x, int y) {
        return root(x) == root(y);
    }
};

bool validate(UnionFind& uf, vector<pair<int, int>>& queries) {
    for (pair<int,int> x : queries)
        if (uf.are_connected(x.first, x.second)) return false;
    return true;
}

void rhyme_eq_1(UnionFind& uf, Tree& tree, string& str, int i, int i1) {
    if (tree[i1].first == -1) {
        tree[i1].first = i;
        for (int i2 = 0; i2 < 26; i2++) {
            if (tree[i1].second[i2].first != -1)
                uf.connect(i, tree[i1].second[i2].first);
            else {
                for (int i3 = 0; i3 < 26; i3++)
                    if (tree[i1].second[i2].second[i3] != -1)
                        uf.connect(i, tree[i1].second[i2].second[i3]);
            }
        }
    }
}

void rhyme_eq_2(UnionFind& uf, Tree& tree, string& str, int i, int i1, int i2) {
    if (tree[i1].first != -1)
        uf.connect(i, tree[i1].first);
    else if (tree[i1].second[i2].first == -1) {
        tree[i1].second[i2].first = i;
        for (int i3 = 0; i3 < 26; i3++)
            if (tree[i1].second[i2].second[i3] != -1)
                uf.connect(i, tree[i1].second[i2].second[i3]);
    }
}

void rhyme_eq_3(UnionFind& uf, Tree& tree, string& str, int i, int i1, int i2, int i3) {
    if (tree[i1].first != -1)
        uf.connect(i, tree[i1].first);
    else if (tree[i1].second[i2].first != -1)
        uf.connect(i, tree[i1].second[i2].first);
    else if (tree[i1].second[i2].second[i3] == -1)
        tree[i1].second[i2].second[i3] = i;
    else if (tree[i1].second[i2].second[i3] != i)
        uf.connect(tree[i1].second[i2].second[i3],i);
}

void add_rhyme_equivalence(UnionFind& uf, Tree& tree, string& str, int i) {
    switch (str.size()) {
        case 1:
            rhyme_eq_1(uf, tree, str, i, str[0]-'a');
            break;
        case 2:
            rhyme_eq_2(uf, tree, str, i, str[1]-'a', str[0]-'a');
            break;
        default:
            rhyme_eq_3(uf, tree, str, i, str[str.size()-1]-'a', str[str.size()-2]-'a', str[str.size()-3]-'a');
    }
}

int get_index_of(map<string, int>& str2int, string& str, int& next_index) {
    int index;
    if (str2int.find(str) == str2int.end()) {
        index = next_index++;
        str2int[str] = index;
    } else
        index = str2int[str];
    return index;
}
void read(UnionFind& uf, vector<pair<int, int>>& queries, int n) {
    string a, b, op;
    int ax, bx, next_index = 0;
    map<string, int> str2int;
    Tree tree(TREE_INIT);
    for (int i = 0; i < n; i++) {
        cin >> a >> op >> b;
        ax = get_index_of(str2int, a, next_index);
        bx = get_index_of(str2int, b, next_index);
        add_rhyme_equivalence(uf, tree, a, ax);
        add_rhyme_equivalence(uf, tree, b, bx);
        if (op[0] == 'n') queries.push_back({ax, bx});
        else uf.connect(ax, bx);
    }
}


int main() {
    int n;
    cin >> n;
    UnionFind uf(n<<1);
    vector<pair<int, int>> not_queries;
    read(uf, not_queries, n);
    cout << (validate(uf, not_queries) ? "yes\n" : "wait what?\n");
    return 0;
}
