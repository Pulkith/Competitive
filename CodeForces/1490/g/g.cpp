/**
 * author: DespicableMonkey
 * created: 06.23.2021 23:07:03
 * Potatoes FTW!
 **/ 

#include <algorithm>
#include<bits/stdc++.h>
#include <ios>
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

#define ll long long// using ll = int64_t;
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T, class U> T cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

inline namespace CP {
     inline namespace Output {
        string operator+(string str, int num){return str + ts(num);}
        string operator+(int num, string str) { return ts(num) + str; }
        //string to_string(const char* s) { return string(s);}
        #if !defined LOCAL
            #define dbg(...) ;
            #define print_test_case(...) ;
            #define debug_active 0
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T output) { cout << output << '\n'; }
        #define putr(__output) return void(putr(__output))
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
int N, Q;
int a[MX];

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = (1e18); T comb(T x, T y) { return min(x,y); }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) { // min on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

void test_case() {
    cin >> N >> Q;
    FOR(i, 0, N) cin >> a[i];
    vt<ll> values(N);
    ll sum = 0;
    FOR(i, 0, N) values[i] = sum += a[i];
    ll maxx = *max_element(all(values));

    vt<pr<ll, ll>> sorted_values(N);
    FOR(i, 0, N) sorted_values[i] = {values[i], i};
    sort(all(sorted_values));

    Seg<ll> st;
    st.init(N+1);

    FORE(i, 1, N)
        st.upd(i, sorted_values[i-1].s);

    bool nonincreasing = (values[N-1] <=0);

    while(Q--) {
        ll query; cin >> query;
        if(query > maxx && nonincreasing) {
            cout << -1 << " \n"[!Q];
            continue;
        }

        ll cycles_need = (query <= maxx) ? 0 : (query - maxx) / sum;
        if(cycles_need * sum + maxx < query) ++cycles_need;
        assert(cycles_need * sum + maxx >= query);

        ll need_min = (query - cycles_need * sum);
        pr<ll, ll> find = {need_min, -1};
        auto partition_index = lower_bound(sorted_values.begin(), sorted_values.end(), find);
        ll minn_index = st.query(partition_index - sorted_values.begin() + 1, N);
        cout << minn_index + cycles_need * N << " \n"[!Q];

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