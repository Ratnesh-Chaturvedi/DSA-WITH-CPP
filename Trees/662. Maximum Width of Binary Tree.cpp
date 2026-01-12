
// 662. Maximum Width of Binary Tree
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int minIdx=q.front().second;
            int firstIdx,lastIdx;
            for(int i=0;i<n;i++){
                int currIdx=q.front().second-minIdx;
                TreeNode*node=q.front().first;
                q.pop();
                if(i==0) firstIdx=currIdx;
                if(i==n-1) lastIdx=currIdx;
                if(node->left!=NULL) {
                    q.push({node->left,(long long)currIdx*2+1});
                }
                if(node->right!=NULL){
                q.push({node->right,(long long)currIdx*2+2});
                }
            }
            ans=max(ans,lastIdx-firstIdx+1);
        }
        return ans;
    }
