//992. Subarrays with K Different Integers
// same like binary subarray with sum / count no. of subarray equal k
int count(vector<int>& nums, int k){
    if(k<0) return 0;
     int r=0,l=0,cnt=0;
        int n=nums.size();
        unordered_map<int,int>hash;
        while(r<n){
         hash[nums[r]]++;
         while(hash.size()>k){
         
            hash[nums[l]]--;
            if(hash[nums[l]]==0) hash.erase(nums[l]);
            l++;
         }
        cnt+=r-l+1;
         r++;
        }
        return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return count(nums,k)-count(nums,k-1);
    }
