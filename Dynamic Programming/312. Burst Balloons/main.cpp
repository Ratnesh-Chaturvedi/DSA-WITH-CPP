class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = -1e9;
        int n = nums.size();
        for (int idx = i; idx <= j; idx++) {
            int a1 = (i == 0) ? 1 : nums[i - 1];
            int a2 = (j == nums.size() - 1) ? 1 : nums[j + 1];
            int c = a1 * nums[idx] * a2 + solve(i, idx - 1, nums, dp) +
                    solve(idx + 1, j, nums, dp);
            maxi = max(maxi, c);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, n - 1, nums, dp);

        // tabulation

        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxi = 0;
                // if(i>j)  continue;
                for (int idx = i; idx <= j; idx++) {
                    int a1 = nums[i - 1];
                    int a2 = nums[j + 1];
                    int coins =
                        a1 * nums[idx] * a2 + dp[i][idx - 1] + dp[idx + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};