

// You are given a square matrix ‘Mat’ of size ‘N’. You need to rotate ‘Mat’ by 90 degrees in the clockwise direction.
// Note:
// You must rotate the matrix in place, i.e., you must modify the given matrix itself. You must not allocate another square matrix for rotation.
// For example
// When,
// ‘N’ = 2 and ‘Mat’ = {{1, 2}, {3, 4}}, we must modify ‘Mat’ to {{3, 1}, {4, 2}}.


#include <bits/stdc++.h>
#include <vector>
void rotateMatrix(vector<vector<int>> &mat) {
	//  my  brute force
  int n = mat.size();
  vector<vector<int>> temp(n,vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[j][i] = mat[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    reverse(temp[i].begin(), temp[i].end());
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = temp[i][j];
    }
  }


//brute force
int n = mat.size();
vector<vector<int>>ans(n,vector<int>(n));
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		ans[j][n-i-1]=mat[i][j];
	}
}

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		mat[i][j]=ans[i][j];
	}
}





//optimal 
 int n = mat.size();
	// taking transpose
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}

	//reverse each row
	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
}