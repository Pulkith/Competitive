/**
 * author: DespicableMonkey
 * created: 06.16.2021 20:54:38
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#if LOCAL
    #include <DespicableMonkey/Execution_Time.h>
    #include <DespicableMonkey/Debug.h>
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define my_brain_hurts int T = 1;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ts(x) to_string(x)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for(int i = (a); i<= (b); ++i)

using ll = int64_t;
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T, class U> T cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

inline namespace CP {
    inline namespace IO {
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void FastIO() { cin.tie(nullptr)->sync_with_stdio(0); }
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

const int MX = (2e5+5); //Check the limits idiot


int test_case(int test_case = 0) {
    int N, M;
    cin >> N >> M;
    vt<vt<int>> grid(N, vt<int>(M));

    FOR(i, 0, N) {
        string s; cin >> s;
        FOR(j, 0, M)
            grid[i][j] = s[j] - '0';
    }

    auto o = [&](int x1,int y1, int x2,int  y2, int x3, int y3) {
        cout << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << " " << x3+1 <<  " " << y3+1 << '\n';
    };

    int ops = 0;
    FOR(i, 0, N - 1) {
        FOR(j, 0, M - 1) {
            int& tl = grid[j][i];
            int& tr = grid[i][j+1];
            int& bl = grid[i+1][j];
            int& br = grid[i+1][j+1];

            if(i == N-2 && j == M - 2) {
                if(br == 0 && bl == 0 && tr == 0) continue;
    
                else if(br == 1 && bl == 1 && tr == 1) {
                    ++ops;
                    o(i+1, j+1, i, j+1, i+1, j);
                } else if(br == 1 && tr == 0) {
                    ops += 2;
                    o(i, j, i+1, j, i+1, j+1);
                    o(i, j, i, j+1, i+1, j);
                } else if(br == 1 && bl == 1) {
                    ops += 2;
                    o(i, j, i, j+1, i+1, j+1);
                    o(i, j, i+1, j, i, j+1);
                }
                else if(tr == 1 && bl == 1) {
                    ops += 2;
                    o(i, j, i+1, j+1, i, j+1);
                    o(i, j, i+1, j+1, i+1, j);
                }
                else if(br == 1) {
                    ops += 3;
                    o(i+1, j+1, i, j+1, i+1, j);
                    o(i, j, i+1, j+1, i, j+1);
                    o(i, j, i+1, j+1, i+1, j);
                } else if(tr == 1) {
                    ops += 3;
                    o(i+1, j, i, j+1, i+1, j+1);
                    o(i, j, i, j+1, i+1, j+1);
                    o(i, j, i+1, j, i, j+1);
                } else if(bl == 1) {
                    ops += 3;
                    o(i, j+1, i+1, j+1, i+1, j);
                    o(i, j, i+1, j, i+1, j+1);
                    o(i, j, i, j+1, i+1, j);
                } else
                    assert(0);
            } else {
                ++ops;

                if(tl == 1 && tr == 1 && bl == 1) {
                    o(i, j, i, j+1, i+1, j );
                    tl = 0, tr = 0, bl = 0;
                }
                else if(tl == 1 && tr == 1) {
                    o(i, j, i, j+1, i+1, j+1);
                    tl = 0, tr = 0, br = !br;
                }
                else if(tl == 1 && bl == 1) {
                    o(i, j, i+1, j, i+1, j+1);
                    tl = 0, br = 0, br = !br;
                } 
                else if(tr == 1 && bl == 1) {
                    o(i+1, j, i, j+1, i+1, j+1);
                    tr = 0, bl = 0, br = !br;
                } 
                else {
                    ++ops;
                    o(i, j, i+1, j, i, j+1);
                    if(tr == 1) {
                        o(i, j, i+1, j, i+1, j+1);
                        tr = 0, br = !br;
                    } else if(tl == 1) {
                        o(i+1, j, i, j+1, i+1, j+1);
                        tl = 0, br = !br;
                    } else if(bl == 1) {
                        o(i, j, i, j+1, i+1, j+1);
                        bl = 0, br = !br;
                    }
                }
            }
        }
    }

    assert(ops < (N * M));
    return 0;
}

int main () {
    CP::IO::SetIO();
    CP::IO::FastIO();

    #if LOCAL
        //CP::IO::setIn("in1.txt");
        CP::ExecTime::use_clock();
        debug = true;
    #endif
    my_brain_hurts
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        if (debug) { cerr << "\033[33m" << "\n[Test #" << (tt) << "]\n" << "\033[0m"; }
        test_case(tt);
    }

    #if LOCAL
        CP::ExecTime::log_time(0);
    #endif

    return 0;
}