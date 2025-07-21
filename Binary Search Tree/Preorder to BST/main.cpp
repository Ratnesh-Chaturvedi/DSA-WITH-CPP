//  Brute 
// by using the concept of insert node in the BST at correct position
    void insertNode(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        TreeNode* curr = root;
        while (curr) {
            if (curr->val <= val) {
                if ( curr->right != NULL) {
                    curr = curr->right;
                } else {
                    curr->right = node;
                    break;
                }
            } else {
                if ( curr->left != NULL) {
                    curr = curr->left;
                } else {
                    curr->left = node;
                    break;
                }
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < n; i++) {
            insertNode(root, preorder[i]);
        }
        return root;
    }


    // Better approach is by using the inorder and preorder to construct BST 


    // Optimised appraoch -> using the concept of validate BST by using upperbound concept
    TreeNode*build(vector<int>&arr,int &i,int bound){
if(i==arr.size() || arr[i]>bound) return NULL;
TreeNode*root=new TreeNode(arr[i++]);
root->left=build(arr,i,root->val);
root->right=build(arr,i,bound);
return root;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
   int i=0;
   return build(preorder,i,INT_MAX);

    }

