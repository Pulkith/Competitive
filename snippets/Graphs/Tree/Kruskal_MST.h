/**
 * https://github.com/morsalins/Algorithms-and-Data-Structures/blob/master/Minimum%20Spanning%20Tree/Kruskal%20MST%20(using%20STL).cpp
 **/ 

#include<bits/stdc++.h>
using namespace std;


const int MX = (1000+5); 

struct edge{int u, v, w;};
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
            totalCost += graph[i].w;
            selected_edges.push_back( graph[i] );

            edgeCounter++;
            if( edgeCounter == nodes-1 )
                break;
        }
    }

    return totalCost;
}


void solve() {
    /*
        FOR(i, 0, # of edges) {
            E getEdge;
            getEdge.u = ...,
            getEdge.v = ...,
            getEdge.w = ...

            graph.push_back(getEdge);
        }

        total_cost = Kruskal_MST(number of nodes)

    */

}
