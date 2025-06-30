//Root to particular Node Path
bool path(Node*root,vector<int>&temp,int node){
    if(root==NULL) return false;
    temp.push_back(root->val);
    if(root->val==node) return true;
    if(path(root->right,temp,node) || path(root->left,temp,node)) return true;
    temp.pop_back();
    return false;    
}

// Root to all leaf Paths
     vector<vector<int>>ans;
  void traverse(Node*root,vector<int>&temp){
      if(root==NULL){
         return;
      }
      temp.push_back(root->data);
      if(root->left==NULL && root->right==NULL){
          ans.push_back(temp);
      }
      if(root->left!=NULL){
          traverse(root->left,temp);
      }
        if(root->right!=NULL){
          traverse(root->right,temp);
      }
      // backtrack and popping the value
      temp.pop_back();
  }
    vector<vector<int>> Paths(Node* root) {
  vector<int>temp;
  traverse(root,temp);
  return ans;
    }



  // 236. Lowest Common Ancestor of a Binary Tree
  //Brute 
  bool path(TreeNode*root,vector<TreeNode*>&temp,TreeNode*node){
if(root==NULL) return false;
temp.push_back(root);
if(root==node)return true;
if(path(root->left,temp,node)|| path(root->right,temp,node)) return true ;
temp.pop_back();
return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a1,a2;
        path(root,a1,p);
        path(root,a2,q);
       int i=0,j=0;
       TreeNode*lca;
       while(i<a1.size() && j<a2.size()){
        if(a1[i]==a2[i]) {
            lca=a1[i];
            i++,j++; 
        }
        else break;
       }
        return lca;
}

//Optimsed 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q ) return root;

        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL)return right;
        else if(right==NULL) return left;
        else return root;
  }


// 662. Maximum Width of Binary Tree
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int minIdx=q.front().second;
            int firstIdx,lastIdx;
            for(int i=0;i<n;i++){
                int currIdx=q.front().second-minIdx;
                TreeNode*node=q.front().first;
                q.pop();
                if(i==0) firstIdx=currIdx;
                if(i==n-1) lastIdx=currIdx;
                if(node->left!=NULL) {
                    q.push({node->left,(long long)currIdx*2+1});
                }
                if(node->right!=NULL){
                q.push({node->right,(long long)currIdx*2+2});
                }
            }
            ans=max(ans,lastIdx-firstIdx+1);
        }
        return ans;
    }


// Children Sum in a Binary Tree -> in this only check the node is equal to its children sum or not || return 1 if yes else 0
int isSumProperty(Node *root) {
 if( (root==NULL) || (root->left==NULL  && root->right==NULL ))  return 1;
 int cnt=0;
  if(root->left!=NULL)cnt+=root->left->data;
  if(root->right!=NULL) cnt+=root->right->data;
  return (root->data==cnt  && isSumProperty(root->left) && isSumProperty(root->right) );
}


// creating the children sum tree
void makeSumOfChildren(Node*root){
   if(root==NULL) return 0;
   int childSum=0;
   if(root->left!=NULL) childSum+=root->left->data;
   if(root->right!=NULL) childSum+=root->right->data;

   if(childSum>=root->data) root->data=childSum;
   else{
    if(root->left!=NULL) root->left->data=root->data;
    if(root->right!=NULL) root->right->data=root->data;
   } 
   makeSumOfChildren(root->left);
   makeSumOfChildren(root->right);

   int total=0;
   if(root->left!=NULL) total+=root->left->data;
   if(root->right!=NULL) total+=root->right->data;
   if(root->left || root->right) root->data=total;  
}


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

// Burning Tree

 int BurnTime(unordered_map<Node*,Node*>parent,Node*target){
     unordered_map<Node*,bool>visited;
     queue<Node*>q;
     q.push(target);
     visited[target]=true;
     int maxi=0;
     while(!q.empty()){
         int n=q.size();
     int flag=0; // it is used to check whether it is burn or not
         for(int i=0;i<n;i++){
             Node*node=q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                flag=1;
                q.push(node->left) ;
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                flag=1;
                q.push(node->right);
                visited[node->right]=true;
            }
            if(parent[node] && !visited[parent[node]]){
                flag=1;
                q.push(parent[node]);
            visited[parent[node]]=true;
            }
         }
         if(flag==1) maxi++;
     }
     return maxi;
 }
 
 
 
 
  // first BFS to map parent and return the target
  Node* mapParent(Node*root,unordered_map<Node*,Node*>&parents,int target){
     queue<Node*>q;
     q.push(root);
     Node*res;
     while(!q.empty()){
         Node*temp=q.front();
         q.pop();
         if(temp->data==target) res=temp;
         if(temp->left){
             q.push(temp->left);
             parents[temp->left]=temp;
         }
         if(temp->right){
             q.push(temp->right);
             parents[temp->right]=temp;
         }
     }
     return res;
  }
  
    int minTime(Node* root, int target) {
     unordered_map<Node*,Node*>parent;
     Node*node=mapParent(root,parent,target);
     int maxi=BurnTime(parent,node);
     return maxi;
    }
    


// 222. Count Complete Tree Nodes
int leftHeight(TreeNode*node){
    int height=0;
    while(node){
        height++;
        node=node->left;
    }
    return height;
}
int rightHeight(TreeNode*node){
    int height=0;
    while(node){
        height++;
        node=node->right;
    }
    return height;
}
    int countNodes(TreeNode* root) {
    if(root==NULL) return 0;
    int lh=leftHeight(root);      
    int rh=rightHeight(root); 
    if(rh==lh) return (1 << lh ) - 1;
    return 1+ countNodes(root->left) + countNodes(root->right);     
    }


// 105. Construct Binary Tree from Preorder and Inorder Traversal
 TreeNode* treeBuild(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& hash) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;   
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = hash[root->val];
        int numsLeft = inRoot - inStart;

        root->left = treeBuild(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, hash);
        root->right = treeBuild(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, hash);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++)
            hash[inorder[i]] = i;

        TreeNode* root = treeBuild(preorder, 0, preorder.size() - 1, inorder, 0,
                                   inorder.size() - 1, hash);
        return root;
    }

// 106. Construct Binary Tree from Inorder and Postorder Traversal
TreeNode*treeBuild(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int pstart,int pend,   map<int,int>&hash){

if(pstart >pend || instart>inend) return NULL;
TreeNode *root=new TreeNode(postorder[pend]);
int idx=hash[root->val];
int numsleft=idx-instart;

root->left=treeBuild(inorder,instart,instart+numsleft-1,postorder,pstart,pstart+numsleft-1,hash);
root->right=treeBuild(inorder,instart+numsleft+1,inend,postorder,pstart+numsleft,pend-1,hash);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      map<int,int>hash;
      for(int i=0;i<inorder.size();i++){
        hash[inorder[i]]=i;
      }  
      TreeNode *root=treeBuild(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hash);
      return root; 
    }



// Morris Traversal 
// Inorder Traversal
   vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = curr; // thread created
                    curr = curr->left;
                } else {
                    prev->right = NULL; // thread deleted
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }


    // Preorder 
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> prerorder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                perorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = curr; // thread created
                      preorder.push_back(curr->val);
                    curr = curr->left;
                } else {
                    prev->right = NULL; // thread deleted
                  
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }



    // 114. Flatten Binary Tree to Linked List 
   //Approach 1- SC -O(n)
   void flat(TreeNode*node,TreeNode*&prev){
    if(node==NULL) return;
    flat(node->right,prev);
    flat(node->left,prev);
    node->right=prev;
    node->left=NULL;
    prev=node;
}
    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        flat(root,prev);
    }


    //Approach 2- By using stack
     void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*cur=st.top();
            st.pop();
            if(cur->right!=NULL) st.push(cur->right); 
            if(cur->left!=NULL) st.push(cur->left); 
            if(!st.empty()) cur->right=st.top(); // link to next node in preorder
            cur->left=NULL; // detach the left link
        }
    }

    // Optimised approach SC-O(1) // Morris Traversal approach
    // by Morris Traversal Approach
    void flatten(TreeNode* root) {
        TreeNode*curr=root;
        while(curr){
            if(curr->left){
                TreeNode*prev=curr->left;
                while(prev->right!=NULL) prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
   
    }

 



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
    