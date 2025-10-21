class Solution {
public:
    int solve(int idx, vector<int>& n, vector<int>& dp) {
        if (idx < 0)
            return 0;
        if (idx == 0)
            return n[idx];
        if (dp[idx] != -1)
            return dp[idx];

        int first = n[idx] + solve(idx - 2, n, dp);
        int second = solve(idx - 1, n, dp);
        return dp[idx] = max(first, second);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> dp(n, -1);
        //By memoization
        // return solve(n - 1, nums, dp);
        
        
        // using tabulation 
        // dp[0]=nums[0];
        // dp[1]=max(nums[1],nums[0]);
        
        // for(int i=2;i<n;i++){
        // int f=dp[i-1];
        // int sec=nums[i]+dp[i-2];
        // dp[i]=max(f,sec);
        // }
        //  return dp[n-1];
        

        // space optimisation;
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nontake=prev;
            int curr=max(take,nontake);
            prev2=prev;
            prev=curr;
        }
        return prev;

    }
};