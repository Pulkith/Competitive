#include "std.h"

using namespace std;

/*
Using Dynamic Programming - House Robber 
At each house robber can either:
1: rob that house, and add it to the value from 2 houses ago
2: skip that house

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)  
            return 0;
        int memo[nums.size()+10];
        
        memo[0] = 0;
        memo[1] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            memo[i+1] = fmax(memo[i], memo[i-1] + nums[i]);
        }
        
        return memo[nums.size()];
    }
};