   int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n); // u - v , wt
        // undirected graph
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int mod=(int)(1e9+7);
       vector<long long>distance(n, LLONG_MAX) ; 
       vector<int>ways(n,0) ;  // ways to reach the node with minimum distance
       priority_queue<pair<long long ,int >,
       vector<pair<long long ,int >>,
       greater<pair<long long,int>>> pq;
        // pq store {distance,node} 
        
    pq.push({0,0}); // src node is at distance 0;
    distance[0]=0;
    ways[0]=1; // beccause it is the starting node 
    while(!pq.empty()){
        long long dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        for(auto it:adj[node]){
            int adjNode=it.first;
            int edgeWeight=it.second;
            long long  newWeight=dis+edgeWeight;
            if(newWeight<distance[adjNode]){
                // means it is  node reached at 
                distance[adjNode]=newWeight;
                pq.push({newWeight,adjNode});
                ways[adjNode]=ways[node]; // current node kitne or nodes ke dyara reach kari gayi hai
                
            }
            else if(newWeight==distance[adjNode]){
                // it means the node is already reached 
                // just check will it reached by the shortest distance 
                ways[adjNode]=(ways[node]+ways[adjNode])%mod;
            }
        }
    }
    return ways[n-1];
        
    }