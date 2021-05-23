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
 
const int INF = 1000000000;
const int MOD = 1000000000;
 
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
 
        string s;
        cin >> s;
        if(n == 3 || n == 0){
            cout << (s=="TMT" ? "YES" : "NO") nl
        } else {
            bool ok = true;
 
           for(int i = 0, cur = 0, ms = 0; i < n && ms < n/3 && ok; ++i) {
               if(s[i] == 'T') {
                   ++ms;
                   ++cur;
               }
               else --cur;
               if(cur < 0) ok = false;
           }
           if(count(s.begin(), s.end(), 'T') != (n / 3 * 2)) ok = false;
           for(int i = n-1, cur = 0, ms = 0; i >= 0 && ms < n/3 && ok; --i) {
               if(s[i] == 'T') {
                   ++ms;
                   ++cur;
               }
               else --cur;
               if(cur < 0) ok = false;
           }
 
           cout << (ok ? "YES":"NO") nl
        }
    }
}
