
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
