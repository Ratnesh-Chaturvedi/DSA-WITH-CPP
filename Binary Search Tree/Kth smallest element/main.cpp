// 230. Kth Smallest Element in a BST

// Brute 
void dfs(TreeNode*root,vector<int>&arr){
    if(root==NULL) return;
    if(root->left) dfs(root->left,arr);
    arr.push_back(root->val);
    if(root->right) dfs(root->right,arr);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        dfs(root,arr);
        return arr[k-1];
    }


// optimised 
void inorder(TreeNode*root,int key,int &ans){
    if(root==NULL) return;
    if(root->left) inorder(root->left,key,ans);
    cnt++;
    if(cnt==key) {
      ans=root->val;
      return;
    }
    if(root->right) inorder(root->right,key,ans);
}
    int kthSmallest(TreeNode* root, int k) {
         int ans;
         inorder(root,k,ans);
         return ans;
    }