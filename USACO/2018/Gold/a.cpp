/**
 * author: DespicableMonkey
 * created: 09.28.2021 23:14:45
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
int N, B;
pr<int, int> tiles[MX];
pr<int, int> boots[MX];
int prv[MX], nxt[MX];
int loc[MX];
int boot_id[MX];

template<class T> struct LinkedList {
    int prv[MX], nxt[MX];
    T dat[MX];
    int cur_index = 0;
    LinkedList() {
        FOR(i, 0, N) prv[i] = nxt[i] = -1;
    }
    void insert(T obj, int index) {
        if(index > 0) nxt[index-1] = cur_index;
        if(index < cur_index) prv[index+1] = cur_index;
        dat[cur_index] = obj;
        ++cur_index;
    }
    T get(int index)  return 
};

void test_case() {
    cin >> N >> B;
    FOR(i, 0, N) {
        cin >> tiles[i].f;
        tiles[i].s = i;
    }
    FOR(i, 0, B) {
        cin >> boots[i].f >> boots[i].s;
        boot_id[i] = i;
    }
    sort(tiles, tiles+N);
    sort(boots, boots + B, [&](int l, int r) -> bool {
        return boots[l].f < boots[r].f;
    });
    FOR(i, 0, N) {
        nxt[i] = prv[i] = -1;
        loc[tiles[i].s] = i;
    }
    FOR(i, 0, N) {
        if(tiles[i].s > 0) prv[i] = loc[tiles[i].s - 1];
        if(tiles[i].s < N-1) nxt[i] = loc[tiles[i].s + 1];  
    }
    set<int> poss;
    int cur_tile = N-1;
    vt<int> ans(N);
    int mx_distance = 0;
    FOR(i, 1, N) cmax(mx_distance, tiles[i].f - tiles[prv[i]].f );
    for(int cur_boot = B-1; cur_boot >= 0; --cur_boot) {
        while(tiles[cur_tile].f > boots[B-1].f && cur_tile > 0) {
            if(cur_tile > 0) nxt[cur_tile - 1] = nxt[cur_tile];
            if(cur_tile < N-1) prv[cur_tile = 1] = prv[cur_tile];
            --cur_tile;
        }
        // ans[cur_boot] = boots[i].f < 
    }
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
