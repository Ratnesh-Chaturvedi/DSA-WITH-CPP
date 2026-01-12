
// 863. All Nodes Distance K in Binary Tree
//First BFS
void markParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode*target){
    //Doing same as BFS
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();
        if(node->left){
            parent_track[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parent_track[node->right]=node;
            q.push(node->right);
        }
    }
    
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markParent(root,parent_track,target);
        // creating a map for visited nodes;
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);  
        visited[target]=true;
        int currDistance=0;
        //second  BFS
        while(!q.empty()){
            int size=q.size();
            if(currDistance++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode*current=q.front();
                q.pop();
                // if left exist and not visited
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                // if right exist and not visited 
                    if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                // if parent exist and not visited
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
