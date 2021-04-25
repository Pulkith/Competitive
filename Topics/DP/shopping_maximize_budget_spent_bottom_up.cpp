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
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int i, j, l, TC, M, C, K, price[25][25]; // price[garment_id (<= 20)][model (<= 20)]
    bool can_reach[210][25];                 // can_reach table[money_left (<= 200)][garment_id (<= 20)]
                                             // question: is 2nd dimension (model) needed? M = (201*20) -> (201) only?
    scanf("%d", &TC);                        // can we compute the solution by just maintaining 2 most recent columns?
    while (TC--){                            // hint: DP-on-the-fly (a.k.a space saving trick)
        scanf("%d %d", &M, &C);
        for (i = 0; i < C; i++) {
            scanf("%d", &K);
            price[i][0] = K; // to simplify coding, we store K in price[i][0]
            for (j = 1; j <= K; j++)
                scanf("%d", &price[i][j]);
        }
        memset(can_reach, false, sizeof can_reach); // clear everything
        for (i = 1; i <= price[0][0]; i++)          // initial values
            can_reach[M - price[0][i]][0] = true;   // if only using first garment_id

        
        // Challenge: this loop is written in column major, rewrite it in row major!
        // See Tips 6.3 in Section 3.1.2
        for (j = 1; j < C; j++) // for each remaining garment
            for (i = 0; i < M; i++)
                if (can_reach[i][j - 1]) // if can reach this state
                    for (l = 1; l <= price[j][0]; l++)
                        if (i - price[j][l] >= 0)                 // flag the rest
                            can_reach[i - price[j][l]][j] = true; // as long as it is feasible
        for (i = 0; i <= M && !can_reach[i][C - 1]; i++);           // the answer is in the last column

        if (i == M + 1) // nothing in this last column has its bit turned on
            printf("no solution\n");
        else
            printf("%d\n", M - i);
    }
} // return 0;