/**
 * author: DespicableMonkey
 * created: 07.10.2021 23:54:01
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

const int MX = (2e5+43); //Check the limits idiot
int N;
int a[3][3];


void test_case() {
    FOR(i, 0, 3) {
        FOR(j, 0, 3){
        if(i == 1 &&j == 1) continue;
            cin >> a[i][j];
        }
    }

    int maxx = 0;

    auto tr = [&]() -> int{
        int cur = 0;
        FOR(i, 0, 3) cur += (a[i][2] - a[i][1] == a[i][1] - a[i][0]);
        FOR(i, 0, 3) cur += (a[2][i] - a[1][i] == a[1][i] - a[0][i]);
        cur += (a[0][0] - a[1][1] == a[1][1] - a[2][2]);
        cur += (a[0][2] - a[1][1] == a[1][1] - a[2][0]);

        return cur;
    };

    a[1][1] = (a[1][0] + a[1][2]) / 2;
    cmax(maxx, tr());

    a[1][1] = (a[0][1] + a[2][1]) / 2;
    cmax(maxx, tr());

    a[1][1] = (a[0][0] + a[2][2]) / 2;
    cmax(maxx, tr());

    a[1][1] = (a[0][2] + a[2][0]) / 2;
    cmax(maxx, tr());

    cout << maxx << '\n';
    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        cout << "Case #" << tt << ": ";
        test_case();
    }

    return 0;
}
