class DisjointSet {
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findUp(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUp(parent[node]);
    }
    void unionBySize(int u,int v){
      int ulp_u=findUp(u);  
      int ulp_v=findUp(v);
      if(ulp_u==ulp_v) return;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=-1,maxCol=-1;
        // Find the max row and col to size the DSU array
        for(int i=0;i<n;i++){
            maxRow=max(stones[i][0],maxRow);
            maxCol=max(stones[i][1],maxCol);
        }
        // initalise the size of disjoint set
        DisjointSet ds(maxRow+maxCol+2);
         // To track which nodes are used
        unordered_map<int,int>stonesNode;
        for(auto it:stones){
             int node=it[0];
             int adjNode=it[1]+maxRow+1; // considering each row as a separate node 
             ds.unionBySize(node,adjNode);
             // Mark these nodes as used
             stonesNode[node]=1;
             stonesNode[adjNode]=1; 
        }   
        int parent=0;
 // Count number of unique parents => number of connected components
        for(auto it:stonesNode){
            if(ds.findUp(it.first)==it.first) parent++;
        }
        // Total stones - number of components = max stones that can be removed
        return n-parent;
         
    }
};


// idea -> row ko node ki tarh treat karo and col ko bhi ek node man lo like col+maxrow+1 -> so ye new node ki tarh treat hoga 