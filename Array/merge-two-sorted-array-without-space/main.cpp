





Problem statement
Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.
You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.
Note:
You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
For example:
When ‘N’ = 4, ‘A’ = {1, 4, 5, 7} and ‘M’ = 3, ‘B’ = {2, 3, 6}. 
We can merge these two arrays into {1, 2, 3, 4, 5, 6, 7} (The elements of ‘A’ are {1, 2, 3, 4} ).
Hence, the answer is {1, 2, 3, 4, 5, 6, 7}.


Sample Input 1:
3 4
1 8 8
2 3 4 5
Sample Output 1:
1 2 3 4 5 8 8
Explanation Of Sample Input 1:
We have ‘A’ = {1, 8, 8} and ‘B’ = {2, 3, 4, 5}. 
Merging the two arrays results in {1, 2, 3, 4, 5, 8, 8}.
Hence the answer is {1, 2, 3, 4, 5, 8, 8}, where ‘A’ contains {1, 2, 3} and ‘B’ contains {4, 5, 8, 8}.

#include<vector>
#include <bits/stdc++.h>
 
 //helper function for optimised approach 2
 void swapIfGreater(vector<long long> &a, vector<long long> &b, int idx1 ,int idx2){
	 if(a[idx1]>b[idx2]){
		 swap(a[idx1],b[idx2]);
	 }
 }

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n=a.size();
	int m=b.size();

// My solution 
     int i=0,j=0;
	 vector<long long >ans;
	 while(i<n && j<m){
		 if(a[i]<=b[j]){
		ans.push_back(a[i]);
		i++;
		 }
		 else {
			 ans.push_back(b[j]);
			 j++;
		 }
	 }
	 while(i<n){
		 ans.push_back(a[i]);
		 i++;
	 }
	 while(j<m){
   ans.push_back(b[j]);
   j++;
	 }
	 a.clear();
	 b.clear();
	 int idx;
	 for(idx=0;idx<n;idx++){
		 a.push_back(ans[idx]);
	 }
	 for(idx=n;idx<n+m;idx++){
		 b.push_back(ans[idx]);
	 }
	

	// optimised solution 1

	int i=n-1;
	int j=0;
	while(i>=0 && j<n){
		if(a[i]>b[j]){
			swap(a[i],b[j]);
			i--,j++;
		}
		else break;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());



// optimised solution by using gap method which is used in shell sort
int len = m + n;
int gap = (len / 2) + (len % 2); // Calculate the initial gap (ceil value)

while (gap > 0) {
    int left = 0;
    int right = left + gap;

    while (right < len) { 
        // Case 1: left pointer in the first array and right pointer in the second array
        if (left < n && right >= n) {
            swapIfGreater(a, b, left, right - n);
        }
        // Case 2: Both pointers in the second array
        else if (left >= n) {
            swapIfGreater(b, b, left - n, right - n);
        }
        // Case 3: Both pointers in the first array
        else {
            swapIfGreater(a, a, left, right);
        }
        left++;
        right++;
    }

    // Break if the gap becomes 1 after this iteration
    if (gap == 1) break;

    // Recalculate the gap
    gap = (gap / 2) + (gap % 2);
}

}