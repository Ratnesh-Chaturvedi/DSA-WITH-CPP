class Solution {
public:
    // Recursive + Memoization approach
    int solve(int i, vector<int>& arr, int& k, vector<int>& dp) {
        // Base case: if we reach beyond the array, sum is 0
        if (i >= arr.size())
            return 0;

        // Return already computed result for index i
        if (dp[i] != -1)
            return dp[i];

        int maxi = 0;  // maximum element in the current subarray
        int mxsum = 0; // maximum sum we can get starting from index i

        // Try all subarrays starting at i with length <= k
        for (int j = i; j < i + k && j < arr.size(); j++) {
            maxi = max(arr[j], maxi); // update maximum element in current subarray
            int len = j - i + 1;      // length of current subarray
            int sum = maxi * len;     // sum if we replace all elements with maxi
            // Recursively calculate sum for remaining array and take maximum
            mxsum = max(mxsum, sum + solve(j + 1, arr, k, dp));
        }

        // Memoize result for index i
        return dp[i] = mxsum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // -----------------------
        // Memoization approach:
        // vector<int> dp(n, -1);
        // return solve(0, arr, k, dp);
        // -----------------------

        // Tabulation approach (Bottom-up DP)
        vector<int> dp(n + 1, 0); // dp[i] stores maximum sum starting from index i

        // Fill dp array from right to left
        for (int i = n - 1; i >= 0; i--) {
            int maxi = 0;  // maximum element in the current subarray
            int mxsum = 0; // maximum sum we can get starting from index i

            // Try all subarrays starting at i with length <= k
            for (int j = i; j < i + k && j < n; j++) {
                maxi = max(arr[j], maxi);   // update maximum element in current subarray
                int len = j - i + 1;        // length of current subarray
                int sum = maxi * len;       // sum if we replace all elements with maxi
                // Add maximum sum of remaining array (dp[j+1]) and take maximum
                mxsum = max(mxsum, sum + dp[j + 1]);
            }

            dp[i] = mxsum; // store maximum sum starting from index i
        }

        return dp[0]; // maximum sum for the whole array
    }
};
