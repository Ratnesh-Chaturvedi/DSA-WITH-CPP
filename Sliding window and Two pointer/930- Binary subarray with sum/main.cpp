//930- Binary subarray with sum // count no of subarray having sum==k
//Brute 
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==goal) cnt++;
        }
        }
        return cnt;
}
//better 
  // By using prefix sum;
   int sum=0,cnt=0;
   map<int,int>prefix;
   prefix[0]=1;
for(int i=0;i<n;i++){
    sum+=nums[i];
    cnt+=prefix[sum-goal];
    prefix[sum]++;
}
return cnt;

// optimal- using sliding window
int subarrayCnt(vector<int>& arr, int goal) {
    int n=arr.size();
    if(goal<0) return 0;
    int l=0,r=0,cnt=0,sum=0;
    while(r<n){
        sum+=arr[r];
        while(sum>goal){
            sum-=arr[l];
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;
}
 int numSubarraysWithSum(vector<int>& nums, int goal) {
     return subarrayCnt(nums,goal)-subarrayCnt(nums,goal-1);
}
   