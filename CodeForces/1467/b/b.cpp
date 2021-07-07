/**
 * author: DespicableMonkey
 * created: 06.26.2021 20:57:16
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

const int MX = (3e5+5); //Check the limits idiot
int N;
int a[MX];


void test_case() {
    cin >> N;
    FOR(i, 0, N) cin >> a[i];
    vt<bool> is(N, 0);
    ll ans = 0, total = 0;

    auto is_v_h = [&](int i) -> bool {
        if(i > 0 && i < N-1) {
            if(a[i] > a[i-1] && a[i] > a[i+1]) return 1;
            if(a[i] < a[i-1] && a[i] < a[i+1]) return 1;
        }
        return 0;
    };

    FOR(i, 1, N-1) {
        is[i] = is_v_h(i);
        total = ans += is[i];
    }


    FOR(i, 1, N-1) {
        
        int save = a[i];
        
        FOR(j, 0, 2) {
            int cur = 0;
            a[i] = (j == 0 ? a[i-1] : a[i+1]);

            cur += (is[i] ^ is_v_h(i)) ? -1 + (is[i] * 2) : 0;
            cur += (is[i+1] ^ is_v_h(i+1)) ? -1 + (is[i+1] * 2) : 0;
            cur += (is[i-1] ^ is_v_h(i-1)) ? -1 + (is[i-1] * 2) : 0;

            

            cmin(ans, total - cur);
        }

        a[i] = save;

    }
    put(ans);
    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(2);

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}