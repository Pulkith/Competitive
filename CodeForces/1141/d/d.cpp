/**
 * author: DespicableMonkey
 * created: 08.24.2021 22:52:37
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
            if(sz(__t) && !debug_active) setIn(__s), setOut(__t);
            else if (sz(__s) && !debug_active) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+43); //Check the limits idiot
int N;
map<char, vt<int>> lefts, rights;


void test_case() {
    cin >> N;
    string l, r;
    cin >> l >> r;
    FOR(i, 0, N) lefts[l[i]].pb(i+1);
    FOR(i, 0, N) rights[r[i]].pb(i+1);
    vt<pr<int, int>> ans;
    for(auto& [val, ind] : lefts) {
        if(val != '?' && rights[val].size() > 0) {
            while(sz(ind) && sz(rights[val])) {
                ans.pb({ind.back(), rights[val].back()});
                ind.pop_back();
                rights[val].pop_back();
            }
        }
    }

    vt<vt<int>> rem(2, vt<int>());
    FOR(j, 0, 2) for(auto e : (j?rights:lefts)) if(e.f != '?') FOR(i, 0, sz(e.s)) rem[j].pb(e.s[i]);
    while(sz(lefts['?']) && sz(rem[1])) {
        ans.pb({lefts['?'].back(), rem[1].back()});
        lefts['?'].pop_back();
        rem[1].pop_back();
    }
    while(sz(rights['?']) && sz(rem[0])) {
        ans.pb({rem[0].back(), rights['?'].back()});
        rights['?'].pop_back();
        rem[0].pop_back();
    }

    while(sz(lefts['?']) && sz(rights['?'])){
        ans.pb({lefts['?'].back(), rights['?'].back()});
        lefts['?'].pop_back();
        rights['?'].pop_back();
    }

    put(sz(ans));
    for(auto e : ans)
        cout << e.f << " " << e.s << '\n';
    
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
