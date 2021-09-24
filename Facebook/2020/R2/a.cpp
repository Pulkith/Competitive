/**
 * author: DespicableMonkey
 * created: 09.19.2021 13:15:14
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

const int MX = (1e6+43); //Check the limits idiot
int N, K;
ll S[MX], X[MX], Y[MX];
vt<vt<ll>> ic(3, vt<ll>(4));


void test_case() {
    cin >> N >> K;
    FOR(i, 0, K) cin >> S[i];
    FOR(i, 0, 4) cin >> ic[0][i];
    FOR(i, K, N) S[i] = (ic[0][0] * S[i-2] + ic[0][1] * S[i-1] + ic[0][2]) % ic[0][3];
    FOR(i, 0, K) cin >> X[i];
    FOR(i, 0, 4) cin >> ic[1][i];
    FOR(i, K, N) X[i] = (ic[1][0] * X[i-2] + ic[1][1] * X[i-1] + ic[1][2]) % ic[1][3];
    FOR(i, 0, K) cin >> Y[i];
    FOR(i, 0, 4) cin >> ic[2][i];
    FOR(i, K, N) Y[i] = (ic[2][0] * Y[i-2] + ic[2][1] * Y[i-1] + ic[2][2]) % ic[2][3];
    ll ans = 0;
    ll cur = 0;
    FOR(i, 0, N) {
        if(S[i] > X[i] + Y[i]) {
            ll ovf = (S[i] - (X[i] + Y[i]));
            ans += ovf;
            cur += ovf;
            S[i] = X[i] + Y[i];
        }
        else if(S[i] < X[i]) {
            ll ovf = (X[i] - S[i]);
            cur -= ovf;
            S[i] = X[i];
        }
    }

    FOR(i, 0, N) {
        if(cur > 0) {
            int mv = min(X[i] + Y[i] - S[i], cur);
            cur -= mv;
            S[i] += mv;
        } else if(cur < 0) {
            int mv = min(S[i] - X[i], -cur);
            ans += mv;
            cur += mv;
            S[i] -= mv;
        }
    }

    if(cur != 0) putr(-1);
    put(ans);
    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(2);
    CP::IO().setOut("/Users/despicablemonkey/Desktop/Competitive/Facebook/2020/R2/ans2.txt");
    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        cout << "Case #" << tt << ": ";
        test_case();
    }

    return 0;
}
