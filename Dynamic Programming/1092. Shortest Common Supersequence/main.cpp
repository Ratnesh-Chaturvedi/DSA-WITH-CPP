class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // by using the concept of LCS
        // using the table
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
            // forming the answer String 
            string ans="";
            int i=n,j=m;
            while(i>0 && j>0){
                if(str1[i-1]==str2[j-1]){
                    ans+=str1[i-1];
                    i--;
                    j--;
                }
                // moving upward so take the character on that row
                else if(dp[i-1][j]>dp[i][j-1]){
                    ans+=str1[i-1];
                    i--;
                }
                // moving left side so take the character on that col
                else {
                        ans+=str2[j-1];
                        j--;
                }
            } 
            // if charater are still remain i.e not ended at (0,0);
            while(i>0){
                ans+=str1[i-1];
                i--;
            }
            while(j>0){
                ans+=str2[j-1];
                j--;
            }
            // answer build in reverse order so reverse the string
            reverse(ans.begin(),ans.end());
            return ans;

    }
};