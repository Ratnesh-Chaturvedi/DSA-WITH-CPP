 bool DFS(int node , vector<int>&visited,vector<int>&pathVisited,vector<vector<int>>&adj){
      visited[node]=1;
      pathVisited[node]=1; // marks the node because we are currently running on it
      for(auto it:adj[node]){
          if(!visited[it]){
              if(DFS(it,visited,pathVisited,adj)==true) {
                  return true;
              }
              // if the node is previously visited but it has to be on the same path 
              }
              else if(pathVisited[it]){
                  return true;
          }
      }
      pathVisited[node]=0; // unmarks because we came back from that node 
      return false;
  }  
bool isCyclic(int V, vector<vector<int>> &edges) {  
        vector<vector<int>>adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int>visited(V,0);
        vector<int>pathVisited(V,0);
        
        // checking for all component 
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(DFS(i,visited,pathVisited,adj)==true) 
                return true;
            }
        }
        
        return false;
}

// by using single visited array
  bool DFS(int node , vector<int>&visited,vector<vector<int>>&adj){
      visited[node]=1; // marks the node because we are currently running on it
      for(auto it:adj[node]){
          if(visited[it]==0){
              if(DFS(it,visited,adj)==true) {
                  return true;
              }
              // if the node is previously visited but it has to be on the same path 
              }
              else if(visited[it]==1){
                  return true;
          }
      }
      visited[node]=2; // unmarks because we came back from that node 
      return false;
  }
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>>adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int>visited(V,0);
       
        
        // checking for all component 
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(DFS(i,visited,adj)==true) 
                return true;
            }
        }
        
        return false;
    }