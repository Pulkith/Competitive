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

    string a,b;
    cin >> a >> b;

      int lcs[sz(a)+1][sz(b)+1];
        for(int i=0;i<=sz(a);i++){
          for(int j=0;j<=sz(b);j++){
              if(i==0||j==0)
                  lcs[i][j]=0;
              else if(a[i-1]==b[j-1])
                  lcs[i][j]=1+lcs[i-1][j-1];
              else
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
          }
      }
      return lcs[sz(a)][sz(b)];

}