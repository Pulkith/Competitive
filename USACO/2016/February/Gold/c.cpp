/**
 * author: DespicableMonkey
 * created: 02.02.2022 02:12:06
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

const int MX = (4e6+43);
int N, M, A, B;
int a[MX], b[MX];
struct edge{int u, v, w;};
typedef struct  edge E;

int parents[MX];
vector <E> graph; 
vector <E> selected_edges; 

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

long long Kruskal_MST (int nodes){
    make_set(nodes);
    sort(graph.begin(), graph.end(), comp);
    long long edgeCounter=0, totalCost=0;
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
    cin >> A >> B >> N >> M;
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 0; i < M; ++i) cin >> b[i];
    a[N++] = A;
    b[M++] = B; 

    sort(a, a+N);
    sort(b, b+M);
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < M; ++j) {

        if(i != N-1) {
          E e;
          e.u = (i*M+j);
          e.v = ((i+1)*M+j);
          e.w = b[j] - (j == 0 ? 0 : b[j-1]);
          graph.push_back(e);
        }

        if(j != M-1) {
            E e2;
            e2.u = (i * M + j);
            e2.v = (i*M + j+1);
            e2.w =  a[i] - (i == 0 ? 0 : a[i-1]);
            graph.push_back(e2);
          }
        }
    }

    cout << Kruskal_MST(N * M) << '\n';

}

int main () {
  CP::IO().SetIO("fencedin")->FastIO().Input(0);
  my_brain_hurts

  for(int tt = 1; tt <= Test_Cases; ++tt){
      print_test_case(tt);
      test_case();
  }

  return 0;
}
