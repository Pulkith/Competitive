#include <iostream>

using namespace std;

using ll = long long;

int a[105];
bool dp[200005]; //Max Possible Sum of All Element / 2 + 1
int N;

//Partition an array so the left and right halves are equal
bool partitionPossible() { //https://www.geeksforgeeks.org/partition-problem-dp-18/
    ll sum = 0;
    for(int i = 0; i < N; ++i)
        sum += a[i];
    if(sum%2)
        return false;
    ll mxSum = sum / 2;

    for(int i = 0; i < N; ++i) {
        for(int j = mxSum; j>= a[i]; j--)
            if(dp[j - a[i]] == true || j == a[i])
                dp[j] = true;
    }
    return dp[sum / 2];
}