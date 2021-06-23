/**
 * author: DespicableMonkey
 * created: 06.21.2021 11:23:27
 * Potatoes FTW!
 **/ 

#include<bits/stdc++.h>
#include <iterator>
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

const int MX = (1000+5); //Check the limits idiot
int N, M, K, W;
char a[MX][10][10];

struct edge{

    int u, v, w;
};

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
bool comp2 (const E&l, const E&r) {
    return l.u < r.u;
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
            totalCost += graph[i].w;
            selected_edges.push_back( graph[i] );

            edgeCounter++;
            if( edgeCounter == nodes-1 )
                break;
        }
    }

    return totalCost;
}


void test_case() {
    cin >> N >> M >> K >> W;

    FOR(i, 0, K) {
        FOR(j, 0, N) {
            string s; cin >> s;
            FOR(k, 0, M)
                a[i][j][k] = s[k];
        }
    }

    E getEdge;
    int nodes = K+1;
    for(int i=0; i <= K; i++){
        for(int j = i+1; j <= K; ++j) {
            if(i == 0) {
                getEdge.u = 0;
                getEdge.v = j;
                getEdge.w = N * M;
            } else {
                getEdge.u = i;
                getEdge.v = j;
                int cost = 0;

                FOR(x, 0, N)
                    FOR(y, 0, M)
                        cost += a[i-1][x][y] != a[j-1][x][y];

                getEdge.w = cost * W;
            }
            graph.push_back(getEdge);
        }
    }

    int totalCost = Kruskal_MST(nodes); 
    put(totalCost);
    for(auto& E : selected_edges)
        if(E.u > E.v)
            swap(E.u, E.v);

    sort(all(selected_edges), comp2);
    auto find = [&](int start) -> vt<E> {
        vt<E> ans;
        FOR(i, 0, sz(selected_edges)) {
            if(!used[i] && (selected_edges[i].u == start || selected_edges[i].v == start)) {
                used[i] = 1;
                ans.pb(selected_edges[i]);
            }
        }
        return ans;
    };

    int lst = 0;
    queue<int> bfs;
    bfs.push(0);

    while(!empty(bfs)) {
        int cur = bfs.front(); bfs.pop();
        vt<E> children = find(cur);

        FOR(i, 0, sz(children)) {
            if(cur == children[i].u) {
                cout << children[i].v << ' ' << cur << '\n';
                bfs.push(children[i].v);
            } else if(cur == children[i].v) {
                cout << children[i].u << " " << cur << '\n';
                bfs.push(children[i].u);
            }
        }

    }

}

int main () {
    CP::IO().SetIO()->FastIO().Input(0);

    my_brain_hurts
    //cin >> Test_Cases;

    for(int tt = 1; tt <= Test_Cases; ++tt){
        print_test_case(tt);
        test_case();
    }


    return 0;
}