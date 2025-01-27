 K-th Element of Two Sorted Arrays

//  Problem statement
// You're given two sorted arrays 'arr1' and 'arr2' of size 'n' and 'm' respectively and an element 'k'.


// Find the element that would be at the 'kth' position of the combined sorted array.

// Position 'k' is given according to 1 - based indexing, but arrays 'arr1' and 'arr2' are using 0 - based indexing.
// For example :
// Input: 'arr1' = [2, 3, 45], 'arr2' = [4, 6, 7, 8] and 'k' = 4
// Output: 6
// Explanation: The merged array will be [2, 3, 4, 6, 7, 8, 45]. The element at position '4' of this array is 6. Hence we return 6.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5
// 2 3 6 7 9
// 4
// 1 4 8 10
// 4
// Sample Output 1:
// 4
// Explanation of sample input 1 :
// The merged array will be: [1, 2, 3, 4, 6, 7, 8, 9, 10]

// The element at position '4' is 4 so we return 4.
// Sample Input 2:
// 5
// 1 2 3 5 6
// 5
// 4 7 8 9 100  
// 6


// Similar to median of two sorted array and all appraches are also same
#include <bits/stdc++.h>

int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    // Brute force
    // just merge the a and b by using merge function and return the k+1 index number

    // optimised -same as median of 2 sorted array;
    if(n1>n2) return kthElement(b,a,n2,n1,k);
    int low=max(k-n2,0);
    int high=min(n1,k);
    int left=k;
    int n=n1+n2;
    while(low<=high){
        int mid1=(low+high)>>1;
        int mid2=left-mid1;
        int l1=INT_MIN , l2=INT_MIN;
        int r1=INT_MAX , r2=INT_MAX;
        if(mid1 < n1) r1=a[mid1];
        if(mid2 < n2) r2=b[mid2];
        if(mid1-1>=0) l1=a[mid1-1];
        if(mid2-1>=0) l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1 > r2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
    
}