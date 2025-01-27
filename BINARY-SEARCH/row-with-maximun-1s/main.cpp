// Row with Maximum 1's
Problem statement
You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.
Example:
Input: 'n' = 3, 'm' = 3, 'mat' = [[1, 1, 1], [0, 0, 1], [0, 0, 0]]
Output: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= n <= 50
1 <= m <= 50
0 <= mat[i][j] <= 1
Where ‘n’ is the number of rows and ‘m’ is the number of columns.
Time limit: 1 sec
Sample Input 1:
3 3
1 1 1
0 0 1
0 0 0
Sample Output 1:
0
Explanation of the Sample Input 1:
The row with the maximum number of ones is 0 (0 - indexed).
Sample Input 2:
2 2
1 1
1 1
Sample Output 2:
0
Explanation of the Sample Input 2:
Both rows have the same number of ones. Therefore, we will pick the row with smaller index.

#include <bits/stdc++.h>

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    //MY Code
//     int ans=-1;
//     vector<int>temp;
//     for(int i = 0; i<n ;i++){
//         int sum=0;
//         for(int j=0;j<m;j++){
//             sum +=matrix[i][j];
//         }
//         temp.push_back(sum);
//     }
//  int maxi=INT_MIN;
//     for(auto val:temp){
//      maxi=max(val,maxi);
//     }
    
//    for(int i=0;i<n;i++){
//        if(maxi==temp[i] && temp[i]!=0 && maxi!=0){
//            ans=i;
//            break;
//        }
//    }
//     return ans;

//brute force

// int index=-1;
// int max_cnt=0;
// for(int i=0;i<n;i++){
//     int cnt_1=0;
//     for(int j=0;j<m;j++){
//         cnt_1+=matrix[i][j];
//     }
//     if(cnt_1 > max_cnt){
//         max_cnt=cnt_1;
//         index=i;
//     }
// }
// return index;


// optimised using BS
// we can use lowerbound for 1 and upperbound for 0
int index=-1;
int max_cnt=0;
for(int i=0;i<n;i++){
    int cnt_1= m - (lower_bound(matrix[i].begin(),matrix[i].end(),1)-matrix[i].begin());
    if(cnt_1 > max_cnt){
        max_cnt=cnt_1;
        index=i;
    }
}
return index;


}