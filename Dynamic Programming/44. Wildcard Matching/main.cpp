class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (j < 0 && i < 0)
            return true; // both get s and p exhausted
        if (j < 0 && i >= 0)
            return false;      // p is exhausted but s is remain
        if (i < 0 && j >= 0) { // p has element left and s get exhausted
            for (int idx = 0; idx <= j; idx++) {
                if (p[idx] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }
        // *
        else {
            // trying all posible subsequences where star can replace
            if (p[j] == '*')
                return dp[i][j] = solve(i - 1, j, s, p, dp) ||
                                  solve(i, j - 1, s, p, dp);
            else
                return false; // if it has other character which are not
                              // matching
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,s,p,dp);

        // tabulation
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // base cases
        // we can convert memoization in one based indexing
        // which helps to understand better the basecases for tabulation
        //  if(j==0 && i==0) return true
        dp[0][0] = true;
        // if(j==0 && i>0) return false
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;
        // if(i==0 && j>0)
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if (p[j-1] == '*') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    } else
                        dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

// space optimised 
// TUF article
