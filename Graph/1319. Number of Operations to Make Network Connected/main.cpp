class DisjointSet {
    vector<int> parent, size;
public:
    // Initialize DSU for 'n' elements
    DisjointSet(int n) {
        parent.resize(n);        // Parent of each node
        size.resize(n, 1);       // Size of each component
        for (int i = 0; i < n; i++) parent[i] = i; // Each node is its own parent
    }
    // Find with path compression
    int findUp(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUp(parent[node]); // Compress path
    }
    // Union two nodes by size
    void unionBySize(int u, int v) {
        int ulp_u = findUp(u);  // Ultimate parent of u
        int ulp_v = findUp(v);  // Ultimate parent of v
        if (ulp_u == ulp_v) return; // Already connected
        // Union by size: attach smaller tree under larger tree
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
// Solution class
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cable = connections.size();
        // Not enough cables to connect all computers
        if (n > cable + 1) return -1;
        DisjointSet ds(n);
        // Union all directly connected computers
        for (int i = 0; i < cable; i++) {
            ds.unionBySize(connections[i][0], connections[i][1]);
        }
        int cnt = 0; // Count of disconnected components
        // Count how many nodes are their own ultimate parent
        for (int i = 0; i < n; i++) {
            if (ds.findUp(i) == i) cnt++;
        }
        // To connect all components, need (cnt - 1) operations
        return cnt - 1;
    }
}; 