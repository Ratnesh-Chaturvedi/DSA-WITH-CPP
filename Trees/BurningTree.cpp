
// Burning Tree

 int BurnTime(unordered_map<Node*,Node*>parent,Node*target){
     unordered_map<Node*,bool>visited;
     queue<Node*>q;
     q.push(target);
     visited[target]=true;
     int maxi=0;
     while(!q.empty()){
         int n=q.size();
     int flag=0; // it is used to check whether it is burn or not
         for(int i=0;i<n;i++){
             Node*node=q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                flag=1;
                q.push(node->left) ;
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                flag=1;
                q.push(node->right);
                visited[node->right]=true;
            }
            if(parent[node] && !visited[parent[node]]){
                flag=1;
                q.push(parent[node]);
            visited[parent[node]]=true;
            }
         }
         if(flag==1) maxi++;
     }
     return maxi;
 }
 
 
 
 
  // first BFS to map parent and return the target
  Node* mapParent(Node*root,unordered_map<Node*,Node*>&parents,int target){
     queue<Node*>q;
     q.push(root);
     Node*res;
     while(!q.empty()){
         Node*temp=q.front();
         q.pop();
         if(temp->data==target) res=temp;
         if(temp->left){
             q.push(temp->left);
             parents[temp->left]=temp;
         }
         if(temp->right){
             q.push(temp->right);
             parents[temp->right]=temp;
         }
     }
     return res;
  }
  
    int minTime(Node* root, int target) {
     unordered_map<Node*,Node*>parent;
     Node*node=mapParent(root,parent,target);
     int maxi=BurnTime(parent,node);
     return maxi;
    }
    
