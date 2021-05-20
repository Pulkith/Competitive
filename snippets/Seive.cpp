/**
 * 
 * author: DespicableMonkey
 * created: 05.20.2021 00:08:58
 * 
 * Potatoes FTW!
 * 
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

using namespace std;

bool factors[10000005]{true};
int ans[10000005]{-1};
vector<int> fac;
void seive(int limit) {
    factors[2] = true;
    for(int i = 4; i <= limit; i += 2)
        factors[i] = false;
    for(int i = 3; i <= limit; i += 2) {
        if(factors[i]) {
            for(int j = i*2; i <= limit; j += i)
                factors[j] = false;
            fac.push_back(i);
        }
    }
}