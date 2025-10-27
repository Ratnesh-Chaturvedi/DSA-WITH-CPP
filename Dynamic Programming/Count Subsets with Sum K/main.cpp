#include <bits/stdc++.h>

const int M=1e9+7;


// or we can do like count all zeros and then do pow(2,number of zeros)*ans;
// and do the simple count subset 

int solve(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){

// applied this for handling the case where the array contains 0 
//bcoz if it has zero it will form 2 subset one with zero and one without zero
	if(i==0){
	if(sum==0 && arr[0]==0) {
		return 2;
	}
	if(sum==0) return 1;
	if(arr[0]==sum) return 1;
	return 0;
	}
	if(dp[i][sum]!=-1) return dp[i][sum]%M;
	int pick=0;
	if(arr[i]<=sum){
		pick=solve(i-1,sum-arr[i],arr,dp)%M;
	}
	
	int notpick=solve(i-1,sum,arr,dp)%M;
	return dp[i][sum] = (notpick+pick)%M;
}


int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	// vector<vector<int>>dp(n,vector<int>(k+1,-1));

// return  solve(n-1,k,arr,dp);
	
	// tabultaion 
//    vector<vector<int>>dp(n,vector<int>(k+1,0));
//    for(int i=0;i<n;i++){
// 	   dp[i][0]=1;
//    }
// dp[0][0]=arr[0]==0?2:1;  // we done this because we have 0 in the array and it count twice for the target subset 1-> in which we take 0 in ans 2-> in which didnot take 0 in ans set
// if(arr[0]!=0 && arr[0]<=k)
//     dp[0][arr[0]]=1;
    
// 	for(int i=1;i<n;i++){
// 		for(int t=0;t<=k;t++){
// 			int pick=0;
// 	if(arr[i]<=t){
// 		pick=dp[i-1][t-arr[i]]%M;
// 	}
// 	int notpick=dp[i-1][t]%M;
// 	dp[i][t]=(pick+notpick)%M;
// 		}
// 	}

//    return dp[n-1][k];


//space optimised 
vector<int>prev(k+1,0);
if(arr[0]!=0 && arr[0]<=k)
    prev[arr[0]]=1;
prev[0]=arr[0]==0?2:1;
	for(int i=1;i<n;i++){
		vector<int>curr(k+1,0);
		for(int t=0;t<=k;t++){
			int pick=0;
	if(arr[i]<=t){
		pick=prev[t-arr[i]]%M;
	}
	int notpick=prev[t]%M;
	curr[t]=(pick+notpick)%M;
		}
		prev=curr;
	}

return prev[k];

}











