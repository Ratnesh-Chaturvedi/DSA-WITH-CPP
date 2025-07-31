//  Brute force using the concept of validate BST
// TC- O(n^2)

   bool validate(Node*root,long maxi,long mini){
       if(root==NULL) return true;
       if(root->data >= maxi || root->data<=mini) return false;
       return validate(root->left,root->data,mini) && validate(root->right,maxi,root->data); 
   }
   int countNode(Node*root){
       if(root==NULL) return 0;
       return 1+countNode(root->left)+countNode(root->right);
   }

    int largestBst(Node *root) {
    if(root==NULL) return 0;
    if(validate(root,LONG_MAX,LONG_MIN))
     return countNode(root);
    return max(largestBst(root->left),largestBst(root->right));
    } 



// Optimised 

class NodeValue {
public:
    int maxSize, maxNode, minNode;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    NodeValue largestBstHelper(Node* root) {
        // empty tree is a bst of size 0
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // get values from left and right subtree
        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);

        // current node is greater than the maximum node in the left subtree and less than the minimum node in the right subtree , hence it is a valid BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            // hence it is a valid bst 
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // otherwise it is not a valid bst // return (INT_MIN, INT_MAX) hence parent can't be a valid bst
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(Node* root) {
        return largestBstHelper(root).maxSize;
    }
};
