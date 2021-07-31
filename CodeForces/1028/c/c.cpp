/**
 * author: DespicableMonkey
 * created: 07.17.2021 00:25:52
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <iterator>
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
vt<pr<int, int>> a[MX];
vt<pr<int, int>> prefix_bound[MX];
vt<pr<int, int>> suffix_bound[MX];

void test_case() {
    cin >> N;
    FOR(i, 0, N) {
        a[i] = vt<pr<int, int>>(2);
        auto s = a[i];
        cin >> s[0].f >> s[0].s >> s[1].f >> s[1].s;
        a[i][0].f = s[0].f;
        a[i][0].s = s[1].s;
        a[i][1].f = s[1].f;
        a[i][1].s = s[0].s;
    }

    if(N  == 2) putr(ts(a[0][0].f) + " " + ts(a[0][0].s));

    auto out_of_bounds = [&](vt<pr<int, int>> rect1, vt<pr<int, int>> rect2) -> bool {
        bool b1 = rect1[1].f < rect2[0].f;
        bool b2 = rect1[0].f > rect2[1].f;
        bool b3 = rect1[1].s > rect2[0].s;
        bool b4 = rect1[0].s < rect2[1].s;
        return (rect1[1].f < rect2[0].f || rect1[0].f > rect2[1].f || rect1[1].s > rect2[0].s || rect1[0].s < rect2[1].s);
    };

    auto intersection = [&](vt<pr<int, int>>& box, vt<pr<int, int>> new_box) {
            cmax(box[0].f, new_box[0].f);
            cmin(box[1].f, new_box[1].f);
            cmin(box[0].s, new_box[0].s);
            cmax(box[1].s, new_box[1].s);
    };


    FOR(j, 0, 2) {
        reverse(a, a+N);
        auto& cur = (j == 0 ? suffix_bound : prefix_bound);
        cur[0] = a[0];
        FOR(i, 1, N) {
            if(out_of_bounds(a[i], cur[i-1])) break; //No point of intersection
            cur[i] = cur[i-1];
            intersection(cur[i], a[i]);
        }
    }
    reverse(suffix_bound, suffix_bound + N); 

    if(prefix_bound[N-2].size() > 0) putr(ts(prefix_bound[N-2][0].f) + " " + ts(prefix_bound[N-2][0].s));
    if(suffix_bound[1].size() > 0) putr(ts(suffix_bound[1][0].f) + " " + ts(suffix_bound[1][0].s));

    FOR(i, 1, N-1) {
        if(prefix_bound[i-1].size() > 0 && suffix_bound[i+1].size() > 0) {
            if(!out_of_bounds(prefix_bound[i-1], suffix_bound[i+1])){
                intersection(prefix_bound[i-1], suffix_bound[i+1]);
                cout << prefix_bound[i-1][0].f << ' ' << prefix_bound[i-1][0].s << '\n';
                return;
            }
        }
    }

    assert(0);


    
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
