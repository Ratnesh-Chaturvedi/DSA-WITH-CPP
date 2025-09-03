 Rotation

 Problem statement
You are given an array 'arr' having 'n' distinct integers sorted in ascending order. The array is right rotated 'r' times
Find the minimum value of 'r'.
Right rotating an array means shifting the element at 'ith' index to (‘i+1') mod 'n' index, for all 'i' from 0 to ‘n-1'.
Example:
Input: 'n' = 5 , ‘arr’ = [3, 4, 5, 1, 2]
Output: 3 
Explanation:
If we rotate the array [1 ,2, 3, 4, 5] right '3' times then we will get the 'arr'. Thus 'r' = 3.


#include <bits/stdc++.h>
int findKRotation(vector<int> &arr) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  int ans = INT_MAX;
  int index = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[low] <= arr[high]) {
      if (arr[low] < ans) { //  ans=min(ans,arr[low]);
        index = low;
        ans = arr[low];
      }
      break;
    }
    // left sorted
    if (arr[low] <= arr[mid]) {
      if (arr[low] < ans) { //  ans=min(ans,arr[low]);
        index = low;
        ans = arr[low];
      }
     low=mid+1;
    }
    //  right sorted
    else {
      if (arr[mid] < ans) { //  ans=min(ans,arr[mid]);
        index = mid;
        ans = arr[mid];
      }
      high = mid - 1;
    }
  }
  return index;
}