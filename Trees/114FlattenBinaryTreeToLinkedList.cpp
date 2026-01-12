 // 114. Flatten Binary Tree to Linked List 
   //Approach 1- SC -O(n)
   void flat(TreeNode*node,TreeNode*&prev){
    if(node==NULL) return;
    flat(node->right,prev);
    flat(node->left,prev);
    node->right=prev;
    node->left=NULL;
    prev=node;
}
    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        flat(root,prev);
    }


    //Approach 2- By using stack
     void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*cur=st.top();
            st.pop();
            if(cur->right!=NULL) st.push(cur->right); 
            if(cur->left!=NULL) st.push(cur->left); 
            if(!st.empty()) cur->right=st.top(); // link to next node in preorder
            cur->left=NULL; // detach the left link
        }
    }

    // Optimised approach SC-O(1) // Morris Traversal approach
    // by Morris Traversal Approach
    void flatten(TreeNode* root) {
        TreeNode*curr=root;
        while(curr){
            if(curr->left){
                TreeNode*prev=curr->left;
                while(prev->right!=NULL) prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
   
    }

 
