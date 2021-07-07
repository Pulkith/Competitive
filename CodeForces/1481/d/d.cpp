/**
 * author: DespicableMonkey
 * created: 07.02.2021 11:21:21
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

const int MX = (1e3+5); //Check the limits idiot
int N, M;
string a[MX];


void test_case() {
    cin >> N >> M;
    FOR(i, 0, N) cin >> a[i];

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if((a[j][i] == a[i][j] || M&1) && a[i][j] != '*') {
                put("YES");
                FOR(k, 0, M+1) 
                    cout << ((k&1 ? j+1 : i+1)) << " \n"[k == M];
                return;
            } 
        }
    }
    if(N <= 2) putr("NO");
    else put("YES");


    vt<int> index;

    FOR(i, 0, 3) {
        FOR(j, 0, 3) {
            FOR(k, 0, 3) {
                if(a[j][i] == a[i][k] && j != k) {
                    if(a[j][i] == '*' || a[i][k] =='*') continue;
                    index.pb(k+1);
                    index.pb(i+1);
                    index.pb(j+1);

                    break;
                }
            }
        }
    }
    if(M%4) {
        // x..y..z..y..x -> repeat
        cout << index[0] << ' ';
        int idx = 1;
        bool inverse = 0;
        FOR(i, 0, M) {
            if(idx == 2 || idx == 0) inverse = !inverse;
            cout << index[idx] << ' ';
            idx += (inverse ? -1 : 1);
        }
       
    } else {
        // y..x..y..z..y -> repeat
        cout << index[1] << ' ';
        FOR(i, 0, M / 2)
            cout << (index[(i&1) ? 2 : 0]) << ' ' << index[1] << ' ';
    }
    cout << '\n';


    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(1);

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}