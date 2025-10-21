class Solution {
  public:
  void solve(vector<int>&arr,int k,int idx){
      int n=arr.size();
      if(n==1) return;
      int i=(idx+k)%n;
      arr.erase(arr.begin()+i);
      solve(arr,k,i);
  }
    int safePos(int n, int k) {
     vector<int>arr(n);
     for(int i=0;i<n;i++) arr[i]=i+1;
    solve(arr,k-1,0); 
    return arr[0];
    }
};
