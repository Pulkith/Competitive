/**
 * author: DespicableMonkey
 * created: 06.30.2021 14:40:27
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

const int MX = (1e5+5); //Check the limits idiot
int N, K, P;
int a[MX];


void test_case() {
    cin >> N >> K >> P;
    FOR(i, 0, N) cin >> a[i];
    vt<vt<int>> sets(K, vt<int>()); vt<pr<int, int>> even_pairs, odd_pairs;
    int ptr = 0, used = 0;
    FOR(i, 0, N) {
        if(a[i] & 1 && ptr < (K - P))
            sets[ptr++].pb(a[i]);
        else if(a[i] & 1){
            if(used) odd_pairs.back().s = a[i]; else odd_pairs.pb({a[i], -1});
            used = !used;
        }
        else
            even_pairs.pb({a[i], -1});
    }
    if(ptr != (K - P) || used || sz(even_pairs) + sz(odd_pairs) < P) putr("NO");
    even_pairs.insert(even_pairs.end(), odd_pairs.begin(), odd_pairs.end());
    if(P == 0) {
        for(auto pr : even_pairs) {
            if(pr.f & 1)
                sets[0].pb(pr.s);
            sets[0].pb(pr.f);
        }
    } else {
        int have = sz(even_pairs);

        FOR(i, 0, P) {
            if(i == P - 1)
                for(auto pair : even_pairs){
                    sets[ptr].pb(pair.f);
                    if(pair.f & 1) sets[ptr].pb(pair.s);
                }
            else {
                if(even_pairs.back().f & 1)
                    sets[ptr].pb(even_pairs.back().s);
                sets[ptr++].pb(even_pairs.back().f);
                even_pairs.pop_back();
            }

        }

    }
    put("YES");
    FOR(i, 0, K) {
        cout << sz(sets[i]) << " ";
        FOR(j, 0, sz(sets[i]))
            cout << sets[i][j] << " \n"[j == sz(sets[i]) - 1];
    }

    
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