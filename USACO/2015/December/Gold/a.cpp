/**
 * author: DespicableMonkey
 * created: 07.25.2021 01:22:05
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <functional>
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
#define has(container, element) container.find(element) != container.end()

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

const int MX = (1e5+43); //Check the limits idiot
int N;
int a[MX];


void test_case() {
    cin >> N;
    FOR(i, 0, N) cin >> a[i];
    set<int> you_lo, you_hi, you;
    FORE(i, 1, 2 * N) you.insert(i);
    FOR(i, 0, N) you.erase(a[i]);
    FOR(i, 0, N / 2) you_lo.insert(*you.begin()), you.erase(you.begin());
    FOR(i, 0, N / 2) you_hi.insert(*you.begin()), you.erase(you.begin());
    FOR(i, 0, N / 2) {
        auto lowest = you_hi.lower_bound(a[i]);
        if(lowest != you_hi.end()) you_hi.erase(lowest);
    }
    FOR(i, N / 2, N) {
        auto highest = you_lo.lower_bound(a[i]);
        if(highest != you_lo.begin()) you_lo.erase(--highest);
    }
    
    put(N - sz(you_lo) - sz(you_hi));
}

int main () {
    CP::IO().SetIO("cardgame")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
