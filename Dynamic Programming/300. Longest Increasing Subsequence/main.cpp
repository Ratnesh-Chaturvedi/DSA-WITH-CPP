class Solution {
public:
    int solve(int idx, int prevIdx, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx == arr.size())
            return 0;

        if (dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];

        int take = 0;
        if (prevIdx == -1 || arr[idx] > arr[prevIdx]) {
            take = 1 + solve(idx + 1, idx, arr, dp);
        }
        int nottake = solve(idx + 1, prevIdx, arr, dp);
        return dp[idx][prevIdx + 1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // n+1 because at dp[i][n] define that no previous elem selected  and
        // prevIdx=-1 define not previous elem is selected
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // return solve(0, -1, nums, dp);

        // tabulation
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // for (int idx = n - 1; idx >= 0; idx--) {
        //     for (int pidx = idx - 1; pidx >= -1; pidx--) {

        //         int take = 0;
        //         if ( pidx == -1 || nums[idx] > nums[pidx] ) {
        //             take = 1 + dp[idx + 1][idx + 1];
        //         }
        //         int nottake = dp[idx + 1][pidx + 1];
        //         dp[idx][pidx + 1] = max(take, nottake);
        //     }
        // }
        // return dp[0][0];

        // space optimised 2d array
        //  vector<int>next(n + 1, 0),curr(n+1,0);
        //  for (int idx = n - 1; idx >= 0; idx--) {
        //     for (int pidx = idx - 1; pidx >= -1; pidx--) {

        //         int take = 0;
        //         if ( pidx == -1 || nums[idx] > nums[pidx] ) {
        //             take = 1 + next[idx + 1];
        //         }
        //         int nottake = next[pidx + 1];
        //         curr[pidx + 1] = max(take, nottake);
        //     }
        //     next=curr;
        // }
        // return next[0];

        // space optimisd 1d array
        int ans=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int pi=0;pi<i;pi++){
                if(nums[i]>nums[pi]){
                    dp[i]=max(dp[i],1+dp[pi]);
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};


// printing lis
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // space optimisd 1d array
        // or we can print the lis
        int ans = 1;
        int lastIdx = 1;
        // hash arra store the index form where it can traverse back to store
        // LIS
        vector<int> dp(n, 1), hash(n, 0);
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int pi = 0; pi < i; pi++) {
                if (nums[i] > nums[pi] && dp[i] < 1 + dp[pi]) {
                
                dp[i] = dp[pi] + 1;
                hash[i] = pi;
            }
            }
            if(dp[i]>ans){
                lastIdx = i;
                ans = max(ans, dp[i]);
        }
        }
         vector<int>lis;
         lis.push_back(nums[lastIdx]);
         while(hash[lastIdx]!=lastIdx){
            lastIdx=hash[lastIdx];
            lis.push_back(nums[lastIdx]);
         }

         for(int i=0;i<ans;i++) cout<<lis[i]<<" ";
        return ans;
    }
};

// using Binary search

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (lis.back() < nums[i]) {
                // if last element is smaller so no need to find lowevound
                lis.push_back(nums[i]);
            } else {
                // finding the lower bound if it exist
                int lb =
                    lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                // replace preexisting element
                lis[lb] = nums[i];
            }
        }
        return lis.size();
    }
