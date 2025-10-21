#include <bits/stdc++.h>
using namespace std;

// traditional recursion 
int fibo(int n){
    if(n<=1) return n;
    return fibo(n-1)+fibo(n-2);
}

// memoization technique
int fiboByMemoization(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fiboByMemoization(n-1,dp)+fiboByMemoization(n-2,dp);
}


int main(){

    int n=5;
    // by using traditional recursion
    // cout<<fibo(5);


    // using memoization
//     vector<int>dp(n+1,-1);
//    fiboByMemoization(n,dp);
//     cout<<dp[5];

// using tabulation method 
vector<int>dp(n+1,-1);
// base case -> fibo(1)==1 and fibo(0)==0
dp[0]=0,dp[1]=1;
//and the recursion start from the value >=2
for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}
// cout<<dp[5];

// otimising the extra space used as an array 

int prev=1;
int prev2=0;
for(int i=2;i<=n;i++){
int current=prev+prev2;
prev2=prev;
prev=current;
}
cout<<prev;

}