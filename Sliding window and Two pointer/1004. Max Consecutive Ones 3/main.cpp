
// 1004. Max Consecutive Ones III
 int longestOnes(vector<int>& nums, int k) {
        // optimised 
        // vector<int>arr(2,0);
        // int n=nums.size();
        // int l=0,r=0;
        // int len=0;
        // while(r<n){
        //     arr[nums[r]]++;
        //     while(arr[0]>k){
        //      arr[nums[l]]--;
        //      l++;
        //     }
        //     len=max(len,r-l+1);
        //     r++;
        // }
        // return len;

        // most Optimised
        int n=nums.size();
        int l=0,r=0,zero=0,maxlen=0;
        while(r<n){
            if(nums[r]==0) zero++;
            if(zero>k) {
                if(nums[l]==0)zero--;
                l++; 
            }
            if(zero<=k) {
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
            r++;
        }
        return maxlen;
    }
