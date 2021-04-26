#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
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
#define ld long double
#define ull unsigned long long

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define vi vector<int>
#define vll vector<ll>
#define vb = vector<bool>
#define pb push_back

#define f first
#define s second

#define nl << "\n";

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)
#define rall(x) x.rbegin(), x.rend()
#define sortt(x) sort(all(x))
#define rtn return
#define ins(x) insert(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
#define TC(i) for(int tt = (1); tt <= (i); ++tt)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const long long LLNF = (ll)10e17+7;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        elems.push_back(item);
 
    return elems;
}
int PowerSet(int arr[], int n, int target)
{
    vector<string> list;
    int minn = INF;
    /* Run counter i from 000..0 to 111..1*/
    for (int i = 0; i < (int) pow(2, n); i++){
        string subset = "";
        for (int j = 0; j < n; j++){
            if ((i & (1 << j)) != 0)
                subset += to_string(arr[j]) + "|";
        }
        if (find(list.begin(), list.end(), subset) == list.end())
            list.push_back(subset);
    }
    for (string subset : list)
    {
        // split the subset and print its elements
        vector<string> arr = split(subset, '|');
        int sum = 0;
        for (string str: arr)
           sum += stoi(str);
        if(sum == target) {
            sortt(arr);
            string r = "";
            for(string sx : arr)
                r += sx;
            minn = min(minn, stoi(r));
            
        }
    }
    return (minn == INF ? -1 : minn);
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int T;
    cin >> T;
    TC(T) {
        int x; cin >> x;

       if(sz(ts(x)) == 1) cout << x nl
       else {
           int a[9]{1,2,3,4,5,6,7,8,9};
           int res = PowerSet(a ,9, x);
           cout << res nl;
       }
    }

    return 0;
}