bool canFinish(int nc, vector<vector<int>>& pr) {
        vector<vector<int>>adj(nc); // creating adjacency list
        vector<int>indegree(nc,0); // storing indegree
        for(auto it:pr){
            adj[it[1]].push_back(it[0]); // marking the edges b->a
            indegree[it[0]]++;//  indegree-> a++;
        }
       int topo=0;
        queue<int>q;
       for(int i=0;i<nc;i++){
        if(indegree[i]==0)q.push(i);
       }
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            topo++;
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
           return topo==nc; // it means no cycle exist 
    }