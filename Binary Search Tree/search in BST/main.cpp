// recursive solution

  TreeNode* searchBST(TreeNode* root, int val) {
    if(root==NULL ) return NULL;
    if(root->val==val) return root;
    if(root->val > val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
    }

    // iterative solution
      TreeNode* searchBST(TreeNode* root, int val) {
 while(root!=NULL && root->val!=val){
     root=val>root->val?root=root->right:root=root->left;
 }
 return root;
    }