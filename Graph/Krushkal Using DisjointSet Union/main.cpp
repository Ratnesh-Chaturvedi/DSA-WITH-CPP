class DisjointSet{
  vector<int>parent,size;
  public:
  DisjointSet(int n){
      parent.resize(n+1);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++) parent[i]=i;
  }
  int findUP(int node){
      if(node==parent[node]) return node;
      return parent[node]=findUP(parent[node]);
  }
      void unionBySize(int u,int v){
        int ulp_u=findUP(u); // find the ultimate parent of u
        int ulp_v=findUP(v); // find the ultimate parent of v
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
       
        else {
            // if not the same size we still attach anyone to anyone
            //  both size are same we can attach anyone to anyone of them 
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v]; // size also increases
        }
    }
};



class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
       vector<pair<int,pair<int,int>>>ed;// wt u v
       for(auto it:edges){
         int u=it[0];
         int v=it[1];
         int w=it[2];
         ed.push_back({w,{u,v}});
       }
       sort(ed.begin(),ed.end());
       DisjointSet ds(V);
       int minWt=0;
       for(auto it:ed){
           int wt=it.first;
           int u=it.second.first;
           int v=it.second.second;
           if(ds.findUP(u)!=ds.findUP(v)){
               minWt+=wt;
               ds.unionBySize(u,v);
           }
       }
        return minWt;
    }
};