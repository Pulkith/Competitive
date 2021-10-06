/**
 * author: DespicableMonkey
 * created: 09.29.2021 00:49:13
 * Potatoes FTW!
 **/ 

#include <algorithm>
#include<bits/stdc++.h>
#include <iterator>
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
int N, Q;
ll a[MX], prefix[MX];


void test_case() {
    cin >> N >> Q;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    sort(a, a+N);
    FOR(i, 0, N) prefix[i] = a[i] + (i > 0 ? prefix[i-1] : 0);
    set<ll> possible;
    function<void(int, int)> merge = [&](int l, int r) {
        possible.insert(prefix[r] - (l == 0 ? 0 : prefix[l-1]));
        dbg(prefix[r], prefix[l]);
        if(l == r) return;
        dbg(l, r);
        int mid = (a[l] + a[r]) / 2;
        auto bound = upper_bound(a + l, a+r+1, mid);
        int new_split = bound - a;
        if(new_split <= r && new_split > l) merge(new_split, r);
        --new_split;
        if(new_split >= l && new_split < r) merge(l, new_split);
    };

    merge(0, N-1);  

    while(Q--) {
        int q; cin >> q;
        cout << (has(possible, q) ? "Yes" : "No") << '\n';
    }  
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
