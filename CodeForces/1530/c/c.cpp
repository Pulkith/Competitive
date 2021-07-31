/**
 * author: DespicableMonkey
 * created: 07.17.2021 09:35:10
 * Potatoes FTW!
 **/ 

#include <algorithm>
#include<bits/stdc++.h>
#include <functional>
#include <numeric>
#include <queue>
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


void test_case() {
   cin >> N;
   vector<int> a(N), b(N);
   FOR(i, 0, N) cin >> b[i];
   FOR(i, 0, N) cin >> a[i]; 

    sort(all(a)); reverse(all(a));
    sort(all(b));  reverse(all(b));

    int t_score = accumulate(a.begin(), a.begin() + (N - N / 4), 0LL);
    int y_score = accumulate(b.begin(), b.begin() + (N - N / 4), 0LL);
    priority_queue<int> remaining;
    priority_queue<int, vt<int> , greater<int>> your_rem;

    FOR(i, 0, N - N / 4) {
        if(b[i] != 100)
            your_rem.push(b[i]);
    }

    for(int i = N - (N/4); i < N; ++i)
        remaining.push(a[i]);

    int cur = N;
    while(y_score < t_score) {
        ++cur;
        if(cur%4) {
            y_score += 100, b.pb(100);
            if(sz(remaining)) {
                t_score += remaining.top();
                remaining.pop();
            }
        } else {
            if(your_rem.size()) {
                y_score -= your_rem.top(); your_rem.pop();
                y_score += 100;
            }
        }
    }
    put(cur - N);
}
/*
4 -> top 3 scores
5 -> 4
6 -> 5
7 -> 6 
8 -> 6


*/

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
