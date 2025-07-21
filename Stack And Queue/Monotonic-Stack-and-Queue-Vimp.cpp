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


//Find nearest smaller element on the left side
void smaller(vector<int>&arr){
    stack<int>st;
    int n=arr.size();
    int mini=INT_MAX;
    vector<int>ans(n,-1);
  
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(st.empty()){
            ans[i]=-1;
            
        }
        else ans[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
  
    
}

//next smallest Element
vector<int>nextSmallEl(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}


// previous smallest Element
vector<int>prevSmallEl(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}



// 42. Trapping Rain Water
//TC-O(3n) SC-O(2n) 
//little Optimisation in space can we done by replacing the prefix max SC-O(N); 



int trap(vector<int>& height) {
        int n=height.size();
        // vector<int>prefixMax(n);
        vector<int>suffixMax(n);
        // prefixMax[0]=height[0];
        // for(int i=1;i<n;i++){
        //     prefixMax[i]=max( prefixMax[i-1],height[i]);
        // }
        suffixMax[n-1]=height[n-1];
           for(int i=n-2;i>=0;i--){
            suffixMax[i]=max( suffixMax[i+1],height[i]);
        }
          int total=0;
           int maxi=INT_MIN;
          for(int i=0;i<n;i++){
            //for space Optimisation
                 maxi=max(height[i],maxi);
            total+=min(maxi,suffixMax[i])-height[i];
            //by using prefixMax;
            // total+=min(prefixMax[i],suffixMax[i])-height[i];

          }
 return total;
    }


    // optimla -Two pointer 
    // TC-O(N) SC-O(1)
     int trap(vector<int>& height) {
        int n=height.size();
       int total=0;
       int lmax=0,rmax=0,l=0,r=n-1;
       while(l<r){
        if(height[l]<=height[r]){
            if(lmax>height[l]) total+=lmax-height[l];
            else lmax=height[l];
            l++;
        }
        else {
            if(rmax>height[r]) total+=rmax-height[r];
            else rmax=height[r];
            r--;
        }
       }
       
          
 return total;
    }


    // 907. Sum of Subarray Minimums
    //Brute 
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        int mod=(int)(1e9 + 7);
        for(int i=0;i<n;i++){
            int mini=arr[i];
            for(int j=i;j<n;j++){
           mini=min(arr[j],mini);
           sum=(sum+mini)%mod;
            }
        }
        return sum;
    }

    //optimal
    vector<int>findNse(vector<int>&arr){
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
     while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        nse[i]=st.empty()?n:st.top();
        st.push(i);
        }
        return nse;
    }
    vector<int>findPsee(vector<int>&arr){
        int n=arr.size();
        vector<int>psee(n);
        stack<int>st;
        for(int i=0;i<n;i++){
     while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        psee[i]=st.empty()?-1:st.top();
        st.push(i);
        }
        return psee;
    }
    
        int sumSubarrayMins(vector<int>& arr) {
         vector<int>nse=findNse(arr);
         vector<int>psee=findPsee(arr);
         int total=0;
         int mod=(int)(1e9+7);
         for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total=(total+(right*left*1LL*arr[i])%mod)%mod;
         }
         return total;
        }


        // 2104. Sum of Subarray Ranges
        // Brute force
        long long subArrayRanges(vector<int>& arr) {
            int n=arr.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                int maxi=arr[i];
                int mini=arr[i];
                for(int j=i;j<n;j++){
                    maxi=max(maxi,arr[j]);
                    mini=min(mini,arr[j]);
                    sum+=(maxi-mini);
                }
            }
            return sum;
        }

        //optimal
        vector<int>findNge(vector<int>&arr){
            int n=arr.size();
            stack<int>st;
            vector<int>ans(n);
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
                ans[i]=st.empty()?n:st.top();
                st.push(i);
            }
            return ans;
        }
           vector<int>findPgee(vector<int>&arr){
                int n=arr.size();
                vector<int>pgee(n);
                stack<int>st;
                for(int i=0;i<n;i++){
             while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
                pgee[i]=st.empty()?-1:st.top();
                st.push(i);
                }
                return pgee;
            }
             long long sumSubarrayMins(vector<int>& arr) {
                 vector<int>nse=findNse(arr);
                 vector<int>psee=findPsee(arr);
                 long long total=0;
                 
                 for(int i=0;i<arr.size();i++){
                     long long left = i - psee[i];
                    long long right = nse[i] - i;
                    total += (left * right * (long long)arr[i]);
                 }
                 return total;
                }
                 long long  sumSubarrayMax(vector<int>& arr) {
                 vector<int>nge=findNge(arr);
                 vector<int>pgee=findPgee(arr);
                 long long total=0;
                 for(int i=0;i<arr.size();i++){
                     long long left = i - pgee[i];
                    long long right = nge[i] - i;
                    total += (left * right * (long long)arr[i]);
                 }
                 return total;
                }
            long long subArrayRanges(vector<int>& arr) {
                return  sumSubarrayMax(arr)*1LL-sumSubarrayMins(arr)*1LL;
            }



            // 735. Asteroid Collision
            vector<int> asteroidCollision(vector<int>& arr) {
                int n = arr.size();
                vector<int> st;
                for (int i = 0; i < n; i++) {
                    if (arr[i] > 0)
                        st.push_back(arr[i]);
                    else {
                        while (!st.empty() && st.back() > 0 &&
                               (abs(arr[i]) > st.back()))
                            st.pop_back();
                        if (!st.empty() && st.back() == abs(arr[i]))
                            st.pop_back();
                        else if (st.empty() || st.back() < 0)
                            st.push_back(arr[i]);
                    }
                }
                return st;
            }

            // 84. Largest Rectangle in Histogram
            // Brute Force
            //we use next and previous smaller indexes 
            int largestRectangleArea(vector<int>& heights) {
                int n=heights.size();
             if(n==1) return heights[0];
             vector<int>Nse=findNse(heights);
             vector<int>Pse=findPsee(heights);
             int maxi=0;
             for(int i=0;i<n;i++){
                int area=heights[i]*(Nse[i]-Pse[i]-1);
                maxi=max(area,maxi);
             }
             return maxi;
            }

            //optimal
            int largestRectangleArea(vector<int>& arr) {
                int n=arr.size();
                int maxArea=0;
                stack<int>st; // it stores the indexes
                for(int i=0;i<n;i++){
              while(!st.empty() && arr[st.top()]>arr[i] ){
               int elem=st.top();
               st.pop();
               int nse=i;
               int pse=st.empty()?-1:st.top();
               maxArea=max(maxArea,(arr[elem]*(nse-pse-1)));
              }
              st.push(i);
                }
                // if there is still some element left in the stack;
                while(!st.empty()){
                      int elem=st.top();
               st.pop();
               int nse=n;
               int pse=st.empty()?-1:st.top();
               maxArea=max(maxArea,(arr[elem]*(nse-pse-1)));
                }
                return maxArea;
            }


            // 85. Maximal Rectangle
            int maximalRectangle(vector<vector<char>>& matrix) {
                int n=matrix.size();
                int m=matrix[0].size();
                vector<vector<int>>prefixSum(n,vector<int>(m));
            //calculating prefix sum
            for(int j=0;j<m;j++){
                int sum=0;
                for(int i=0;i<n;i++){
                    sum+=matrix[i][j]-'0';
                    if(matrix[i][j]=='0') sum=0;
                    prefixSum[i][j]=sum;
                }
            }
            int maxA=0;
            for(int i=0;i<n;i++){
           maxA=max(maxA,largestRectangleArea(prefixSum[i]));
            }
            return maxA;
            }
            // for space optimise- we can optimsed the prefix sum ->because we just need each row wise prefix sum so that we can compute this under 2 loops where we also put the maxArea and call the largestRectangle area;
            
            
            //402. Remove K Digits
            string removeKdigits(string num, int k) {
                int n=num.size();
                if(k==n) return "0";
                stack<char>st;
                for(int i=0;i<n;i++){
                    while(!st.empty() && k && st.top() > num[i] ){
                        k--;
                        st.pop();
                    }
                    st.push(num[i]);
                }
                while(k){
                    st.pop();
                    k--;
                }
                if(st.empty()) return "0";
                 string res="";
                 while(!st.empty()){
                    res.push_back(st.top());
                    st.pop();
                 }
                 while(res.size() && res.back()=='0'){
                    res.pop_back();
                 }
                 reverse(res.begin(),res.end());
                 if(res.size()==0) return "0";
                 return res;
        
            }


            
                    