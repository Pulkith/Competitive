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

int n; //(number of numbers)
int a[20]; // actual elements;
int t; //target sum;

bool possible() { //O(2^N*N). You can get (O(2^N) with recursion)
                  // for longer masks, you can use dp to use calculated values of shorter submasks
    for(int mask = 0; mask < (1<<n); ++mask) {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(mask&(i<<i))
                sum += a[i];
        }
        if(sum == t) return true;
    }
    return false;
}