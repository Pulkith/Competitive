/**
 * author: DespicableMonkey
 * created: 07.04.2021 01:53:06
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

const int MX = (100+5); //Check the limits idiot
int N, M;
int a[MX], b[MX];


void test_case() {
    cin >> N; FOR(i, 0, N) cin >> a[i];
    cin >> M; FOR(i, 0, M) cin >> b[i];

    if(*max_element(a, a+N) == 0 && *max_element(b, b+M) == 0) putr(0);


    vt<int> segsA, segsB;

    for(int i = 0; i < N; ) {
        int cur = i;
        int sum = a[i++];
        while(i < N && ((a[cur] >= 0 && a[i] >= 0) || (a[cur] <= 0 && a[i] <= 0))) ++i, sum += a[cur];
        segsA.pb(cur);
    }

    for(int i = 0; i < M; ) {
        int cur = i;
        int sum = b[i++];
        while(i < N && ((b[cur] >= 0 && b[i] >= 0) || (b[cur] <= 0 && b[i] <= 0))) ++i, sum += b[cur];
        segsB.pb(cur);
    }

    if(segsB.back() < 0) segsB.pop_back();
    if(segsA.back() < 0) segsA.pop_back();

    ll ans = 0;
    int iA = 0, iB = 0;
    while(iA + iB < sz(segsA) + sz(segsB)) {
        
    }
    
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
