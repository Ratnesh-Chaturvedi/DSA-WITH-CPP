
// 199. Binary Tree Right Side View
// Recursive Way -
void rightView(TreeNode*root,int lvl,vector<int>&DS){
    if(root==NULL) return;
    if(lvl==DS.size()) DS.push_back(root->val);
    rightView(root->right,lvl+1,DS);
    rightView(root->left,lvl+1,DS);
}
    vector<int> rightSideView(TreeNode* root) {
          vector<int>ans;
          rightView(root,0,ans);
          return ans;
    }


// Iterative Code 
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int node;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* newNode=q.front();
                q.pop();
                if(newNode->left) q.push(newNode->left);
                if(newNode->right) q.push(newNode->right);
                node=newNode->val;
            }
            ans.push_back(node);
        }
        return ans;
    }