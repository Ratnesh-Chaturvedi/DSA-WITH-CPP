Search In A 2D Matrix - I 

Problem statement
You have been given a 2-D array 'mat' of size 'M x N' where 'M' and 'N' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order.
Moreover, the first element of a row is greater than the last element of the previous row (if it exists).
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
Example:
Input: ‘M’ = 3, 'N' = 4, ‘mat’ = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]], ‘target’ = 8
Output: true
Explanation: The output should be true as '8' exists in the matrix.



#include <bits/stdc++.h>

//BS for Better approach
bool BS(vector<int>arr,int target){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
       // brute force is just by traversing all the element
       int n=mat.size();
       int m=mat[0].size();

       // better by using BS on the row elements
    //    for(int i=0;i<n;i++){
    //        if(mat[i][0]<=target && mat[i][m-1]>=target){
    //            return BS(mat[i],target);
    //        }
    //    }
    //    return false;



// Optimised appraoch- by assuming that 2d array as 1d array

int low=0;
int high=n*m-1;
while(low<=high){
    int mid=(low+high)/2;
    int row=mid/m; // to get the row index of the element
    int col=mid%m; // to get the col index of the element
    if(mat[row][col]==target) return true;
    else if(mat[row][col]<target) low=mid+1;
    else high=mid-1;

}
return false;
}