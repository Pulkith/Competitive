/**
 * author: DespicableMonkey
 * created: 06.15.2021 19:44:39
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
#endif

using namespace std;

typedef int64_t ll;

#define pb push_back
#define f first
#define s second
#define x first
#define y second

#define my_brain_hurts int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T, class U> T cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

[[maybe_unused]] const int MOD = 1'000'000'007;
[[maybe_unused]] const double EPS = (1e-9);
[[maybe_unused]] const int INF = 2'000'000'000; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
[[maybe_unused]] const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

inline namespace CP {
    inline namespace IO {
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void FastIO() {
            cin.tie(nullptr)->sync_with_stdio(0);
            std::cout << std::fixed << std::showpoint;
            std::cout << std::setprecision(14);
        }
        void SetIO(string s = "", string t = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if(sz(t)) setIn(s), setOut(t);
            else if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
        }
    }
    inline namespace Output {
        bool debug = 0;
        string operator+(string str, int num){return str + ts(num);}
        string operator+(int num, string str) { return str + ts(num); }
        string to_string(const char* s) { return string(s);}
        #if !defined LOCAL
            #define dbg(...)
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T s) { cout << s << '\n'; }
        #define putr(s) return put(s), 0
    }
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (1000+7); //Check the limits idiot
int N, M;
char a[MX][MX];
bool vis[MX][MX]{{false}};
pr<int, int> from[MX][MX];
string dir[4] = {"D", "R", "U", "L"};
string bfs(int fir, int sec) {
    queue<pr<int, int>> cur;
    vis[fir][sec] = 1;
    cur.push({fir, sec});

    while(!cur.empty()) {
        auto top = cur.front();
        cur.pop();
        if(a[top.f][top.s] == 'B'){
            string ans = "";
            int curx = top.f, cury = top.s;

            while(curx != fir || cury != sec) {
                int frx = from[curx][cury].f, fry = from[curx][cury].s;
                if(frx != curx) ans += (frx < curx ? "D" : "U");
                else ans += (fry < cury ? "R" : "L");
                curx = frx;
                cury = fry;
            }   
            reverse(ans.begin(), ans.end());
            return ans;
        }

        FOR(i, 0, 4) {
            int x = top.f + dx[i];
            int y = top.s + dy[i];

            if(x >= 0 && x < N && y >= 0 && y < M && !vis[x][y] && a[x][y] != '#') {
                vis[x][y] = 1;
                cur.push({x, y});
                from[x][y] = {top.f,top.s};
            }
        }

    }


    return "";
}

int test_case(int test_case = 0) {
    cin >> N >> M;
    pr<int, int> loc = {0, 0};
    FOR(i, 0, N){
        string se; cin >> se;
        FOR(j, 0, M){
            a[i][j] = se[j];
            if(se[j] == 'A')
                loc.x = i, loc.y = j;
        }
    }
    string ans = bfs(loc.x, loc.y);
    if(ans != "") {
        put("YES");
        put(sz(ans));
        put(ans);
    } else put("NO");

    return 0;
}

int main () {
    CP::IO::SetIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in2.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif
    my_brain_hurts
   // cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        //cout << "Case #" << tt << ": ";
        if (debug) { cerr << "\033[33m" << "\n[Test #" << (tt) << "]\n" << "\033[0m"; }
        test_case(tt);
    }

    #if LOCAL
        CP::ExecTime::log_time(0);
    #endif

    return 0;
}