 int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        // floyd warshall 
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < 1e9 && dist[k][j] < 1e9)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int mini = INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt) cnt++;
            }
            if(cnt<=mini){
                ans=max(i,ans);
                mini=min(cnt,mini);
            }
        }
        return ans;
    }