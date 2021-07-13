/**
 * author: DespicableMonkey
 * created: 07.10.2021 10:35:06
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <cstdio>
#include <functional>
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

const int MX = (3e5+43); //Check the limits idiot


void test_case() {
    ll N, K;
    cin >> N >> K;
    vt<pr<ll, ll>> hold(K);
    vt<ll> a(K), t(K);
    FOR(i, 0, K){
        cin >> hold[i].f; --hold[i].f;
    }
    FOR(i, 0, K) cin >> hold[i].s;
    sort(all(hold));

    FOR(i, 0, K) a[i] = hold[i].f;
    FOR(i, 0, K) t[i] = hold[i].s;


    ll bef = (2e9);
    bool before = 0;
    ll index = 0;

    multiset<ll> pq;
    FOR(i, 0, N) 
        if(i == a[index])
            pq.insert(t[index] + a[index]), ++index;

    index = 0;
    ll bef_add = 0;
    FOR(i, 0, N) {
        if(index < K && a[index] == i) {
            before = 1;
            if((t[index]) < bef + bef_add) {
                bef_add = 0;
                bef = t[index];
            }
            pq.erase(pq.lower_bound(t[index] + a[index]));
            ++index;
        } 

        if(sz(pq)) {
            cout << min(bef + bef_add, *pq.begin() - i) << ' ';
        }
        else {
            assert(before);
            cout << bef + bef_add << ' ';

        }

        ++bef_add;
    }

    cout << '\n';
    

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
