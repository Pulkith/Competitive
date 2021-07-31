/**
 * author: DespicableMonkey
 * created: 07.24.2021 13:42:23
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
pr<int, int> a[MX];

void test_case() {
    cin >> N;

    FOR(i, 0, N) {
        cin >> a[i].f;
        a[i].s = (i+1);
    }
    if(N == 2 || N == 3) putr(1);

    sort(a, a+N);
    map<int, int> cnt;
    FOR(i, 2, N) ++cnt[a[i].f - a[i-1].f];
    if(sz(cnt) == 1) putr(a[0].s);
    cnt.clear();
    FOR(i, 1, N) {
        if(i == 1) continue;
        if(i == 2) ++cnt[a[i].f - a[i-2].f];
        else ++cnt[a[i].f - a[i-1].f];
    }
    if(sz(cnt) == 1) putr(a[1].s);
    int d = a[1].f - a[0].f;


    FOR(i, 1, N) {
        if(a[i].f - a[i-1].f != d) {
            bool ok = 1;
            FOR(j, 1, N) {
                if(j == i) continue;
                if(j == i+1) ok &= a[j].f - a[j-2].f == d;
                else ok &= (a[j].f - a[j-1].f == d);
            }
            putr(ok ? a[i].s : -1);  
        }  
    }
    assert(0);
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
