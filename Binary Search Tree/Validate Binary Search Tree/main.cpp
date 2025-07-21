// 98. Validate Binary Search Tree

// brute 
void inorder(TreeNode*root,vector<int>&vals){
    if(root==NULL) return;
    inorder(root->left,vals);
    vals.push_back(root->val);
    inorder(root->right,vals);
}
    bool isValidBST(TreeNode* root) {
        vector<int>vals;
        inorder(root,vals);
        for(int i=0;i<vals.size()-1;i++){
            if(vals[i]>=vals[i+1]) return false;
        }
        return true;
    }

//optimised 
bool isValid(TreeNode*root,long mini,long maxi){
    if(root==NULL) return true;
    if(root->val>=maxi ||  root->val <=mini) return false;
    return  isValid(root->left,mini,root->val) && isValid(root->right,root->val,maxi) ;
}
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }