vector<int>LDS(vector<int>&arr,int n){
vector<int>dp(n,1);
for(int i=n-1;i>=0;i--){
	for(int pi=n-1;pi>=i;pi--){
		if(arr[i]>arr[pi]){
			   dp[i]=max(dp[i],1+dp[pi]);
		}
	}
}
return dp;
}

vector<int> LIS(vector<int>&arr,int n){
vector<int>dp(n,1);
for(int i=1;i<n;i++){
	for(int pi=0;pi<i;pi++){
		if(arr[i]>arr[pi]){
			   dp[i]=max(dp[i],1+dp[pi]);
		}
	}
}
return dp;

}

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int>dp1=LIS(arr,n);
	vector<int>dp2=LDS(arr,n);
	int maxi=0;
	for(int i=0;i<n;i++){
		int ans=dp1[i]+dp2[i]-1;
		maxi=max(ans,maxi);
	}
return maxi;
}




