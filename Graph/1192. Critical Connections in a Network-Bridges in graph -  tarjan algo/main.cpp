class Solution {
    private:
    int timer=1;
    private:
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges ){
        tin[node]=timer;
        low[node]=timer;
        vis[node]=true;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue; 
            // if the adjnode are not visited
            if(!vis[it]){
                dfs(it,node,adj,vis,tin,low,bridges);
                // taking the lowest time of adjacent nodes
                low[node]=min(low[it],low[node]);
                // checking that the nodes---it is the bridges edge or not
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }

            else {
                // taking low from adjacent node except the parent node 
               low[node]=min(low[it],low[node]);
        }
    }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // forming the graph wusing edges
        vector<vector<int>>adjList(n);
        for(auto it:connections){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        } 
        // forming a visited array
        vector<bool>vis(n,false);
        // time of insertion 
        vector<int>tin(n);
        // lowest time of insertion
        vector<int>low(n);

        // array to store the bridges 
        vector<vector<int>>bridges;
        dfs(0,-1,adjList,vis,tin,low,bridges);

        return bridges;
    }
};