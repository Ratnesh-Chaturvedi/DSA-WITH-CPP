// User function Template for C++

class Solution {
    private:
    int timer=1;
    void dfs(int node,int parent,vector<int>adj[],
    vector<bool>&vis,vector<int>&tin,vector<int>&low,vector<int>&mark){
        vis[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        // if it is the starting point and have more then one child 
        // it can be an articulation node 
        int child=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,tin,low,mark);
                // marking the low if with adjacent low because it is not visited
                low[node]=min(low[it],low[node]);
                // checking if it is an articulation Point
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else {
                // if node is already visited then low will be the tin of adjacent node
                low[node]=min(low[node],tin[it]);
            }
            
        }
        // if it is starting node and  have more than one child then it is an articulation point
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
       // visited array
       vector<bool>vis(n,false);
       // time of insertion and lowest time
       vector<int>tin(n),low(n);
       // to mark the articulation points
       vector<int>mark(n);
       for(int i=0;i<n;i++){
           if(!vis[i]){
               dfs(i,-1,adj,vis,tin,low,mark);
           }
       }
       // to store the articulation points
       vector<int>aPoints;
       for(int i=0;i<n;i++){
           if(mark[i]==1) aPoints.push_back(i);
       }
      if(aPoints.size()>=1) return aPoints;
      return {-1};
        
    }
};