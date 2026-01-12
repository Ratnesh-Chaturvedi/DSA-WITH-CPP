
// 987 Vertical order traversal


vector<vector<int>> verticalTraversal(TreeNode* root) {
map<int,map<int,multiset<int>>>nodes;
queue<pair<TreeNode*,pair<int,int>>>q;
q.push({root,{0,0}});
while(!q.empty()){
    auto p=q.front();
    q.pop();
    TreeNode*treeNode=p.first;
    int vertical=p.second.first;
    int lvl=p.second.second;
    nodes[vertical][lvl].insert(treeNode->val);
    if(treeNode->left) 
    q.push({treeNode->left,{vertical-1,lvl+1}});
    if(treeNode->right) 
     q.push({treeNode->right,{vertical+1,lvl+1}});
}
vector<vector<int>>ans;
for(auto it:nodes){
    vector<int>col;
    for(auto it2:it.second){
      col.insert(col.end(),it2.second.begin(),it2.second.end());
    ans.push_back(col);
}
return ans;
    }
}

// using inorder Traversal-> we can do same for preOrder and postOrder
void inorder(TreeNode*root,int vertical,int lvl,map<int,map<int,multiset<int>>>&mpp){
    if(root==NULL) return;
    inorder(root->left,vertical-1,lvl+1,mpp);
    mpp[vertical][lvl].insert(root->val);
    inorder(root->right,vertical+1,lvl+1,mpp);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mpp;
        if(root==NULL) return {};
        inorder(root,0,0,mpp);

        vector<vector<int>>ans;
        for(auto it:mpp){
            vector<int>col;
            for(auto it2:it.second){
                col.insert(col.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
