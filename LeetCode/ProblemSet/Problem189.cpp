#include "std.h"

using namespace std;

/*

Rotate Array, Cyclic Rotations with cosntant space





*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        //number of rotations/single replacements completed
        int count = 0;
        //go through each index of the array, if n%k == 0, a cycle will occur, before the complete array rotation is complete. If n%k!=0, a complete cycle means array rotation was finished.
        // At each index, keep replacing until a cycle is complete, and 
        //then go to the next index and complete another cycle. If n%k!=0, and a cycle means a complete array rotation, the for loop will terminate after one for-loop iteration. If
        //n&k == 0, go through the cycle at each index, until count == nums.size(), which means
        // the correct number of rotations/single replacments were completed and we should termiante the loop.
        for(int i = 0; count < nums.size(); ++i) {
            int index = i;
            int prev = nums[index];
            do{
                int temp = nums[(index+k)%nums.size()];
                nums[(index+k)%nums.size()] = prev;
                prev = temp;
                index = (index + k) % nums.size();
                ++count;
            }
            //keep going until a cycle is detected
            while(i != index);
        }
    }
};