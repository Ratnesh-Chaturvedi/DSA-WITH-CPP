class DisjointSet{
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    
    int findUp(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUp(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u=findUp(u);
        int ulp_v=findUp(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
      DisjointSet ds(n*m);
      vector<vector<bool>>visited(n,vector<bool>(m,false));
      
      vector<int>ans;
      int cnt=0;
      for(auto it:operators){
          int row=it[0];
          int col=it[1];
          
          // check if the node is already visited
          if(visited[row][col]){
              ans.push_back(cnt);
              continue;
          }
          
          // mark as visited
          visited[row][col]=true;
          cnt++; // inc count for every node which is not visited yet
          
          
          // check in all 4 direction
          int dr[]={0,1,0,-1};
          int dc[]={1,0,-1,0};
          for(int i=0;i<4;i++){
              int adjr=row+dr[i];
              int adjc=col+dc[i];
              if(adjr>=0 && adjr<n && adjc>=0 && adjc<m ){
                  // check that the sides node are visited or not 
                  if(visited[adjr][adjc]){
                      // find the node number
                      int nodeNo=row*m+col;
                      int adjNodeNo=adjr*m+adjc;
                      if(ds.findUp(nodeNo)!=ds.findUp(adjNodeNo)){
                          cnt--; // because now they are become a single island
                          ds.unionBySize(nodeNo,adjNodeNo);
                      }
                      
                  }
              }
            
          }
          ans.push_back(cnt);
      }
        return ans;
    }
};














