
// 105. Construct Binary Tree from Preorder and Inorder Traversal
 TreeNode* treeBuild(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& hash) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;   
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = hash[root->val];
        int numsLeft = inRoot - inStart;

        root->left = treeBuild(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, hash);
        root->right = treeBuild(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, hash);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;

        TreeNode* root = treeBuild(preorder, 0, preorder.size() - 1, inorder, 0,
                                   inorder.size() - 1, hash);
        return root;
    }

// 106. Construct Binary Tree from Inorder and Postorder Traversal
TreeNode*treeBuild(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int pstart,int pend,   map<int,int>&hash){

if(pstart >pend || instart>inend) return NULL;
TreeNode *root=new TreeNode(postorder[pend]);
int idx=hash[root->val];
int numsleft=idx-instart;

root->left=treeBuild(inorder,instart,instart+numsleft-1,postorder,pstart,pstart+numsleft-1,hash);
root->right=treeBuild(inorder,instart+numsleft+1,inend,postorder,pstart+numsleft,pend-1,hash);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      map<int,int>hash;
      for(int i=0;i<inorder.size();i++){
        hash[inorder[i]]=i;
      }  
      TreeNode *root=treeBuild(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hash);
      return root; 
    }



// Morris Traversal 
// Inorder Traversal
   vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = curr; // thread created
                    curr = curr->left;
                } else {
                    prev->right = NULL; // thread deleted
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }


    // Preorder 
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> prerorder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                perorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = curr; // thread created
                      preorder.push_back(curr->val);
                    curr = curr->left;
                } else {
                    prev->right = NULL; // thread deleted
                  
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }



