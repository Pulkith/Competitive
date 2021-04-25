#include "std.h"

using namespace std;

/*
 * DFS Solution - Island Count, Grid Search
 * 
 * Search The entire array, when island found, incremeent count, and use dfs to convert all connected portions to 0. after exhauasted, continue search for islands
 * 
 * 
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    ++count;
                    delIsland(grid, i, j);
                }
            }
        }
        return count;
        
    }
private:
    void delIsland(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        delIsland(grid, i+1, j);
        delIsland(grid, i-1, j);
        delIsland(grid, i, j+1);
        delIsland(grid, i, j-1);
    }
};
