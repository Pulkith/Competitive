#include "std.h"

using namespace std;

int main()
{
    int n, m;

    //get number of nodes and edges
    cin >> n >> m;
    //create 2d array
    int d[n][n];

    //loop through empty array
    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < n; ++k) {
            //if nodes are same i.e. 3,3, then the distance is 0
            if(i == k) 
                d[i][k] = 0;
            //otherwise set distance to infinity(nothing can be more, and we want to find the least distance, so this is a placeholder)
            else 
                d[i][k] = INF;
        }
    }

    //loop through input to get all DIRECTED edges and their weights, and put into distance array
    for (int i = 0; i < m; i++) {
        int a,b, w;
        cin >> a >> b >> w;
        d[a-1][b-1] = w;
    }
    
    //algorithim implemention, get the shortest distance
     for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }   
    
    //for each query output the shortest path between 2 nodes
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        
        //if the nodes are the same, output 0, extraneous
        if(x == y)
            cout << 0;
        else {
            //if output is infinity, that means placeholder never changed and it is impossile
            if(d[x-1][y-1] == INF)
                cout << -1;
            //output shortest path
            else
                cout << d[x-1][y-1];
        }
        cout << endl;
    }
    return 0;
}