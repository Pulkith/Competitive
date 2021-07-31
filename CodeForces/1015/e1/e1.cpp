/**
 * author: DespicableMonkey
 * created: 07.16.2021 23:37:47
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <numeric>
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

const int MX = (1000+43); //Check the limits idiot
int N, M;
string a[MX];
bool good[MX][MX];


void test_case() {
    cin >> N >> M;
    FOR(i, 0, N) {
        cin >> a[i];
        FOR(j, 0, M) good[i][j] = (a[i][j] == '.');
    }
    vt<vt<int>> ans;

    FOR(i, 1, N-1) {
        FOR(j, 1, M-1) {
            if(a[i][j] == '*') {
                int span = 1;
                while(j-span >= 0 && j+span < M && i-span >= 0 && i+span < N && a[i][j+span] == '*' && a[i][j-span] == '*' && a[i+span][j] == '*' && a[i-span][j] == '*') {
                    good[i][j+span] = good[i][j-span] = good[i+span][j] = good[i-span][j] = 1;
                    ++span;
                } 

                if(--span > 0) {
                    good[i][j] = 1;
                    ans.pb({i+1, j+1, span});
                }
            }
        }
    }
    

    int sum = 0;
    FOR(i, 0, N) FOR(j, 0, M) sum += good[i][j];
    if(sum != N * M) putr(-1);

    put(sz(ans));
    FOR(i, 0, sz(ans))
        cout << ans[i][0] << ' '<< ans[i][1] << ' ' << ans[i][2] << '\n';
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
