// 101. Symmetric Tree
 bool isSameTree(TreeNode* p, TreeNode* q) {
   if(p==NULL || q==NULL) return p==q;
   return (p->val==q->val) && isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
}
    bool isSymmetric(TreeNode* root) {
    if(root==NULL) return true;
  bool l=isSameTree(root->left,root->right);
  return l;
    }
