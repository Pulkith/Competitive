/**
 * author: DespicableMonkey
 * created: 07.17.2021 15:12:26
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

const int MX = (3e5+43); //Check the limits idiot
int N, ans;
pr<int, int> a[MX], l[MX], r[MX];


void test_case() {
    cin >> N;
    FOR(i, 0, N) cin >> a[i].f >> a[i].s;
    l[0] = a[0]; r[N-1] = a[N-1]; 

    FOR(i, 1, N) {
        if(l[i-1].f > a[i].s || l[i-1].s < a[i].f) break;
        l[i] = l[i-1];
        cmax(l[i].f, a[i].f); cmin(l[i].s, a[i].s);
    }

    for(int i = N-2; i >= 0; --i) {
        if(r[i+1].f > a[i].s || r[i+1].s < a[i].f) break;
        r[i] = r[i+1];
        cmax(r[i].f, a[i].f); cmin(r[i].s, a[i].s);
    }

    FOR(i, 0, N) {
        pr<int, int> cur = {-(2e9), (2e9)};
        if(i != 0)  cmax(cur.f, l[i-1].f), cmin(cur.s, l[i-1].s);
        if(i != N-1) cmax(cur.f, r[i+1].f), cmin(cur.s, r[i+1].s);
        cmax(ans, cur.s - cur.f );
    }

    put(ans);
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    //cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
