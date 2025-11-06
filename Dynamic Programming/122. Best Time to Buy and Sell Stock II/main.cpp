class Solution {
public:
    int solve(int idx, bool buy, vector<int>& p, vector<vector<int>>& dp) {
        if (idx == p.size())
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        if (buy) {
            // we can either sell or not sell
            return dp[idx][buy] = max(-p[idx] + solve(idx + 1, !buy, p, dp),
                                      solve(idx + 1, buy, p, dp));
        } else {
            // either we can buy or dont buy
            return dp[idx][buy] = max(p[idx] + solve(idx + 1, !buy, p, dp),
                                      solve(idx + 1, buy, p, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // bool buy = true; // beacuse at 0th day we can only buy
        // return solve(0,buy,prices,dp);

        // tabulation
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // //  base case
        // dp[n][0] = dp[n][1] = 0;

        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = 0; j <= 1; j++) {
        //         int profit = 0;
        //         if (j) {
        //             profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
        //         } else {
        //             profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
        //         }
        //         dp[i][j] = profit;
        //     }
        // }
        // return dp[0][1];

        // space optimised 
        vector<int>ahead(2,0),curr(2,0);
       // base cases
        ahead[0]=ahead[1]=0;
             for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                int profit = 0;
                if (j) {
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                } else {
                    profit = max(prices[i] + ahead[1], ahead[0]);
                }
                curr[j] = profit;
            }
            ahead=curr;
        }
        return ahead[1];

        // we can also do it used four variable 
        // loop n-1 to 0 
        // aheadbuy=0,aheadnotbuy=0,currbuy=0,currnotbuy=0;
        // 0 and 1 j hamesha chalega so directly do
        // currnotbuy=max(aheadbuy+prices[i],aheadnotbuy)
        // currbuy=max(aheadbuy,-prices[i]+aheadnotbuy)
        // aheadbuy=currbuy;
        // aheadnotbuy=currnotbuy;
        //return aheadbuy
    }
};