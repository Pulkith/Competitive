/**
 * author: DespicableMonkey
 * created: 09.04.2021 12:02:03
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

const int MX = (3e2+43); //Check the limits idiot
int N;
int a[MX][MX];
int ff1vis[MX][MX];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL
set<pr<int, int>> vis[MX][MX];

int ff1(int i, int j, int index) {
    int cur = 1;
    ff1vis[i][j] = index;
    FOR(k, 0, 4){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni >= 0 && ni < N && nj >= 0 && nj < N && !ff1vis[ni][nj] && a[ni][nj] == a[i][j])
            cur += ff1(ni, nj, index);
    }
    return cur;
}

int ff2(int i, int j, int c1, int c2) {
    vis[i][j].insert({c1, c2});
    int cur = 1;
    FOR(k, 0, 4) {
        int di = i + dx[k];
        int dj = j + dy[k];
        if(di >= 0 && di < N && dj >= 0 && dj < N && 
            (a[di][dj] == c1 || a[di][dj] == c2) &&
            vis[di][dj].find({c1, c2}) == vis[di][dj].end()
            )
                cur += ff2(di, dj, c1, c2);
    }
    return cur;
}

void test_case() {
    cin >> N;
    FOR(i, 0, N)
        FOR(j, 0, N)
            cin >> a[i][j];
    int ans1 = 0, ans2 = 0;
    int index = 1;
    FOR(i, 0, N)
        FOR(j, 0, N)
            if(!ff1vis[i][j])
                cmax(ans1, ff1(i, j, index++));
    FOR(i, 0, N) 
        FOR(j, 0, N)
            FOR(k, 0, 4) {
                int di = i + dx[k];
                int dj = j + dy[k];
                if(di >= 0 && di < N && dj >= 0 && dj < N){
                    int c1 = a[di][dj];
                    int c2 = a[i][j];
                    if(c1 > c2) swap(c1, c2);
                    if(vis[i][j].find({c1, c2}) == vis[i][j].end())
                        cmax(ans2, ff2(i, j, c1, c2));
                }
            }

    put(ans1);
    put(ans2);

    
}

int main () {
    CP::IO().SetIO("multimoo")->FastIO().Input(0);

    my_brain_hurts

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }

    return 0;
}
