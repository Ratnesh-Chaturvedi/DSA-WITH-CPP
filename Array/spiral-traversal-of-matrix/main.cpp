1 3 7
10 12 15
19 20 21
Sample Output 1:
1 3 7 15 21 20 19 10 12


vector<int> spiralMatrix(vector<vector<int>>&mat) {
    //
    vector<int>ans;
    int n=mat[0].size();
    int m=mat.size();
    int top=0,right=n-1,bottom=m-1,left=0;

    while(top<=bottom && left<=right){
        //left->right
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        //top->bottom
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        //right->left
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(mat[bottom][i]);
        }
        bottom--;
        }
        //bottom->top
        if(left<=right){

        for(int i=bottom;i>=top;i--){
            ans.push_back(mat[i][left]);
        }
        left++;
        }

    }
    return ans;
}