#include <bits/stdc++.h>
using namespace std;
// By union by rank and size  // we can use anyone of them 
class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0); // it works for both 1 base and 0 based indexing
        parent.resize(n+1);
         size.resize(n+1,1); // it works for both 1 base and 0 based indexing
        // assign each node to parent -> node ka parent node hi hoga initially
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    // finding ultimate parent  -> a type of path compression move
    int findUParent(int node){
        if(node==parent[node] ) return node;
        return parent[node]=findUParent(parent[node]); //a type of path compression move
    }

    // Union by rank
    void unionByRank(int u,int v){
        int ulp_u=findUParent(u); // find the ultimate parent of u
        int ulp_v=findUParent(v); // find the ultimate parent of v
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else {
            //  both ranks are same we can attach anyone to anyone of them
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++; // rank also increases
        }
    }
    // union by size
      void unionBySize(int u,int v){
        int ulp_u=findUParent(u); // find the ultimate parent of u
        int ulp_v=findUParent(v); // find the ultimate parent of v
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




int main(){
    DisjointSet ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    // before it check whether 3 and 7 belong to same component or not
    // if(ds.findUParent(3)==ds.findUParent(7)){
    //     cout<<"same";
    // }
    // else cout<<"Not same";
    // ds.unionByRank(3,7);
    //  if(ds.findUParent(3)==ds.findUParent(7)){
    //     cout<<"same";
    // }
    // else cout<<"Not same";




    // unions by size 
ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // before it check whether 3 and 7 belong to same component or not
    // if(ds.findUParent(3)==ds.findUParent(7)){
    //     cout<<"same";
    // }
    // else cout<<"Not same";
    ds.unionBySize(3,7);
     if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"same";
    }
    else cout<<"Not same";
}