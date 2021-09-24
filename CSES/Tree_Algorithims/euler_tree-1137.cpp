/**
 * author: DespicableMonkey
 * created: 09.18.2021 19:49:03
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
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return a+b; } 
    int n; vt<T> seg;
    void init(int _n) { // upd, query also work if n = _n
        for (n = 1; n < _n; ) n *= 2; 
        seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) { // any associative op on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

const int MX = (2e5+43); //Check the limits idiot
int N, Q;
int val[MX];
Seg<ll> seg;
vt<int> adj[MX];
int st[MX], en[MX];
int cur = 0;

void dfs(int u, int p) {
    st[u] = cur++;
    for(auto v : adj[u]) {
        if(v != p) {
            dfs(v, u);
        }
    }
    en[u] = cur - 1;
}

void test_case() {
    cin >> N >> Q;
    FOR(i, 0, N) cin >> val[i];
    FOR(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }


    dfs(1, 0);

    seg.init(N+1);
    FORE(i, 1, N) {
        seg.upd(st[i], val[i-1]);
    }

    while(Q--) {
        int o; cin >> o;
        if(o == 1) {
            int s, x; cin >> s >> x;
            seg.upd(st[s], x);
        } else {
            int u; cin >> u;
            put(seg.query(st[u], en[u]));
        }
    }
    
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
