/**
 * author: DespicableMonkey
 * created: 08.25.2021 23:31:50
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <cmath>
#include <sys/errno.h>
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
#define has(container, element) container.find(element) != container.end()

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
            if(sz(__t) && !debug_active) setIn(__s), setOut(__t);
            else if (sz(__s) && !debug_active) setIn(__s+".in"), setOut(__s+".out"); // for old USACO
            return this;
        }
    };
}
/*|||||||||||||||||| ||||||||||||||||||  CODE STARTS HERE  |||||||||||||||||| |||||||||||||||||| */

const int MX = (2e5+43); //Check the limits idiot
int N;
vt<set<int>> under(3), over(3);

void test_case() {
    cin >> N;
    string s; cin >> s;

    map<int, int> cnt;
    FOR(i, 0, N) ++cnt[s[i] - '0'];
    FOR(i, 0, 2) {
        FOR(j, 0, N)
            if(cnt[i] > N / 3)
                over[i].insert(j);
            else
                under[i].insert(j);
    }

    while(cnt[0] > N / 3) {
        --cnt[0];
        bool eraseOne = 0, eraseTwo = 0;
        if(sz(over[1]) && sz(over[2])) {
            if(*over[1].begin() < *over[2].begin()) eraseOne = 1;
            else eraseTwo = 1;
        }
        else if(sz(over[1])) eraseOne = 1;
        else eraseTwo = 1;

        if(eraseOne) {
            s[*over[1].begin()] = '0';
            over[1].erase(over[1].begin());
        } else {
            s[*over[2].begin()] = '0';
            over[2].erase(over[2].begin());
        }
    }

    while(cnt[2] > N / 3) {
        --cnt[1]; bool erase0 = 0, erase1 = 0;
        if(sz(over[0]) && sz(over[1])) (*over[0].rbegin() > *over[1].rbegin() ? erase0 : erase1) = 1;
        else if(sz(over[0])) erase0 = 1;
        else erase1 = 1;

        if(erase0) {
            s[*over[0].rbegin()] = '1';
            over[0].erase(--over[0].end());
        }
        else {
            s[*over[1].rbegin()] = '1';
            over[1].erase(--over[1].end());
        }
    }

    while(cnt[1] > N / 3) {
        if(sz(over[2]))
    }

    
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
