 void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>>q; // row,col,marks 1 if the O is on boundary

               // left side  boundary-> if any 0 appears on left boundary mark it as 1
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                board[i][0] = '1';
                visited[i][0] = true;
                q.push({i, {0, 1}});
            }
        }
        // up side if any 0 appears on top boundary mark it as 1
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                board[0][j] = '1';
                visited[0][j] = true;
                q.push({0, {j, 1}});
            }
        }
        //    right side if any 0 appears on right boundary mark it as 1
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) {
                board[i][n - 1] = '1';
                visited[i][n - 1] = true;
                q.push({i, {n - 1, 1}});
            }
        }
        // bottom side  if any 0 appears on bottom boundary mark it as 1
        for (int j = 0; j < n; j++) {
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) {
                board[m - 1][j] = '1';
                visited[m - 1][j] = true;
                q.push({m - 1, {j, 1}});
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second.first;
            int boundary = q.front().second.second;
            q.pop();
            // check in 4 direction that there exist any 1
            int drow[4] = {-1, 0, 1, 0};
            int dcol[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int r = row + drow[i];
                int c = col + dcol[i];
                if (r < m && r >= 0 && c < n && c >= 0 && !visited[r][c] &&
                    board[r][c] == 'O') {
                    visited[r][c] = true;
                    q.push({r, {c, 1}});
                    board[r][c] ='1'; // marks if the element O is connect to boundary O
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }