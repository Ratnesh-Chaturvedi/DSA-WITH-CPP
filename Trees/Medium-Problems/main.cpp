// 104. Maximum Depth of Binary Tree

// Approach 1 
// really we dont need vector to store ans we just need to find the depth so we can do 
int BFS(TreeNode*root){
    // vector<vector<int>>ans;
    if(root==NULL) return 0; 
    int depth=0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        // vector<int>arr;
        depth++;
        int size=q.size();
        for(int i=0;i<size;i++){
        TreeNode*node=q.front();
        q.pop();
        if(node->left!=NULL) q.push(node->left);
        if(node->right!=NULL) q.push(node->right);
        // arr.push_back(node->val);
        }
        // ans.push_back(arr);   
    }
    // return ans.size();
    return depth;
}

// Approach 2
int MaxHeight(TreeNode*root){
    if(root==NULL) return 0; 
    int l=MaxHeight(root->left);
    int r=MaxHeight(root->right);
    return 1 + max(l,r);
}


// 110. Balanced Binary Tree
///Brute 

int height(TreeNode*root){
    if(root==NULL) return 0;
    return  1+ max ( height(root->left), height(root->right));

}
    bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
      int lh=height(root->left);
      int rh=height(root->right);
      if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
     return false;
    }

// Optimised 
int height(TreeNode*root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    if(lh==-1) return -1;
    int rh=height(root->right);
    if(rh==-1)
    return -1;
    if(abs(rh-lh)>1) return -1;
    return 1+max(rh,lh);
   
}
    bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
    if(height(root)==-1) return false;
    return true;
    }


// 100. Same Tree
// here we can use any of three taversal
// in this we are going with the preorder
    bool isSameTree(TreeNode* p, TreeNode* q) {
   if(p==NULL || q==NULL) return p==q;

   return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

    }


// 101. Symmetric Tree
 bool isSameTree(TreeNode* p, TreeNode* q) {
   if(p==NULL || q==NULL) return p==q;
   return (p->val==q->val) && isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
}
    bool isSymmetric(TreeNode* root) {
    if(root==NULL) return true;
  bool l=isSameTree(root->left,root->right);
  return l;
    }



// 543. Diameter of Binary Tree
int height(TreeNode*root,int &maxi){
    if(root==NULL) return 0;
    int lh=height(root->left,maxi);
    int rh=height(root->right,maxi);
    int temp=max(0,lh)+max(0,rh);
    maxi=max(maxi,temp);
    return 1 + max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi;
    }


// 124. Binary Tree Maximum Path Sum
int traverse(TreeNode*root,int &pathsum){
    if(root==NULL) return 0;
    int lh=max(0,traverse(root->left,pathsum));
    int rh=max(0,traverse(root->right,pathsum));
    pathsum=max(pathsum,lh+rh+root->val);
    return root->val+ max(lh,rh) ;
}
    int maxPathSum(TreeNode* root) {
        int pathsum=INT_MIN;
       traverse(root,pathsum);
        return pathsum;
    }



// 103. Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            TreeNode*node=q.front();
            q.pop();
            // finding position to fill the value;
            int idx=flag?i:(size-1-i);
            level[idx]=node->val;
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        flag=!flag;
        ans.push_back(level);
    }
    return ans;
    }



// Tree Boundary Traversal

  bool isleaf(Node*root){
      if(!root->left && !root->right) return true;
      return false;
  }
 void leftNode(Node*root,vector<int>&res){
      Node*curr=root->left;
      while(curr){
      if(!isleaf(curr))  res.push_back(curr->data);
      if(curr->left) curr=curr->left;
      else    curr=curr->right;
      }
}
  void leafNode(Node*root,vector<int>&res){
     if(isleaf(root)){
         res.push_back(root->data);
         return;
     }
     if(root->left)
         leafNode(root->left,res);
     if(root->right)
         leafNode(root->right,res);
  }
   void rightNode(Node*root,vector<int>&res){
       vector<int>temp;
      Node*curr=root->right;
      while(curr){
      if(!isleaf(curr) ) temp.push_back(curr->data);
      if(curr->right) curr=curr->right;
      else  curr=curr->left;
      }
        for(int i=temp.size()-1;i>=0;i--)
         res.push_back(temp[i]);
     
  }
    vector<int> boundaryTraversal(Node *root) {
   vector<int>res;
   if(!root) return res;
   if(!isleaf(root)) res.push_back(root->data);
   leftNode(root,res);
   leafNode(root,res);
   rightNode(root,res);
   return res;
        
    }



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




// 199. Binary Tree Right Side View
// Recursive Way -
void rightView(TreeNode*root,int lvl,vector<int>&DS){
    if(root==NULL) return;
    if(lvl==DS.size()) DS.push_back(root->val);
    rightView(root->right,lvl+1,DS);
    rightView(root->left,lvl+1,DS);
}
    vector<int> rightSideView(TreeNode* root) {
          vector<int>ans;
          rightView(root,0,ans);
          return ans;
    }


// Iterative Code 
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int node;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* newNode=q.front();
                q.pop();
                if(newNode->left) q.push(newNode->left);
                if(newNode->right) q.push(newNode->right);
                node=newNode->val;
            }
            ans.push_back(node);
        }
        return ans;
    }