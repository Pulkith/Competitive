/**
 * author: DespicableMonkey
 * created: 08.21.2021 22:21:05
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
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


string test_case(string s) {
    // string s; cin >> s;
    map<char,vt<int>> freq;
    vt<pr<char, vt<int>>> cur;
    FOR(i, 0, sz(s)){
        freq[s[i]].pb(i);
    }
    for(auto k : freq){
        if(k.s.size() > sz(s)/2 )
            return "IMPOSSIBLE";
        cur.pb(k);
    }
    sort(all(cur), [&](pr<char, vt<int>> l, pr<char, vt<int>> r) -> bool { return l.s.size() < r.s.size(); });
    vt<vt<int>> swaps;
    while(sz(cur) > 1) {
        auto& b = cur.back();
        auto& b1 = cur[cur.size() - 2];
        swaps.pb({b.s.back(), b1.s.back()});
        b.s.pop_back();
        b1.s.pop_back();
        bool b1e = !sz(b1.s), be = !sz(b.s);
        if(b1e) cur.erase(cur.end() - 2); 
        if(be) cur.pop_back();
    } 
    if(sz(cur)) {
        char c = s[cur.front().s[0]];
        for(auto& g : swaps) {
            if(g[0] != c && g[1] != c) {
                g.pb(cur.front().s[0]);
                break;
            }
        }
    }
    

    for(auto v : swaps)
        FOR(i, 1, sz(v))
            swap(s[v[i]], s[v[i-1]]);

    return s;
}

bool stress() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dd(1, 10); // distribution in range [1, 6]

    int len = dd(rng);
    string ans(len, 'a');

    FOR(i, 0, len)
        ans[i] = dd(rng)-1 + 'a';
    string t = test_case(ans);

    FOR(i, 0, len)
        if(ans[i] == t[i]){
            put("FAILED " + t + " " + ans);
            return 0;
        }
    cout << "PASSED: " << ans << '\n';
    return 1;
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    cin >> Test_Cases;
    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        cout << "Case #" << tt <<": ";
        if(!stress()) break;
        //string s; cin >> s;
        //put(test_case(s));
    }

    return 0;
}

//a f g j j c c c
