// First and Last Position of an Element In Sorted Array
// Problem statement
// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
// Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.
// Note :
// 1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
// 2. 'arr' may contain duplicate elements.
// Example:
// Input: 'arr' = [0,1,1,5] , 'k' = 1
// Output: 1 2
// Explanation:
// If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.
Sample Input 1:
8 2
0 0 1 1 2 2 2 2
Sample output 1:
4 7
Explanation of Sample output 1:
For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.



#include <bits/stdc++.h>

int upperbound(vector<int> &arr, int n, int k) {
  int low = 0;
  int high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] > k) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return ans;
}

int lowerbound(vector<int> &arr, int n, int k) {
  int low = 0;
  int high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= k) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return ans;
}

int bsforFirst(vector<int> &arr, int n, int k){
    int ans=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            high=mid-1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return ans;
}

int bsforLast(vector<int> &arr, int n, int k){
    int ans=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k){
            ans=mid;
            low=mid+1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
    //better appraoch
//   int first_occ = lowerbound(arr, n, k);
//   if (first_occ == n || arr[first_occ] != k) {
//     return {-1, -1};
//   }
//   int last_occ = upperbound(arr, n, k);
//   return {first_occ, last_occ-1};


// without the use of lb and ub

int first=bsforFirst(arr, n,  k);
int last=bsforLast(arr,  n,  k);
return {first,last};

}




//  Number of occurrence

// You have been given a sorted array/list of integers 'arr' of size 'n' and an integer 'x'.
// Find the total number of occurrences of 'x' in the array/list.
// Example:
// Input: 'n' = 7, 'x' = 3
// 'arr' = [1, 1, 1, 2, 2, 3, 3]
// Output: 2
// Explanation: Total occurrences of '3' in the array 'arr' is 2.


int bsforFirst(vector<int>& arr, int n, int x){
	int first=-1;
	int l=0;
	int h=n-1;
	while(l<=h){
		int mid=l+(h-l)/2;
		if(arr[mid]==x){
			first=mid;
			h=mid-1;
		}
		else if(arr[mid]<x){
			l=mid+1;
		}
		else h=mid-1;
	}
	return first;
}




int bsforLast(vector<int>& arr, int n, int x){
	int last=-1;
	int l=0;
	int h=n-1;
	while(l<=h){
		int mid=l+(h-l)/2;
		if(arr[mid]==x){
			last=mid;
			l=mid+1;
		}
		else if(arr[mid]<x){
			l=mid+1;
		}
		else h=mid-1;
	}
	return last;
}


int count(vector<int>& arr, int n, int x) {

	int first=bsforFirst(arr, n,x);
	if(first==-1) return 0;	
	int last=bsforLast(arr, n,x);
	return (last-first)+1;	
}
