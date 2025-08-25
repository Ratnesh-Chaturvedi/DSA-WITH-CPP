 
  bool bipartiteBFS(int node,vector<int>&color,vector<vector<int>>&adj){
      queue<int>q;
      q.push(node);
      // choose two color 0 and 1
      color[node]=0;
      
      while(!q.empty()){
          int top=q.front();
          q.pop();
          for(auto it:adj[top]){
              // if the adjacent node is not colored give it opposite value of the node 
              if(color[it]==-1){
                  color[it]=!color[top];
                  q.push(it);
              }
              // check if someone is already colored it out so that is it opposite to node or not
              else if(color[it]==color[top]){
                 return false;
              }
          }
      }
      return true;
  }
  
  bool bipartiteDFS(int node,int c,vector<int>&color,vector<vector<int>>&adj){
      color[node]=c; // color
      for(auto it:adj[node]){
          if(color[it]==-1){
               if(bipartiteDFS(it,!c,color,adj)==false) return false;       
          } 
          else if(color[it]==c)return false;
      }
      return true;
  }
    bool isBipartite(int V, vector<vector<int>> &edges) {
       int n=edges.size();
      vector<vector<int>>adj(V);
      vector<int>color(V+1,-1); // colors array 
      for(auto e:edges){
          adj[e[0]].push_back(e[1]);
          adj[e[1]].push_back(e[0]);
      }
      for(int i=0;i<V;i++){
          if(color[i]==-1){
             if(bipartiteDFS(i,0,color,adj)==false) return false;
          }
      }
      return true;
    
    }