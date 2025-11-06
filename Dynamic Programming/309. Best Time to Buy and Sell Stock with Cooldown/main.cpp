class Solution {
public:
int solve(int idx, bool buy, vector<int>& p, vector<vector<int>>& dp) {
        if (idx >= p.size())
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];

        if (buy) {
            return dp[idx][buy] = max(-p[idx] + solve(idx + 1, !buy, p, dp),
                                      solve(idx + 1, buy, p, dp));
        } else {
            // cooldown  one day -> by skip the next day 
            // skip the current day
            return dp[idx][buy] = max(p[idx] + solve(idx + 2, !buy, p, dp),
                                      solve(idx + 1, buy, p, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(0,true,prices,dp);

        // memoization
        //same like  buy and sell stock 2 just tweek the condition

            // in tabultaion make sure the size will be n+2 // because to we do idx+2

// most optimised 
vector<int>curr(2,0);
vector<int>ahead1(2,0);
vector<int>ahead2(2,0);
for(int i=n-1;i>=0;i--){
    for(int j=0;j<=1;j++){
        int profit=0;
        if(j%2==0){
        profit=max(-prices[i]+ahead1[1],ahead1[0]);
        }
        else {
            profit=max(prices[i]+ahead2[0],ahead1[1]);
        }
        curr[j]=profit;
    }
    ahead2=ahead1;
    ahead1=curr;
}
return curr[0];
            
    }
};