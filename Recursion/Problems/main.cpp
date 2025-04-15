39. Combination Sum 

void UniqueCom(int idx,int t,vector<int>&curr,vector<vector<int>>&ans,vector<int>&arr){
    if(idx==arr.size()){
        if(t==0){
            ans.push_back(curr);
        }
            return;
    }
    // pickup condition
    if(arr[idx]<=t){
        curr.push_back(arr[idx]);
        UniqueCom(idx,t-arr[idx],curr,ans,arr);
        curr.pop_back();
    }
    // not pickup condition
     UniqueCom(idx+1,t,curr,ans,arr);
    }
        vector<vector<int>> combinationSum(vector<int>&arr , int target) {
    
            vector<vector<int>>ans;
            vector<int>curr;
     UniqueCom(0,target,curr,ans,arr);
     return ans;
        }



// 40 - combination sum II

// Brute force

// but this gives TLE
void comb(int idx, int s, int t, vector<int>& arr, set<vector<int>>& ans,
    vector<int> temp) {

if (idx == arr.size()) {
  if (s == t) {
      sort(temp.begin(),temp.end());
      ans.insert(temp);
  }
  return;
}

// picked
temp.push_back(arr[idx]);
s+=arr[idx];
comb(idx+1,s,t,arr,ans,temp);
temp.pop_back();
s-=arr[idx];
//not picked
comb(idx+1,s,t,arr,ans,temp);
}
vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
set<vector<int>> ans;
vector<int> temp;
comb(0, 0, target, arr, ans, temp);
vector<vector<int>>result;
for(auto it:ans){
  result.push_back(it);
}
return result;
}

// optimised 
void comb(int idx, int t, vector<int>& arr, vector<vector<int>>& ans,
    vector<int> curr) {
      if(t==0){
          ans.push_back(curr);
          return;
      }
      for(int i=idx;i<arr.size();i++){
          if(i>idx && arr[i]==arr[i-1]) continue;
          if(arr[i]>t) break;
          curr.push_back(arr[i]);
          comb(i+1,t-arr[i],arr,ans,curr);
          curr.pop_back();
      }
}
vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
sort(arr.begin(),arr.end());
vector<vector<int>> ans;
vector<int> curr;
comb(0,target, arr, ans,curr);
return ans;
}



