#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int arr[501][501];

struct Node {
    int c, n, i, j;
    bool operator<(const Node & n) const {
        return  c > n.c;
    }
};
int r,c,n;
bool passExists(int x, int y) {
    if (x < 1 || x > r-2 || y < 1 || y > c-2) 
        return 0;
    else if (arr[x-1][y] == -1 || arr[x+1][y] == -1 || arr[x][y-1] == -1 || arr[x][y+1] == -1 || arr[x][y] == -1) 
        return 0;
    else if (arr[x-1][y] <= arr[x][y] || arr[x+1][y] <= arr[x][y]) 
        return 0;
    else if (arr[x][y-1] >= arr[x][y] || arr[x][y+1] >= arr[x][y]) 
        return 0;
   else return 1;
    return 1;
}
int adjx[] = {1,0,-1}, adjy[] = {1,1,1};
int main() {
    bool ok = false;
    cin >> r >> c >> n;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
           cin >> arr[i][j];
    }
    priority_queue<Node> q;
    for(int i = 0; i < r; ++i) arr[i][c] = 0;

    for (int i = 0; i < r; ++i) {
        if (arr[i][0] == -1) continue;
        Node d;
        d.c = arr[i][0];
        d.n = 0;
        d.i = i;
        d.j = 0;
        q.push(d);
    }

    vector<vector<vector<int> > > 
    adj(r+1, vector<vector<int> >
    (c+1, vector<int>(n+1,-1)));

    while (!q.empty()) {
        Node node = q.top();        q.pop();
        int cost =node.c, k = node.n, x=node.i, y=node.j;
        if (adj[x][y][k] != -1) 
            continue;
        else
            adj[x][y][k] = cost;
        if (y == c && k == n ) {
            cout << cost << endl;
            ok = true;
            break;
        }

        for (int l = 0; l < 3; ++l) {
            int adjxAs = x + adjx[l], adjYas = y + adjy[l];
            if (adjxAs >= r|| adjxAs < 0  || adjYas > c || adjYas < 0  || arr[adjxAs][adjYas] == -1) 
                continue;
            int n1 = k + (passExists(adjxAs,adjYas)), c1 = cost + arr[adjxAs][adjYas];
            if (n1 > n || adj[adjxAs][adjYas][n1] != -1) continue;
            Node d;
            d.c = c1;
            d.n = n1;
            d.i = adjxAs;
            d.j = adjYas;
            q.push(d);
        }
    }
    if (!ok) cout << "Impossible" << endl;
}