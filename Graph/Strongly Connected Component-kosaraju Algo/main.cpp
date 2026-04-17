//Position this line where user code will be pasted.
class Solution {
  private:
  // step 1-> sort edges acc to the finishing time
  void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,stack<int>&st){
      vis[node]=true;
      for(auto it:adj[node]){
          if(!vis[it]){
             dfs(it,vis,adj,st);
          }
      }
      st.push(node);
  }
  // again making a DFS for step 3
  private:
  void dfs3(int node,vector<bool>&vis,vector<vector<int>>&adjTranspose,vector<int>&comp){
      vis[node]=true;
      comp.push_back(node); // storing each component of SCC
      for(auto it:adjTranspose[node]){
          if(!vis[it])  dfs3(it,vis,adjTranspose,comp);
      }
  }
  
  public:
    int kosaraju(vector<vector<int>> &adj) {
       int n=adj.size();
       vector<bool>visited(n,false);
       stack<int>st; // for storing the element with their finishing time ->bottom elem of stack hash least finishing time
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        //Step 2->
        // Reverse the graph -> transpose the graph bcoz it is the adjacency matrix
        vector<vector<int>>adjTranspose(n);
     for(int i=0;i<n;i++){
         visited[i]=false ; // so we can use it again in step 3 
         for(auto it:adj[i]){
            // edge is -> i -> it  
            adjTranspose[it].push_back(i);
         }
     }
     
     int scc=0; // to count the number of scc
     vector<vector<int>>sccComponent; // to store the path of the SCC nodes
     //Step 3->
     // do DFS one the graph node that are stored in stack
     while(!st.empty()){
         int node=st.top();
         st.pop();
             if(!visited[node]){
                 vector<int>comp;
                 scc++; // each node count the scc component
                 dfs3(node,visited,adjTranspose,comp);
                 sccComponent.push_back(comp);
                 
             }
         
     }
     return scc;
    }
    
};
