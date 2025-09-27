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









    // Another Solution Using DSU

    // Disjoint Set (Union-Find) class with Union by Size and Path Compression
class DisjointSet {
    vector<int> parent, size;
public:
    // Constructor to initialize DSU for 'n' elements (0-based indexing)
    DisjointSet(int n) {
        parent.resize(n + 1);       // Parent array to keep track of each node's leader
        size.resize(n + 1, 1);      // Size array to track the size of each set

        // Initially, every node is its own parent (leader of itself)
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    // Find function with path compression
    int findUp(int node) {
        // If the node is the leader of its set, return it
        if (node == parent[node]) return node;
        // Else, recursively find the leader and compress the path
        return parent[node] = findUp(parent[node]);
    }
    // Union by size: attach smaller tree under larger tree
    void unionBySize(int u, int v) {
        int ulp_u = findUp(u); // Find ultimate parent of u
        int ulp_v = findUp(v); // Find ultimate parent of v
        // If both nodes have the same parent, they're already in the same set
        if (ulp_u == ulp_v) return;
        // Attach the smaller set to the larger one
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
// Solution class to solve the problem using DSU
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();     // Number of cities (nodes)
        DisjointSet ds(n);              // Initialize DSU for n cities
        // Traverse the adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If city i and city j are directly connected, union them
                if (isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt = 0; // To count number of provinces
        // Count how many nodes are their own ultimate parent
        // These represent distinct connected components
        for (int i = 0; i < n; i++) {
            if (ds.findUp(i) == i) cnt++;
        }

        return cnt; // Total number of provinces
    }
};
