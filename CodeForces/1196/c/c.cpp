/**
 * author: DespicableMonkey
 * created: 07.19.2021 11:33:46
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

const int MX = (2e5+43); //Check the limits idiot
int N;
vector<pr<int, int>> bounds[MX];


void test_case() {
    cin >> N;

    auto intersection = [&](vt<pr<int, int>>& box, vt<pr<int, int>> new_box) {
        cmax(box[0].f, new_box[0].f);
        cmin(box[1].f, new_box[1].f);
        cmax(box[0].s, new_box[0].s);
        cmin(box[1].s, new_box[1].s);
    };
    auto out_of_bounds = [&](vt<pr<int, int>> rect1, vt<pr<int, int>> rect2) -> bool {
       
        bool b1 = rect1[1].f < rect2[0].f;
        bool b2 = rect1[0].f > rect2[1].f;
        bool b3 = rect1[1].s < rect2[0].s;
        bool b4 = rect1[0].s > rect2[1].s;

        return (b1 || b2 || b3 || b4 );
    };


    FOR(i, 0, N) {
        int x, y; cin >>x  >> y;
        vt<int> robot(4); 
        FOR(j, 0, 4) cin >> robot[j];
        vt<pr<int, int>> cur = {{-100000, -100000}, {100000, 100000}};
        if(!robot[0]) cur[0].f = x;
        if(!robot[1]) cur[1].s = y;
        if(!robot[2]) cur[1].f = x;
        if(!robot[3]) cur[0].s = y;
        bounds[i] = cur;
    }

    FOR(i, 1, N) {
        if(out_of_bounds(bounds[i-1], bounds[i])) putr(0);
        intersection(bounds[i], bounds[i-1]);
    }
    put("1 " + ts(bounds[N-1][0].f) + " " + ts(bounds[N-1][0].s));


    
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
