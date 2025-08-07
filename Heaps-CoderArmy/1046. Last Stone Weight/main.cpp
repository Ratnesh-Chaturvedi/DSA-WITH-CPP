    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1) return stones[0];
        priority_queue<int>pq; // building maxHeap
        for(int i=0;i<n;i++)
        pq.push(stones[i]);
    while(!pq.empty() && pq.size()>1){
        int y=pq.top();
        pq.pop();
        int x=pq.top();
        pq.pop();
        if(x!=y){
            y=y-x;
            pq.push(y);
        }
    }
    if(pq.size()==1){
        return pq.top();
    }
     return 0;
    }