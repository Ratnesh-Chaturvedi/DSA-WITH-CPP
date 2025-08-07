  
//   Gfg
//   O(n*log(n)) Time and O(n) Space

  int minCost(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
         priority_queue<int,vector<int>,greater<int>>pq; // build a min heap
         for(int i=0;i<n;i++){
             pq.push(arr[i]);
         }
         
         int cnt=0;
         while(!pq.empty() && pq.size()>1){
            int a1=pq.top();
            pq.pop();
            int a2=pq.top();
            pq.pop();
            int sum=a1+a2;
            cnt+=sum;
            pq.push(sum);
         }
        
        return cnt;
        
    }