//Root to particular Node Path
bool path(Node*root,vector<int>&temp,int node){
    if(root==NULL) return false;
    temp.push_back(root->val);
    if(root->val==node) return true;
    if(path(root->right,temp,node) || path(root->left,temp,node)) return true;
    temp.pop_back();
    return false;    
}

// Root to all leaf Paths
     vector<vector<int>>ans;
  void traverse(Node*root,vector<int>&temp){
      if(root==NULL){
         return;
      }
      temp.push_back(root->data);
      if(root->left==NULL && root->right==NULL){
          ans.push_back(temp);
      }
      if(root->left!=NULL){
          traverse(root->left,temp);
      }
        if(root->right!=NULL){
          traverse(root->right,temp);
      }
      // backtrack and popping the value
      temp.pop_back();
  }
    vector<vector<int>> Paths(Node* root) {
  vector<int>temp;
  traverse(root,temp);
  return ans;
    }

