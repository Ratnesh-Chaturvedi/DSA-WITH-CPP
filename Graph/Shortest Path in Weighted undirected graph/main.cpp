class Solution {
  public:
     /// By using Dijkstra Algo
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
         // Min-heap: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Initialize distance array with INT_MAX
        vector<int> distance(n+1, INT_MAX);

        // Parent array to reconstruct the shortest path
        vector<int> parent(n+1);

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

        // Initialize parent of each node to itself
        for (int i = 1; i <= n; i++) parent[i] = i;

        // Start from node 1
        distance[1] = 0;
        pq.push({0, 1});  // {distance, node}

        // Dijkstra's Algorithm
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                // If a shorter path to adjNode is found
                if (d + wt < distance[adjNode]) {
                    distance[adjNode] = d + wt;
                    parent[adjNode] = node;  // Track parent to reconstruct path
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        // If destination node `n` is unreachable
        if (distance[n] == INT_MAX) return {-1};

        // Reconstruct shortest path from node 1 to node n using parent array
        vector<int> path;
        int currentNode = n;

        // Trace back from destination to source
        while (parent[currentNode] != currentNode) {
            path.push_back(currentNode);
            currentNode = parent[currentNode];
        }

        // Finally push the source node (1)
        path.push_back(1);
        path.push_back(distance[n]);

        // Reverse the path to get it from source to destination
        reverse(path.begin(), path.end());

        return path;
    }
};