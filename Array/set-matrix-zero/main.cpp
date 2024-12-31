#include <bits/stdc++.h> 

// You are given a matrix 'MATRIX' of dimension 'N' x 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to 0 if any element in the ith row or jth column of the matrix is 0.
// Note:
// 1) The number of rows should be at least 1.
// 2) The number of columns should be at least 1
Sample Input 1:
2 3
2 4 3
1 0 0
Sample Output 1:
2 0 0 
0 0 0 


//brute force
// helper function for brute force

void row(int i, vector<vector<int>> &a, int n, int m) {
    for (int j = 0; j < m; j++) {
        if (a[i][j] != 0)
            a[i][j] = -1; // Mark as -1 to avoid immediate conflict with original 0s
    }
}

// Helper function to mark the entire column
void col(int j, vector<vector<int>> &a, int n, int m) {
    for (int i = 0; i < n; i++) {
        if (a[i][j] != 0)
            a[i][j] = -1; // Mark as -1 to avoid immediate conflict with original 0s
    }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &a, int n, int m) {
	//  Brute force
// helper function for brute force




	  // First pass: Mark rows and columns to be zeroed
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                row(i, a, n, m);
                col(j, a, n, m);
            }
        }
    }

        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == -1)
                a[i][j] = 0;
        }
    }
	
	return a;
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &a, int n, int m) {
	//better approach

	// vector<int>row(n,0);
	// vector<int>col(m,0);
	// // marking the row and col
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(a[i][j]==0){
	// 			row[i]=1;
	// 			col[j]=1;
	// 		}
	// 	}
	// }
	// // setting the row and column element equal to 0
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(row[i]==1 || col[j]==1){
	// 			a[i][j]=0;
	// 		}
	// 	}
	// }
	// return a;


	//optimised approach
	//  vector<int>row(n,0);  --> a[..][0]
	// vector<int>col(m,0);   -->a[0][..]
int col0=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
                  if (a[i][j] == 0) {
                    // check for row and column;
                    a[i][0] = 0;
                    if (j != 0){
					a[0][j]=0;
                  } else
                    col0 = 0;
                        }
		}
	}

	// setting value to zero ignore the first row and first col we set the value after this loop
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i][j]!=0){
				if(a[i][0]==0 || a[0][j]==0){
					a[i][j]=0;
				}
			}
		}
	}
	if(a[0][0]==0){
		for(int j=0;j<m;j++){
			a[0][j]=0;
		}
	}
	if(col0==0){
		for(int i=0;i<n;i++){
			a[i][0]=0;
		}
	}
	return a;
}