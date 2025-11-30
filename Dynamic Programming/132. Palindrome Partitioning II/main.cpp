class Solution {
public:
    bool pal(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int j, string& s, vector<int>& dp) {
        if (pal(i, j, s))
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int cut = 1e5;
        for (int k = i; k < j; k++) {
            if (pal(i, k, s)) {
                // cut only if left substring is palindrome
                int right = 1 + solve(k + 1, j, s, dp);
                cut = min(cut, right);
            }
        }
        return dp[i] = cut;
    }
    int minCut(string s) {
        int n = s.size();
        if (pal(0, n - 1, s))
            return 0;

        // memoization
        // vector<int>dp(n,-1);
        // return solve(0,n-1,s,dp);

        // tabulation
        //  dp[i] = min cuts needed for substring s[i...end]
        vector<int> dp(n + 1, 0);
        //// Base case: no cuts needed beyond the last index
        dp[n] = -1;
        for (int i = n - 1; i >= 0; i--) {
            int cut = 1e9;
            for (int j = i; j < n; j++) {
                if (pal(i, j, s)) {
                    cut = min(cut, 1 + dp[j + 1]);
                }
            }
            dp[i] = cut;
        }
        return dp[0];
    }
};