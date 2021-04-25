#include "std.h"

using namespace std;

//calcaulate maximum subseqeunce and maximum subarray
vector<int> maxSubarray(vector<int> arr) {

//vars for max subseqeunce
int mbmax = -(1e9+7), mbsum = 0;
//vars for max subarray
int max = -(1e9+7), lmax = 0;


for(int i = 0; i < arr.size(); ++i) {
    //Kadane’s Algorithm, max subarray
    lmax = fmax(arr[i], arr[i] + lmax);
    max = fmax(max, lmax);
    
    //get max subseqeunce(its the sum of all positive numbers, if there are no positive numbers, it is the largest(closest to 0) negative numbebr)

    //if number is positive add to sum
    if(arr[i] >= 0)
        mbsum += arr[i];
    //get the smallest/closest to 0 negative numer
    else
        mbmax = fmax(mbmax, arr[i]);
}
//if there are no positive numbers, set maximum subseqeunce to neg numer that is closest to 0;
if(mbsum == 0)
    mbsum = mbmax;


return {max, mbsum};

}