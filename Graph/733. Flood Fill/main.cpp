 void bfs(int row, int col, int color, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int el = grid[row][col];
        q.push({row, col});
        visited[row][col] = true;
        grid[row][col] = color;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // checking in 4 direction
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int rr = r + dx[i];
                int cc = c + dy[i];
                if (rr >= 0 && rr < m && cc >= 0 && cc < n &&
                    !visited[rr][cc] && grid[rr][cc] == el) {
                    visited[rr][cc] = true;
                    q.push({rr, cc});
                    grid[rr][cc] = color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // we can directly change data in that image matrix but is not a good
        // practice to manupulate the given data
        vector<vector<int>> grid = image;
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bfs(sr, sc, color, grid, visited);
        return grid;
    }

