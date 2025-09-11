int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency list: adj[node] = vector of {neighbour, cost}
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Distance vector initialized to INT_MAX
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        // Queue for BFS: {stops, {node, total_cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            // If stops exceed k, skip further traversal
            if (stops > k) continue;

            // Traverse all adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                // If a cheaper cost path is found, update and enqueue
                if (cost + wt < distance[adjNode]) {
                    distance[adjNode] = cost + wt;
                    q.push({stops + 1, {adjNode, cost + wt}});
                }
            }
        }

        // If destination is unreachable, return -1
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }