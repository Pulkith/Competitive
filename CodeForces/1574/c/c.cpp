/**
 * author: DespicableMonkey
 * created: 09.23.2021 01:44:58
 * Potatoes FTW!
 **/ 

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
#define has(container, element) ((bool)(container.find(element) != container.end()))

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
            if(sz(__t) && !debug_active) setIn(__s), setOut(__t);
            else if (sz(__s) && !debug_active) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+43); //Check the limits idiot
int N, M;
ll a[MX];
pr<ll, ll> drags[MX];


void test_case() {
    cin >> N;
    FOR(i, 0, N) cin >> a[i];
    sort(a, a+N);
    cin >> M;
    FOR(i, 0, M ) cin >> drags[i].f >> drags[i].s;
    ll sum = accumulate(a, a+N, 0LL);
    set<ll> heros;
    FOR(i, 0, N) heros.insert(a[i]);
    FOR(i, 0, M) {
        if(a[N-1] < drags[i].f) {
            ll ans = drags[i].f - a[N-1];
            ll rem = sum - a[N-1];
            put(ans + max(0LL, drags[i].s - rem));
        } else {
            auto bound = heros.lower_bound(drags[i].f);
            ll r1 = drags[i].s - (sum - *bound);
            cmax(r1, 0LL);
            
            if(*bound != a[0]) {
                --bound;
                ll ans = drags[i].f - *bound;
                ll rem = sum - *bound;
                ans += max(0LL, drags[i].s - rem);
                cmin(r1, ans);
            }

            put(r1);
        }
    }
    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
