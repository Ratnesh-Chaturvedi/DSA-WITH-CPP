int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxTime = 0;
        int cntFresh = 0;    // to check fresh oranges
        queue<pair<pair<int, int>, int>> q; // row , col ,time
        vector<vector<int>> visited(n,vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }
        // Bfs Code
        int cnt=0; // cnt fresh -> shortcut for -1 case
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            maxTime = max(time, maxTime);
            q.pop();
            // for checking in 4 direction 
            int drow[4] = {-1, 0, 1, 0};
            int dcol[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int row = r + drow[i];
                int col = c + dcol[i];
                if (row >= 0 && row < n && col >= 0 && col < m &&
                    visited[row][col] != 2 && grid[row][col] == 1) {
                    q.push({{row, col}, time + 1});
                    visited[row][col] = 2;
                    cnt++;  // shortcut for the -1 case
                }
            }
        }

        // check whether all oranges are rotted or not
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (visited[i][j] != 2 && grid[i][j] == 1)
        //             return -1;
        //     }
        // }
        // shortcut to do the upper loops  check
         if(cnt!=cntFresh) return -1;

        return maxTime;
    }