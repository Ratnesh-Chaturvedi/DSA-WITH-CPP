 long long pickGifts(vector<int>& gifts, int k) {
        long long  ans=0;
        int n=gifts.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++) pq.push(gifts[i]);

        while(k--){
            int top=pq.top();
            pq.pop();
             top=floor(sqrt(top));
            pq.push(top);
        }
        
        while(!pq.empty()){
         ans+=pq.top();
         pq.pop();
        }
          return ans;
    }