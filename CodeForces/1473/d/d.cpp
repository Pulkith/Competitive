/**
 * author: DespicableMonkey
 * created: 06.23.2021 01:59:04
 * Potatoes FTW!
 **/ 

#include "bits/stdc++.h"
#include <numeric>
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
int N, Q;
string s;
int front[MX][2], back[MX][2]; //min, max;
int val[MX];
void test_case(int tt) {
    cin >> N >> Q >> s;
    //if(tt == 1) return;
    int cur = 0;
    front[0][0] = front[0][1] = prefix[0] = val[0] = cur = (s[0] == '-' ? -1 : 1);
    FOR(i, 1, N) {
        int delta = (s[i] == '-' ? -1 : 1);
        prefix[i] = val[i] = cur += delta;
        front[i][0] = min(front[i-1][0], cur);
        front[i][1] = max(front[i-1][1], cur);
    }
    back[0][0] = back[0][1] = 0;
    for(int i = N-2; i >= 0; --i) {
        int delta = (s[i] == '-' ? -1 : 1);
        back[i][0] = min(back[i-1][0] + delta, 0);
        back[i][1] = max(back[i-1][1] + delta, 0);
    }

    for(int i = N-2; i >= 0; --i) {
        
    }

    auto distinct = [&](int low, int high) -> int {
        return (high - low) + (low > 0 || high < 0) + 1;
    };

    while(Q--) {
        int l,r;
        cin >> l >> r;

        if(l == 1 && r == N) {
            put(1); continue;
        }
        else if(l == 1) {
            put(distinct(back[r+1][0], back[r+1][1]));
            continue;
        } else if(r == N) {
            put(distinct(front[l-1][0], front[l-1][1]));
            continue;
        }

        --l, --r;

        int min_before = front[l-1][0];
        int max_before = front[l-1][1];

        int min_after = front[r+1][0];
        int max_after = front[r+1][1];

        int total_max = max(max_before, val[l-1] + max_after);
        int total_min = min(min_before, val[l-1] + min_after);

        put(distinct(total_min, total_max));
    }
    


    
}

int main () {
    CP::IO().SetIO()->FastIO().Input(1);

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case(tt);
    }


    return 0;
}



/*
void solve() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vi min_front(N), max_front(N), max_back, min_back, ans(N);
    multiset<int> back;
    int cur = 0;
    FOR(i, 0, N) {
        int delta = (s[i] == '-' ? -1 : 1);
        cur += delta;
        min_front[i] = (i == 0 ? delta : min(min_front[i-1], cur));
        max_front[i] = (i==0?delta: max(max_front[i-1], cur));
        ans[i] = cur;
        back.insert(cur);
    }
}

// void solve() {
//     int N, Q;
//     string s;
//     cin >> N >> Q >> s;
//     auto amt = [&](int l, int r) -> int {
//         if(r < l) swap(l, r);
//         int dif = abs(r - l) + 1;
//         return (l <= 0 && r>=0?dif:dif+1);
//     };
//     vi min_front(N), max_front(N), min_back(N), max_back(N), ans(N);
//     int cur = 0;
//     FOR(i, 0, N) {
//         int delta = (s[i] == '-' ? -1 : 1);
//         cur += delta;
//         min_front[i] = (i == 0 ? delta : min(min_front[i-1], cur));
//         max_front[i] = (i==0?delta: max(max_front[i-1], cur));
//         ans[i] = cur;
//     }
//     cur = 0;
//      for(int i = N-1; i >= 0; --i) {
//          int delta = (s[i] == '-' ? -1 : 1);
//          cur += delta;
//          min_back[i] = (i == N-1? delta : min(min_back[i+1], cur));
//          max_back[i] = (i==N-1?delta: max(max_back[i+1], cur));
//      }
//      while(Q--) {
//          int l, r;
//          cin >> l >> r;
//          --l, --r;
//         if(l == 0 && r == N-1) put("1");
//         else if(l == 0) put(amt(max_back[r+1], min_back[r+1]));
//         else if(r == N-1) put(amt(max_front[l-1], min_front[l-1]));
//         else {
//             int minf = min_front[l-1], maxf = max_front[l-1], minb = min_back[r+1], maxb = max_back[r+1];
//             int ans_high = ans[l-1] + maxb, 
//                 ans_low = ans[l-1] - minb;

//             int range_max = max(ans_high, maxf),
//                 range_min = min(ans_low, minf);
//             int ans_f = amt(range_min, range_max);
//             dbg(ans[l-1]);
//             dbg(minb, maxb);
//             dbg(range_min, range_max);
//             put(ans_f);
//             // if(minf > maxb || maxf < minb) {
//             //     int dif = (abs(minf - maxf) + abs(minb - maxb) + 2);
//             //     if(!(maxf >= 0 && minf <= 0 || maxb >= 0 && minb <= 0)) ++dif;
//             //     put(dif);
//             // } else {
//             //     dbg(minf, minb, maxf, maxb);
//             //     int range_min = min(minf, minb);
//             //     int range_max = max(maxf, maxb);
//             //     dbg(range_min, range_max);
//             //     int dif = (range_min+range_max+1) + (0 >= range_min && 0 <= range_max?0:1);
//             //     put(dif);
//             // }
//         }
//      }
// }

*/