/**
 * author: DespicableMonkey
 * created: 06.22.2021 16:24:51
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
        #define putr(__output) return put(__output), void();
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
string s;
ll K, N;

bool good(string str) {
    for(int i = 0; i < K; ++i)
        for(int j = i + K; j < sz(str); j += K)
            if(str[j] != str[i])
                return 0;
    return 1;
}

string brute() {
    string cur = s;
    while(!good(cur)) {
        ll k = stoll(cur);
        ++k;
        cur = ts(k);
    }
    return cur;
}

void test_case() {
    cin >> N >> K >> s;
    //string ans2 = brute();
    bool ok = 0;
    for(int i = 0; i < K && !ok; ++i)
        for(int j = i + K; j < sz(s) && !ok; j += K)
            if(s[j] < s[i]) s[j] = s[i];
            else if(s[j] > s[i]) {
                ++s[K-1];
                if(s[K-1] > '9') {
                    int x = K-2;
                    while(x >= 0 && s[x] == '9') --x;
                    assert(x >= 0);
                    ++s[x];
                    for(int k = x+1; k < sz(s); ++k)
                        s[k] = '0';
                }
                ok = 1;
            }


    for(int i = 0; i < K; ++i)
        for(int j = i + K; j < sz(s); j += K)
            if(s[i] != s[j])
                s[j] = s[i];

    //assert(s == ans2);
    put(N);
    putr(s);
    
}
/*
for all i in K
if s[i+Kx] < s[i]: increase everything to s[i]
if s[i+Kx] > s[i], increase s[K-1] by 1, and set everything equal to their corresponding s[i]

*/
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