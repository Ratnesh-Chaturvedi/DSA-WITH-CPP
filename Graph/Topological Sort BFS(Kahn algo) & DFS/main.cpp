   void DFS(int node,stack<int>&st,vector<bool>&vis,vector<vector<int>>&adj){
       vis[node]=true; // marks as visited 
       for(auto it:adj[node]){
           if(!vis[it]){
               DFS(it,st,vis,adj);
           }
           
       }
       
       st.push(node);  // push the node when all calls are ended
   }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adj(V,vector<int>(V,0)); //adjacency list 
       vector<bool>vis(V,false); // visited array
       stack<int>st;
       for(auto it:edges){
           adj[it[0]].push_back(it[1]); // marking edges 
       }
       
       for(int i=0;i<V;i++){
           if(!vis[i]){
               DFS(i,st,vis,adj);
           }
       }
       vector<int>ans; // for storing final ans 
       while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
       }
        return ans;
    }






    // using BFS
    // It is also known as KAHN algorithm
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adj(V); //adjacency list 
          vector<int>indegree(V,0);
       for(auto it:edges){
           adj[it[0]].push_back(it[1]);// marking edges
           indegree[it[1]]++;
       }
       vector<int>topo; // for storing the element in topological order
       queue<int>q; 
       for(int i=0;i<V;i++){
           if(indegree[i]==0) q.push(i);
       }
       while(!q.empty()){
           int top=q.front();
           q.pop();
           topo.push_back(top);
           for(auto it:adj[top]){
               indegree[it]--;
               if(indegree[it]==0) q.push(it); // if degree becomes 0 push it into Q 
           }
       }
       return topo;
       
    }