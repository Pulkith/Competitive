/**
 * author: DespicableMonkey
 * created: 10.16.2021 08:19:05
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

const int MX = (2e5+43);
int N;
vt<int> a[MX];


void test_case() {
    cin >> N; 
    FOR(i, 0, N) {
        int x, y, z, b;
        cin >> x >> y >> z >> b;
        a[i] = {x, y, z, b};
    }
    pr<int, int> best = {0, 0};
    int bv = (1e9);
    FORE(X, -100, 100) {
        FORE(Y, -100, 100) {
            int ans = 0;
            FOR(i, 0, N) {
                if(a[i][1] >= Y) ans += a[i][1] - Y;
                else if(a[i][3] <= Y) ans += Y - a[i][3];
                
                if(a[i][0] >= X) ans += a[i][0] - X;
                else if(a[i][2] <= X) ans += X - a[i][2];  
            }   
            if(cmin(bv, ans)) {
                best = {X, Y};
            }
        }
    }
    cout << best.f << " " << best.s << '\n';

    
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
