
// we can use both queue or priority queue  here we use queue because weight are 1 and it maintain in increasing order when they enter into    queue and the front elemnent is the smallest wt element 


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        vector<int> distance(n+1, INT_MAX);
       
        queue<pair<int, int>> q; // wt,node

        distance[k]=0;
        q.push({0, k});
        while (!q.empty()) {
            int w = q.front().first;
            int node = q.front().second;
            q.pop();
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int adjW = it.second;
                if (distance[adjNode]>adjW +w) {
                    distance[adjNode]=adjW+w;
                    q.push({ distance[adjNode],adjNode});
                }
            }
        }
        
        int minW = INT_MIN;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;
            minW=max(distance[i],minW);
        }
        return minW;
    }
};