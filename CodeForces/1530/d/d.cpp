/**
 * author: DespicableMonkey
 * created: 07.17.2021 09:35:09
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <cassert>
#include <iostream>
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

void test_case() {
    cin >> N;
    FORE(i, 1, N) cin >> a[i];

    vt<int> ans(N+2);
    vt<bool> is_assign(N+2), has_assign(N+2); 

    FORE(i, 1, N) {
        if(!has_assign[i] && !is_assign[a[i]] && a[a[i]] == i) {
            has_assign[i] = is_assign[a[i]] = has_assign[a[i]] = is_assign[i] = 1;
            ans[i] = a[i];
            ans[a[i]] = i;
        }
    }
    FORE(i, 1, N) {
        if(!has_assign[i] && !is_assign[a[i]]) {
            has_assign[i] = is_assign[a[i]] = 1;
            ans[i] = a[i];
        }
    }
     deque<int> need_to_be_assigned, need_to_be_assignment;

    FORE(i, 1, N) {
        if(!has_assign[i]) need_to_be_assignment.pb(i); 
        if(!is_assign[i]) need_to_be_assigned.push_front(i); 
    }

    while(sz(need_to_be_assigned) && sz(need_to_be_assignment)) {
        int t2 = need_to_be_assigned.front(), t1 = need_to_be_assignment.front();
        if(t1 == t2) {
            if(need_to_be_assigned.size() > 1) {
                need_to_be_assigned.pop_front(); need_to_be_assigned.push_back(t2);
            } else if(need_to_be_assignment.size() > 1) {
                need_to_be_assignment.pop_front(); need_to_be_assignment.push_back(t1);
            } else break;
            continue;
        }
        need_to_be_assigned.pop_front();
        need_to_be_assignment.pop_front();
        has_assign[t1] = is_assign[t2] = 1;
        ans[t1] = t2;
    }
    assert(need_to_be_assigned.size() == need_to_be_assignment.size() && need_to_be_assignment.size() < 2);

    if(sz(need_to_be_assignment)) {
        int t = need_to_be_assignment.front();
        ans[t] = a[t];
        FORE(i, 1, N) {
            if(i == t) continue;
            if(ans[i] == a[t]) {
                ans[i] = t;
                break;
            }
        }
    }

    int K = 0; 
    FORE(i, 1, N) K += (a[i] == ans[i]);
    put(K);
    FORE(i, 1, N) cout << ans[i] << " \n"[i==N];

    
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
