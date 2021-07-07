/**
 * author: DespicableMonkey
 * created: 06.26.2021 23:06:47
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
template<class T, class U> T cdiv(T a, U b) { 
    return a/b+((a^b)>0&&a%b); 
} // divide a by b rounded up
const int MX = (2e5+5); //Check the limits idiot
int N;
string a, b;


void test_case() {
    cin >> N >> a >> b;
    vt<int> ans;

    // Mind = Blown Solution(convert all to 0s, then convert to b)
    // bool zero = a[0] == '0';
    // FOR(i, 0, N-1) {
    //     if(a[i] != a[i+1]) {
    //         ans.pb(i+1);
    //         zero = !zero;
    //     }
    // }

    // if(!zero) ans.pb(N), zero = 1;

    // for(int i = N-1; i >= 0; --i) {
    //     if(b[i] == (zero ? '0' : '1')) continue;
    //     zero = !zero;
    //     ans.pb(i+1);
    // }


    //Proper implementation of my solution using 2 pointers
    auto opp = [&](char c) -> char {return c == '0' ? '1' : '0';};
    int ptr1 = 0, ptr2 = N-1;
    bool flipped = 0;
    for(int i = N-1; i >= 0; --i) {
        if((flipped?opp(a[ptr1]):a[ptr2]) == b[i]) {
            (flipped?ptr1++:ptr2--);
            continue;
        }
        if(b[i] == (flipped?opp(a[ptr2]): a[ptr1]))
            ans.pb(1);

        ans.pb(i+1);
        (!flipped?ptr1++:ptr2--);
        flipped = !flipped;

    }

    assert(sz(ans) <= N * 2);
    put(sz(ans));
    outv(ans);
    
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