// 543. Diameter of Binary Tree
int height(TreeNode*root,int &maxi){
    if(root==NULL) return 0;
    int lh=height(root->left,maxi);
    int rh=height(root->right,maxi);
    int temp=max(0,lh)+max(0,rh);
    maxi=max(maxi,temp);
    return 1 + max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi;
    }

