  int minimumMultiplications(vector<int>& arr, int start, int end) {
      if(start==end ) return 0; // when the start and end both are same 
      vector<int>distance(1e5,INT_MAX); // because it has 10^5 max -> treating each multiplication answer as a node
      queue<pair<int,int>>q; // {node,step} ->because the nodes are come in order so we can do it using queue
      int mod=1e5; 
      distance[start]=0;
      q.push({start,0}) ; // src start from the 0th step 
      while(!q.empty()){
          int node=q.front().first;
          int step=q.front().second; // step covered till this node
          q.pop();
          for(int i=0;i<arr.size();i++){ // 
                 int newNode=(node*arr[i])%mod;
             if(step+1<distance[newNode]){ 
                 distance[newNode]=step+1;
          if(newNode==end) return step+1;  // if we get the end node 
                 q.push({newNode,step+1});
             }
          }
          
      }
        return -1;
    }