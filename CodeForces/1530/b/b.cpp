/**
 * author: DespicableMonkey
 * created: 07.17.2021 09:35:11
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <iostream>
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

const int MX = (25+43); //Check the limits idiot
int H, W;
int a[MX][MX], b[MX][MX], c[MX][MX];


void test_case() {
    memset(a, 0, sizeof(a));
    cin >> H >> W;
    bool swapped = 0;
    if(H > W) {
        swapped = 1;
        swap(H, W);
    }

    FOR(i, 0, W)
        a[0][i] =  a[H-1][i] = ((i&1) == 0);
    FOR(i, 1, H-1)
        a[i][0] = !(a[i-1][0] || a[i-1][1] || a[i+1][0] || a[i+1][1]);
    FOR(i, 1, H-1)
        a[i][W-1] = !(a[i-1][W-1] || a[i-1][W-2] || a[i+1][W-1] || a[i+1][W-2]);
    if(swapped) {

        FOR(i, 0, W) {
            for(int j = H-1; j >= 0; --j)
                cout << a[j][i];
            cout << '\n';
        }
    } else {
        FOR(i, 0, H){
            FOR(j, 0, W)
                cout << a[i][j];
            cout << '\n';
        }
        
    }
    cout << '\n';

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
