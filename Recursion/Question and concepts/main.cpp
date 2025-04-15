#include <bits/stdc++.h>
using namespace std;


// Print All subsequence (like printing the powerset)
void printSeq(vector<int>&vec,int idx,vector<int>&emptyArr,int n){
if(idx==n){
    //printing the sequence
for(auto it:emptyArr){
    cout<<it<<" ";
}
if(idx==emptyArr.size()) cout<<"{}";
cout<<endl;
return;
}
// for printing reverse first
printSeq(vec,idx+1,emptyArr,n);

//take or pick the particular index into the subsequence
emptyArr.push_back(vec[idx]);
printSeq(vec,idx+1,emptyArr,n);
emptyArr.pop_back();

//reject 
// printSeq(vec,idx+1,emptyArr,n);
}



// 78. Subsets - print all the subsets
// we take the current to store the current subset
void printSubSet(int idx,int n,vector<int>&nums,vector<vector<int>>&ans,vector<int>current){
    if(idx==n){
       ans.push_back(current);
       
       return ;
    }
    // pickup condition
    current.push_back(nums[idx]);
    printSubSet(idx+1,n,nums,ans,current);
    current.pop_back();
    //reject condition
    printSubSet(idx+1,n,nums,ans,current);
   }
       vector<vector<int>> subsets(vector<int>& nums) {
           vector<vector<int>>ans;
           vector<int>current;
           int n=nums.size();
           printSubSet(0,n,nums,ans,current);
           return ans;
       }





       // print all the subsequence which has the sum==k


void printSum(int idx,vector<int>ans,int s,int sum,int n,vector<int>&vec ){
    if(idx==n){
        if(s==sum){
            for(auto it:ans) cout<<it<<" ";
            cout<<endl;
        }
        return;
}
//picked
ans.push_back(vec[idx]);
s+=vec[idx];
printSum(idx+1,ans,s,sum,n,vec);
ans.pop_back();
s-=vec[idx];

// not pick
printSum(idx+1,ans,s,sum,n,vec);
}


// if want ot print only one subsequence
bool printSumOne(int idx,vector<int>ans,int s,int sum,int n,vector<int>&vec ){
    if(s>sum) return 0; // for +ve array only
    if(idx==n){
        if(s==sum){
            for(auto it:ans) cout<<it<<" ";
            return true;
        }
        return false;
}
//picked
ans.push_back(vec[idx]);
s+=vec[idx];
if(printSumOne(idx+1,ans,s,sum,n,vec)==true)return true;
ans.pop_back();
s-=vec[idx];

// not pick
if(printSumOne(idx+1,ans,s,sum,n,vec)==true) return true;
return false;
}

// Count the no of subsequence whose sum is equal to k
int printCnt(int idx,int s,int sum,int n,vector<int>&vec){
if(idx==n){
    if(s==sum){
       
        return 1;
    }
    return 0;
}
s+=vec[idx];
int left=printCnt(idx+1,s,sum,n,vec);
s-=vec[idx];

int right=printCnt(idx+1,s,sum,n,vec);
    return left+right;
}

int main(){
    vector<int>vec={1,2,1};
      vector<int>ans;
      int n=3;
      int sum=2;
      int cnt=0;
     cout<<printCnt(0,0,sum,n,vec);
}

// Subset Sums

void subset(int idx,int s,vector<int>&arr,vector<int>&ans){
    if(idx==arr.size()){
        ans.push_back(s);
        return;
    }
    //picked up the elment
    subset(idx+1,s+arr[idx],arr,ans);
    //not picking the element
    subset(idx+1,s,arr,ans);
}
  vector<int> subsetSums(vector<int>& arr) {
    vector<int>ans;
    subset(0,0,arr,ans);
    sort(ans.begin(),ans.end());
    return ans;
  }



  // 90. Subsets II
  void subset(int idx,vector<int>&nums,set<vector<int>>&ans,vector<int>&curr){
    if(idx==nums.size()){
        ans.insert(curr);
        return;
    }
    curr.push_back(nums[idx]);
    subset(idx+1,nums,ans,curr);
    curr.pop_back();
    subset(idx+1,nums,ans,curr);
    
      }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      set<vector<int>>ans;
      sort(nums.begin(),nums.end());
      vector<int>curr;
      subset(0,nums,ans,curr);
      vector<vector<int>>result(ans.begin(),ans.end());
      return result;
    }

    // optimised Code
    void subset(int idx,vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr){

        ans.push_back(curr);
         
      for(int i=idx;i<nums.size();i++){
          if(i!=idx && nums[i]==nums[i-1]) continue;
          curr.push_back(nums[i]);
          subset(i+1,nums,ans,curr);
          curr.pop_back();
      }
      
        }
  
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>curr;
        subset(0,nums,ans,curr);
        
        return ans;
      }

      




    //   46. Permutations - Print all the permutaions of string or Array
    // Appraoch 1 - by using extra space
      void recPermutation(vector<int>&curr,vector<int>& nums ,vector<vector<int>>&ans,vector<int>&freq){
    if(curr.size()==nums.size()){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            freq[i]=1;
            curr.push_back(nums[i]);
            recPermutation(curr,nums,ans,freq);
            freq[i]=0;
            curr.pop_back();
        }
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<vector<int>>ans;
     vector<int>curr;
     vector<int>freq(nums.size(),0);
     recPermutation(curr,nums,ans,freq);
     return ans;
    }


    // Approach 2 - By swapping
    void recPermutation(int idx,vector<int>& nums ,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
                recPermutation(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
            }
        }





        // 51. N-Queens
        // approach 1
        
bool isSafe(int row,int col,vector<string>board,int n){
    // checking upper diagnol
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
     if(board[row][col]=='Q') return false;
     row--;
     col--;
    } 
    // chedking left side
    row=duprow;
   col = dupcol;
   while(col>=0){
     if(board[row][col]=='Q') return false;
     col--;
   }
   //checking lower diagnol
   row=duprow;
   col=dupcol;
   while(row<n && col>=0){
     if(board[row][col]=='Q') return false;
     row++;
     col--;
   }
   return true;
 }
 
 void solve(int col,vector<string>board, vector<vector<string>>&ans,int n){
  if(col==n){
     ans.push_back(board);
     return;
  }
  for(int row=0;row<n;row++){
     if(isSafe(row,col,board,n)){
         board[row][col]='Q';
         solve(col+1,board,ans,n);
         board[row][col]='.';
     }
  }
 }
     vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s (n ,'.');
      for(int i=0;i<n;i++){
         board[i]=s;
      }
      solve(0,board,ans,n);
      return ans;  
     }


     // Approach using hashing 
     void solve(int col,vector<string>&board, vector<vector<string>>&ans,int n ,vector<int>&leftrow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal){
        if(col==n){
         ans.push_back(board);
         return;
        }
        for(int row=0;row<n;row++){
         if(leftrow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0 ){
             board[row][col]='Q';
             leftrow[row]=1;
             upperDiagonal[n-1+col-row]=1;
             lowerDiagonal[row+col]=1;
           solve(col+1,board,ans,n,leftrow,upperDiagonal,lowerDiagonal);
     board[row][col]='.';
             leftrow[row]=0;
             upperDiagonal[n-1+col-row]=0;
             lowerDiagonal[row+col]=0;
         }
        }
     }
     
         vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>>ans;
            vector<string>board(n);
            string s (n ,'.');
          for(int i=0;i<n;i++){
             board[i]=s;
          }
          vector<int>leftrow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
          solve(0,board,ans,n,leftrow,upperDiagonal,lowerDiagonal);
          return ans;
            
         }




         //37. Sudoku Solver

         
bool solve(vector<vector<char>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            //finding the empty place and filled the correct value
         if(board[i][j]=='.'){
         // solving the board // we retun true if the value which is valid  or false if not valid
         for(char c='1' ; c<='9' ;c++){
            if(isValid(board,i,j,c)){
                board[i][j]=c;
            if(solve(board)==true) return true;
            else 
                board[i][j]='.';
         }
        }
        return false;
  }
    }
    }
    return true;
}
bool isValid(vector<vector<char>>&board,int row,int col,char c){
    for(int i=0;i<9;i++){
        //checking the row wise (downward)
        if(board[i][col]==c) return false;
        //checking the column wise (horizontal)
        if(board[row][i]==c) return false;

        // checking the sub matrix of size 3x3
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
    }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }





    // 131. Palindrome Partitioning
    
 void func(int idx,string s , vector<string>&path,vector<vector<string>>&res){
    if(idx==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=idx;i<s.size();i++){
        if(isPalindrome(s,idx,i)){
            path.push_back(s.substr(idx,i-idx+1));
            func(i+1,s,path,res);
            path.pop_back();
        }
    }
 }
 bool isPalindrome(string s,int st,int end){
    while(st<=end){
        if(s[st++]!=s[end--]) return false;
    }
    return true;
 }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        func(0,s,path,res);
        return res;
    }




    // Rat in a Maze Problem - I
    // Approach 1  - by using individual moves;


    void solve(int i,int j,vector<vector<int>>&mat,int n,vector<string>&ans,string s,vector<vector<int>>&visited){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        // downward
        if(i+1<n && !visited[i+1][j] &&  mat[i+1][j]==1){
            visited[i][j]=1;
            solve(i+1,j,mat,n,ans,s+'D',visited);
              visited[i][j]=0;
        }
        //left 
        if(j-1>=0 && !visited[i][j-1] && mat[i][j-1]==1){
            visited[i][j]=1;
            solve(i,j-1,mat,n,ans,s+'L',visited);
            visited[i][j]=0;
            
        }
        
        //right
        if(j+1<n && !visited[i][j+1] && mat[i][j+1]==1){
              visited[i][j]=1;
            solve(i,j+1,mat,n,ans,s+'R',visited);
            visited[i][j]=0;
        }
        //upward
        if(i-1>=0 && !visited[i-1][j] && mat[i-1][j]==1){
              visited[i][j]=1;
            solve(i-1,j,mat,n,ans,s+'U',visited);
            visited[i][j]=0;
        }
    }
      vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        int n=mat.size();
       vector<vector<int>>visited(n,vector<int>(n,0));
       if(mat[0][0]==1) solve(0,0,mat,n,ans,"",visited);
       return ans;
      }



      //approach 2 - with using single loop for moves
      void solve(int i,int j,vector<vector<int>>&mat,int n,vector<string>&ans,string s,vector<vector<int>>&visited ,int di[],int dj[]){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
  string dir="DLRU";
  for(int idx=0;idx<4;idx++){
  int nexti=i+di[idx];
  int nextj=j+dj[idx];
  if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !visited[nexti][nextj]  && mat[nexti][nextj]==1){
      visited[i][j]=1;
              solve(nexti,nextj,mat,n,ans,s+dir[idx],visited,di,dj);
              visited[i][j]=0;
  
  }
  }
  
    }
      vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        int n=mat.size();
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,1,0};
       vector<vector<int>>visited(n,vector<int>(n,0));
       if(mat[0][0]==1) solve(0,0,mat,n,ans,"",visited,di,dj);
       return ans;
      }



      //60. Permutation Sequence
    //   Brute force
    void recPermutation(int idx,string &str ,vector<string>&ans){
        if(idx==str.size()){
            ans.push_back(str);
            return;
        }
        for(int i=idx;i<str.size();i++){
            swap(str[idx],str[i]);
                recPermutation(idx+1,str,ans);
            swap(str[idx],str[i]);
            }
        }
    string getPermutation(int n, int k) {
         string s="123456789";
        string str="";
        for(int i=0;i<n;i++){
            str=str+s[i];
        }
        vector<string>ans;
        recPermutation(0,str,ans);
        int  cnt=0;
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cnt++;
            if(cnt==k){
                return ans[i];
            }
        }
  return "0";
    }


    //optimal
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans="";
        k=k-1; // bcoz we are taking 0th base indexing
        while(true){
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) break;
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }