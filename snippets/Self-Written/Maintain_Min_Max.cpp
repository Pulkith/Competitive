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

using namespace std;

using INF = 100000007;

struct min_max {
    int minv;
    int maxv;

    min_max() {
        minv = INF;
        maxv = -INF;
    }

    void u(int v) {
        maxv = max(maxv, v);
        minv = min(minv, v);
    }
};

struct two_max {
    int max1;
    int max2;

    two_max() {
        max1 = -INF;
        max2 = -INF;
    }

    void u(int v) {
        if(max2 > max1) 
            swap(max1, max2);
        if(v > max2) {
            max2 = v;
            if(max2 > max1)
                swap(max2, max1);
        }
    }

    void check() {
        if(max2 > max1)
            swap(max1, max2);
    }
};

struct two_min {
    int min1;
    int min2; 

    two_min() {
        min1 = INF;
        min2 = INF;
    }

    void u(int v) {
        if(min2 < min1)
            swap(min1, min2);
        if(v < min2) {
            min2 = v;
            if(min2 < min1)
                swap(min2, min1);
        }

    }

    void check() {
        if(min2 < min1)
            swap(min2, min1);
    }
};
