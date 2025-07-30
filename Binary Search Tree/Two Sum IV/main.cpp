// 653. Two Sum IV - Input is a BST


class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = true; // true -> before // false-> next

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    // return whether we have next element or not
    bool hasNext() { return !st.empty(); }
    // return the next number
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);
        return node->val;
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        BSTIterator l(root, false); // for next
        BSTIterator r(root, true);  // for before

        int i = l.next();
        int j = r.next();
        while (i < j) {
            int sum = i + j;
            if (sum == k)
                return true;
            if (sum > k)
                j = r.next();
            else
                i = l.next();
        }
        return false;
    }
};