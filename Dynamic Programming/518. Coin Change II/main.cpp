using ll= long long  ;
class Solution {
public:
    int solve(int i, int target, vector<int>& c, vector<vector<int>>& dp) {

        if (i == 0) {
            int cnt = 0;
            if (target % c[0] == 0)
                cnt++;

            return cnt;
        }
        // not pick
        if (dp[i][target] != -1)
            return dp[i][target];
        int notPick = solve(i - 1, target, c, dp);
        int pick = 0;
        if (c[i] <= target) {
            pick = solve(i, target - c[i], c, dp);
        }

        return dp[i][target] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // return solve(n-1,amount,coins,dp);

        // tabultaion buts gives overflow
//         vector<vector<ll>> dp(n, vector<ll>(amount + 1, 0));
   
//     for(int i=0;i<=amount;i++){
//             if(i%coins[0]==0) dp[0][i]=1;
//     }
 
//        for (int ind = 1; ind < n; ind++) {
//         for (int target = 0; target <= amount; target++) {
//             ll notTaken = dp[ind - 1][target];

//             ll taken = 0;
//             if (coins[ind] <= target)
//                 taken = dp[ind][target - coins[ind]];

//             dp[ind][target] = (ll)(notTaken + taken);
//         }
//     }
//     return (int)dp[n - 1][amount];


     // space optimised 
//      vector<int>prev(amount+1,0),curr(amount+1,0);
//       for(int i=0;i<=amount;i++){
//             if(i%coins[0]==0) prev[i]=1;
//     }
//       for (int ind = 1; ind < n; ind++) {
//         for (int target = 0; target <= amount; target++) {
//             ll notTaken =prev[target];

//             ll taken = 0;
//             if (coins[ind] <= target)
//                 taken =curr[target-coins[ind]];

//             curr[target] = (ll)(notTaken + taken);
//         }
//         prev=curr;
//     }
//  return prev[amount];



// }

   

};


// single array using concept knapsack 
int change(int amount, vector<int>& coins){
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        
        for(int coin : coins){
            for(int j = coin; j <= amount; j++){
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }