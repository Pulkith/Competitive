/**
 * author: DespicableMonkey
 * created: 07.11.2021 12:13:58
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

const int MX = (1e6+43); //Check the limits idiot
int N;
int a[MX];


void test_case() {
    cin >> N;
    FOR(i, 0, N) cin >> a[i];

    map<int, int> nums;

    auto get_last = [&](ll num, int n) -> ll {
        return num & ((1LL << n) -1);
    };

    auto flip = [&](int num) -> int {
        int X = log2(num) + 1;
        FOR(i, 0, X)
            num = (num ^ (1 << i));
        return num;
    };

    FOR(i, 0, N) {
        string cur = bitset<22>(a[i]).to_string();
        reverse(all(cur));
        while(sz(cur) > 1 && cur.back() == '0') cur.pop_back();
        reverse(all(cur));
        if(cur == "0") nums.insert({0, a[i]});
        else
            FOR(j, 0, sz(cur))
                nums.insert({get_last(a[i], sz(cur) - j), a[i]});
    }

    for(auto n : nums)
        dbg(n.f, n.s);

    FOR(i, 0, N) {
        int flipped = flip(a[i]);
        dbg(a[i], flipped);
        if(nums.find(flipped) != nums.end())
            cout << nums[flipped] << ' ';
        else
            cout << -1 << ' ';

    }
    
    cout << '\n';
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
