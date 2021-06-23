#include<bits/stdc++.h>

using namespace std;

    const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL
    map<int, set<pair<int, int>>> islands;
    set<pair<int, int>> cur;
    int N, M;
    void floodfill(vector<vector<int>>& g, int i, int j, int index) {
        if(i < 0 || i >= N || j < 0 || j >= M) return;
        if(g[i][j] != 1) return;
        g[i][j] = index;
        if(index == -1)
            cur.insert({i, j});
        else
            islands[index].insert({i, j});
        
        floodfill(g, i, j+1, index);
        floodfill(g, i, j-1, index);
        floodfill(g, i+1, j, index);
        floodfill(g, i-1, j, index);
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        N = (grid1).size(), M = (grid1[0]).size();
        int index = 2;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if(grid1[i][j] == 1)
                    floodfill(grid1, i, j, index);
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(grid2[i][j] == 1) {
                    floodfill(grid2, i, j, -1);
                    int ind = grid1[i][j];
                    if(ind >= 2) {
                        bool ok = 1;
                        for(auto num : cur) {
                            ok&=(islands[ind].find(num) != islands[ind].end());
                        }
                        ans += ok;
                    }
                    cur.clear();
                }
            }
        }
        
        return ans;
        
    }