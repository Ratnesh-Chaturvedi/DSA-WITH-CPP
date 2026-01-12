
// 100. Same Tree
// here we can use any of three taversal
// in this we are going with the preorder
    bool isSameTree(TreeNode* p, TreeNode* q) {
   if(p==NULL || q==NULL) return p==q;

   return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

    }
