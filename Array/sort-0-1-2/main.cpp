#include <bits/stdc++.h> 


/*
Problem statement
You have been given an array/list 'arr' consisting of 'n' elements.
Each element in the array is either 0, 1 or 2.
Sort this array/list in increasing order.
Do not make a new array/list. Make changes in the given array/list.

Example :
Input: 'arr' = [2, 2, 2, 2, 0, 0, 1, 0]
Output: Final 'arr' = [0, 0, 0, 1, 2, 2, 2, 2]

*/


//Dutch national flag algorithm;

void sortArray(vector<int>& arr, int n)
{
    int low=0,mid=0,high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
