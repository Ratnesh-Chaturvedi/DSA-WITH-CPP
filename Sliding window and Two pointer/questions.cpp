// 1423. Maximum Points You Can Obtain from Cards
int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxsum = 0;
        if (k >= n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += cardPoints[i];
        maxsum = sum;
        int ridx = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[ridx];
            ridx--;
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }


// 1004. Max Consecutive Ones III
 int longestOnes(vector<int>& nums, int k) {
        // optimised 
        // vector<int>arr(2,0);
        // int n=nums.size();
        // int l=0,r=0;
        // int len=0;
        // while(r<n){
        //     arr[nums[r]]++;
        //     while(arr[0]>k){
        //      arr[nums[l]]--;
        //      l++;
        //     }
        //     len=max(len,r-l+1);
        //     r++;
        // }
        // return len;

        // most Optimised
        int n=nums.size();
        int l=0,r=0,zero=0,maxlen=0;
        while(r<n){
            if(nums[r]==0) zero++;
            if(zero>k) {
                if(nums[l]==0)zero--;
                l++; 
            }
            if(zero<=k) {
                int len=r-l+1;
                maxlen=max(len,maxlen);
            }
            r++;
        }
        return maxlen;
    }


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


// Longest Substring with K Uniques
int longestKSubstr(string &s, int k) {
       int len=-1;
       unordered_map<char,int>mpp;
       int l=0,r=0;
       int n=s.size();
       while(r<n){
           mpp[s[r]]++;
           if(mpp.size()>k){
               mpp[s[l]]--;
               if(mpp[s[l]]==0) mpp.erase(s[l]);
               l++;
           }
           if(mpp.size()==k)
           len=max(len,r-l+1);
           r++;
       }
      
        return len;
    }


// 424. Longest Repeating Character Replacement
 int characterReplacement(string s, int k) {
        int n = s.size();
        int r = 0, l = 0, len = 0;
        unordered_map<char, int> hash;
        int maxfreq = 0;
        while (r < n) {
            hash[s[r]]++;
            // maxfreq is the used to take the character which has highest count
            maxfreq = max(maxfreq, hash[s[r]]);
            if ((r - l + 1) - maxfreq > k) {
                hash[s[l]]--;
                l++;
            }
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }

//930- Binary subarray with sum // count no of subarray having sum==k
//Brute 
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==goal) cnt++;
        }
        }
        return cnt;
}
//better 
  // By using prefix sum;
   int sum=0,cnt=0;
   map<int,int>prefix;
   prefix[0]=1;
for(int i=0;i<n;i++){
    sum+=nums[i];
    cnt+=prefix[sum-goal];
    prefix[sum]++;
}
return cnt;

// optimal- using sliding window
int subarrayCnt(vector<int>& arr, int goal) {
    int n=arr.size();
    if(goal<0) return 0;
    int l=0,r=0,cnt=0,sum=0;
    while(r<n){
        sum+=arr[r];
        while(sum>goal){
            sum-=arr[l];
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;
}
 int numSubarraysWithSum(vector<int>& nums, int goal) {
     return subarrayCnt(nums,goal)-subarrayCnt(nums,goal-1);
}
    
// 1248. Count Number of Nice Subarrays
// Similar to Binary subarray with sum // count no of subarray having sum==k
// only covert the value of the arr in 0 or 1 by using nums[i]%2;
int cntsubarray(vector<int>& nums, int k){
    int n=nums.size();
    if(k<0) return 0;
    int r=0,l=0,cnt=0,sum=0;
    while(r<n){
        sum+=nums[r]%2;
        while(sum>k) {
            sum-=nums[l]%2;
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;

 }

    int numberOfSubarrays(vector<int>& nums, int k) {
    int n=nums.size();

    // this question is similar to binary subarray with sum eqaul to k
    //better approach
//           unordered_map<int,int>prefix;
//           int cnt=0;
//           prefix[0]=1;
//           int sum=0;
//           for(int i=0;i<n;i++){
//             sum+=nums[i]%2;
//              cnt+=prefix[sum-k];
//              prefix[sum]++;
//           }
// return cnt;

//optimised approach
return cntsubarray(nums,k)-cntsubarray(nums,k-1);
    }

