/**
 * author: DespicableMonkey
 * created: 06.28.2021 12:08:27
 * Potatoes FTW!
 **/ 

#include <algorithm>
#include<bits/stdc++.h>
#include <queue>
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

const int MX = (2e5+5); //Check the limits idiot
int N;


void test_case() {
    cin >> N;
    vt<vt<int>> a(7, vt<int>());
    vt<pr<int, string>> m;
    FOR(i, 0, N){
        int cost;
        string let;
        cin >> cost >> let;
        if(sz(let) == 1) {
            if(let == "A") a[0].push_back(cost);
            else if(let == "B") a[1].pb(cost);
            else a[2].pb(cost);
        }
        else if(sz(let) == 2) {
            if(let == "AB") a[3].pb(cost);
            else if(let == "BC") a[4].pb(cost);
            else if(let == "AC") a[5].pb(cost);
        }
        else a[6].pb(cost);
        m.pb({cost, let});
    }
    ll cost = (1e9);
    if(sz(a[6])) cost = *min_element(a[6].begin(), a[6].end());
    if(sz(a[0]) && sz(a[1]) && sz(a[2])) {
        ll cur = 0;
        FOR(i, 0, 3)
            cur += *min_element(a[i].begin(), a[i].end());
        cmin(cost, cur);
    }

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if(i != j) {
                set<char> cur;
                for(auto c : m[i].s)
                    cur.insert(c);
                for(auto c : m[j].s)
                    cur.insert(c);
                if(sz(cur) == 3)
                    cmin(cost, m[i].f * 1LL + m[j].f);
            }
        }
    }
    int INF = (1e9);
    put(cost == INF ? -1 : cost);

   
    
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