/**
 * author: DespicableMonkey
 * created: 07.19.2021 22:35:11
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
string a[MX];


void test_case() {
    cin >> N;

    int ones = 0, zeros = 0;
    set<string> one_zeros_, zero_ones_;
    vt<int> one_zeros, zero_ones;
    int ex = 0;
    FOR(i, 0, N) {
        cin >> a[i];
        if(sz(a[i]) > 1 && a[i][0] != a[i][sz(a[i])-1]) {
            string t = a[i]; reverse(all(t));
            if(a[i][0] == '0') {
                if(one_zeros_.find(t) != one_zeros_.end()) one_zeros_.erase(t), ++ex;
                else  zero_ones_.insert(a[i]);
            } else {
                if(zero_ones_.find(t) != zero_ones_.end())  zero_ones_.erase(t), ++ex;
                else one_zeros_.insert(a[i]);
            }
        } else {
            if(a[i][0] == '0') ++zeros; else ++ones;
        }
    }
    FOR(i, 0, N) {
        if(one_zeros_.find(a[i]) != one_zeros_.end()) one_zeros.pb(i+1);
        if(zero_ones_.find(a[i]) != zero_ones_.end()) zero_ones.pb(i+1);
    }

    if(ones && zeros && ! sz(one_zeros) && !sz(zero_ones) && !ex) putr("-1");
    if(abs(sz(one_zeros) - sz(zero_ones)) <= 1) putr(0);
    int need = abs(sz(one_zeros) - sz(zero_ones)) / 2;
    put(need);
    auto& ans = (sz(one_zeros) > sz(zero_ones)) ? one_zeros : zero_ones;
    ans.resize(need);
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
