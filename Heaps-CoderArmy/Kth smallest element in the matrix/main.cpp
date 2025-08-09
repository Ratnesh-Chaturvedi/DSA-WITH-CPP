

// Brute Force

int kthSmallest(vector<vector<int>> &mat, int k) {
      int n=mat.size();
      priority_queue<int>pq;
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             if(pq.size()<k){
                 pq.push(mat[i][j]);
             }
            else if(pq.size()==k){
                 if(pq.top()>mat[i][j]){
                     pq.pop();
                     pq.push(mat[i][j]);
                 }
             }
         }
      }
      
      return pq.top();
        
    }



// appraoch 3

 int kthSmallest(vector<vector<int>> &mat, int k) {
    vector<pair<int,pair<int,int>> >arr;
    // it contains data row col
    int n=mat.size();
    for(int i=0;i<n;i++){
        arr.push_back(make_pair(mat[i][0],make_pair(i,0)));
    } 
    //building heap in O(n) 
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(arr.begin(),arr.end());
    
    
    pair<int,pair<int,int>>Element;
    int i,j,ans;
    
    while(k--){
        Element=pq.top();
        pq.pop();
        ans=Element.first;
        i=Element.second.first;
        j=Element.second.second;
        if(j+1<n){
            pq.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
        }
    }
    return ans;
    
        
    }



    // Approach 5  ->Using Binary search

     int count(vector<vector<int>> &arr, int mid)
    {
        int n=arr.size();
        int l=0,h=n-1,c=0;
        while(l<n && h>=0)
        {
            if(arr[l][h]<=mid)
            {
                c+=h+1;
                l++;
            }
            else    //if arr[l][h]>mid
                h--;
        }
        return c;
    }
    int kthSmallest(vector<vector<int>> &arr, int k) {
        int n=arr.size();
        int ans=0;
        int start=arr[0][0],end=arr[n-1][n-1];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int c=count(arr,mid); //how many ele r less than or eq to mid
            if(c>=k){
                ans=mid;//as we r taking equal case here only
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
