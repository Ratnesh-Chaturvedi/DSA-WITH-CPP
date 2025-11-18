class Solution {
public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int idx = i; idx <= j; idx++) {
            int cost = arr[j + 1] - arr[i - 1] + solve(i, idx - 1, arr, dp) +
                       solve(idx + 1, j, arr, dp);
            mini = min(cost, mini);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        // we can use the cuts array but we dont want to change the given input
        // adding 0 in front and n at end;
        vector<int> arr = cuts;
        arr.push_back(0);
        arr.push_back(n);
        // make array independent
        sort(arr.begin(), arr.end());
        // dp will be size of the cuts array
        int m = cuts.size();
        //  vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        //  int size=arr.size();
        //  return solve(1,size-2,arr,dp);

        // tabulation
        //  base case when i>j and our dp is already has all 0
       // for out of bound me do m+2 size dp
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
        for (int i = m; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                int mini = 1e9;
                if (i > j)
                    continue;
                for (int idx = i; idx <= j; idx++) {
                    int cost = arr[j + 1] - arr[i - 1] + dp[i][idx - 1] +
                               dp[idx + 1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m];
    }
};