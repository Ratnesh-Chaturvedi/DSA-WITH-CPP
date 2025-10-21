
class Solution {
  public:
  unordered_map<string,int>hash;
  void solve(int n,int one,int zero,string temp,vector<string>&ans){
      if(temp.size()==n) {
          if(hash[temp]==0){
         ans.push_back(temp);
            hash[temp]=1;  
          }
         return;
      }
      if(one==0){
          solve(n,one+1,zero,temp+"1",ans);
      }
      if(one<n)
          solve(n,one+1,zero,temp+"1",ans);
     if(zero<one) solve(n,one,zero+1,temp+"0",ans);
      
      
  }
    vector<string> NBitBinary(int n) {
      vector<string>ans;
       solve(n,0,0,"",ans);
       return ans;
    }
};