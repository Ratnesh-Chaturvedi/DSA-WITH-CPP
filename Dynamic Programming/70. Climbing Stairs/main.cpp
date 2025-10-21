class Solution {
public:


//Below code give tle because 2^45 call will generate when n=45
void solve(int target,int sum,int &cnt){
    if(sum>target) return ;
    if(sum==target){
        cnt++;
        return;
    }
    solve(target,sum+1,cnt);
    solve(target,sum+2,cnt);
}

// using dp;
int  solveByDp(int target,vector<int>&dp){
    // because target ==0 it means we find a valid solution
 if(target==0){
    return 1;
 }
 if(target<0) return 0;
if(dp[target]!=-1) return dp[target];
 return dp[target]=solveByDp(target-1,dp)+solveByDp(target-2,dp);
}
    int climbStairs(int n) {
        int cnt=0;
        // By recursion
        // solve(n,0,cnt);
        // vector<int>dp(n+1,-1);
        // dp[0]=0;
        // solveByDp(n,dp);
        // return dp[n];

        // optimising the space 
        int prev=1;
        int prev2=1;
        if(n<=1) return 1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};