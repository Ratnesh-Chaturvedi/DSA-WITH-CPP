 Search In A Sorted 2D Matrix -II
 Problem statement
You are given a 2D matrix ‘MATRIX’ of ‘N’*’M’ dimension. You must check whether a given number ‘target’ is present in the matrix.
The following properties apply to the given matrix:
1. In each row, integers are sorted from left to right.
2. Each row's first integer is greater than the previous row's last integer.
Example:
Input:
'MATRIX' = [ [1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60] ], 'TARGET' = 3 
Output:1
Explanation: Since the given number ‘TARGET’ is present in the matrix, we return true.

Problem statement
You are given a 2D matrix ‘MATRIX’ of ‘N’*’M’ dimension. You must check whether a given number ‘target’ is present in the matrix.



The following properties apply to the given matrix:

1. In each row, integers are sorted from left to right.
2. Each row's first integer is greater than the previous row's last integer.
Example:

Input:
'MATRIX' = [ [1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60] ], 'TARGET' = 3 
Output:1
Explanation: Since the given number ‘TARGET’ is present in the matrix, we return true.


bool searchElement(vector<vector<int>> &arr, int target) {
    //brute is by linear search 

     int n=arr.size();
int m=arr[0].size();

    //better appraoch
// for(int i=0;i<n;i++){
//     int low=0;
//     int high=m-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[i][mid]==target) return true;
//         else if(arr[i][mid]<target) low=mid+1;
//         else high=mid-1;
// }
// }
// return false;

int row=0;
int col=m-1;
while(row < n && col > -1){
    if(arr[row][col]==target) return true;
   else  if(arr[row][col]<target)row++;
   else col--;
   
}
return false;


}