Find the Smallest Divisor Given a Threshold

// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

 

// Example 1:

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
// Example 2:

// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// 1 <= nums[i] <= 106
// nums.length <= threshold <= 106


 bool IsPossibleDivisor(vector<int>& arr, int div ,int threshold ){
       long long sum=0;
       int n=arr.size();
       for(int i=0;i<n;i++){
        sum+=ceil( (double)arr[i] / (double) div );
        if(sum > threshold) return false;
       }
       if(sum<=threshold) return true;
       else return false;
 }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        if(n>threshold) return -1;
        
        int maxOfArr=INT_MIN;
        for(int i=0;i<n;i++){
            maxOfArr=max(maxOfArr,nums[i]);
        }

        int low=1;
        int high=maxOfArr;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(IsPossibleDivisor(nums,mid,threshold)==true){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans; // return low;
    }
