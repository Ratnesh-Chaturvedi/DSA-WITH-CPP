#include <bits/stdc++.h>

int solve(int idx,int wt,vector<int>&w,vector<int>&v,vector<vector<int>>&dp){
if(idx==0){
 if(w[0]<=wt){
	 return v[0];
 }
 return 0;
}

if(dp[idx][wt]!=1e9) return dp[idx][wt];

int notpick=solve(idx-1,wt,w,v,dp);
int pick=INT_MIN;
if(w[idx]<=wt){
	pick=v[idx]+solve(idx-1,wt-w[idx],w,v,dp);
}

return dp[idx][wt]=max(pick,notpick);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,1e9));
	// return solve(n-1,maxWeight,weight,value,dp);

	// using tabulation
// 	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
// 	// base case when w[0]<=wt marks them as their value if not marks then as 0
// 	for(int w=weight[0];w<=maxWeight;w++){
// 		if(w<=maxWeight)
// 		dp[0][w]=value[0];
// 	}

// 	for(int i=1;i<n;i++){
// 		for(int w=1;w<=maxWeight;w++){
// 			int notpick=dp[i-1][w];
// int pick=INT_MIN;
// if(weight[i]<=w){
// 	pick=value[i]+dp[i-1][w-weight[i]];
// }
// dp[i][w]=max(pick,notpick);

// 		}
// 	}
// 	return dp[n-1][maxWeight];



// space optimised 
// vector<int>prev(maxWeight+1,0);
// 		vector<int>curr(maxWeight+1,0);
// for(int w=weight[0];w<=maxWeight;w++){
// 		if(w<=maxWeight)
// 		prev[w]=value[0];
// 	}
      
// 	for(int i=1;i<n;i++){

// 		for(int w=0;w<=maxWeight;w++){
// 			int notpick=prev[w];
//             int pick=INT_MIN;
// 			if(weight[i]<=w){
// 			pick=value[i]+prev[w-weight[i]];
// 		}
// 		curr[w]=max(pick,notpick);
// 		}
// 		prev=curr;

// 	}

// return prev[maxWeight];

// most optimised 
// single array space
vector<int>prev(maxWeight+1,0);
for(int w=weight[0];w<=maxWeight;w++){
		if(w<=maxWeight)
		prev[w]=value[0];
	}
      
	for(int i=1;i<n;i++){

		for(int w=maxWeight;w>=0;w--){
			int notpick=prev[w];
            int pick=INT_MIN;
			if(weight[i]<=w){
			pick=value[i]+prev[w-weight[i]];
		}
		prev[w]=max(pick,notpick);
		}

	}

return prev[maxWeight];

}