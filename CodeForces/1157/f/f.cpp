/**
 * author: DespicableMonkey
 * created: 07.05.2021 23:43:23
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <cassert>
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
    map<int, int> mp;
    FOR(i, 0, N) {
        cin >> a[i];
        ++mp[a[i]];
    }
    sort(a, a+N);
    vt<int> ans;
    for(auto p : mp) {
        if(p.s > sz(ans)) {
            ans.clear();
            FOR(i, 0, p.s)
                ans.pb(p.f);
        }
    }

    vt<int> cur_front, cur_back;

    bool add = 1;

    auto att = [&]() {
        if(sz(cur_front) + sz(cur_back) > sz(ans)) {
            ans = cur_front;
            reverse(cur_back.begin(), cur_back.end());
            for(auto c : cur_back) ans.pb(c);
        }
        cur_back.clear();
        cur_front.clear();
        add = 1;
    };
    for (auto it = mp.begin(); it != mp.end();) {
        bool go = 1;
        auto& ele = *it;
        if (!ele.s)
            assert(0);
        else {
            if(add) {
                add = 0;
                FOR(i, 0, ele.s) cur_front.pb(ele.f);
            } else {
                assert(sz(cur_front));

                if(ele.f-1 == cur_front.back() && ele.s > 1){
                    FOR(i, 1, ele.s) cur_front.pb(ele.f);
                    cur_back.pb(ele.f);
                } else {
                    if(ele.f-1 == cur_front.back())
                        FOR(i, 0, ele.s) cur_front.push_back(ele.f);

                    att();
                    auto nex = it; ++nex;
                    if(nex != mp.end() && (*nex).f == ele.f + 1) go = 0;
                }
            }
        }

        if(go) ++it;
    }
    att();
    put(sz(ans));
    outv(ans);
    
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
