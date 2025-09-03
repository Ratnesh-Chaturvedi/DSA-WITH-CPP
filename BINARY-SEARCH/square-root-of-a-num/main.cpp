 Square Root of a number

 Problem statement
You are given a positive integer ‘n’.
Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).
Example:
Input: ‘n’ = 7
Output: 2
Explanation:
The square root of the number 7 lies between 2 and 3, so the floor value is 2.



int floorSqrt(int n) {
  // brute force
//   int ans;
//   for (int i = 1; i <= n; i++){
//        if(i*i<=n) ans=i;
//        else break;
// }
// return ans;




// my code 
// int low=1;
// int high=n;
// int ans;
// while(low<=high){
//     int mid=(low+high)/2;
//     if(mid*mid<=n) ans=mid;
//    if(mid*mid>n) high=mid-1;
//    else {
//      low=mid+1;
//    } 
// }
// return ans;

// actual code
int low=1;
int high=n;
while(low<=high){
  long long mid=(low+high)/2;
  long long val=mid*mid;
  if(val<=n) low=mid+1;
  else high=mid-1;
}
return high;
}
