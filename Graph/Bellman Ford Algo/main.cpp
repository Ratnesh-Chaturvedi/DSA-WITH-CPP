vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // assignning distance array with the max value ->here it is 1e8
        vector<int>distance(V,1e8);
        distance[src]=0;
        // run the loop n-1 times // n-> number of nodes
        for(int i=0;i<V;i++){
            // iterate over the  edges
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                // checking whether it is has smaller distance or node to react that node 
                if(distance[u]!=1e8 && distance[u]+wt<distance[v]){
                    distance[v]=distance[u]+wt;
                }
            }
        }
        
        // checking for negative cycle -> Nth iteration 
        for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                // checking whether it is has smaller distance or node to react that node 
                if(distance[u]!=1e8 && distance[u]+wt<distance[v]){
                   return {-1}; // return -1 // it has negative cycle because the distance is reduced 
                }
            }
        return distance;
    }