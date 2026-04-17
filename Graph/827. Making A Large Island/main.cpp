class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUp(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUp(parent[node]);
    } 

    void unionBySize(int u, int v) {
        int ulp_u = findUp(u);
        int ulp_v = findUp(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int zeroCnt = 0; // for edge case if there is no zero
                         // connecting all the components

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    zeroCnt++;
                    continue;
                }
                int dr[] = {0, 1, 0, -1};
                int dc[] = {1, 0, -1, 0};
                for (int k = 0; k < 4; k++) {
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if (newr < n && newr >= 0 && newc < n && newc >= 0 &&
                        grid[newr][newc] == 1) {
                        int nodeNo = i * n + j;
                        int adjNode = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNode);
                    }
                }
            }
        }
        // find the max size after converting one 0 into 1
        int maxSize = 0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    continue;
                int dr[] = {0, 1, 0, -1};
                int dc[] = {1, 0, -1, 0};
                set<int> adjNodeSize; // to store the unique componets parent
                for (int k = 0; k < 4; k++) {
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if (newr < n && newr >= 0 && newc < n && newc >= 0 &&
                        grid[newr][newc] == 1) {
                        int adjNode = newr * n + newc;
                        adjNodeSize.insert(ds.findUp(adjNode));
                    }
                }
                int totalSize = 0;
                for (auto it : adjNodeSize) {
            totalSize+=ds.size[it];
                }
                maxSize = max(maxSize, totalSize + 1); // +1 in temp because 0->1
            }
        }

        // checking the case if there is no zero in whole matrix
        if (zeroCnt == 0) {
            return n * n;
        }
        return maxSize;
    }
};
