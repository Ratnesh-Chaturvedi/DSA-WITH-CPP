class Solution {
public:

 //  question is exact similar to the buy and sell stock II
// only include fee

 int solve(int idx, bool buy, vector<int>& p, vector<vector<int>>& dp,int &fee) {
        if (idx == p.size())
            return 0;

        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        
        // its your choice to pay fee when u buy stocks or sell stocks
        // i am here pay fee when we biu stocks 
        if (buy) {
            
            return dp[idx][buy] = max(-p[idx] -fee + solve(idx + 1, !buy, p, dp,fee) ,
                                      solve(idx + 1, buy, p, dp,fee));
        } else {
            
            return dp[idx][buy] = max(p[idx] + solve(idx + 1, !buy, p, dp,fee) ,
                                      solve(idx + 1, buy, p, dp,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
       
      return   solve(0,true,prices,dp,fee );
        
       
    }
};