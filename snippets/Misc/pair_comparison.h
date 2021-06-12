
#include <bits/stdc++.h>

using namespace std;

template<typename T, typename U>  bool operator< (pair<T, U> &l, pair<T, U> &r) {
    return l < r;
}

struct pred { bool operator()(const pair<int, int> &l, const pair<int, int> &r) { 
    return l.second < r.second; } };