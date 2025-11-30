class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    
    // filling up the first row
    for(int i=0;i<n;i++)dp[0][i]=mat[0][i];
    //filling up the first column
    for(int i=0;i<m;i++)dp[i][0]=mat[i][0];

    // filling up the table
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(mat[i][j]==0) continue;
            // the count of square will be the minimum of the top , left and diagonal
            int top=dp[i-1][j];
            int dia=dp[i-1][j-1];
            int left=dp[i][j-1];
            int mini=min(top,min(left,dia));
            dp[i][j]=1+mini;
            cout<<dp[i][j]<< " ";
        }
        cout<<endl;
    }
     
     // taking sum of all the dp table values
     int totalSquare=0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
         totalSquare+=dp[i][j];
     }
     return totalSquare;




    }
};