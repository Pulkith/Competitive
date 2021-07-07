/**
 * author: DespicableMonkey
 * created: 07.03.2021 13:14:34
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

const int MX = (2e5+5); //Check the limits idiot


template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0; T comb(T a, T b) { return a+b; } 
    int n; vector<T> seg;
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
    int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
        if (r < lo || val > seg[ind]) return -1;
        if (l == r) return l;
        int m = (l+r)/2;
        int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
        return first_at_least(lo,val,2*ind+1,m+1,r);
    }
};



void test_case() {

    vt<Seg<int>> trees(26);

    string s; cin >> s;

    int N = sz(s);
    FOR(i, 0, 26) trees[i].init(N + 1);
    FORE(i, 1, N) trees[s[i - 1] - 'a'].upd(i, 1);

    int Q; cin >> Q;
    while(Q--) {
        int op; cin >> op;
        if(op == 1) {
            int pos; char c;
            cin >> pos >> c;
            int char_before = s[pos - 1];
            s[pos - 1] = c;

            trees[char_before - 'a'].upd(pos, 0);
            trees[c - 'a'].upd(pos, 1);
        } else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            FOR(i, 0, 26) ans += !!(trees[i].query(l, r));
            put(ans);
        }
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