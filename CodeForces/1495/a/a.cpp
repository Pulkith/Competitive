/**
 * 
 * author: DespicableMonkey
 * created: 05.19.2021 15:18:51
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
#include <numeric> 
#include <cassert>
#include <iomanip>

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

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

template<typename T> istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T> &v){for (auto& i : v) is << i << " "; return is;}
void ff() { fflush(stdout); }
void IO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(14);
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
struct pred {
    bool operator()(const double &l, const double &r) {
        return (abs(l) < abs(r));
    }
};

int main () {
    IO();

    int T; cin >> T;
    TC(T){
        int n;
        cin >> n;
        vector<int> miners, diamonds;

        FOR(i, 0, 2*n) {
            int a, b; //huh... Using a double here causes TLE, using int runs in ~125ms
            cin >> a >> b;
            if(a == 0) 
                miners.pb(b);
            else
                diamonds.pb(a);
        }

        sort(all(miners), pred());
        sort(all(diamonds), pred());

        long double sum = 0;
        FOR(i, 0, n)
            sum += sqrt((double)(miners[i] * 1LL * miners[i] + diamonds[i] * 1LL * diamonds[i]));

        cout << sum nl


    }

    return 0;
}