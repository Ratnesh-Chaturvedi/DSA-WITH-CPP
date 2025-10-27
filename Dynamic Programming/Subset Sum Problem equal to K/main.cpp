class Solution {
  public:



  // Tabulation and space otipmised givinbg tle check again when u visit again and correct them
int  solve(int i, vector<int>& arr, int t, vector<vector<int>>& dp) {
     
     if(t==0) return 1;
     if(i==0) return arr[i]==t;
     if(dp[i][t]!=-1) return dp[i][t];
     int nottake=solve(i-1,arr,t,dp);
     int take=0;
     if(t-arr[i]>=0)
     take=solve(i-1,arr,t-arr[i],dp);
     
     return dp[i][t]=take||nottake;
}

bool isSubsetSum(vector<int>& arr, int sum) {
    int n=arr.size();
    // vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
    // return solve(arr.size()-1, arr, sum, dp);
    
    // tabulation
    // vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
    // // base case
    //  for (int i = 0; i < n; i++)
    //     dp[i][0] = true;

    // if (arr[0] <= sum)
    //     dp[0][arr[0]] = true;

    // for (int i = 1; i < n; i++) {
    //     for (int t = 1; t <= sum; t++) {
    //         bool nottake = dp[i - 1][t];
    //         bool take = false;
    //         if (t >= arr[i])
    //             take = dp[i - 1][t - arr[i]];
    //         dp[i][t] = take || nottake;
    //     }
    // }

    // return dp[n - 1][sum];
    
    // space optimised 
    vector<bool>prev(sum+1,false);
    prev[0]=true;
    if (arr[0] <= sum) {
        prev[arr[0]] = true;
    }
  
    for (int i = 1; i < n; i++) {
        vector<bool> curr(sum+1,false);
        curr[0]=true;
        for (int t = 1; t <= sum; t++) {
            bool nottake = prev[t];
            bool take = false;
            if (t >= arr[i])
                take = prev[t-arr[i]];
            curr[t] = take || nottake;
        }
        prev=curr;
    }
    
    return prev[sum];
    
}
};


