class Solution {
public:
    int solve(int idx, vector<int>& n, vector<int>& dp) {
        if (idx < 0)
            return 0;
        if (idx == 0) {
            return n[0];
        }
        if (dp[idx] != -1)
            return dp[idx];
        int first = n[idx] + solve(idx - 2, n, dp);
        int second = solve(idx - 1, n, dp);

        return dp[idx] = max(first, second);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        // Case 1: Exclude first house
        vector<int> temp1(nums.begin() + 1, nums.end());
        vector<int> dp1(n - 1, -1);
        int ans1 =
            solve(n - 2, temp1, dp1); // size is n-1, so last index is n-2

        // Case 2: Exclude last house
        vector<int> temp2(nums.begin(), nums.end() - 1);
        vector<int> dp2(n - 1, -1);
        int ans2 = solve(n - 2, temp2, dp2);
        return max(ans1, ans2);
    }
};

// diretly space optimised

 int solveSpaceOptimised(vector<int>&nums,int st,int end){
        int prev=0,prev2=0;
        for(int i=st;i<=end;i++){
            int pick=nums[i]+prev2;
            int notPick=prev;
            int curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
         
         // space optimised 
         int ans1=solveSpaceOptimised(nums,1,n-1);
         int ans2=solveSpaceOptimised(nums,0,n-2);
         return max(ans1,ans2);
      
    }