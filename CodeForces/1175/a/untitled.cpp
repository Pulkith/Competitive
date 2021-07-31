#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int, int> n;
        for(int i = 0; i < nums.size(); ++i)
            ++n[nums[i]];
        set<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < nums.size(); ++j){
                if(j == i) continue;
                for(int k = 0; k < nums.size(); ++k){
                    if(k == i || j == k) continue;
                    
                    
                    int need = target - (nums[i] + nums[j] + nums[k]);
                    int cnt = 0;
                    cnt += (need == nums[i]) + (need == nums[j]) + (need == nums[k]);
                    
                    if(n[need] > cnt) {
                        vector<int> cur = {nums[i], nums[j], nums[k], need}; sort(cur.begin(), cur.end());
                        ans.insert(cur);
                    }
                }
            }
        }
        vector<vector<int>> ret;
        for(auto vt : ans) ret.push_back(vt);
        return ret;
    }
};