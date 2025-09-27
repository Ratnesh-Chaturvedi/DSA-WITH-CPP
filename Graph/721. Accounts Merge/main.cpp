// Disjoint Set (Union-Find) class with union by size and path compression
class DisjointSet {
    vector<int> parent, size;

public:
    // Constructor initializes parent and size arrays
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is initially its own parent
        }
    }

    // Find with path compression
    int findUp(int node) {
        if (node == parent[node]) return node; // Base case: parent of itself
        return parent[node] = findUp(parent[node]); // Path compression
    }

    // Union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUp(u); // Ultimate parent of u
        int ulp_v = findUp(v); // Ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in the same set

        // Union the smaller set into the larger one
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

// Solution class to merge accounts using DSU
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        DisjointSet ds(n); // Initialize DSU with number of accounts

        unordered_map<string, int> hash; // Maps email to account index

        // Step 1: Map each email to its account index or union if already seen
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < acc[i].size(); j++) {
                string mail = acc[i][j];
                if (hash.find(mail) == hash.end()) {
                    hash[mail] = i; // First time seeing this email
                } else {
                    ds.unionBySize(hash[mail], i); // Union current and previous account
                }
            }
        }

        // Step 2: Group all emails belonging to the same connected component
        vector<vector<string>> mails(n);
        for (auto it : hash) {
            string mail = it.first;
            int node = ds.findUp(it.second); // Find root account index
            mails[node].push_back(mail); // Group email under root
        }

        // Step 3: Build the final answer
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mails[i].size() != 0) {
                string accHolder = acc[i][0]; // Account holder's name
                sort(mails[i].begin(), mails[i].end()); // Sort emails
                vector<string> temp;
                temp.push_back(accHolder);
                for (int j = 0; j < mails[i].size(); j++) {
                    temp.push_back(mails[i][j]);
                }
                ans.push_back(temp); // Add to result
            }
        }

        return ans;
    }
};
