// 104. Maximum Depth of Binary Tree

// Approach 1 
// really we dont need vector to store ans we just need to find the depth so we can do 
int BFS(TreeNode*root){
    // vector<vector<int>>ans;
    if(root==NULL) return 0; 
    int depth=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        // vector<int>arr;
        depth++;
        int size=q.size();
        for(int i=0;i<size;i++){
        TreeNode*node=q.front();
        q.pop();
        if(node->left!=NULL) q.push(node->left);
        if(node->right!=NULL) q.push(node->right);
        // arr.push_back(node->val);
        }
        // ans.push_back(arr);   
    }
    // return ans.size();
    return depth;
}

// Approach 2
int MaxHeight(TreeNode*root){
    if(root==NULL) return 0; 
    int l=MaxHeight(root->left);
    int r=MaxHeight(root->right);
    return 1 + max(l,r);
}
