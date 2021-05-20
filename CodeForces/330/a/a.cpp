#include <iostream>
#include<set>
#include<vector>

using namespace std;

int main() {
    int r,c;
    cin >> r >> c;
    int grid[r][c];
    set<pair<int, int>> se;
    for(int i = 0; i < r; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < c; ++j)
            grid[i][j] = s[j];
    }
    for(int i = 0; i < r; ++i) {
        vector<pair<int,int > > v;
        bool ok = true;
        for(int j = 0; j < c && ok; ++j) {
            if(grid[i][j] == 'S') 
                ok = false;
            else
                v.push_back({i, j});
        }
        if(ok) {
            for(pair<int, int> p : v)
                se.insert(p);
        }
    }
    for(int i = 0; i < c; ++i) {
        vector<pair<int,int> > v;
        bool ok = true;
        for(int j = 0; j < r && ok; ++j) {
            if(grid[j][i] == 'S') 
                ok = false;
            else
                v.push_back({j, i});
        }
        if(ok) {
            for(pair<int, int> p : v)
                se.insert(p);
        }
    }
    cout << (se.size());

}
