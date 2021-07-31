/**
 * author: DespicableMonkey
 * created: 07.17.2021 17:31:51
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
int a[MX];


void test_case() {
    cin >> N;
    FORE(i, 1, N) cin >> a[i];
    int neg = 0; int neg_max = -(2e9), neg_index = 0;
    vt<int> zeros;
    FORE(i, 1, N) {
        neg += (a[i] < 0);
        if(a[i] < 0) 
            if(cmax(neg_max, a[i]))
                neg_index = i;
        if(a[i] == 0) {
            zeros.pb(i); a[i] = (2e9);
        }
    }
    if(sz(zeros)) {
        FOR(i, 1, sz(zeros))
            cout << "1 " << zeros[i] << " " << zeros[0] << '\n';
        if(sz(zeros) == N) return;

        if(neg == 1 && neg+sz(zeros) == N) putr("1 " + ts(neg_index) + " " + ts(zeros[0]));
        if(neg%2==0) cout << "2 " << (zeros[0]) << '\n';
    } 
    if(neg&1) {
        a[neg_index] = (2e9);
        if(sz(zeros)) cout << "1 " << zeros[0] << " " << neg_index << '\n';
        cout << "2 " << neg_index << "\n"; 
    } 
    vt<int> rem;
    FORE(i, 1, N)
        if(a[i] <= (1e9+10))
            rem.pb(i);
    FOR(i, 1, sz(rem))
        cout << "1 " << rem[i] << " "<< rem[0] << '\n';



    
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
