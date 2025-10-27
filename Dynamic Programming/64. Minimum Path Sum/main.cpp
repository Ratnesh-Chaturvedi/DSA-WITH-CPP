class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1 && j == n - 1) {
            return grid[m - 1][n - 1];
        }
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = INT_MAX, down = INT_MAX;
        if (i + 1 < m)
            left = grid[i][j] + solve(i + 1, j, grid, dp);
        if (j + 1 < n)
            down = grid[i][j] + solve(i, j + 1, grid, dp);
        return dp[i][j] = min(left, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, grid, dp);

        // tabulation format
        // dp[0][0] = grid[0][0];
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 && j == 0)
        //             dp[0][0] = grid[0][0];
        //         else {
        //             int left = INT_MAX, down = INT_MAX;
        //             if (i>0)
        //                 left = grid[i][j] + dp[i-1][j];
        //             if (j>0)
        //                 down = grid[i][j] + dp[i][j-1];
        //             dp[i][j]=min(left,down);    
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // space optimised like previous but here we use the grid which is given but we cal also used an array of size n which store the row and it can change at each step  dp 
           
           for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                 else {
                    int left = INT_MAX, down = INT_MAX;
                    if (i>0)
                        left = grid[i][j] + grid[i-1][j];
                    if (j>0)
                        down = grid[i][j] + grid[i][j-1];
                    grid[i][j]=min(left,down);    
                }
            }
           }

    return grid[m-1][n-1];

    }
};