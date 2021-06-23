/**
 * author: DespicableMonkey
 * created: 06.20.2021 19:37:37
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

const int MX = (1e6+500); //Check the limits idiot
int N;
string a[MX];
void pre() {
    int loc = 1;
    int size = 0;
    int amt = 1;
    int ptr = 0;
    a[0] = "";
    while(loc < (1e6+5)) {
        ++size;
        for(int i = 0; i < 26 && loc < (1e6+5); ++i) {
            for(int j = 0; j < amt && loc < (1e6+5); ++j) {
                a[loc] = ((char)(i+'A')) + a[ptr + j];
                ++loc;
            }
        }
        ptr += amt;
        amt *= 26;
    }
}

void test_case() {
    string str; cin >> str;
    bool found = 0;

    FOR(i, 1, sz(str)) {
        if(str[i] >= 'A' && str[i] <= 'Z' && str[i-1] >= '0' && str[i-1] <= '9') {
            int row = stoi(str.substr(1, i - 1));
            int col = stoi(str.substr(i+1));

            putr(a[col] + row);
        }
    }

    int i = 0;
    while(!(str[i] >= '0' && str[i] <= '9')) ++i;
    string col = str.substr(0, i);
    int row = stoi(str.substr(i));
    int l = 0, r = (1e6+2);
    int res = -1;
    while(l < r) {
        int mid = (l+r) / 2;
        if(sz(a[mid]) < sz(col)) l = mid+1;
        else if(sz(a[mid]) > sz(col)) r = mid;
        else {
            if(a[mid] < col) l = mid+1;
            else r = mid;
        }
    }
    cout << "R" << row << "C" << l << '\n';

}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);
    pre();
    my_brain_hurts
    cin >> Test_Cases;
    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }


    return 0;
}