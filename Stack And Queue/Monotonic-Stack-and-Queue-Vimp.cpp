// 496. Next Greater Element I
//Brute Force naive TC-O(n^3)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    vector<int>ans;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(nums1[i]==nums2[j]){
                bool found=false;
                for(int k=j+1;k<n2;k++){
                    if(nums2[j]<nums2[k]){
                        ans.push_back(nums2[k]);
                        found=true;
                        break;
                    }
                }
                if(!found) ans.push_back(-1);
            }
        }
    }
    return ans;
}


// Optimised 
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    stack<int>st;
    unordered_map<int,int>mpp;
    for(int j=n2-1;j>=0;j--){
        while(!st.empty() && st.top()<=nums2[j])
        st.pop();
        if(st.empty()){
            mpp[nums2[j]]=-1;
        }
        else mpp[nums2[j]]=st.top();
        st.push(nums2[j]);

    }
    vector<int>ans;
    for(int i=0;i<n1;i++){
        ans.push_back(mpp[nums1[i]]);
    }
   return ans;
   
}


// 503. Next Greater Element II
vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    stack<int>st;
    vector<int>ans(n);
   for(int i=2*n-1;i>=0;i--){
      int idx=i%n;
      while(!st.empty() && st.top()<=nums[idx]) st.pop();
      if(i<n){
        ans[idx]=st.empty()?-1:st.top();
      }

      st.push(nums[idx]);
   }
   return ans;
}