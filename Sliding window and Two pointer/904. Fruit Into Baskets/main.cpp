
// Fruits in Baskets ->Find length of the longest subarray containing atmost two distinct integers
//Brute force
 int totalElements(vector<int> &arr) {
      int n=arr.size();
  //brute 
  int len=0;
  for(int i=0;i<n;i++){
  set<int>st;
      for(int j=i;j<n;j++){
          if(st.size()<=2 ) {
              st.insert(arr[j]);
              len=max(len,j-i+1);
          }
          else break;
      }
      st.clear();
  }
  return len;
    }

// (Optimal)
  int totalElements(vector<int> &arr) {
      int n=arr.size();
 unordered_map<int,int>mpp;
 int r=0,l=0;
 int len=0;
 while(r<n){
    mpp[arr[r]]++;
    while(mpp.size()>2){
        mpp[arr[l]]--;
    if (mpp[arr[l]] == 0) {
        mpp.erase(arr[l]);
    } 
         l++;
    }
    len=max(len,r-l+1);
    r++;
 }
 return len;
    }

// Most Optimal
    int totalElements(vector<int> &arr) {
      int n=arr.size();
 unordered_map<int,int>mpp;
 int r=0,l=0;
 int len=0;
 while(r<n){
    mpp[arr[r]]++;
   if(mpp.size()>2){
       mpp[arr[l]]--;
       if(mpp[arr[l]]==0) mpp.erase(arr[l]);
       l++;
   }
   if(mpp.size()<=2) len=max(len,r-l+1);
    r++;
 }
 return len;
    }

