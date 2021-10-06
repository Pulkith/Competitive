/**
 * author: DespicableMonkey
 * created: 09.25.2021 11:41:44
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
int N, M;


void test_case() {
    cin >> N >> M;
    vector<vector<int>> g(N, vector<int>(M));
    map<int, multiset<int>> mp;
    FOR(i, 0, M) {
        int x; cin >> x;
        mp[x].insert(1);
    }

    FOR(i, 0, N) FOR(j, 0, M) cin >> g[i][j];

    ll ans = 0;

    FOR(i, 0, N) {
        map<int, multiset<int>> nxt_mp;
        priority_queue<int> rem;
        FOR(j, 0, M) {
            if(sz(mp[g[i][j]]) > 0) {
                int e = *(mp[g[i][j]].begin());
                mp[g[i][j]].erase(mp[g[i][j]].begin());
                nxt_mp[g[i][j]].insert(e);
                g[i][j] = -1;
            }
        }

       for(auto c : mp)
            for(auto k : c.s)
                rem.push(k);

        FOR(j, 0, M) {
            if(g[i][j] != -1) {
                int t = rem.top();
                rem.pop();
                ans += !t;
                nxt_mp[g[i][j]].insert(0);
            }
        }
        mp = nxt_mp;
    }

    put(ans);
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);
    CP::IO().SetIO()->FastIO().Input(1);
    CP::IO().setOut("ans1.txt");

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        cout << "Case #" << tt << ": ";
        test_case();
    }

    return 0;
}
