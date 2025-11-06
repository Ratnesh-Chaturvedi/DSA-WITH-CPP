class Solution {
public:
int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp,int &longest){
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]){
        int result=1+solve(i-1,j-1,s1,s2,dp,longest);
        longest=max(longest,result);
        return dp[i][j]=result;
    }
    else return dp[i][j]=max(
        solve(i-1,j,s1,s2,dp,longest),
        solve(i,j-1,s1,s2,dp,longest)
    );
}
    int longestPalindromeSubseq(string s) {
        // approach using longest common Subsequence
        // just make another string which is reverse of original string 
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
     
        //memoization 
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return  solve(n-1,n-1,s,s2,dp,longest);


        // Tabultaion is also same 
            
           
        // space optimised
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    curr[j]= 1 + prev[j-1];
                }
                 else 
                curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return prev[n];
    }
};