
// 110. Balanced Binary Tree
///Brute 

int height(TreeNode*root){
    if(root==NULL) return 0;
    return  1+ max ( height(root->left), height(root->right));

}
    bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
      int lh=height(root->left);
      int rh=height(root->right);
      if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
     return false;
    }

// Optimised 
int height(TreeNode*root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    if(lh==-1) return -1;
    int rh=height(root->right);
    if(rh==-1)
    return -1;
    if(abs(rh-lh)>1) return -1;
    return 1+max(rh,lh);
   
}
    bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
    if(height(root)==-1) return false;
    return true;
    }

