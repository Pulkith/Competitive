/**
 * author: DespicableMonkey
 * created: 07.24.2021 22:44:16
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
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
int a[MX];

struct pred { bool operator()(const pair<int, int> &l, const pair<int, int> &r) { 
    if(l.s - l.f + 1 == r.s - r.f + 1) 
        return l.f > r.f;
    return (l.s - l.f + 1) < (r.s - r.f + 1);
} };

void test_case() {
    cin >> N;
    FORE(i, 1, N) a[i] = 0;
    priority_queue<pr<int, int>, vt<pr<int, int>>, pred> pq; 
    pq.push({1, N});
    int op = 1;
    while(!empty(pq)) {
        auto tp = pq.top(); pq.pop();
        int idx;
        if((tp.s-tp.f+1)&1) 
            idx = (tp.s+tp.f)/2;
        else
            idx = (tp.s+tp.f -1) / 2;
        a[idx] = op++;
        if(idx != tp.f) pq.push({tp.f, idx-1});
        if(idx != tp.s) pq.push({idx+1, tp.s});
    }
    FORE(i, 1, N) cout << a[i] << " \n"[i==N];

    
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
