// 173. Binary Search Tree Iterator

// in o(n) space 
class BSTIterator {
public:
// finding inorder to check next element
void inorder(TreeNode*root ,vector<int>&in){
    if(root==NULL)return;
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}
    int idx=0;
    vector<int>ino;
    BSTIterator(TreeNode* root) {
    inorder(root,ino);
    }
    // print the next element inordercally exist or not
    int next() {
        if(idx < ino.size()) {
            int el=ino[idx];
            idx++;
            return el;
        }
        else return -1; 
        
    }
    // check the element has next member or not 
    bool hasNext() {
       if(idx>ino.size()-1) return false;
       else return true; 
    }
};


// optimised in O(h) space 
//Instead of storing the entire inorder traversal, we can simulate the traversal using a stack to store the path to the next smallest node. This reduces space usage to the height of the tree.
class BSTIterator {
public:
    void pushLeft(TreeNode* root, stack<TreeNode*>& in) {
       while(root){
        ino.push(root);
        root=root->left;
       }
    }
    stack<TreeNode*> ino;
    BSTIterator(TreeNode* root) { pushLeft(root, ino); }
    // print the next element if it exist
    int next() {
       TreeNode*node=ino.top();
       ino.pop();
       if(node->right){
       pushLeft(node->right,ino);
       }
       return node->val;
    }
    // for checking whether it has the next element or not;
    bool hasNext() {
        if (ino.empty())
            return false;
        else
            return true;
    }
};