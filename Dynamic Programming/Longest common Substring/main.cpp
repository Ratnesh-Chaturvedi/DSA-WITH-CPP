int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp,int &longest){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    int result=0;
    if(s1[i-1]==s2[j-1]) {
        result=1+solve(i-1,j-1,s1,s2,dp,longest);
        longest=max(longest,result);
    }
    else result=0;
    solve(i-1,j,s1,s2,dp,longest);
    solve(i,j-1,s1,s2,dp,longest);

    return dp[i][j]=result;
}

int LCSubStr(string &str1, string &str2)
{
 int n1=str1.size();
 int n2=str2.size();
 int longest=0;
vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
 solve(n1,n2,str1,str2,dp,longest);
 return longest;



 // using tabulation 
//  vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
// int longest=0;
//  for(int i=1;i<=n1;i++){
//      for(int j=1;j<=n2;j++){

//          if(str1[i-1]==str2[j-1]){
//              dp[i][j]=1+dp[i-1][j-1];
//              longest=max(longest,dp[i][j]);
//          }
//          else dp[i][j]=0;
//      }
//  }  

 // space optimised 
//  vector<int>prev(n2+1,0),curr(n2+1,0);
//  for(int i=1;i<=n1;i++){
//      for(int j=1;j<=n2;j++){

//          if(str1[i-1]==str2[j-1]){
//              curr[j]=1+prev[j-1];
//              longest=max(longest,curr[j]);
//          }
//          else curr[j]=0;
         
//      }
//      prev=curr;
//  }

// return longest;
}

