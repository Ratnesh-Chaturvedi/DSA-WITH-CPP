class Solution {
public:
    int solve(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            // if the 0th index is perfectly divide the amount it means that we
            // can form the amount using that coin;
            if (amt % coins[0] == 0)
                return amt / coins[0];
            return 1e9;
        }
        if (amt < 0)
            return 1e9;

        if (dp[idx][amt] != -1)
            return dp[idx][amt];

        int notpick = solve(idx - 1, amt, coins, dp);
        int pick = 1e9;
        if (coins[idx] <= amt) {
            // we dont move to other index because we may be possibly made the
            // amount by using that coin
            pick = 1 + solve(idx, amt - coins[idx], coins, dp);
        }
        return dp[idx][amt] = min(pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        //     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        //    int ans= solve(n-1,amount,coins,dp);
        //     if(ans>=1e9 ) return -1;
        //     return ans;

        // tabulation
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
    //     for (int t = 0; t <= amount; t++) {
    //         if (t % coins[0] == 0) {
    //             dp[0][t] = t / coins[0];
    //         }
    //     }

    //     for (int i = 1; i < n; i++) {
    //         for (int t = 0; t <= amount; t++) {
    //             int notpick = dp[i - 1][t];
    //             int pick = 1e9;
    //             if (coins[i] <= t) {
    //                 // we dont move to other index because we may be possibly
    //                 // made the amount by using that coin
    //                 pick = 1 +dp[i][t - coins[i]];
    //             }
    //             dp[i][t]=min(pick,notpick);
    //         }
    //     }
    //    int ans=dp[n-1][amount];
    //    if(ans>=1e9) return -1;
    //    return ans;
        

        // space optimised 
        // vector<int> prev(amount + 1, 0),curr(amount+1,0);
        // for(int t=0;t<=amount;t++){
        //     if(t%coins[0]==0){
        //         prev[t]=t/coins[0];
        //     }else prev[t]=1e9;
        // }
        // for(int i=1;i<n;i++){
        //     for(int t=0;t<=amount;t++){
        //         int notpick = prev[t];
        //         int pick = 1e9;
        //         if (coins[i] <= t) {
        //          // it is current because we are using the same coin
        //             pick = 1 + curr[t - coins[i]];
        //         }
        //         curr[t]=min(pick,notpick);
        //     }
        //     prev=curr;
        // }
        // int ans=prev[amount];
        // if(ans>=1e9) return -1;
        // return ans;

        
        
	
    }
};
// single array space optimised 

int coinChange(vector<int>& coins, int amount) {
    // dp[i] will store the minimum number of coins needed to make amount 'i'
    // Initialize with -1 meaning "unreachable" for now
    vector<int> dp(amount + 1, -1);

    // Base case: To make amount 0, we need 0 coins
    dp[0] = 0;

    // Loop through all amounts from 1 to 'amount'
    for (int i = 1; i <= amount; i++) {
        int val = INT_MAX;  // Track the minimum coins needed for current 'i'

        // Try using each coin denomination
        for (auto &j : coins) {
            // Check if using coin 'j' is possible (i >= j) 
            // and the remaining amount (i - j) can be formed (dp[i - j] != -1)
            if (i >= j && dp[i - j] != -1) {
                val = min(dp[i - j], val);  // Keep track of the smallest previous result
            }
        }

        // If we found a valid combination, update dp[i]
        if (val != INT_MAX) {
            dp[i] = 1 + val;  // Add 1 coin (the one we just used)
        }
    }

    // dp[amount] will have the answer.
    // If it's still -1, it means it's not possible to make the given amount.
    return dp[amount];
}