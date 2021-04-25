#include "std.h"

using namespace std;

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int ls = 1, cs = 1;
        
        for(int i = 1; i < nums.size(); ++i) {
            if((nums[i] - nums[i-1] == 1))
                ++cs;
            else {
                if(nums[i] != nums[i-1]){
                    ls = fmax(ls, cs);
                    cs = 1;
                }
            }
        }
        return fmax(ls, cs);
    }