/**
 * author: DespicableMonkey
 * created: 07.10.2021 21:33:59
 * Potatoes FTW!
 **/ 

#include <algorithm>
#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
    #define debug_active 1
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define my_brain_hurts int Test_Cases = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

#define ll long long
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

inline namespace CP {
     inline namespace Output {
        #if !defined LOCAL
            #define dbg(...) ;
            #define print_test_case(...) ;
            #define debug_active 0
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T output) { cout << output << '\n'; }
        #define putr(__output) return void(put(__output))
    }
    class IO { public:
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void Input(int __use_input = 0) {if(!!__use_input && debug_active){setIn("in"+to_string(__use_input)+".txt");}}
        IO FastIO() { cin.tie(nullptr)->sync_with_stdio(0); return *this; }
        IO* SetIO(string __s = "", string __t = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if(sz(__t)) setIn(__s), setOut(__t);
            else if (sz(__s)) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+43); //Check the limits idiot
int N;
int a[MX];
int dp[MX];

namespace number_theory {
    ll gcd(ll x, ll y) {
        if (x == 0) return y;
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    bool is_prime(ll n) { 
        if (n <= 1) return false; 
        if (n <= 3) return true; 
      
        if (n % 2 == 0 || n % 3 == 0) return false; 
      
        for (ll i = 5; i * i <= n; i += 6) 
            if (n % i == 0 || n % (i+2) == 0) 
                return false; 
      
        return true; 
    } 
     
    bool prime[15000105]; 

    void sieve(int n) { 
        for (ll i = 0; i <= n; i++) prime[i] = 1;
        for (ll p = 2; p * p <= n; p++) { 
            if (prime[p] == true) { 
                for (ll i = p * p; i <= n; i += p) 
                    prime[i] = false; 
                } 
            } 
        prime[1] = prime[0] = 0;
    } 
     
    vector<ll> primelist;
    bool __primes_generated__ = 0;
     
    template<int n> void gen_primes() {
        __primes_generated__ = 1;
        sieve(n + 1);
        for (ll i = 2; i <= n; i++) 
            if (prime[i]) 
                primelist.push_back(i);
    }
     
    vector<ll> get_factors(ll n) {
        if (!__primes_generated__) {
            cerr << "Call genprimes you dope" << endl;
            exit(1);
        }
        vector<ll> facs;
     
        for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
            if (n % primelist[i] == 0) {
                while (n % primelist[i] == 0) {
                    n /= primelist[i];
                    facs.push_back(primelist[i]);
                }
            }
        }
        if (n > 1) {
            facs.push_back(n);
        }
        sort(facs.begin(), facs.end());
        return facs;
    }
    
    vector<ll> get_divisors(ll n) {
        vector<ll> divs;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                divs.push_back(n / i);
            }
        }
        divs.erase(unique(divs.begin(), divs.end()), divs.end());
        return divs;
    }
}

using namespace number_theory;

void test_case() {
    cin >> N;
    map<int, int> mp;
    FOR(i, 0, N) {
        int x; cin >> x;
        ++mp[x];
    }
    int ans = N;
    memset(dp, 0, sizeof dp);

    for(auto &[x, y] : mp){
        for(auto div : get_divisors(x))
            cmax(dp[x], dp[div]);
        dp[x] += y;
    }


    cout << (N - (*max_element(dp+1, dp + 20003))) << '\n';


    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
