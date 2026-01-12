

// 124. Binary Tree Maximum Path Sum
int traverse(TreeNode*root,int &pathsum){
    if(root==NULL) return 0;
    int lh=max(0,traverse(root->left,pathsum));
    int rh=max(0,traverse(root->right,pathsum));
    pathsum=max(pathsum,lh+rh+root->val);
    return root->val+ max(lh,rh) ;
}
    int maxPathSum(TreeNode* root) {
        int pathsum=INT_MIN;
       traverse(root,pathsum);
        return pathsum;
    }

