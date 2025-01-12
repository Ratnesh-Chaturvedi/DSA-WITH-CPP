Subarray With Maximum Product

Problem statement
Given an array ‘Arr’ that has ‘N’ elements. You have to find the subarray of ‘Arr’ that has the largest product. You must return the product of the subarray with the maximum product.



For example:
When ‘N’ = 5, and ‘Arr’ = {-2, 3, -4, 0}
The subarrays of ‘Arr’ are:
{-2}, {-2, 3}, {-2, 3, -4}, {-2, 3, -4, 0}, {3}, {3, -4}, {3, -4, 0}, {-4}, {-4, 0}, {0}.
Among these, {-2, 3, -4} is the subarray having the maximum product equal to 24.
Hence, the answer is 24.

#include<vector>
#include "bits/stdc++.h"

int subarrayWithMaxProduct(vector<int> &arr){
	int n=arr.size();

	// brute force
	int ans=arr[0];
    for(int i=0;i<n;i++){
		int product=arr[i];
		for(int j=i+1;j<n;j++){
			
			product*=arr[j];
		}
		ans=max(ans,product);
	}
	return ans;


// optimal solution
	int ans=INT_MIN;
	int prefix=1,suffix=1;
	for(int i=0;i<n;i++ ){
      if(prefix==0) prefix=1;
      if(suffix==0) suffix=1;

	prefix*=arr[i];
	suffix*=arr[n-i-1];
	  ans=max(ans,max(prefix,suffix));
	}

	return ans;
}