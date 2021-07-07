/**
 * author: DespicableMonkey
 * created: 06.30.2021 17:17:26
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <numeric>
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

const int MX = (50+5); //Check the limits idiot
int N, M;
string a[MX];
string ff_copy[MX];

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL
int prefix_x[MX][MX], prefix_y[MX][MX];
set<pr<int, int>> pts;
void ff(int x, int y) {
    prefix_x[x][y] = prefix_y[x][y] = 1;
    pts.insert({x, y});
    ff_copy[x][y] = 'W';

    FOR(i, 0, 4) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x > 0 && new_x <= N && new_y > 0 && new_y <= M && ff_copy[new_x][new_y] == 'B')
            ff(new_x, new_y);
    }
}

bool chk(int i, int j) {
    auto path_exists =[&](pr<int, int> x, pr<int, int> y) -> bool {
        


        if(abs(prefix_y[x.f][x.s] - prefix_y[y.f][x.s]) == abs(y.f - x.f) ) {
            if(abs(prefix_x[y.f][x.s] - prefix_x[y.f][y.s]) == abs(y.s - x.s)) return 1;
        }  

        if(abs(prefix_y[x.f][y.s] - prefix_y[y.f][y.s]) == abs(y.f - x.f)) {
            if(abs(prefix_x[x.f][x.s] - prefix_x[x.f][y.s]) == abs(y.s - x.s)) return 1;
        }

        return 0;
    };

    for(auto v : pts)
        if(v.f != i || v.s != j)
            if(!path_exists(v, {i, j}))
                return 0;
    return 1;
}

void test_case() {
    cin >> N >> M;
    FORE(i, 1, N){
       cin >> a[i];
       a[i] = " " + a[i];
       ff_copy[i] = a[i];
    }


    bool ok = 1;
    FORE(i, 1, N){
        FORE(j, 1, M){
            if(ff_copy[i][j] == 'B') {
                if(!ok)
                    putr("NO");
                ok = 0;
                ff(i, j);

            }
        }
    }
    FORE(i, 1, N) 
        FORE(j, 2, M)
            prefix_x[i][j] = prefix_x[i][j] + prefix_x[i][j-1];

    FORE(j, 1, M)
        FORE(i, 2, N)
            prefix_y[i][j] = prefix_y[i-1][j] + prefix_y[i][j];

    FORE(i, 1, N) {
        FORE(j, 1, M) {
            if(a[i][j] == 'B') {
                if(!chk(i, j)) putr("NO");
            }
        }
    }

    putr("YES");
    
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