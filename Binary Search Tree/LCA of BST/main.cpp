// 235. Lowest Common Ancestor of a Binary Search Tree

// brute 
    // brute by taking the path and then find the last similar element
    void Path(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (root == NULL)
            return;
        if (root->val == node->val)
            path.push_back(root);
        if (root->val >= node->val) {
            path.push_back(root);
            Path(root->left, node, path);
        } else {
            path.push_back(root);
            Path(root->right, node, path);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath;
        Path(root, p, pPath);
        Path(root, q, qPath);
        TreeNode* ans;
        for (int i = 0; i < min(qPath.size(), pPath.size()); i++) {
            if (pPath[i] == qPath[i]) {
                ans = pPath[i];
            } else
                break;
        }
        return ans;
    }

// optimised -> using recursion;
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        int curr = root->val;
        // both are on left side;
        if (curr > p->val && curr > q->val)
           return  lowestCommonAncestor(root->left, p, q);
        // both are on right side
        if (curr < p->val && curr < q->val)
           return  lowestCommonAncestor(root->right, p, q);

        // split condition i.e root is the LCA // intersection point
        return root;
    }

    // Using Iteration
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root!=NULL) {
        int curr = root->val;
            // both node are on left side
            if (curr > p->val && curr > q->val)
                root = root->left;
            // both node are on right side
            else if (curr < p->val && curr < q->val)
                root = root->right;
            // insection or split point
            else
                return root;
        }
        return root;
    }

