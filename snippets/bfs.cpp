/**
 * author: DespicableMonkey
 * created: 05.26.2021 22:26:06
 * 
 * Potatoes FTW!
 **/ 

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>
#include <cstring>
#include <numeric> 
#include <cassert>
#include <iomanip>
#include <chrono>

using namespace std;
vector<vector<int>> adj(100, vector<int>(100));
bool visited[100]{false};
void bfs(int s) {
    queue<int> q;
    visited[s] = 1;
    q.push(s);

    while(!q.empty()) {
        s = q.front();
        /* use front node */
        q.pop();

        for(auto i = adj[s].begin(); i < adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }

    }
}

