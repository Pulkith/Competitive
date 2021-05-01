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


bool isPal(string s) {
    int sx = s.size();
    for(int i = 0; i < sx / 2; ++i) {
        if(s[i] != s[sx - 1 - i]) return false;
    }
    return true;
}