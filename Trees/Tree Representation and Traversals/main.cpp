#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;
    public:
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

// making a tree 
// int main(){
//     Node *root=new Node(1);
//     root->left=new Node(2);
//     root->right=new Node(3);
//     root->right->left=new Node(4);

// }


// Traversals

// Preorder Traversal
//  Root left Right
void Preorder(Node *root){
    if(root==nullptr){
        return;
    }
    cout<< root->data <<" ";
    Preorder(root->left);
    Preorder(root->right);
}

// Inorder traversal
// Left Root Right
void Inorder(Node *root){
    if(root==nullptr){
        return;
    }
    Inorder(root->left);
    cout<< root->data <<" ";
    Inorder(root->right);
}

//  Postorder Traversal
//Left Right Root
void Postorder(Node *root){
    if(root==nullptr){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<< root->data <<" ";
}




// Breadth first search - level Order Traversal

vector<vector<int>>levelOrder(Node *root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size=q.size();
        for(int i=0;i<size;i++){
            Node *node=q.front();
            q.pop();
            if(node->left!=NULL ) q.push(node->left);
            if(node->right!=NULL ) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}



// iterative PreOrder Traversal
vector<int>iterativePreorder(Node*root){
    vector<int>traversed;
    if(root==NULL) return traversed;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        traversed.push_back(root->data);
        if(root->right!=NULL ) st.push(root->right);
        if(root->left!=NULL ) st.push(root->left);
    }
    return traversed;
}
// iterative InOrder Traversal
 vector<int>iterativeInorder(Node*root){
    Node*node=root;
    vector<int>traversed;
    stack<Node*>st;
    if(node==NULL) return traversed;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else {
            if(st.empty()==true) break;
            node=st.top();
            st.pop();
            traversed.push_back(node->data);
            node=node->right;
        }
    }
    return traversed;
 }

// iterative PostOrder Traversal using Stacks

vector<int>iterativePostorderByStacks(Node*root){
    vector<int>ans;
    if(root==NULL) return ans;
  stack<Node*>st1;
  stack<Node*>st2;
  st1.push(root);
  while(!st1.empty()){
    root=st1.top();
    st1.pop();
    st2.push(root); // do this when u are using 2 stacks
    //  ans.push_back(root->data);   // do this operation when u are using one stack  
    if(root->left!=NULL) st1.push(root->left);
    if(root->right!=NULL)
    st1.push(root->right);
  }

// do this operation when u are using 2 stacks
while(!st2.empty()){
    ans.push_back(st2.top()->data);
    st2.pop();
}


// reverse(ans.begin(),ans.end()); // do this when u are using one stack
return ans;

}


// PostOrder / Inorder / Preorder in One traversal
vector<vector<int>>preInPost(Node*root) {
    vector<int>pre,in,post;
    if(root==NULL) return {pre,in,post};
 stack<pair<Node*,int>>st;
 st.push({root,1});
 while(!st.empty()){
    auto it=st.top();
    st.pop();
    // this is the part of pre;
    //increament num  1->2
    // put the left side of tree;
    if(it.second==1){
        pre.push_back(it.first->data);
        it.second++;
        st.push(it);
        if(it.first->left!=NULL){
            st.push({it.first->left,1});
        }
    }
    // this is the part of inorder 
    // increment num 2->3
    // put the right child of the tree
   else if(it.second==2){
        in.push_back(it.first->data);
        it.second++;
        st.push(it);
        if(it.first->right!=NULL) st.push({it.first->right,1});
    }

    // this is the part of postorder
    // dont push again the node in stack
    else if(it.second==3){
        post.push_back(it.first->data);
    }
 }
 return {pre,in,post};
}
// recursive way
void trav(Node*root,vector<int> &in, vector<int> &pre, vector<int> &post){
    if(!root) return;
    pre.push_back(root->data);
    
    trav(root->left, in, pre, post);
    in.push_back(root->data);
    trav(root->right, in, pre, post);
    post.push_back(root->data);
}

  // Creating the  binary tree
    /*
            1
           /  \
          2    3
         / \   / \
        4   5 6  7
    */

int main(){
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    // Preorder Traversals
    // Preorder(root);

    // Inorder Traveral
    // Inorder(root);

    // PostOrder Traversal
    // Postorder(root);

    //BFS
    // vector<vector<int>>ans=levelOrder(root);
    // for(int i=0;i<ans.size();i++){
    //     for(auto a:ans[i]) cout<<a<<" ";
    // }

    //iterative Preorder
    // vector<int>Ans=iterativePreorder(root);
    // for(auto it:Ans) cout<<it<< " ";

    //  //iterative Inorder
    // vector<int>Ans=iterativeInorder(root);
    // for(auto it:Ans) cout<<it<< " ";


// iterative PostOrder Traversal using 2 Stacks
    // vector<int>Ans=iterativePostorderByStacks(root);
    // for(auto it:Ans) cout<<it<< " ";

// all three iteration in one traversal
 vector<vector<int>> result = preInPost(root);
    cout << "Preorder: ";
    for (int x : result[0]) cout << x << " ";
    cout << "\nInorder: ";
    for (int x : result[1]) cout << x << " ";
    cout << "\nPostorder: ";
    for (int x : result[2]) cout << x << " ";
    cout << endl;

}

