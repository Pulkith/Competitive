/**
 * author: DespicableMonkey
 * created: 06.20.2021 18:07:32
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

const int MX = (1e5+5); //Check the limits idiot
int N;
pr<ll, ll> a[MX];
ll dp[MX];

void test_case() {
    cin >> N;
    FORE(i, 1, N) cin >> a[i].f >> a[i].s;

    sort(a, a+N, [](pr<ll, ll> &pr1, pr<ll, ll> &pr2)->bool{
        if(pr1.s == pr2.s) return pr1.f > pr2.f;
        return pr1.s < pr2.s;
    });


    for(int i = 1; i <= N; ++i)
        dbg(a[i].f,a[i].s);


    ll ans = 0;
    ll tot = 0;
    FORE(i, 1, N) {

        ll two_num = (a[i].s <= tot) ? 0 : min(a[i].s - tot, a[i].f);
        ll one_num = a[i].f - two_num;

        ll cost = two_num * 2 + one_num;

        ans += cost;
        tot += a[i].f;

        if(i != N) {
            ll two_num_next = (a[i+1].s <= tot) ? 0 : min(a[i].s - tot, a[i+1].f);
            ll one_num_next = a[i+1].f - two_num;
            ll cost_next = two_num_next * 2 + one_num_next;

            ll climb = a[i+1].s - tot;

            if(climb <= 0 ) continue;

            ll climb_two_num = (a[i].s <= tot) ? 0 : min(a[i].s - tot, climb);
            ll climb_one_num = climb - climb_two_num;
            ll cost_to_climb = climb_two_num * 2 + climb_one_num;
            ll cost_total = cost_to_climb + a[i+1].f;

            if(cost_total <= cost_next) {
                ans += cost_to_climb;
                tot += climb;
            }

        }

        dbg(tot, ans);

    }

    put(ans);



}

int main () {
    CP::IO().SetIO()->FastIO().Input(2);

    my_brain_hurts
    //cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }


    return 0;
}