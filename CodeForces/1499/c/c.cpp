/**
 * 
 * author: DespicableMonkey
 * created: 05.03.2021 02:11:50
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

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    TC(T){
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) {
            int x;
            cin >> x;
            a[i] = x;
        }
        ll mn = 0;
        ll eve = 1, odd = 0, sumeve = a[0], sumodd = 0, mineve = a[0], minodd = 0;
        FOR(i, 1, n) {
            if(i%2==0) {
                ++eve;
                sumeve += a[i];
                mineve = min(mineve, (ll)a[i]);
            } else {
                ++odd;
                sumodd += a[i];
                if(i == 1) minodd = a[i];
                else minodd = min((ll)a[i], minodd);;
            }
            if(i == 1) mn = (sumodd + minodd * (n-odd) + sumeve + mineve * (n-eve));
            else mn = min(mn, (sumodd + minodd * (n-odd) + sumeve + mineve * (n-eve)));
        }
        cout << mn nl
    }

    return 0;
}