class Solution {
public:
    bool solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (i >= nums.size())
            return false;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        bool left = false;
        if (nums[i] <= sum)
            left = solve(i + 1, sum - nums[i], nums, dp);
        bool right = solve(i + 1, sum, nums, dp);

        return dp[i][sum] = left || right;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int targetsum = sum / 2;
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        //    return solve(0,targetsum,nums,dp);

        // tabulation
        vector<vector<int>> dp(n, vector<int>(targetsum + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (nums[0] <= targetsum)
            dp[0][nums[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= targetsum; target++) {
                bool taken = false;
                if (nums[idx] <= target)
                    taken= dp[idx - 1][target - nums[idx]];
                bool nottaken = dp[idx - 1][target];
                dp[idx][target] = taken || nottaken;
            }
        }
        return dp[n - 1][targetsum];
    }
};
// see space otpimised from TUF article