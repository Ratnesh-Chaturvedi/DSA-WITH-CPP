  void BFS(int row,int col,vector<vector<bool>>&visited,vector<vector<char>>& grid){
        int n=grid.size();
       int m=grid[0].size();
       queue<pair<int,int>>q;
       q.push({row,col});
       visited[row][col]=true;
       while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
           q.pop();
           // traverse in all the eight direction
           for(int delrow=-1;delrow<=1;delrow++){
               for(int delcol=-1;delcol<=1;delcol++){
                int nrow=row+delrow;
                 int ncol=col+delcol;
                  if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]=='L'){
                     visited[nrow][ncol]=true;
                     q.push({nrow,ncol});
                  }
               }
           }
       }
      
  }
    int countIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       int cnt=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            // we only visit those coordinate which are marked as land
              if(!visited[i][j] && grid[i][j]=='L'){
                  cnt++;
                  BFS(i,j,visited,grid);
              }
           }
       }
       return cnt;
        
    }