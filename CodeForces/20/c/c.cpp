/**
 * author: DespicableMonkey
 * created: 06.30.2021 00:15:31
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

const int MX = (1e5);
vt<set<int>> adj(MX, set<int>());
map<pr<int, int>, int> weight;
int num_vertices, num_edges;
int dist[MX]; 
bool sptSet[MX];
int parent[MX];
   
// A utility function to find the 
// vertex with minimum distance
// value, from the set of vertices
// not yet included in shortest
// path tree
int minDistance(){
       
    int min = INT_MAX, min_index;
   
    for (int v = 0; v < num_edges; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
   
    return min_index;
}
void printPath(int j) {
       
    if (parent[j] == - 1)
        return;
   
    printPath(parent[j]);
   
    printf("%d ", j);
}
   

void printSolution(){
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < num_vertices; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ",
                      src, i, dist[i], src);
        printPath(i);
    }
}

void dijkstra(int src){
    memset(parent, -1, sizeof(parent));
    FOR(i, 1, num_vertices)
        dist[i] = INT_MAX;


    for (int count = 0; count < num_vertices - 1; count++){
        int u = minDistance();
        sptSet[u] = true;
        for(auto v : adj[u]) {
            if (!sptSet[v] && dist[u] + weight[{u, v}] < dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + weight[{u, v}];
            } 
        }
    }
   
    // print the constructed
    // distance array
    printSolution();
}



void test_case() {
    cin >> num_vertices >> num_edges;

    FOR(i, 0, num_edges) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        if(adj[u].find(v) == adj[u].end())
            weight[{u, v}] = w, weight[{v, u}] = w;
        else
            cmin(weight[{u, v}], w), cmin(weight[{v, u}], w);
        adj[u].insert(v);
        adj[v].insert(u);
    }

    dijkstra(0);   
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