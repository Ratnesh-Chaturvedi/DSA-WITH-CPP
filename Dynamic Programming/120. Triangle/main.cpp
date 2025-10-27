class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        if (i == triangle.size() - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        
       int  down = triangle[i][j] + solve(i + 1, j, triangle, dp);
       int  diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
         // Memoization -> Gives TLE
    //      solve(0, 0, triangle, dp);
    //   int ans=INT_MAX;
    //   for(int i=0;i<n;i++){
    //     ans=min(ans,dp[n-1][i]);
    //   }
    //   return ans;
        // tabulation
        // for(int j=0;j<n;j++)dp[n-1][j]=triangle[n-1][j];
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int down=triangle[i][j]+dp[i+1][j]; 
        //         int diagonal=triangle[i][j]+dp[i+1][j+1];
        //         dp[i][j]=min(diagonal,down);
        //     }
        // }
        // return dp[0][0];


        // space optimised 
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
         dp[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
        vector<int>curr(n,-1);
        for(int j=i;j>=0;j--){
              int down=triangle[i][j]+dp[j]; 
                int diagonal=triangle[i][j]+dp[j+1];
                curr[j]=min(diagonal,down);
        }
        dp=curr;
        }
    return dp[0];
    }

};