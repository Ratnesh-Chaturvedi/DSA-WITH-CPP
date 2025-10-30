class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, string& s1, string& s2) {
        // if we do for shifted index we apply for i==0 || j==0 which represent
        // -1
        if (i < 0 || j < 0)
            return 0;

        // if we used shifted index we do for i-1 and j-1
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, dp, s1, s2);
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = max(solve(i - 1, j, dp, s1, s2),
                              solve(i, j - 1, dp, s1, s2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // if we use shifted idx we make size of n+1,m+1;
        // vector<vector<int>>dp(n,vector<int>(m,-1));

        // return solve(n-1,m-1,dp,text1,text2);

        // tabulation ;
        // in dp[-1] doest not exist  so we shift the indexes by one
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        // we already covered for -1
        // start from 1 because we shifted the indexes

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
               else  dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];

        // space optmised 
        vector<int>prev(n+1,0),curr(n+1,0);
            for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + prev[j - 1];
                }
               else  curr[j] = max(prev[j], curr[j - 1]);
            }
        }
return prev[n];
    }
};


// Printring the longested common subsequnce we use the Tabulation table 
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (text1[i - 1] == text2[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
}

int ansSize = dp[n][m];
string lcsString(ansSize, '$');
int i = n, j = m, idx = ansSize - 1;

while (i > 0 && j > 0) {
    if (text1[i - 1] == text2[j - 1]) {
        lcsString[idx] = text1[i - 1];
        i--, j--;
        idx--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
    } else {
        j--;
    }
}

cout << lcsString;
return dp[n][m];