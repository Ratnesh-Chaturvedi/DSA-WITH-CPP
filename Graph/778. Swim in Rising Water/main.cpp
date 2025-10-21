class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int miniD = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // distance , r ,c to that point
        vector<bool> visited(n * n, false);
        int dis = grid[0][0];
        pq.push({dis, {0, 0}});
        visited[0] = true;
        while (!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            miniD = max(miniD, d);
            if (row == n - 1 && col == n - 1)
                return miniD;
            int dr[] = {0, 1, 0, -1};
            int dc[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int adjr = row + dr[i];
                int adjc = col + dc[i];

                if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n) {
                    int nodeIdx = adjr * n + adjc;
                    if (!visited[nodeIdx]) {
                        visited[nodeIdx] = true;
                        pq.push({grid[adjr][adjc], {adjr, adjc}});
                    }
                }
            }
        }
        return miniD;
    }
};