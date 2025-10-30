 // this problem is similar to the 
 // s1-s2=D




// By count subset
class Solution {
public:



int countPartitions(int n, int d, vector<int> &arr) {
     int sum=accumulate(arr.begin(),arr.end(),0);
 if(sum-d <0) return 0;
 if((sum-d)%2!=0) return 0; 
 int target=(sum-d)/2;
vector<int>prev(target+1,0);
 prev[0]=arr[0]==0?2:1; 
if(arr[0]!=0 && arr[0]<=target)
    prev[arr[0]]=1;

for(int i=1;i<n;i++){
	vector<int>curr(target+1,0);
	for(int t=0;t<=target;t++){
		int nottaken=prev[t];
		int taken=0;
		if(arr[i]<=t){
			taken=prev[t-arr[i]];
		}
		curr[t]=(taken+nottaken);
        
	}
	prev=curr;
}	
return prev[target];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
    
 return countPartitions(n,target,nums);
      
    }
};












 int solve(int idx,int sum,int target,int offset,vector<int>&arr,vector<vector<int>>&dp){
    if(idx==0){
        int cnt=0;
     if(target+arr[0]==0)cnt++;
     if(target-arr[0]==0) cnt++;
     return cnt;
     return 0;
    }
    if(idx<0) return 0;
    if(dp[idx][sum+offset]!=-1)return dp[idx][target];
    // +  
    int pos=solve(idx-1,target+arr[idx],arr);
    // -
    int neg=solve(idx-1,target-arr[idx],arr);
    return neg+pos;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // memoization 
        int sum=accumulate(nums.begin(),nums.end(),0);
        // here target can be negative so our dp can not store the negative index 
        // so we will add the sum so that the the inder shift by that much index 
        // we take an offset 
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
       return  solve(n-1,target,nums,dp);
    }


