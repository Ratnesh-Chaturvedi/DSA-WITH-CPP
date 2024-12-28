/*
Problem statement
You are given an array 'arr' of length 'n', consisting of integers.
A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning and 0 or more integers from the end of an array.
Find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.
The sum of an empty subarray is 0.
Example :
Input: 'arr' = [1, 2, 7, -4, 3, 2, -10, 9, 1]
Output: 11
Explanation: The subarray yielding the maximum sum is [1, 2, 7, -4, 3, 2].
*/








long long maxSubarraySum(vector<int> arr, int n)
{
    Better Approach
    int m=INT_MIN;
    
    for(int i=0;i<n;i++){
    int sum=0;
        for(int j=i;j<n;j++){
           sum+=arr[j];
        m=max(sum,m);
        }
    }
    if(m>0)
    return m;
    return 0;


//Optimised -KADANE ALGO
long long sum=0,maximum=LONG_MIN;

for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum<0){
        sum=0;
    }
    maximum=max(maximum,sum);
}
return maximum;
}