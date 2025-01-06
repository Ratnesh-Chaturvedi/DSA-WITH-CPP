 Subarrays with XOR ‘K’


 Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.
A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.
Example:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3
Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].

#include <bits/stdc++.h>

int subarraysWithSumK(vector < int > a, int k) {
    int n=a.size();


// brute force - by using three loops where third loop running from i to j

    // better solution


    int cnt=0;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=i;j<n;j++){
            x=x^a[j];
            if(x==k) cnt++;
        }
    }
    return cnt;

    // Optimised solution - by using hashing

    int xr=0;
    map<int,int>hash;
    hash[xr]++; // storing {0,1} so that agr zero aaye x ki value to cnt ++ ho sake
    int cnt=0;
    for(int i=0;i<n;i++){
        xr=xr^a[i];
        int x=xr^k;
        cnt+=hash[x];
        hash[xr]++;

    }
    return cnt;

}