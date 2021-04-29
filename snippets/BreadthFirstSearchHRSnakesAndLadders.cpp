#include "std.h"

using namespace std;
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    bool vis[110];
    int dis[110];
    int mov[110];

    for(int i = 1; i <= 100; ++i)
        mov[i] = i;
    for(vi v : ladders) 
        mov[v[0]] = v[1];
    for(vi s : snakes) 
        mov[s[0]] = s[1];

    memset(vis, 0, sizeof(vis));

    queue<int> q;
    vis[1] = 1;
    dis[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int s = q.front(); q.pop();
        for(int i = 1; i<=6; ++i) {
            int n = mov[s+i];
            if(!(vis[n]) && n > 0 && n < 101) {
                vis[n] = 1;
                dis[n] = dis[s]+1;  
                q.push(n);
            }
        }
    }

    if(!vis[100])
        return -1;
    else
        return dis[100];

}
int main() {

}