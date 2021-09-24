/**
 * author: DespicableMonkey
 * created: 09.18.2021 12:08:22
 * Potatoes FTW!
 **/ 

#include <algorithm>
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
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (3e5+43); //Check the limits idiot
int D, N, K;


void test_case() {
    cin >> D >> N >> K;
    vt<vt<int>> H(N, vt<int>(3));

    FOR(i, 0, N)
        cin >> H[i][2] >> H[i][0] >> H[i][1];
    vt<ll> ans(D + 1);

    vt<vt<int>> start(D+2), end(D+2);

    FOR(i, 0, N) {
        start[H[i][0]].pb(i);
        end[H[i][1]].pb(i);
    }

    ll curmax = 0;
    set<pr<int, int>> current;
    set<pr<int, int>> other;

    FORE(i, 1, D) {
        if(sz(start[i])) {
            FOR(j, 0, sz(start[i])) {
                if(sz(current) < K) {
                    curmax += H[start[i][j]][2];
                    current.insert({H[start[i][j]][2], start[i][j]});
                }
                else if(H[start[i][j]][2] > (*current.begin()).f) {
                    auto k = *current.begin();
                    other.insert({k.f, k.s});
                    curmax -= k.f;
                    current.erase(k);
                    current.insert({H[start[i][j]][2], start[i][j]});
                    curmax += (H[start[i][j]][2]);
                } 
                else {
                    other.insert({H[start[i][j]][2], start[i][j]});
                }
            }
        }

        ans[i] = curmax;

        if(sz(end[i])) {
            FOR(j, 0, sz(end[i])) {
                if(current.find({H[end[i][j]][2], end[i][j]}) != current.end()) {
                    curmax -= H[end[i][j]][2];
                    current.erase(current.lower_bound({H[end[i][j]][2], end[i][j]}));
                } else {
                    other.erase(other.lower_bound({H[end[i][j]][2], end[i][j]}));
                }
            }
        }

        while(sz(current) < K && sz(other)) {
            auto bck = --other.end();
            current.insert(*bck);
            curmax += (*bck).f;
            other.erase(bck);
        }
    }
    put(*max_element(ans.begin(), ans.end()));

    
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
