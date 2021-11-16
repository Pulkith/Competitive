/**
 * author: DespicableMonkey
 * created: 10.23.2021 10:49:52
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

long long s(vector<int> nums, int n) {
    const int MOD = (1e9+7);
    if(n < nums.size()) return nums[n];
    else {
        int cur = (int) ((2 * s(nums, n-1) - s(nums, n-3)) % (MOD));
        if(cur < 0) cur += MOD;
        nums.push_back(cur);
        return nums[n];
    }
}

int main () {
    int T; cin >> T;

    while(T--) {
        int N; cin >> N;
        vector<int> nums; nums = {1, 2, 3};
        cout << s(nums, N) << '\n';
    }

    return 0;
}
