//  ceil 
int findCeil(Node* root, int x) {
    int ans=-1;
    
    while(root!=NULL){
        if(root->data==x){
            return x;
        }
        else if(root->data>=x){
            ans=root->data;
            root=root->left;
        }
        else root=root->right;
    }
    return ans;
    
}


// floor
// recursive
  void find(Node*root, int &node,int &val){
      if(root==NULL) return;
      if(root->data==node) {
          val=node;
          return;
      }
      if(root->data>node){
        find(root->left,node,val);
      }
       if(root->data<=node){
            val=max(root->data,val);
          find(root->right,node,val);
       }
  }
    int floor(Node* root, int x) {
     int ans=-1;
    // find(root,x,ans);
    // return ans;
    // iterative 
       while(root!=NULL){
           if(root->data==x) return x;
           else if(root->data<=x) {
             ans=max(ans,root->data);
             root=root->right;
           }
           else root=root->left;
       }
       return ans;
    }