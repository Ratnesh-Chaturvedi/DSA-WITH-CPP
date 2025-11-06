// extreme brute force 
class Solution {
public:
 void solve(int i,string &s,string temp,vector<string>&st,string &t){
    if(i<0){
        reverse(temp.begin(),temp.end());
        if(temp==t){
          st.push_back(temp);
        }
        return;
    }
    temp.push_back(s[i]);
    solve(i-1,s,temp,st,t);
    temp.pop_back();
    solve(i-1,s,temp,st,t);

 }
    int numDistinct(string s, string t) {
         int n=s.size();
         vector<string>st;
         string temp="";
         solve(n-1,s,temp,st,t);    
         return st.size();   
    }
};


class Solution {
public:
using ll =long long ;
const int  M=1e9+7;
 ll solve(int i,int j,string &s,string &t,vector<vector<ll>>&dp){
    if(j<0){
       return 1;
    }
    if(i<0 ) return 0;
   if(dp[i][j]!=-1) return dp[i][j];

   if(s[i]==t[j]){
   // include s[i] + exclude s[i]
   return  dp[i][j]=solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
   }
   // skip s[i]
   return dp[i][j]=solve(i-1,j,s,t,dp);


 }
    int numDistinct(string s, string t) {
         int n=s.size();
         int m=t.size();
        //  vector<vector<ll>>dp(n,vector<ll>(m,-1));
         
        //  return solve(n-1,m-1,s,t,dp);   

        // tabulation
        //  vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        //  for(int i=0;i<=n;i++)dp[i][0]=1; // t is empty // it is the j<=0 case 
        //  for(int j=1;j<=m;j++) //  s is empty but t is not empty
        //     dp[0][j]=0;
         
         
        //  for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%M;
        //         }
        //         else dp[i][j]=dp[i-1][j];
        //     }
        //  }
        //  return dp[n][m];

         // two array space is similar to tabulation

        // single array  optimised
         vector<ll>prev(m+1,0);
         prev[0]=1; // bc
         for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    prev[j]=(prev[j-1]+prev[j])%M;
                }
                // else prev[j]=prev[j];
            }
         }
        return prev[m];
    }
};