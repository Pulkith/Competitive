/**
 * author: DespicableMonkey
 * created: 11.27.2021 16:48:05
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

const int MX = (1e3+43);
int N, M;
int a[MX][MX], jC[MX][MX], fC[MX][MX];

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

void test_case() {
    cin >> N >> M;
    pr<int, int> joe, f;
    FOR(i, 0, N) {
        string s; cin >> s;
        FOR(j, 0, M) {
            if(s[j] == '#') a[i][j] = -1;
            if(s[j] == 'F') {
                a[i][j] = -1;
                f = {i, j};
            }
            if(s[j] == 'J') {
                a[i][j] = -1;
                joe = {i, j};
            }
        }
    }

    queue<pr<int, int>> jBFS, fBFS;
    jBFS.push(joe);
    fBFS.push(f);

    while(sz(jBFS)) {
        jC[jBFS.front().f][jBFS.front().s] = abs(joe.f - jBFS.front().f) + abs(joe.s - jBFS.front().s) + 1;
        for(int i = 0; i < 4; ++i) {
            int u = jBFS.front().f + dx[i], v = jBFS.front().s + dy[i];
            if(u >= 0 && u < N && v >= 0 && v < M && jC[u][v] == 0 && a[u][v] != -1)
                jBFS.push({u, v});
        }
        jBFS.pop();
    }

    while(sz(fBFS)) {
        fC[fBFS.front().f][fBFS.front().s] = abs(f.f - fBFS.front().f) + abs(f.s - fBFS.front().s) + 1;
        for(int i = 0; i < 4; ++i) {
            int u = fBFS.front().f + dx[i], v = fBFS.front().s + dy[i];
            if(u >= 0 && u < N && v >= 0 && v < M && fC[u][v] == 0 && a[u][v] != -1)
                fBFS.push({u, v});
        }
        fBFS.pop();
    }
    
    int ans = (1e9);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if(i == 0 || i == N-1 || j == 0 || j == M-1)
                if(jC[i][j] > 0 && (fC[i][j] == 0 || jC[i][j] < fC[i][j]))
                    cmin(ans, jC[i][j]);
    put(ans == (1e9) ? "IMPOSSIBLE" : ts(ans));
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
