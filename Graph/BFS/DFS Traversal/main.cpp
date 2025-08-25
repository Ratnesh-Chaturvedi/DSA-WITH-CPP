 // Function to return Breadth First Traversal of given graph.
 // Adj is the adjacency list 
    vector<int> bfs(vector<vector<int>> &adj) {
      // creating a visited array
      int n=adj.size();
     vector<bool> visited(n+1,false); // false->not visited
     queue<int>q;
     q.push(0); // because starting from 0
     visited[0]=true;
     vector<int>bfs; // take an array for storing traversal 
     while(!q.empty()){
         int node=q.front();
         q.pop();
         bfs.push_back(node);
         // getting all its connected nodes
         for(auto it:adj[node]){
             if(!visited[it]){
                 visited[it]=true;
                 q.push(it);
             }
         }
     }
     return bfs;
        
    }



//DFS- > Recursive
  void dfsTraverse(int node,vector<bool>&visited,vector<vector<int>>&adj,vector<int>&dfsArr){
        visited[node]=true;
        dfsArr.push_back(node);
        //traverse all its neighbour
        for(auto it:adj[node]){
            if(!visited[it])
            dfsTraverse(it,visited,adj,dfsArr);
        }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        int st=0; // starting node can vary
      vector<bool>visited(n+1,false); // false ->not visited
      vector<int>dfsArr;
      dfsTraverse(st,visited,adj,dfsArr);
      return dfsArr;
    }