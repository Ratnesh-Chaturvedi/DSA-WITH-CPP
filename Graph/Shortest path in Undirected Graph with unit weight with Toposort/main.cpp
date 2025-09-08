   vector<int> shortestPath(vector<vector<int>>& adj, int src) {
      int n=adj.size();
      vector<int>distance(n,-1);
      
      queue<pair<int,int>>q; // node ,distance
     distance[src]=0;
     q.push({src,0});
     while(!q.empty()){
         int node=q.front().first;
         int d=q.front().second;
         q.pop();
         for(auto it:adj[node]){
             if(distance[it]==-1){
                 distance[it]=d+1; // the node visited first through the path is the shortest path 
                 q.push({it,d+1});
             }
         }
     }
     
     return distance;
         
    }