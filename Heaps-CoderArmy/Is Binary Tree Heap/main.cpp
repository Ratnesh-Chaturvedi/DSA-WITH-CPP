// / Check if tree is a Complete Binary Tree
// bool isCBT(Node* root) {
//     if (!root) return true;
//     queue<Node*> q;
//     q.push(root);
//     bool end = false;

//     while (!q.empty()) {
//         Node* current = q.front();
//         q.pop();

//         if (current->left) {
//             if (end) return false;
//             q.push(current->left);
//         } else {
//             end = true;
//         }

//         if (current->right) {
//             if (end) return false;
//             q.push(current->right);
//         } else {
//             end = true;
//         }
//     }

//     return true;
// }

// method 2 to check tree is CBT OR NOT
//cnt number of node
  int cntNode(Node*root){
      if(!root) return 0;
      return 1+cntNode(root->left)+cntNode(root->right);
  }
 // Check if tree is a Complete Binary Tree
bool isCBT(Node* root,int idx,int totalNodes) {
    if(!root) return true;
    if(idx>=totalNodes){
        return false;
    }
return  isCBT(root->left,2*idx+1,totalNodes) && isCBT(root->right,2*idx+2,totalNodes);
}








bool checkMaxHeap(Node*root){
    if(root==NULL) return true;
   
   // leaf node
   if(!root->left && !root->right){
       return true;
   }
   // if only left child exist
   if(root->left && !root->right){
      return (root->data>=root->left->data) && checkMaxHeap(root->left);
   }
   
   // Both children exist
   if(root->left && root->right){
       return ( root->data>=root->left->data && root->data>=root->right->data) &&
       checkMaxHeap(root->left) && checkMaxHeap(root->right);
   }
   
 // If only right child exists (which should not happen in a heap)
   return true;
   
}
    bool isHeap(Node* tree) {
          return isCBT(tree) && checkMaxHeap(tree);
    }