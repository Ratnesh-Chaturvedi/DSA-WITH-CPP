You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.

You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.

Sample Input 1:
3 15
7 2 4
5 10 20


Expected Answer:
21


Output on console:
21


Explanation of Sample Input 1
The given knapsack capacity is 15. We can fill the knapsack as [1, 1, 1] giving us profit 21 and as [1,2] giving us profit 9. Thus maximum profit will be 21.


Sample Input 2
2 3
6 12
4 17


Expected Answer:
0


Output on console:
0


Explanation of Sample Input 2:
We can clearly see that no item has weight less than knapsack capacity. Therefore we can not fill knapsack with any item.


Expected Time Complexity:
Try to solve this in O(n*w).


Constraints
1 <= n <= 10^3
1 <= w <= 10^3
1 <= profit[i] , weight[i] <= 10^8


using ll=long long;
ll  solve(int i, int w, vector<int> &p, vector<int> &wt,
vector<vector<ll>>&dp){
    if(i==0){
        // think of like we have maxweight=8 and wt[0]=2 and p[0]=10
        // so how much i can pick if it has infinite supply 
        return (w/wt[0])*(ll)p[0];
        return 0; 
    }
    if(dp[i][w]!=-1) return dp[i][w];

    int nottake=solve(i-1,w,p,wt,dp);
   int take = -1e9;
    if(wt[i]<=w){
        take=p[i]+solve(i,w-wt[i],p,wt,dp);
    }

return dp[i][w]=max(nottake,take);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//    vector<vector<ll>>dp(n,vector<ll>(w+1,-1));
//    return (int)solve(n-1,w,profit,weight,dp);


    // tabulation 
//     vector<vector<ll>>dp(n,vector<ll>(w+1,0));
//     for(int i=0;i<=w;i++){
//         dp[0][i]=(i/weight[0])*(ll)profit[0];
//     }

//     for(int i=1;i<n;i++){
//         for(int j=0;j<=w;j++){
//     int nottake=dp[i-1][j];
//    int take = -1e9;
//     if(weight[i]<=j){
//         take=profit[i]+dp[i][j-weight[i]];
//     }
//     dp[i][j]=max(nottake,take);

//         }
//     }
//     return dp[n-1][w];



// space optimised
//  vector<int>prev(w+1,0),curr(w+1,0);
//  for(int i=0;i<=w;i++){
//         prev[i]=(i/weight[0])*(ll)profit[0];
//     }
    
//     for(int i=1;i<n;i++){
//         for(int j=0;j<=w;j++){
//     int nottake=prev[j];
//    int take = -1e9;
//     if(weight[i]<=j){
//         take=profit[i]+curr[j-weight[i]];
//     }
//     curr[j]=max(nottake,take);
//         }
//         prev=curr;
//     }
// return prev[w];

   // single array optmisation 
    vector<int>prev(w+1,0);
 for(int i=0;i<=w;i++){
        prev[i]=(i/weight[0])*(ll)profit[0];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
    int nottake=prev[j];
   int take = -1e9;
    if(weight[i]<=j){
        take=profit[i]+prev[j-weight[i]];
    }
    prev[j]=max(nottake,take);
        }
        
    }
return prev[w];

}










