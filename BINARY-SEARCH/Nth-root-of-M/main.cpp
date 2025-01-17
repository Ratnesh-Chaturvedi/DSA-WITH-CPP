 Find Nth Root Of M
 Problem statement
// You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. If the 'nth root is not an integer, return -1.
// Note:
// 'nth' root of an integer 'm' is a number, which, when raised to the power 'n', gives 'm' as a result.
// Example:
// Input: ‘n’ = 3, ‘m’ = 27
// Output: 3
// Explanation: 
// 3rd Root of 27 is 3, as (3)^3 equals 27.

// Sample Input 2:
// 4 69
// Sample Output 2:
// -1
// Explanation For Sample Input 2:
// 4th Root of 69 is not an integer, hence -1.




#include <bits/stdc++.h>

// return 1 if ans==m;
//return 2 if ans>m
// return 0 if ans<m
int func(int mid,int n ,int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*mid;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
// brute force 
// for(int i=1;i<=m;i++){
//   if(pow(i,n)==m) return i;
//   else if(pow(i,n)>m) break;
// }
// return -1;


// optimised by myself

  // int low=1;
  // int high=m;
  // while(low<=high){
  //   long mid=(low+high)/2;
  //   if(pow(mid,n)==m) return mid;
  //   else if(pow(mid,n)>m) high=mid-1;
  //   else low=mid+1;
  // }
  // return -1;

// optimised 

int low=1;
int high=m;
while(low<=high){
  int mid=(low+high)/2;
  if(func(mid,n,m)==1) return mid;
  else if(func(mid,n,m)==2) high=mid-1;
  else low=mid+1;
}
return -1;
}