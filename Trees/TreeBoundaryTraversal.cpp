
// Tree Boundary Traversal

  bool isleaf(Node*root){
      if(!root->left && !root->right) return true;
      return false;
  }
 void leftNode(Node*root,vector<int>&res){
      Node*curr=root->left;
      while(curr){
      if(!isleaf(curr))  res.push_back(curr->data);
      if(curr->left) curr=curr->left;
      else    curr=curr->right;
      }
}
  void leafNode(Node*root,vector<int>&res){
     if(isleaf(root)){
         res.push_back(root->data);
         return;
     }
     if(root->left)
         leafNode(root->left,res);
     if(root->right)
         leafNode(root->right,res);
  }
   void rightNode(Node*root,vector<int>&res){
       vector<int>temp;
      Node*curr=root->right;
      while(curr){
      if(!isleaf(curr) ) temp.push_back(curr->data);
      if(curr->right) curr=curr->right;
      else  curr=curr->left;
      }
        for(int i=temp.size()-1;i>=0;i--)
         res.push_back(temp[i]);
     
  }
    vector<int> boundaryTraversal(Node *root) {
   vector<int>res;
   if(!root) return res;
   if(!isleaf(root)) res.push_back(root->data);
   leftNode(root,res);
   leafNode(root,res);
   rightNode(root,res);
   return res;
        
    }

