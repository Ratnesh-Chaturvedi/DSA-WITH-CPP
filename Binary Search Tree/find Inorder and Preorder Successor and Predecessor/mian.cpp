// Inorder Successor in BST
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        int ans=-1;
       while(root){
           if(root->data > x->data) {
               ans=root->data;
              root=root->left;
           }
           else root=root->right;
       }
       return ans;
        
    }


//    Inorder Predecessor and Successor   

vector<Node*> findPreSuc(Node* root, int key) {
    Node* pre = nullptr;
    Node* succ = nullptr;
    Node*temp=root;
 // predecessor
    while(temp){
        if(temp->data<key){
        pre=temp;
        temp=temp->right;
        }
        else temp=temp->left;
    }
    //succesor
    temp=root;
         while(temp){
           if(temp->data > key) {
               succ=temp;
              temp=temp->left;
           }
           else temp=temp->right;
       }

    return {pre, succ};
} 
