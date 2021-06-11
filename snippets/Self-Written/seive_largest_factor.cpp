#include<bits/stdc++.h>

using namespace std;

const int limit = 1e7;
vector<int> fac;
int largest[limit+10]; //holds the largest prime factor of every number 
void seive() {
    for (int i = 2; i <= limit; ++i) {
        if (largest[i] == 0) {
            fac.emplace_back(i);
            largest[i] = i;
        }
        for (auto &x : fac) {
            if (x > largest[i] || x * i > limit) break;
            largest[x * i] = x;
        }
    }
}