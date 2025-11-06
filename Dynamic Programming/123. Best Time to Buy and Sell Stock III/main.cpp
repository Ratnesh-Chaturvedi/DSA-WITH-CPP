class Solution {
public:
    int solve(int idx, bool buy, int cnt, vector<int>& p,
              vector<vector<vector<int>>>& dp) {
        if (idx == p.size() || cnt == 0)
            return 0;

        if (dp[idx][buy][cnt] != -1)
            return dp[idx][buy][cnt];
        if (buy) {
            return dp[idx][buy][cnt] =
                       max(-p[idx] + solve(idx + 1, !buy, cnt, p, dp), // buy
                           solve(idx + 1, buy, cnt, p, dp));           // skip
        } else {
            return dp[idx][buy][cnt] = max(
                       p[idx] +
                           solve(
                               idx + 1, !buy, cnt - 1, p,
                               dp), // sell and decrement the transaction count
                       solve(idx + 1, buy, cnt, p, dp)); // skip
        }
    }

    // space optimised soltuion
    int solveSP(int i, int tr, vector<int>& p, vector<vector<int>>& sdp) {
        if (i == p.size() || tr == 4)
            return 0;

        if (sdp[i][tr] != -1)
            return sdp[i][tr];
        // buy
        if (tr % 2 == 0) {
            return sdp[i][tr] = max(-p[i] + solveSP(i + 1, tr + 1, p, sdp),
                                    solveSP(i + 1, tr, p, sdp));
        }
        // sell
        else {
            return sdp[i][tr] = max(p[i] + solveSP(i + 1, tr + 1, p, sdp),
                                    solveSP(i + 1, tr, p, sdp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cnt = 2;
        // vector<vector<vector<int>>> dp(
        // n, vector<vector<int>>(2, vector<int>(cnt + 1, -1)));
        // return solve(0, true, cnt, prices, dp);

        // tabultaion
        // vector<vector<vector<int>>> dp(
        // n+1, vector<vector<int>>(2, vector<int>(cnt + 1, 0)));
        // base case
        //  for cpt==0 //  buy and idx can be 0
        //  for idx==n // buy and cap can be 0
        // already zero
        //  for(int idx=n-1;idx>=0;idx--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int cpt=1;cpt<=2;cpt++){
        //             if(buy){

        //              dp[idx][buy][cpt] =
        //                max(-prices[idx] + dp[idx + 1][ !buy][ cpt],  // buy
        //                    dp[idx + 1][ buy][ cpt]); // skip
        //             }
        //             else {
        //                 dp[idx][buy][cpt] =
        //                max(prices[idx] + dp[idx + 1][!buy][cpt - 1],  // sell
        //                and decrement the transaction count
        //                    dp[idx + 1][ buy][cpt]); // skip
        //             }
        //         }
        //     }
        //  }
        //  return dp[0][1][2];

        // we can decrease the space by using 2 array prev and curr

        // space optimised using n*4 array
        vector<vector<int>> sdp(n, vector<int>(4, -1));
        return solveSP(0, 0, prices, sdp);
    }
};