/**
 * author: DespicableMonkey
 * created: 10.16.2021 06:58:09
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

const int MX = (2e5+43);
int N;
int a[MX];


void test_case() {
    cin >> N;
    map<int, pr<int, int>> Xpts, Ypts;
    FOR(i, 0, N) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        ++Xpts[X1].f;
        ++Xpts[X2+1].s;
        ++Ypts[Y1].f;
        ++Ypts[Y2+1].s;
    }
    FOR(j, 0, 2) {
        int l = 0, r = N;
        int best = 0, bv = 0;
        auto arr = (j) ? Ypts : Xpts;
        for(auto it = arr.begin(); it != arr.end(); ++it) {
            auto X = it->f; auto Y = it->s;
            r -= Y.f;
            l += Y.s;
            if(N-r >= r) {
                best = X;
                bv = N-r;
                ++it;
                while(it != arr.end()) {
                    auto Y1 = it->s;
                    if(Y1.s) {
                        if(r > l)
                            best = it->f - 1;
                        break;
                    }
                    r -= Y1.f;
                    if(cmax(bv, N-r)) best = it->f;
                    ++it;   
                }
                break;
            }
        }
        cout << best << ' ';
    }
    cout << '\n';
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