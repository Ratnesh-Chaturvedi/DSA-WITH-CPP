#include <bits/stdc++.h> 

    // Brute force - only for the positive numbers and no zeroes allowed
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int len=0;
    for(int i=0;i<a.size();i++){
        long long sum=0;
        for(int j=i;j<a.size();j++){
            sum+=a[j];
            if(sum==k) len=max(len,j-i+1);
        }
    }
    return len;
}


// this is the solution for both positive , negative and zeroes in  subarray length sum in the given array
// Better solution
int getLongestSubarray(vector<int>& arr, int k){
    // Write your code here
    map<int,int>preSumMap;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        int remain=sum-k;
        if(preSumMap.find(remain)!=preSumMap.end()){
            int len=i-preSumMap[remain];
            maxlen=max(maxlen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
        
    }
    return maxlen;
}


 // Optimised
  // optimised TC-O(2N) 
    int left=0,right=0;
    long long sum=a[0];
    int maxlen=0;

    int n=a.size();
    while(right<n){
        while(left <=right && sum>k){
            sum-=a[left];
            left++;
        }
        if(sum==k) {
            maxlen=max(maxlen,right-left+1);
        }
            right++;
        if(right<n) sum+=a[right];
    }
    return maxlen;
