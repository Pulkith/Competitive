/**
 * author: DespicableMonkey
 * created: 07.23.2021 12:53:34
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

const int MX = (1e2+43); //Check the limits idiot
int N, M, K;
int a[MX][MX];
string ans[MX];


void test_case() {
    cin >> N >> M >> K;
    FOR(i, 0, N) FOR(j, 0, M) a[i][j] = 0;
    FOR(i, 0, N) ans[i] = string(M, ' ');
    if(N&1) for(int i = 0; i < M; i += 2, --K) a[0][i] = 1, a[0][i+1] = -1;
    for(int i = N&1; i < N && K > 0; i += 2) {
        for(int j = 0; j < M - (M&1) && K > 0; j += 2, K -= 2) {
            a[i][j] = a[i+1][j] = 1;
            a[i][j+1] = a[i+1][j+1] = -1;
        }
    }

    if(K != 0) putr("NO");
    put("YES");

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if(a[i][j] == 0) a[i][j] = 2, a[i+1][j] = -1;

    FOR(i, 0, N) {
        FOR(j, 0, M) {
            set<char> used;
            if(a[i][j] == 1) {
                if(i > 0) used.insert(ans[i-1][j]), used.insert(ans[i-1][j+1]);
                if(j > 0) used.insert(ans[i][j-1]);
                if(j < M-2 && ans[i][j+2] != ' ') used.insert(ans[i][j+2]);
                char cur = 'a'; while(used.find(cur) != used.end()) ++cur;
                ans[i][j] = ans[i][j+1] = cur;
            } else if(a[i][j] == 2) {
                if(i > 0) used.insert(ans[i-1][j]);
                if(j > 0) used.insert(ans[i][j-1]);
                char cur = 'a'; while(used.find(cur) != used.end()) ++cur;
                ans[i][j] = ans[i+1][j] = cur;
            }
        }
    }

    FOR(i, 0, N) 
        FOR(j, 0, M)
            cout << ans[i][j] << (j == M-1 ? "\n" : "");


    
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
