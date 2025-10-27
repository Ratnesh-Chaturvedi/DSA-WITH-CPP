#include <bits/stdc++.h> 

const int M=1e9+7;

int solve(int i,int target,vector<int>&arr,vector<vector<int>>&dp){

	if(i==0){
	if(target==0 && arr[0]==0) {
		return 2;
	}
	if(target==0) return 1;
	if(arr[0]==target) return 1;
	return 0;
	}
if(dp[i][target]!=-1) return dp[i][target];
int taken=0;
if(arr[i]<=target)
taken=solve(i-1,target-arr[i],arr,dp);
int nottaken=solve(i-1,target,arr,dp);

return dp[i][target]=(taken+nottaken)%M;


}
int countPartitions(int n, int d, vector<int> &arr) {

 //s1-s2=D
 //s1=totalsum-s2;
 // totalsum-s2-s2=D;
 // s2=(totalsum-D)/2; // which is our target; 
 //  the totalsum-d >=0 // base case1 
 // totalsum-d should be even because number are even


 int sum=accumulate(arr.begin(),arr.end(),0);
 if(sum-d <0) return 0;
 if((sum-d)%2!=0) return 0; 
 int target=(sum-d)/2;
//  vector<vector<int>>dp(n,vector<int>(target+1,-1));

// memoization
//  return solve(n-1,target,arr,dp);


//tabulation 
//  vector<vector<int>>dp(n,vector<int>(target+1,0));
// dp[0][0]=arr[0]==0?2:1;  // we done this because we have 0 in the array and it count twice for the target subset 1-> in which we take 0 in ans 2-> in which didnot take 0 in ans set
// if(arr[0]!=0 && arr[0]<=target) // if it has 0 it will contain 2 or not zero it has only one 
//     dp[0][arr[0]]=1;

// for(int i=1;i<n;i++){
// 	for(int t=0;t<=target;t++){
// 	int taken=0;
// if(arr[i]<=t)
// taken=dp[i-1][t-arr[i]];
// int nottaken=dp[i-1][t];
// dp[i][t]=(taken+nottaken)%M;	
// 	}
// }
// return dp[n-1][target];


// space optimised 

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
		curr[t]=(taken+nottaken)%M;
        
	}
	prev=curr;
}	
return prev[target];

}


