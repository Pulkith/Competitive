/**
 * author: DespicableMonkey
 * created: 07.10.2021 23:54:05
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

const int MX = (1e5+43); //Check the limits idiot

int N, C;

struct pred { bool operator()(const pair<int, int> &l, const pair<int, int> &r) { 
    return l.second < r.second; } };

void test_case() {
    vector<pr<int, int>> segs;
    cin >> N >> C;
    ll ans = 0;
    FOR(i, 0, N) {
        int x, y;
        cin >> x >> y;
        if(y > x + 1) segs.pb({x, y});
        ++ans;
    }

    FOR(i, 0, min(C, 10000)) {
        int maxx = -1, index = -1;

        vt<int> mp(10005);
        for(auto seg : segs){
            if(seg.f < 0) continue;;
            ++mp[seg.f + 1]; --mp[seg.s];
        }
        for(int j = 1; j < 10000 + 2; ++j) {
            mp[j] += mp[j-1];
            if(mp[j] > maxx) {
                maxx = mp[j];
                index = j;
            }
        }

        ans += maxx;
        int X = index;
        int S = sz(segs);
        FOR(j, 0, S) {
            if(segs[j].f < X && segs[j].s > X) {
                if(segs[j].f + 1 < X) segs.pb({segs[j].f, X});
                if(X+1 < segs[j].s) segs.pb({X, segs[j].s});
                segs[j].f = -1, segs[j].s = -1;
            }
        }

    }

    put(ans);
    
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
