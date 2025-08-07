  void inorder(Node*root,vector<int>&arr){
      if(root==NULL) return;
      inorder(root->left,arr);
      arr.push_back(root->data);
      inorder(root->right,arr);
  }

void postorderFilling(Node*root,vector<int>&arr,int &idx){
    if(!root) return;
    postorderFilling(root->left,arr,idx);
    postorderFilling(root->right,arr,idx);
    root->data=arr[idx++];
    
}
    void convertToMaxHeapUtil(Node* root) {
     vector<int>inorderArr;
     inorder(root,inorderArr);
     int idx=0;
     postorderFilling(root,inorderArr,idx);
    }