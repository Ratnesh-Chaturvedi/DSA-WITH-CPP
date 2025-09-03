  bool DFS(int node,vector<int>&visit,vector<int>&path,vector<int>adj[]){
      visit[node]=1;
      path[node]=1;
      for(auto it:adj[node]){
          if(visit[it]==0){
              if(DFS(it,visit,path,adj)==true) {
                  
                  return true;
              }
          }
          else if(path[it]==1){
              
            return true;  
          } 
      }
     path[node]=0;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
      vector<int>safeNodes;
      vector<int>visit(V,0);
      vector<int>path(V,0);
      
      for(int i=0;i<V;i++){
          if(!visit[i]){
              DFS(i,visit,path,adj);
          }
      }
      for(int i=0;i<V;i++){
          if(!path[i]) safeNodes.push_back(i);
      }
      sort(safeNodes.begin(),safeNodes.end());
      return safeNodes;
      
    }


    // using bfs
    	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> adjRev[V];
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			// i -> it
			// it -> i
			for (auto it : adj[i]) {
				adjRev[it].push_back(i);
				indegree[i]++;
			}
		}
		queue<int> q;
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}