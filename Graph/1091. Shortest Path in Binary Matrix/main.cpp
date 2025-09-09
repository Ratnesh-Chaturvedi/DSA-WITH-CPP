// my approach 
class Solution {
public:
vector<int>shortestPath(int src,vector<vector<int>>&adj){
 int n=adj.size();
 vector<int>distance(n,-1);
 queue<pair<int,int>>q; // node , distance
 distance[src]=1;
 q.push({src,1});
 while(!q.empty()){
     int node=q.front().first;
     int d=q.front().second;
     q.pop();
     for(auto it:adj[node]){
        if(distance[it]==-1){
            distance[it]=d+1;
            q.push({it,d+1});
        }
     }
 }

return distance;

}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
 
 if(grid[0][0] !=0 || grid[n-1][n-1]!=0) return -1;       

        int num=0;
        vector<vector<int>>nodeNum(n,vector<int>(n,0));
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                num++;
             nodeNum[i][j]=num;
            }
         }

        vector<vector<int>>adj(n*n+1);
        int Node=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            Node++;
            // check in 8 direction for the node
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int r=i+dr,c=j+dc;
                   if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0){
                    adj[Node].push_back(nodeNum[r][c]);
                   }
                }
            }

            }
        }
       vector<int>shortestDistance=shortestPath(1,adj);
         return shortestDistance[n*n];

    }
};



//optimised using Dijkstra


  // using dijkstra
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // {0,0}-> source  {n-1,n-1} -> destination
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        distance[0][0] = 1;                 // source
        queue<pair<int, pair<int, int>>> q; // distance, row,col
        q.push({1,{0,0}});
        // using queue instead of PQ because the elements that are going to
        // insert are already maintain the sorted sequence of distance

        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int d = q.front().first;
            q.pop();
            if(row==n-1 && col==n-1) return d;  // no need to further check

            // moving in 8 direction
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue; // skip self
                    int r = row + dr;
                    int c = col + dc;
                    if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0) {
                        if (distance[r][c] > d + 1) {
                            distance[r][c] = d + 1;
                            q.push({d + 1, {r, c}});
                        }
                    }
                }
            }
        }
        return -1; // not reached the destination 
    }