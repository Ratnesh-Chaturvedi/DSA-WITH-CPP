class Solution {
public:

// similar to the lIS printing 
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1) return {nums[0]};
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        int lastidx = 0;
        int maxi=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int pi=0;pi<i;pi++){
                if(nums[i]%nums[pi]==0 && dp[i]<1+dp[pi]){
                       dp[i]=1+dp[pi];
                       hash[i]=pi;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastidx=i;
            }
        }
          vector<int>lds;
         lds.push_back(nums[lastidx]);
         while(hash[lastidx]!=lastidx){
            lastidx=hash[lastidx];
            lds.push_back(nums[lastidx]);
         }
         return lds;
    }
};