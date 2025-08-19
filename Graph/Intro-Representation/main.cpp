#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m; // n->node , m->edges
  cin>>n>>m;

   // using adjacency matrix -> space ->O(N*N)
   int adj[n+1][n+1];
   for(int i=0;i<m;i++){
    int u,v; // edge
    cin>>u>>v;

    // consider that the graph is undirected 
     adj[u][v]=1;
     adj[v][u]=1;

     // if the graph is directed 
     // u->v
      adj[u][v]=1;

      // if weighted graph
         adj[u][v]=weight;
   }


   // by using adjacency List; -> Space => O(2*Edges)

   vector<vector<int>>adj(n+1);
   for(int i=0;i<m;i++){
    int u,v; 
    cin>>u>>v;

    // graph is undirected
    adj[u].push_back(v);
    adj[v].push_back(u);

    // graph is directed
    // u->v;
     adj[u].push_back(v);


     // if weigted we stored in pair where -> {v,weight}
      adj[u].push_back({v,weight});

   }


}
