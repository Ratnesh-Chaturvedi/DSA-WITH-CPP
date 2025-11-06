class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (j < 0)
            return i + 1; // if the second or target string is exhausted
        if (i < 0)
            return j + 1; // if the first string is exhausted
        if (dp[i][j] != -1)
            return dp[i][j];

        // when both same decrement both
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
        }
        // then 3 cases arise
        // insertion -> insert s2[j] in s1
        // deletion -> delete the s1[i] from s1
        // replace -> replace s1[i] with s2[j]
        return dp[i][j] = 1 + min(solve(i - 1, j - 1, s1, s2, dp),
                                  min(solve(i - 1, j, s1, s2, dp),
                                      solve(i, j - 1, s1, s2, dp)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return  solve(n-1,m-1,word1,word2,dp);

        // tabulation
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // // base case
        // for (int i = 0; i <= n; i++)
        //     dp[i][0] = i;
        // for (int j = 0; j <= m; j++)
        //     dp[0][j] = j;

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (word1[i - 1] == word2[j - 1])
        //             dp[i][j] = dp[i - 1][j - 1];

        //         else
        //             dp[i][j] = 1 + min(dp[i - 1][j - 1],
        //                                min(dp[i - 1][j], dp[i][j - 1]));
        //     }
        // }
        // return dp[n][m];

        // space optimised using prev and curr
         vector<int>prev(m+1,0),curr(m+1,0);
         // base case 
         for(int j=0;j<=m;j++) prev[j]=j;

         for(int i=1;i<=n;i++){
            curr[0]=i; // initialise the first colum of the first row -> bcoz it will contain the i th values when the j is exhausted
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }
                else curr[j]=1+min(prev[j-1],min(curr[j-1],prev[j]));
            }
            prev=curr;
         }
    return prev[m];
    }
};