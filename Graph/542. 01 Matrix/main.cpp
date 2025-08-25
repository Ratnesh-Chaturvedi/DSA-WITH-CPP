// brute force 
  int distance(int row, int col, vector<vector<int>> & mat) {
        int mindistance = INT_MAX;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    int r = abs(row - i), c = abs(col - j);
                    mindistance = min(mindistance, r + c);
                }
            }
        }
        return mindistance;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> grid = mat;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int mindistance = distance(i, j, mat);
                    grid[i][j] = mindistance;
                } else
                    continue;
            }
        }
        return grid;
    }


    // Optimised using Multisource BFS 
     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m=mat.size();
      int n=mat[0].size();
     // taking the distance container so that we does not alter the given data 
       vector<vector<int>>distance(m,vector<int>(n,0));
       vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,pair<int,int>>>q ; // row col distance 
      // marking all zeroes
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0) { // hame 1 se 0 ka distance chaiye toh hum iska ulta kar sakte hai ki sare 0 se 1 ka distance nikal le 
              q.push({i,{j,0}}) ;// because 0 toh 0 se 0 distance par hi hoga 
              visited[i][j]=true;           
            }
        }
      }

       // by using bfs 
      
      while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second.first;
        int d=q.front().second.second;
        distance[row][col]=d;
        q.pop();
        // check in 4 direction that there exist any 1
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int r=row+drow[i];
            int c=col+dcol[i];
            if( r<m && r>=0 && c<n && c>=0 && !visited[r][c] ){
             visited[r][c]=true;
             q.push({r,{c,d+1}});
             //  pushing the nearst 0  distance from that node; 
             distance[r][c]=d+1;
            }
        }
      }
       
       return distance;

    }


