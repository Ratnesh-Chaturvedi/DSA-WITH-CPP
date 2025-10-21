class Solution {
public:

    // Recursive function with memoization to count paths
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        // Base case: reached bottom-right corner
        if (i == m - 1 && j == n - 1)
            return 1;
        // Out of bounds check
        if (i >= m || j >= n)
            return 0;
        // If already computed, return memoized result
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = 0, down = 0;
        // Check down movement is within bounds and not an obstacle
        if (i < m - 1 && grid[i + 1][j] != 1) {
            left = solve(i + 1, j, grid, dp);
        }
        // Check right movement is within bounds and not an obstacle
        if (j < n - 1 && grid[i][j + 1] != 1) {
            down = solve(i, j + 1, grid, dp);
        }
        // Store and return the total paths from current cell
        return dp[i][j] = left + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // If start or end is blocked, no path exists
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return 0;
        // -------------------------------
        // Uncomment this block to use memoization
        //
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(0, 0, grid, dp);
        // -------------------------------
        // -------------------------------
        // Uncomment this block to use bottom-up tabulation
        //
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[0][0] = 1;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 && j == 0)
        //             dp[i][j] = 1;
        //         else {
        //             int left = 0;
        //             int down = 0;
        //             if (i >= 1 && grid[i - 1][j] != 1) {
        //                 left = dp[i - 1][j];
        //             }
        //             if (j >= 1 && grid[i][j - 1] != 1) {
        //                 down = dp[i][j - 1];
        //             }
        //             dp[i][j] = left + down;
        //         }
        //     }
        // }
        // return dp[m - 1][n - 1];
        // -------------------------------
        // Space-optimized bottom-up DP
        vector<int> dp(n, -1);  // Previous row
        dp[0] = 1;              // Start point
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);  // Current row
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    curr[j] = 0;  // Obstacle, no paths
                } else if (i == 0 && j == 0) {
                    curr[j] = 1;  // Start cell
                } else {
                    int left = 0;
                    int down = 0;
                    // If we can come from the top
                    if (i > 0 && grid[i - 1][j] != 1) {
                        left = dp[j];
                    }
                    // If we can come from the left
                    if (j > 0 && grid[i][j - 1] != 1) {
                        down = curr[j - 1];
                    }
                    curr[j] = left + down;
                }
            }
            // Update dp with current row for next iteration
            dp = curr;
        }
        return dp[n - 1];
    }
};