 Find A Peak Element

 Problem statement
You are given a 0-indexed 2-D grid ‘g’ of size ‘n’ X ‘m’, where each cell contains a positive integer, and adjacent cells are distinct.
You need to find the location of a peak element in it. If there are multiple answers, find any of them.
A peak element is a cell with a value strictly greater than all its adjacent cells.
Assume the grid to be surrounded by a perimeter of ‘-1s’.
You must write an algorithm that works in O(n * log(m)) or O(m * log(n)) complexity.
Note:
In the output, you will see '0' or '1', where '0' means your answer is wrong, and '1' means your answer is correct.
Sample Input 1:
2 2
8 6
10 1
Sample Output 1:
1       
Explanation of sample output 1:
For g = [[8,6],[10,1]],
Answer = [1,0].
There is only one peak element that is present at [1,0].

//brute force
vector<int> findPeakGrid(vector<vector<int>> &g) {
    int n = g.size();
    int m = g[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool isPeak = true;

            // Check bounds first before accessing elements
            if (j < m - 1 && g[i][j] <= g[i][j + 1]) isPeak = false; // Right
            if (j > 0 && g[i][j] <= g[i][j - 1]) isPeak = false; // Left
            if (i < n - 1 && g[i][j] <= g[i + 1][j]) isPeak = false; // Down
            if (i > 0 && g[i][j] <= g[i - 1][j]) isPeak = false; // Up

            if (isPeak) return {i, j}; // Return first peak found
        }
    }
    return {-1, -1}; // No peak found
}


// optimised 

int Maxidx(vector<vector<int>>&mat,int n,int m,int col){
    int maxval=-1;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxval){
            maxval=mat[i][col];
            idx=i;
        }
    }
    return idx;
}

vector<int> findPeakGrid(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int maxRowIdx=Maxidx(mat,n,m,mid);
        int left=mid-1>=0?mat[maxRowIdx][mid-1]:-1;
        int right=mid+1<m?mat[maxRowIdx][mid+1]:-1;
        if( mat[maxRowIdx][mid]>left && mat[maxRowIdx][mid]>right){
            return {maxRowIdx,mid};
        }
        else if(mat[maxRowIdx][mid]<left) high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}