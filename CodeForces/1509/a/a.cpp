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
        int N;
        cin >> N;
        vector<int> even, odd;
        for(int i = 0; i < N; ++i) {
            int in;
            cin >> in;
            if(in % 2 == 0)
                even.pb(in);
            else 
                odd.pb(in);
        }
        for(int i = 0; i < sz(even); ++i) 
            cout << even[i] << " ";
        for(int i = 0; i < sz(odd); ++i)
            cout << odd[i] << " ";
        cout nl
    }
}