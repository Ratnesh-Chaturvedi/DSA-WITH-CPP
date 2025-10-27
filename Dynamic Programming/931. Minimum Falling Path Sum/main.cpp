class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (i == n - 1 && j < n && j >= 0) {
            return matrix[i][j];
        }
        if (j >= n || j < 0)
            return 0;
        if (dp[i][j] != 1e9)
            return dp[i][j];
        int down = INT_MAX, dleft = INT_MAX, dright = INT_MAX;
        if (i + 1 < n)
            down = matrix[i][j] + solve(i + 1, j, dp, matrix);
        if (j - 1 >= 0)
            dleft = matrix[i][j] + solve(i + 1, j - 1, dp, matrix);
        if (j + 1 < n)
            dright = matrix[i][j] + solve(i + 1, j + 1, dp, matrix);

        return dp[i][j] = min(down, min(dright, dleft));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) {
            return matrix[0][0];
        }

        // // Memoization
        // vector<vector<int>>dp(n,vector<int>(n,1e9));
        // int mini=INT_MAX;
        // for(int j=0;j<n;j++){
        //    mini=min(mini,solve(0,j,dp,matrix));
        // }

        // tabulation
        // vector<vector<int>> dp(n, vector<int>(n, 1e9));
        // base case 
        // for (int i = 0; i < n; i++)
        //     dp[0][i] = matrix[0][i];

        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         int down = INT_MAX, dleft = INT_MAX, dright = INT_MAX;
        //         if (i - 1 >= 0)
        //             down = matrix[i][j] +dp[i-1][j];
        //         if (j - 1 >= 0)
        //             dleft = matrix[i][j] +dp[i-1][j-1] ;
        //         if (j + 1 < n)
        //             dright = matrix[i][j] + dp[i-1][j+1];

        //         dp[i][j] = min(down, min(dright, dleft));
        //     }
        // }
        // int mini = INT_MAX;
        // for (int i = 0; i < n; i++) {
        //     mini = min(mini, dp[n - 1][i]);
        // }
        // return mini;


        // space optimised 
        vector<int>dp(matrix[0]);
      
          for(int i=1;i<n;i++){
            vector<int>curr(n);
            for(int j=0;j<n;j++){
                 int down = INT_MAX, dleft = INT_MAX, dright = INT_MAX;
                    down = matrix[i][j] + dp[j];
                if (j > 0)
                    dleft = matrix[i][j] +dp[j-1] ;
                if (j +1 < n)
                    dright = matrix[i][j] + dp[j+1];
                    curr[j]=min(down,min(dright,dleft));
            }
            dp=curr;
          }  
          int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, dp[i]);
        }
        return mini;
    }
};