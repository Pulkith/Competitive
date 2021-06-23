/**
 * author: DespicableMonkey
 * created: 06.21.2021 16:32:25
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
#define my_brain_hurts int Test_Cases = 1;

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
    class IO { public:
        void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
        void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
        void Input(int __use_input = 0) {if(!!__use_input){setIn("in"+to_string(__use_input)+".txt");}}
        IO FastIO() { cin.tie(nullptr)->sync_with_stdio(0); return *this; }
        IO* SetIO(string __s = "", string __t = "") {
            cin.exceptions(cin.failbit); // throws exception when do smth illegal ex. try to read letter into int
            if(sz(__t)) setIn(__s), setOut(__t);
            else if (sz(__s)) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
    inline namespace Output {
        string operator+(string str, int num){return str + ts(num);}
        string operator+(int num, string str) { return ts(num) + str; }
        string to_string(const char* s) { return string(s);}
        #if !defined LOCAL
            #define dbg(...) ;
            #define print_test_case(...) ;
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T output) { cout << output << '\n'; }
        #define putr(__output) return put(__output), void();
    }
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+5); //Check the limits idiot
int N;
map<int, int> start_segs;
map<int, int> end_segs;


void test_case() {

    start_segs.clear();
    end_segs.clear();

    cin >> N;
    vt<pr<int, int>> segs;
    FOR(i, 0, N){
        int l, r;
        cin >> l >> r;
        ++start_segs[l];
        ++end_segs[r];
        segs.pb({l, r});
    }

    int maxx = 0;
    int lst = 0;

    for(auto& [x, y] : start_segs)
        lst = y += lst;
    lst = 0;
    for(auto& [x, y] : end_segs)
        lst = y += lst;

    for(auto seg : segs) {
        int l = seg.f, r = seg.s;
        auto start_before_r = start_segs.upper_bound(r);
        auto end_before_l = end_segs.upper_bound(l-1);
        int add = (*--start_before_r).s;
        int rem = (end_before_l == end_segs.begin() ? 0 : (*--end_before_l).s);

        
        dbg(add, rem);

        cmax(maxx, add - rem);

    }

    put(N - maxx);


}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    cin >> Test_Cases;
    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }


    return 0;
}