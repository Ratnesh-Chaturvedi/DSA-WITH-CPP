
// recusive approach ->Tle  length of array=10^5

int solve(int idx,vector<int>&height){
    if(idx==0) return 0;

    int left=solve(idx-1,height)+abs(height[idx]-height[idx-1]);
    int right=idx>1?solve(idx-1,height)+abs(height[idx]-height[idx-2])?INT_MAX;

    return min(left,right);
}
// by using Dp ->memoization
int solve(int idx,vector<int>&height,vector<int>&dp){
    if(idx==0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int left=solve(idx-1,height,dp)+abs(height[idx]-height[idx-1]);
    int right=idx>1?solve(idx-1,height,dp)+abs(height[idx]-height[idx-2])?INT_MAX;

    return dp[idx]=min(left,right);
}

  int minCost(vector<int>& height) {
    // recursive
    // solve(height.size()-1,height);

 // Using memoization

 vector<int>dp(n+1,-1);
// return solveByMemo(n-1,height,dp);

// By using tabulation
 dp[0]=0;
    for(int i=1;i<n;i++){
       int first=INT_MAX;
       int second=INT_MAX;
        first=dp[i-1]+abs(height[i-1]-height[i]);
       if(i>1){
           second=dp[i-2]+abs(height[i-2]-height[i]);
       }
       dp[i]=min(first,second);
    }
    return dp[n-1];


    // optimisation of space 

    
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
       int first=INT_MAX;
      int second=INT_MAX;
        first=prev+abs(height[i-1]-height[i]);
      if(i>1){
          second=prev2+abs(height[i-2]-height[i]);
      } 
      int curr=min(first,second);
      prev2=prev;
      prev=curr;
    }
    return prev;
 

  }


  // if there is a follow of k steps jumps 
    int solve(int idx,vector<int>&h,vector<int>&dp,int k){
      if(idx==h.size()-1) return 0;
      if(dp[idx]!=-1) return dp[idx];
      int mini=INT_MAX;
      // for k steps we can find the mininum
      for(int i=1;i<=k;i++){
          if(idx+i<h.size()){
           int  step=solve(idx+i,h,dp,k)+abs(h[idx]-h[idx+i]);
          mini=min(step,mini);
          }
      }
      dp[idx]=mini;
      return dp[idx];
      
  }

  // tabulation
      int minCost(vector<int>& height) {
  int n=height.size();
  vector<int>dp(n,INT_MAX);
  int k=2;
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
              if(i-j>=0){
           int  step=dp[i-j]+abs(height[i]-height[i-j]);
          dp[i]=min(step,dp[i]);
          }   
            }

        }
        return dp[n-1];
    }