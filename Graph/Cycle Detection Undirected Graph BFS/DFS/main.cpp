
// cycle detection using undirected graph 
class Solution {
  public:
  bool detectCycleBFS(int node,vector<bool>&visited,vector<vector<int>>& adj)
  {
      queue<pair<int,int>>q; // node,parentNode
      q.push({node,-1}); // source node does not have any parent so we initialize it with -1
      visited[node]=true;
      while(!q.empty()){
          int nd=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(auto adjacentNode:adj[nd]){
              if(!visited[adjacentNode]){
                  visited[adjacentNode]=true;
                  q.push({adjacentNode,nd});
              } 
              //condition when the intersecting node already visited it means there is a cycle 
              else if(adjacentNode!=parent){
                  return true;
              }
          }
      }
      return false;
  }   

// by dfs 
  bool detectCycleDFS(int node,int parent,vector<bool>&visited,vector<vector<int>>& adj){
      visited[node]=true;
      for(auto it:adj[node]){
          if(!visited[it]){
            // no need to check further when it return true
              if(detectCycleDFS(it,node,visited,adj)==true) return true;
          }
          else if(it!=parent) return true;
      }
      return false;
  }
  





    bool isCycle(int V, vector<vector<int>>& edges) {
      vector<bool>visited(V,false);
        //creating adjaceny list
        vector<vector<int>>adj(V);
        for(auto e:edges){
            // because it is undirected graph
            adj[e[0]].push_back(e[1]);
            adj[ed[1]].push_back(e[0]);
        }
        // we run this loop for case if it has components which are not connected but have the possiblity of cycle
        for(int i=0;i<V;i++){
            if(!visited[i]){
            if(detectCycleBFS(i,visited,adj))  // replace it with  if(detectCycleDFS(i,-1,visited,adj))  for DFS
            return true;
            }
        }
        return false;
    }
};