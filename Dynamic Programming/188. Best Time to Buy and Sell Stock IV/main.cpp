class Solution {
public:
    int solve(int idx, bool buy, int k, vector<int>& p,
              vector<vector<vector<int>>>& dp) {
        if (idx == p.size() || k == 0)
            return 0;

        if (dp[idx][buy][k] != -1)
            return dp[idx][buy][k];
        if (buy) {
            return dp[idx][buy][k] =
                       max(-p[idx] + solve(idx + 1, !buy, k, p, dp),
                           solve(idx + 1, buy, k, p, dp));
        } else {
            return dp[idx][buy][k] =
                       max(p[idx] + solve(idx + 1, !buy, k - 1, p, dp),
                           solve(idx + 1, buy, k, p, dp));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // return solve(0, true, k, prices, dp);

        // memoization
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cnt = 1; cnt <= k; cnt++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(profit,
                                     max(-prices[idx] + dp[idx + 1][!buy][cnt],
                                         dp[idx + 1][buy][cnt]));
                    } else {
                        profit = max(profit, max(prices[idx] +
                                                     dp[idx + 1][!buy][cnt - 1],
                                                 dp[idx + 1][buy][cnt]));
                    }
                    dp[idx][buy][cnt] = profit;
                }
            }
        }
        // return dp[0][1][k];

        // space otpimised using 2d array
        vector<vector<int>> prev(2, vector<int>(k + 1, 0)),
            curr(2, vector<int>(k + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cnt = 1; cnt <= k; cnt++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(profit, max(-prices[idx] + prev[!buy][cnt],
                                                 prev[buy][cnt]));
                    } else {
                        profit =
                            max(profit, max(prices[idx] + prev[!buy][cnt - 1],
                                            prev[buy][cnt]));
                    }
                    curr[buy][cnt] = profit;
                }
                prev = curr;
            }
        }
        // return prev[1][k];

        // 1d array space optimised
        vector<int> p(2 * k + 1, 0);
        vector<int> c(2 * k + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int cnt = 2 * k - 1; cnt >= 0; cnt--) {
                int profit = 0;
                if (cnt % 2 == 0) {
                    c[cnt] =
                        max(profit, max(-prices[idx] + p[cnt + 1], p[cnt]));
                } else {
                    c[cnt] = max(profit, max(prices[idx] + p[cnt + 1], p[cnt]));
                }
            }
            p = c;
        }

        return p[0];
    }
};