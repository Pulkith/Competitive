/**
 * author: DespicableMonkey
 * created: 05.26.2021 22:31:01
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

bool vis[100];
vector<vector<int>> adj(100, vector<int>(100));

void dfs(int v) {
    vis[v] = 1;
    /* do stuff with node */

    for(auto i = adj[v].begin(); i < adj[v].end(); ++i) {
        if(!vis[*i])
            dfs(*i);
    }
}