 // Breadth-First Search to traverse all nodes connected to the given node
    void bfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int nd = q.front();
            q.pop();

            // Traverse all possible neighbors of current node
            for (int i = 0; i < n; i++) {
                // If there is a connection and the neighbor hasn't been visited yet
                if (isConnected[nd][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i); // Add neighbor to queue for further exploration
                }
            }
        }
    }

    // Main function to count the number of provinces
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false); // Track visited nodes
        int cnt = 0; // Count of provinces

        // Loop over all nodes (cities)
        // ❗ Remember: Don't loop from 1 to n, use 0 to n-1 (0-indexed)
        for (int i = 0; i < n; i++) {
            // If the node hasn't been visited, it starts a new province
            if (!visited[i]) {
                cnt++;              // New province found
                bfs(i, visited, isConnected); // Mark all connected nodes
            }
        }

        return cnt; // Total number of provinces
    }