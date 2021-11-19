/**
 * author: DespicableMonkey
 * created: 11.19.2021 00:25:52
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
    FOR(i, 0, N) cin >> a[i];
    vt<int> last(N);
    int ans1 = 0;
    FOR(i, 0, N) {
        last[i] = i;
        ans1 += last[i] != a[i];
    }
    //0 1 0 1 2 3
    put(ans1);
    FORE(i, 2, N) {
        int anscur = N;
        int idx = 0;
        FOR(j, 0, N) {
            if(last[j] != 0) {
                int ls = -1, ans = 0;
                FOR(k, 0, N) {
                    if(k == j) {
                        ls = 0;
                        ans += 0 != a[j];
                    } else {
                        if(last[k] == 0) ans += (a[k] != last[k]);
                        else ans += ls+1 != a[k];
                        ls = (last[k] == 0 ? 0 : ls + 1);
                    }
                }
                if(cmin(anscur, ans)) {
                    idx = j;
                }
            }
        }

        last[idx] = 0;
        FOR(j, idx+1, N) {
            if(last[j] == 0) break;
            last[j] = last[j-1] + 1;
        }

        put(anscur);
    }
    
}
/*
3 8 9 15 17 31 41
3 1 2 1 3 3 6
*/
int main () {
    CP::IO().SetIO("taming")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
