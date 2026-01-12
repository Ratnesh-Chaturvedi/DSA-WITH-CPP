
// 297 Serialize and Deserialize Binary Tree
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node==NULL) s.append("#,");
            else {
             s.append(to_string(node->val)+",");
             q.push(node->left);
             q.push(node->right);
            }
        }
        return s;  
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream s(data); // for accessing each element 
        string str; 
        getline(s,str,','); 
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            getline(s,str,','); // checking for the left child
            if(str=="#") // null  
            node->left=NULL;
            else {
                TreeNode*leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,','); // checking for the right child
            if(str=="#") // null  
            node->right=NULL;
            else {
                TreeNode*rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
    