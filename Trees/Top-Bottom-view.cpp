
// Top View of Binary Tree

 vector<int> topView(Node *root) {
        if(root==NULL) return {};
    map<int,int>nodes;
queue<pair<Node*,int>>q;
q.push({root,0});
while(!q.empty()){
    auto p=q.front();
    q.pop();
    Node*treeNode=p.first;
    int vertical=p.second;
    if(nodes.find(vertical)==nodes.end())
    nodes[vertical]=treeNode->data;
    if(treeNode->left) 
    q.push({treeNode->left,vertical-1});
    if(treeNode->right) 
     q.push({treeNode->right,vertical+1});
}
vector<int>ans;
for(auto it:nodes){
    ans.push_back(it.second);
}

     return ans;   
    }

// Bottom View of Binary Tree
 vector<int> bottomView(Node *root) {
       if(root==NULL )return {};
       map<int,int>mpp;
       queue<pair<Node*,int>>q;
       q.push({root,0});
       
       while(!q.empty()){
           auto p=q.front();
           q.pop();
           Node*node=p.first;
           int vertical=p.second;
           mpp[vertical]=node->data;
           if(node->left){
               q.push({node->left,vertical-1});
           }
           if(node->right){
               q.push({node->right,vertical+1});
           }
       }
       vector<int>ans;
       for(auto it:mpp){
           ans.push_back(it.second);
       }
        return ans;
    }

