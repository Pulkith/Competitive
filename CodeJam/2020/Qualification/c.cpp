/**
 * 
 * author: DespicableMonkey
 * created: 05.01.2021 13:12:58
 * 
 * Potatoes FTW!
 * 
 **/ 


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
#define cnl cout nl

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)
#define rall(x) x.rbegin(), x.rend()
#define sortt(x) sort(all(x))
#define rtn return

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define TC(i) for(int tt = (1); tt <= (i); ++tt)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

#define lower(sl) transform(sl.begin(), sl.end(), sl.begin(), ::tolower)

const int INF = 1000000007;
const int MOD = 1000000007;
const long long LLNF = (ll)10e17+7;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

struct pt {
    int first;
    int second;
    int index;

    pt(int a, int b, int c) {
        first = a; second = b; index = c;
    }
    pt(void) {

    }
};

struct sort_by_first_low_to_high { 
    inline bool operator() (const pt& struct1, const pt& struct2) {
        return (struct1.f > struct2.f);
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        int n;
        cin >> n;
        string res ="";
        pt a,b;
        priority_queue<pt, vector<pt>, sort_by_first_low_to_high> pq;
        FOR(i, 0, n)
            res += " ";
        FOR(i, 0, n){
            int a,b;
            cin >> a >> b;
            pq.push(pt(a,b,i));
        }
        if(!pq.empty()) {
            a = pq.top(); pq.pop();
            res[a.index] = 'C';
        }
        if(!pq.empty()) {
            b = pq.top(); pq.pop();
            res[b.index] = 'J';
        }

        while(!pq.empty()) {
            pt c = pq.top();
            pq.pop();

            if(c.f >= a.s) {
                a = c;
                res[a.index] = 'C';
            }
            else if(c.f >= b.s) {
                b = c;
                res[b.index] = 'J';
            }
            else {
                res = "IMPOSSIBLE";
                break;
            }
        }
  
        cout << "Case #"<<tt<<": " << (res) nl
    }

    return 0;
}