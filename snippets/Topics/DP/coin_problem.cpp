#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <deque>
#include <bitset>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <random>
#include <initializer_list>
#include <ios>
#include <cstring>

using namespace std;

#define ll long long

#define vi vector<int>
#define pb push_back

#define nl << "\n";

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int target;
    cin >> target;
    int N;
    cin >> N;
    vi v(N);
    for(int i = 0; i < N; ++i)
        cin >> v[i];
    
    //Greedy Sollution, Only works with euro coins e.e. 1,5,10,25,50, 1
    int cnt = 0;
    sort(v.begin(), v.end());
    for(int i = v.size() - 1; i>= 0 && target> 0; --i) {
        int diff = target / v[i];
        target -= diff * v[i];
        cnt += diff;
    }
    cout << cnt nl



    //Dynamic Programming Solution, works with everything
    vi dp(target+1, INF);
    dp[0] = 0;
    for(int i = 0; i <= target; ++i) {
        for(auto c : v) 
            if(i - c >= 0)
                dp[i] = min(dp[i], dp[i-c] + 1);
    }
    cout << dp[target];
}