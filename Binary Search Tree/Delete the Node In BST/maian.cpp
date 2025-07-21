// helper function for attaching the links with correct node after deleting the given node 
TreeNode*helper(TreeNode*node){
    if(node->left==NULL) {
        return node->right;
    }
    else if(node->right==NULL){
        return node->left;
    }
    TreeNode*rightchild=node->right;
    TreeNode*lastchild=findLastRight(node->left);
    lastchild->right=rightchild;
    return node->left;
}
// to get the last  right child so that we connect it to the another subtree of that node 

TreeNode*findLastRight(TreeNode*node){
    if(node->right==NULL){
        return node;
    }
    return findLastRight(node->right);
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
     if(root->val==key) return helper(root);
     TreeNode*dummy=root;
     while(root){
        if(root->val>key){
            if(root->left && root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
        }
        else {
            if(root->right && root->right->val==key){
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
     }
     return dummy;
    }