/**
 * author: DespicableMonkey
 * created: 11.09.2021 00:26:28
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

const int MX = (100+43);
int N, K, len;

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

set<pr<int,int>> change;
int a[MX][10], cur[MX][10];

void ff(int u, int v, int c, bool real) {
    auto& mp = (real ? a : cur);
    mp[u][v] = 0;  ++len;
    FOR(i, 0, 4) {
        int du = u + dx[i], dv = v + dy[i];
        if(du >= 0 && du < N && dv >= 0 && dv < 10 && mp[du][dv] == c)
            ff(du, dv, c, real);
    }
}

void test_case() {
    cin >> N >> K;

    FOR(i, 0, N) {
        string s; cin >> s;
        FOR(j, 0, 10) {
            cur[i][j] = a[i][j] = s[j] - '0';
            if(a[i][j])
                change.insert({i, j});
        }
    }

    while(sz(change) > 0) {
        vt<pr<int, int>> rem;
        for(auto p : change){
            if(cur[p.f][p.s]) {
                len = 0; ff(p.f, p.s, cur[p.f][p.s], 0);
                if(len >= K) rem.pb({p.f, p.s});
            }
        }
        change.clear();
        for(auto p : rem) ff(p.f, p.s, a[p.f][p.s], 1);
        FOR(i, 0, 10) {
            int ind = N-1;
            for(int j = N-1; j >= 0; --j) {
                if(a[j][i]) {
                    if(ind != j) change.insert({ind, i});
                    swap(a[ind][i], a[j][i]); 
                    cur[ind][i] = a[ind][i];
                    cur[j][i] = a[j][i];
                    --ind;
                } 
            }
        }
    }
    FOR(i, 0, N) FOR(j, 0, 10) cout << a[i][j] << (j == 9 ? "\n" : "");
    
}

int main () {
    CP::IO().SetIO("mooyomooyo")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
