/**
 * author: DespicableMonkey
 * created: 06.23.2021 10:34:42
 * Potatoes FTW!
 **/ 

#include "bits/stdc++.h"
#include <cassert>
#include <functional>
#include <ratio>
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

using ll = int64_t;
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using vt = vector<T>;
template<class T, class U> T cdiv(T a, U b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int MOD = 1'000'000'007, INF = 2 * MOD; //0xc0, 0x3f. Pos, Neg Inf for memset. Comparison = 0x3f3f3f3f
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; //DRUL

inline namespace CP {
     inline namespace Output {
        string operator+(string str, int num){return str + ts(num);}
        string operator+(int num, string str) { return ts(num) + str; }
        //string to_string(const char* s) { return string(s);}
        #if !defined LOCAL
            #define dbg(...) ;
            #define print_test_case(...) ;
            #define debug_active 0
        #endif
        template<class T> void outv(vector<T> v, int add = 0, bool standard = 1) {for(T& i : v) (standard?cout:cerr) << (i+add) << " "; cout << '\n'; }
        template<class T> void put(T output) { cout << output << '\n'; }
        #define putr(__output) return void(putr(__output))
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

void test_case() {
    int n; cin >> n;
    int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    //           1  1  1  x  1  x  x   1  1   x
    auto maxx = [&](int N) -> string {
        if(N&1) {
            N -= 3;
            return (string(N/2, '1') + '7');
        } else {
            return (string(N/2, '1'));
        }
    };

    auto minn = [&](int N) -> string{
        int val[6] = {2, 3, 4, 5, 6, 7};
        int num[6] = {1, 7, 4, 2, 0, 8};

        string ans = "";
        int rem = N;
        for(int i = 5; i >= 0; --i) {
            if(val[i] <= rem) {
                int amt = rem / val[i];
                if(rem - amt * val[i] < 2 && rem - amt * val[i] != 0) --amt;
                ans += string(amt, '0' + num[i]);
                rem -= amt * val[i];
            }
        }
        if(ans[0] == '0'){
            int i = 0;
            while(ans[i] == '0') ++i;
            swap(ans[0], ans[i]);
        }
        return ans;

    };

    cout << minn(n) << " " << maxx(n) << '\n';
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);
    my_brain_hurts
    //cin >> Test_Cases;
    int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    map<int, int> minn;

    FOR(i, 0, 50000) {
        int sum = 0;
        for(auto c : ts(i))
            sum += a[c - '0']; 
        minn[sum] = (minn.find(sum) != minn.end() ? min(minn[sum], i) : i);
    }

    for(auto [x, y] : minn)
        cout <<x << " " << y << '\n';

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        //test_case();
    }


    return 0;
}