
/*

You are given a 2D array arr[][], of size n, where each element arr[i] is an array of strings representing an account, where the first element arr[i][0] is a name, and the rest of the elements are emails associated with this name. Two accounts belong to the same person if there is a common email associated with both accounts. A person can have any number of accounts initially, but all have the same name.

Your task is to merge these accounts and return them in the following format: the first element of each account is the name, and the rest of the elements are emails in lexicographically sorted order.

Note: Accounts themselves can be returned in any order. Even if two accounts have the same name, they may belong to different people as different people could have the same name.

Examples:

Input: n = 4,
arr[][] =
[["John", "johnsmith@mail.com", "john_newyork@mail.com"],
["John", "johnsmith@mail.com", "john00@mail.com"],
["Mary", "mary@mail.com"],
["John", "johnnybravo@mail.com"]]
Output:
[["John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"],
["Mary", "mary@mail.com"],
["John", "johnnybravo@mail.com"]]
Explanation:
There are three accounts with the same name "John", and two of them share a common email which is "johnsmith@mail.com", thus these two accounts are merged, and remaining two will remain unchanged.
Input: n = 5,
arr[][] =
[["Gabe", "Gabe00@m.co", "Gabe3@m.co", "Gabe1@m.co"],
["Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"],
["Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"],
["Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"],
["Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"]]
Output:
[["Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"],
["Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"],
["Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"],
["Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"],
["Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"]]
Explanation:
There is no common email in any of the users.
Constraints:
1 ≤ n ≤ 1000
2 ≤ accounts[i].size ≤ 10
1 ≤ accounts[i][j].size ≤ 30
accounts[i][0] consists of English letters.

*/


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
