// 1248. Count Number of Nice Subarrays
// Similar to Binary subarray with sum // count no of subarray having sum==k
// only covert the value of the arr in 0 or 1 by using nums[i]%2;
int cntsubarray(vector<int>& nums, int k){
    int n=nums.size();
    if(k<0) return 0;
    int r=0,l=0,cnt=0,sum=0;
    while(r<n){
        sum+=nums[r]%2;
        while(sum>k) {
            sum-=nums[l]%2;
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;

 }

    int numberOfSubarrays(vector<int>& nums, int k) {
    int n=nums.size();

    // this question is similar to binary subarray with sum eqaul to k
    //better approach
//           unordered_map<int,int>prefix;
//           int cnt=0;
//           prefix[0]=1;
//           int sum=0;
//           for(int i=0;i<n;i++){
//             sum+=nums[i]%2;
//              cnt+=prefix[sum-k];
//              prefix[sum]++;
//           }
// return cnt;

//optimised approach
return cntsubarray(nums,k)-cntsubarray(nums,k-1);
    }


