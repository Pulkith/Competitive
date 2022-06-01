
// A Recursive C program to solve minimum sum partition
// problem.
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];
 
            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }
    int diff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--) {
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}
int a[25];
int N;
int main(){
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> a[i];
    int ans = 1005;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        if(i == j) continue;;
        vector<int> cur;
        for(int k = 0; k < N; ++k)
          if(k != i && k != j) cur.push_back(a[k]);
        ans = min(ans, findMin(cur, N - 2));
      }
    }
    return 0;
}