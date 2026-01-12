
// 222. Count Complete Tree Nodes
int leftHeight(TreeNode*node){
    int height=0;
    while(node){
        height++;
        node=node->left;
    }
    return height;
}
int rightHeight(TreeNode*node){
    int height=0;
    while(node){
        height++;
        node=node->right;
    }
    return height;
}
    int countNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int lh=leftHeight(root);      
    int rh=rightHeight(root); 
    if(rh==lh) return (1 << lh ) - 1;
    return 1+ countNodes(root->left) + countNodes(root->right);     
    }

