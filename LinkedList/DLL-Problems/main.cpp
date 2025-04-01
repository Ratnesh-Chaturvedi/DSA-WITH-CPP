
// Delete all occurrences of a given key in a doubly linked list
// TC-O(N)

void deleteAllOccurOfX(struct Node** head, int x) {
    Node*temp=*head;
    while(temp!=NULL){        
       if(temp->data==x){
           if(temp==*head){
               *head=temp->next;
           }
       Node*nextNode=temp->next;
       Node*prevNode=temp->prev;
       if(nextNode) nextNode->prev=prevNode;
       if(prevNode) prevNode->next=nextNode;
       delete temp;
       temp=nextNode;
       }
       else temp=temp->next; 
    } 
    return ;
   }

   // Find pairs with given sum in doubly linked list
   vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
   {
      vector<pair<int,int>>ans;
      Node*front=head;
      Node*back=head;
      while(back->next!=NULL){
          back=back->next;
      }
      while(front->data<back->data){
          int sum=front->data + back->data;
          if(target==sum) {
             ans.push_back({front->data,back->data});
             front=front->next;
             back=back->prev;
          }
          else if(target<sum) back=back->prev;
          else front=front->next;
      }
      return ans;
   }



//    Remove duplicates from a sorted doubly linked list
Node * removeDuplicates(struct Node *head)
{
    if(head==NULL) return head;
    if(head->next==NULL) return head;
   Node*temp=head;
   while(temp!=NULL){
       Node*front=temp->next;
       while(front!=NULL && front->data==temp->data){
           Node*deletednode=front;
           front=front->next;
           delete deletednode;
       }
       temp->next=front;
       if(front) front->prev=temp;
       temp=temp->next;
   
   }
   return head;
}