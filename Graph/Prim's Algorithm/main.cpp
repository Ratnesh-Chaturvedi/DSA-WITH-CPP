// Returns total MST weight and fills mstEdges with edges in MST
    int spanningTree(int V, vector<vector<int>>& edges, vector<pair<int,int>>& mstEdges) {
        vector<vector<pair<int,int>>> adj(V); // {neighbor, weight}
        
        for (auto &it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min-heap {weight, node, parent}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        vector<bool> visited(V, false);
        int totalWt = 0;

        pq.push({0, 0, -1});  // weight=0, start node=0, parent=-1 (no parent)

        while (!pq.empty()) {
            auto [wt, node, parent] = pq.top();
            pq.pop();

            if (visited[node]) continue;

            visited[node] = true;
            totalWt += wt;

            // If node has a parent, add this edge to MST edges list
            if (parent != -1) {
                mstEdges.push_back({parent, node});
            }

            for (auto &[adjNode, edWt] : adj[node]) {
                if (!visited[adjNode]) {
                    pq.push({edWt, adjNode, node});
                }
            }
        }

        return totalWt;
    }