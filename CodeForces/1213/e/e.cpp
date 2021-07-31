/**
 * author: DespicableMonkey
 * created: 07.15.2021 22:58:43
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
    string s, t, ans ="";
    cin >> s >> t;
    vector<char> lets = {'a', 'b', 'c'};
    if(t[0] == s[0]) {
        int index = lets[0] == s[0] ? 0 : (lets[1] == s[0] ? 1 : 2);
        FOR(i, 0, 3) if(i != index) ans += string(N, i + 'a');
        ans = string(N, index + 'a');
    }
    else if(t[1] == s[1]) {
        int index = lets[0] == s[1] ? 0 : (lets[1] == s[1] ? 1 : 2);
        ans = string(N, index + 'a');
        FOR(i, 0, 3) if(i != index) ans += string(N, i + 'a');
    } else {
        vt<string> poss = {"abc", "acb", "bac", "bca", "cab", "cba"};
        FOR(i, 0, sz(poss)) {
            bool ok = 1;
            FOR(j, 0, 2) ok &= (poss[i].substr(j, 2) != s);
            FOR(j, 0, 2) ok &= poss[i].substr(j, 2) != t;
            if(ok) {
                ans = string(N, poss[i][0]) + string(N, poss[i][1]) + string(N, poss[i][2]);
                break;
            }
        }
    }

    put(ans);
    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    //cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}

// first 2 are same: 2nd letter, 3rd letter, 1st letter
// last 2 are the same:  last letter, 1st letter, 2nd letter
// ab ca aaaacccbbb
// ba ac aaaabbbbcccc
