/**
 * author: DespicableMonkey
 * created: 06.24.2021 01:31:25
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

#define ll long long// using ll = int64_t;
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
int N, M, K;
struct edge{int u, v, w, rw;};
typedef struct  edge E;

int parents[MX];
bool used[MX * 5];
vector <E> graph; // Store the inputted graph (u, v, w).
vector <E> selected_edges; // Store the edges which is selected for the MST from given graph.

void make_set(int nodes){
    for(int i=1; i<=nodes; i++)
        parents[i] = i;
    return;
}

int findParent( int r ){
    if( r == parents[r] ) return r;
    return parents[r] = findParent( parents[r] );
}


bool comp (const E& l, const E& r){
    return l.w < r.w;
}

int Kruskal_MST (int nodes){

    make_set(nodes);
    sort(graph.begin(), graph.end(), comp);
    int edgeCounter=0, totalCost=0;
    int len = graph.size();
    
    for(int i=0; i<len; i++){

        int parent_of_u = findParent( graph[i].u );
        int parent_of_v = findParent( graph[i].v );

        if( parent_of_u != parent_of_v ){

            parents[ parent_of_u ] = parent_of_v;
            totalCost += (graph[i].rw > K ? graph[i].rw - K ? 0);
            selected_edges.push_back( graph[i] );

            edgeCounter++;
            if( edgeCounter == nodes-1 )
                break;
        }
    }

    return totalCost;
}




void test_case() {
    cin >> N >> M >> K;
    //Incorrect
    FOR(i, 0, M) {
        int u, v, w;
        cin >> u >> v >> w;
        E e;
        e.u = u;
        e.v = v;
        e.w = abs(K - w);
        e.rw = w;
        graph.pb(e);
    }

    //cout << Kruskal_MST(N);
    
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