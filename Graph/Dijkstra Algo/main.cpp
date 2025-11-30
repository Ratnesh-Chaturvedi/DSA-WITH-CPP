// Approach 1 -> using priority queue
// V is no of Node ,S is the source Node
vector<int>shortestPath(vector<vector<int>>edges,int V ,int S){
     // Adjacency list to store graph: node -> list of {adjacentNode, weight}
        vector<vector<pair<int,int>>> adj(n+1);
    // Build the undirected weighted graph
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // Because the graph is undirected
        }
// creating a priority queue // it stores {distance,node } 
// we are building the minHeap
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
// creating a  distance array to store the distance from each node
vector<int>distance(V,INT_MAX) ; 
distance[S]=0; // because Source to Source the distance travelled is 0
pq.push({0,S});

while(!pq.empty()){
    int d=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it:adj[node]){
       int adjNode = it.first;
        int wt = it.second;
        if(d+wt<distance[adjNode]){
            distance[adjNode]=d+wt;
            pq.push({distance[adjNode],adjNode});
        }
    }
}
 
return distance;



}


// Approach 2 -> using Set
vector<int>shortestPath(vector<vector<int>>edges,int V ,int S){
     // Adjacency list to store graph: node -> list of {adjacentNode, weight}
        vector<vector<pair<int,int>>> adj(n+1);
    // Build the undirected weighted graph
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // Because the graph is undirected
        }
          
        vector<int>distance(V,INT_MAX);
        set<pair<int,int>>st; // distance , node 
        distance[S]=0; // source distance=0
        st.insert({0,S});
        while(!st.empty()){
            auto it=*(st.begin()) ; // it will give the top or smallest distance node
            int d=it.first;
            int node=it.second;
            st.erase(it); // erasing the top element
            for(auto it:adj[node]){
                 int adjNode = it.first;
                int wt = it.second;
                // if the node is already in the set , so erase it  
                if(distance[adjNode]!=INT_MAX) {
                   st.erase({distance[adjNode],adjNode});
                }
                distance[adjNode]=d+wt;
                st.insert({distance[adjNode],adjNode});

            }
        }
        return distance;
}
