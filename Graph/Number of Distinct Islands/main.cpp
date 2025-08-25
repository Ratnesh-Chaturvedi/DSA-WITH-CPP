void DFS(int row,int col, vector<pair<int,int>>&vec, vector<vector<bool>>&visited, 
  vector<vector<int>>& grid,int baseRow,int baseCol){
      int n=grid.size();
       int m=grid[0].size();
       visited[row][col]=true;
       vec.push_back({row-baseRow,col-baseCol}); // pushing the coordinates by subtracting from base coordinates so that if they have the same shape they are considered as a same island 
       
       // checking all 4 directions
       int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int r=row+drow[i];
            int c=col+dcol[i];
            if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && grid[r][c]==1){
                DFS(r,c,vec,visited,grid,baseRow,baseCol);
            }
        }
  }
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
      vector<vector<bool>>visited(n,vector<bool>(m,false));
      set<vector<pair<int,int>>>st;
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(!visited[i][j] && grid[i][j]==1){
                  // to store all the island coordinate 
                  vector<pair<int,int>>vec;
                  DFS(i,j,vec,visited,grid,i,j); // pasing the coordinate and also the base coordinate 
                  st.insert(vec); // inserting into set because there than be same coordinates  // same island
              }
          }
      }
        return st.size(); // number of distanct islands coordinates 
    }