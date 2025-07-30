// 99. Recover Binary Search Tree

//Brute ->
void inorder(TreeNode*root,vector<int>&arr){
    if(root==NULL) return ;
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right,arr);
}
void inorderSwap(TreeNode*root,vector<int>&arr,int &i){
    if(root==NULL) return ;
    inorderSwap(root->left,arr,i);
    swap(root->val,arr[i++]);
    inorderSwap(root->right,arr,i);
}
    void recoverTree(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        sort(arr.begin(),arr.end());
        int i=0;
        inorderSwap(root,arr,i);
    }


// optimised 
// by using three variable -> first , mid and last -> striver method
TreeNode*first,*mid,*prev,*last; // we can remove mid if we want to do it with 2 varibale

void inorder(TreeNode*root){
    if(root==NULL) return ;
    inorder(root->left);
    if(prev!=NULL && root->val < prev->val ) {
     // if this is first voilation mark this as first and middle node
    if(first==NULL){
        first=prev;
        mid=root; // we can directly assign last=root for 2 varible method
    }
    // if this is second voilation
    else last=root;
    }
    //mark this node as previous
    prev=root;
    inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first=mid=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        // for first voilation
        if(first && last) swap(first->val,last->val);    // we can only do this if we want to it by using 2 variable
        // for second voilation
        else if(first&& mid)swap(first->val,mid->val);
    }