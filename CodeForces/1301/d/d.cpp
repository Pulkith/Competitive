/**
 * author: DespicableMonkey
 * created: 07.02.2021 14:58:40
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
int N, M, F;
int a[MX];


void test_case() {
    cin >> N >> M >> F;
    if(F > ((4*N*M) - (2*M) - (2 * N))) putr("NO");
    bool swtch = 0;
    if(N > M) swap(N, M), swtch = 1;
    put("YES");
    vt<pr<int, string>> moves;
    --M; --N;

    moves.pb({min(M, F), "R"});
    F -= min(F, M);

    if(F > 0) {
        moves.pb({min(M, F), "L"});
        F -= min(M, F);
    }
    int down = 0;
    while(F > 0) {

        if(down == N) {
            int move = min(F, N);
            F -= move;
            moves.pb({move, "U"});
            break;
        }

        moves.pb({1, "D"});
        --F;
        ++down;
        if(F > 0) {
            string move = "RUD";
            int amt = min(F / 3, M);
            if(amt > 0){
                moves.pb({amt, move});
                F -= amt * 3;
            }
            if(F == 2) {
                if(amt == M){
                    string m = (M == 1 ? "LU" : "LL");
                    moves.pb({1, m});
                } else {
                    moves.pb({1, "RL"});
                }
                F -= 2;
            }
            if(F == 1) {
                if(amt == M) moves.pb({1, "L"});
                else moves.pb({1, "R"});
                --F;
            }
            if(F > 0) {
                moves.pb({min(F, amt), "L"});
                F -= min(F, amt);
            }
            
        }
    }

    assert(F == 0);
    put(moves.size());

    if(swtch) {
        for(auto & move : moves) {
            for(auto &c : move.s) {
                if(c == 'D') c = 'R';
                else if(c == 'R') c = 'D';
                else if(c == 'U') c = 'L';
                else if(c == 'L') c = 'U';
            }
        }
    }

    for(auto move : moves)
        cout << move.f <<  ' ' << move.s << '\n';
    
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