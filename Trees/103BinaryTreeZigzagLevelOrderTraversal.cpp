
// 103. Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            TreeNode*node=q.front();
            q.pop();
            // finding position to fill the value;
            int idx=flag?i:(size-1-i);
            level[idx]=node->val;
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        flag=!flag;
        ans.push_back(level);
    }
    return ans;
    }
