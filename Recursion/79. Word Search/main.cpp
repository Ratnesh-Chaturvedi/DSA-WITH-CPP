class Solution {
public:
    bool solve(int idx, vector<vector<char>>& b, vector<vector<bool>>& vis,
               string s, string& word, int row, int col) {
        if (s == word) {       
            return true;
        }
       
        int m = b.size(), n = b[0].size();
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int i = row +dr[k];
            int j = col+ dc[k];
            if (i >= 0 && i < m && j >= 0 && j < n && !vis[i][j]) {
                if (word[idx] == b[i][j]) {
                    s += b[i][j];
                    vis[i][j] = true;
                if( solve(idx + 1, b, vis, s, word, i, j))return true;
                vis[i][j]=false;
                s.pop_back();
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    string s = "";
                    vector<vector<bool>> vis(m, vector<bool>(n, false));
                    s += board[i][j];
                    vis[i][j]=true;
                    if(solve(1, board, vis, s, word, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};