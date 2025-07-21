//  iterative 
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
     TreeNode*curr=root;
     while(curr){
        if(curr->val<=val){
            if(curr->right) curr=curr->right;
            else {
                curr->right=new TreeNode(val);
                break;
            }
        }
        else {
            if(curr->left) curr=curr->left;
            else {
                curr->left=new TreeNode(val);
                break;
            }
        }

     }
     return root;
    }


    // recursive
      TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val<=val){
            root->right=insertIntoBST(root->right,val);
        }
        else {
            root->left=insertIntoBST(root->left,val);
        }
        return root;
    }