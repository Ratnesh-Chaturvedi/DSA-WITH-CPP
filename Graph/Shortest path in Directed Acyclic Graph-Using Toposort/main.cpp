
class Solution {
  public:
  // Dfs function of toposort
  void topoSort(int node,vector<bool>&visited,vector<vector<pair<int,int>>>&adj,stack<int>&st){
      visited[node]=true;
      for(auto it:adj[node]){
          int v=it.first;
          if(!visited[v]){
              topoSort(v,visited,adj,st);
          }
      }
      st.push(node);
      
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto it:edges){
         adj[it[0]].push_back({it[1],it[2]}); // u->v and weight
        }
        // TopoSort 
        stack<int>st; // stack for toposort sequence for element
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSort(i,visited,adj,st);
            }
        }
        // marking the distance
        vector<int>distance(V,INT_MAX);
        distance[0]=0; // we can do d[src]=0 // but here source is 0
        while(!st.empty()){
          int node=st.top();
          st.pop();
          
          // run only when the node is approachable i.e is connected
        if (distance[node] != INT_MAX) {
          for(auto it:adj[node]){
              int v=it.first;
              int wt=it.second;
              if(distance[node]+wt<distance[v]) distance[v]=distance[node]+wt;
          }
        }
        }   
        // if there is no distance to any node mark it as -1
            for(int i=0;i<V;i++){
                if(distance[i]==INT_MAX) distance[i]=-1; 
            }
            return distance;
    }
};
