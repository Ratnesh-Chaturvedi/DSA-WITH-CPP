class Solution {
  public:
    string findOrder(vector<string> &words) {
      vector<vector<int>>adj(26); // because only 26 char are in lowercase alphabets
      vector<int>present(26,false); // check for how many char are present
      vector<int>indegree(26,0);
      int n=words.size();
      for(int i=0;i<n-1;i++){
          string s1=words[i];
          string s2=words[i+1];
          int l=min(s1.size(),s2.size());
          
          if(s1.size()>s2.size() && s1.substr(0,l)==s2) return "";
          for(int j=0;j<l;j++){
              if(s1[j]!=s2[j]){
                  adj[s1[j]-'a'].push_back(s2[j]-'a');
                  break;
              }
          }
      }
      for(auto word:words){
          for(auto it:word){
              present[it-'a']=true;
          }
      }
      string ans="";
      // toposort part start from here 
      queue<int>q;
      for(int i=0;i<26;i++){
          for(auto it:adj[i]){
              indegree[it]++;
          }
      }
      for(int i=0;i<26;i++){
          if(present[i] && indegree[i]==0) q.push(i);
      }
     while(!q.empty()){
         int node=q.front();
         q.pop();
         ans+=char(node+'a');
         for(auto it:adj[node]){
             indegree[it]--;
             if(indegree[it]==0)q.push(it);
         }
     }
     for(int i=0;i<26;i++){
         if(indegree[i]!=0) return "";
     }
     return ans;
        
    }
};