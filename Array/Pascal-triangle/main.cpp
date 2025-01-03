#include <bits/stdc++.h>
using namespace std;


// Printing pascal triangle;
You are given an integer ‘N’. You need to return the first ‘N’ rows of Pascal’s triangle.
Example
Input:
N = 4
Output:
1
1 1
1 2 1
1 3 3 1
Explanation: The output matrix has the first four rows of Pascal’s Triangle. 

//brute force helper code 
int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return (int)res;
}
vector<vector<int>> pascalTriangle(int N) {
  vector<vector<int>>ans;
  for(int row=1;row<=N;row++){
    vector<int>temp;
    for(int col=1;col<=row;col++){
        temp.push_back(nCr(row-1, col-1));
    }
    ans.push_back(temp);
  }
  return ans;
}


//optmised apporach to generate a full row
vector<int>generateRow(int row){
    vector<int>ans;
    long long res=1;
    ans.push_back(1);
    for(int col=1;col<row;col++){
        res=res*(row-col);
        res=res/(col);
        ans.push_back(res);
    }
    return ans;
}

// optimised approach to generate full triangle
vector<vector<int>> pascalTriangle(int N) {
vector<vector<int>>ans;
for(int i=1;i<=N;i++){
    ans.push_back(generateRow(i));
}
return ans;
}