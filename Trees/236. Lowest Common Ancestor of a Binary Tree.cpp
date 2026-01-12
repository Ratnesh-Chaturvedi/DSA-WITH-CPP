 // 236. Lowest Common Ancestor of a Binary Tree
  //Brute 
  bool path(TreeNode*root,vector<TreeNode*>&temp,TreeNode*node){
if(root==NULL) return false;
temp.push_back(root);
if(root==node)return true;
if(path(root->left,temp,node)|| path(root->right,temp,node)) return true ;
temp.pop_back();
return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a1,a2;
        path(root,a1,p);
        path(root,a2,q);
       int i=0,j=0;
       TreeNode*lca;
       while(i<a1.size() && j<a2.size()){
        if(a1[i]==a2[i]) {
            lca=a1[i];
            i++,j++; 
        }
        else break;
       }
        return lca;
}

//Optimsed 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q ) return root;

        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL)return right;
        else if(right==NULL) return left;
        else return root;
  }

