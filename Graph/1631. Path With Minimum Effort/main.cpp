class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> distance(
            n, vector<int>(m, INT_MAX)); // marking with maximum;
        distance[0][0] = 0;              // source node;
                            // taking a minheap so that we only traverse the
                            // nodes first which have minimum effort
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q; // diffrence , row , col
        q.push({0, {0, 0}});
        while (!q.empty()) {
            int diff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if (row == n - 1 && col == m - 1)
                return diff;
            // moving in 4 direction
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int r = row + dx[i];
                int c = col + dy[i];
                if (r >= 0 && r < n && c >= 0 && c < m) {
                    int effort = abs(h[row][col] - h[r][c]); // calculating the effort between adjacent nodes;
                    int maxEffort = max(diff, effort); // only take the effort which are maximum  because it calculates the  whole path maximum effort   
                    if(maxEffort<distance[r][c]){
                    distance[r][c] = min(maxEffort,distance[r][c]); // checking the minimum effort  required to reach the point
                    q.push({distance[r][c], {r, c}});
                    }
                }
            }
        }
        return -1; // no path 
    }
};