/**
 * author: DespicableMonkey
 * created: 09.11.2021 12:24:27
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
#define has(container, element) ((bool)(container.find(element) != container.end()))

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
int N, M, A, B;


void test_case() {
    cin >> N >> M >> A >> B;
    int intersections = N + M - 1;

    if(intersections > A || intersections > B) putr("IMPOSSIBLE");
    if(intersections * 1000 < A || intersections * 1000 < B) putr("IMPOSSIBLE");
    vt<vt<int>> ans(N, vt<int>(M, 1000));
    if((N == 2 && M == 2)) {
        if(abs(A-B) > 1000) putr("IMPOSSIBLE");
    }
    else if((N == 3 && M == 2) || (M == 3 && N == 2)) {

    } else {
        int A_low = (A <= (intersections-1) * 1000 + 1) ? 1 : (A - ((intersections-1) * 1000));
        int A_high = (A >= (intersections-1) + 1000) ?  1000 : (A - (intersections - 1));

        int B_low = (B <= (intersections-1) * 1000 + 1) ? 1 : (B - ((intersections - 1) * 1000));
        int B_high = (B >= (intersections - 1) + 1000) ? 1000 : (B - (intersections - 1));

        if(A_low > B_high || A_high < B_low) putr("IMPOSSIBLE");
        put("POSSIBLE");
        int mutual = -1;
        if(A_low >= B_low && A_low <= B_high) mutual = A_low;
        if(A_high >= B_low && A_high <= B_high) mutual = A_high;
        if(B_low >= A_low && B_high <= A_high) mutual = B_low;
        if(B_high >= A_low && B_high <= A_high) mutual = B_high;
        assert(mutual != -1);

        ans[1][M-2] = mutual;

        int A_avg = (A - mutual) / (intersections - 1);
        int B_avg = (B - mutual) / (intersections - 1);
        A -= mutual; B -= mutual;
        for(int i = 0; i < M - 1; ++i) {
            A -= A_avg;
            ans[0][i] = A_avg;
        }
        for(int i = 2; i < N; ++i) {
            A -= A_avg;
            ans[i][M-2] = A_avg;
        }
        for(int i = M-1; i >= 0; --i) {
            if(i == M-2) continue;
            ans[1][i] = B_avg;
            B -= B_avg;
        }
        for(int i = 2; i < N; ++i) {
            ans[i][0] = B_avg;
            B -= B_avg;
        }

        ans[N-1][M-1] = A;
        ans[0][M-1] = B;

        int Aa = ans[N-1][M-1];
        int Bb = ans[0][M-1];
        //assert(Aa >= 1 && Aa <= 1000 && Bb >= 1 && Bb <= 1000);

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                cout << ans[i][j] << " \n"[j == M-1];
    }
}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        cout << "Case #" << ": "; 
        test_case();
    }

    return 0;
}
