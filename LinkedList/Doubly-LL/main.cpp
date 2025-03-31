#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
 Node*next;
 Node*back;
 public:
 Node(int data1,Node*back1,Node*next1){
    data=data1;
   next=next1;
   back=back1;
 }
 
 Node(int data2,Node*next2){
    data=data2;
    next=next2;
    back=nullptr;
 }
 Node(int data3){
    data=data3;
    next=nullptr;
   back=nullptr;
 }
};


// traverse Linked List
void Display(Node *head){
    
    cout<<"null";
    while(head!=NULL){
        cout<<"<-"<<head->data<<"->";
        head=head->next;
    }
    cout<<"null";
}

// Delete Head Node;

Node *DeleteHead(Node *head){
    if(head==NULL || head->next==NULL) return NULL;
    Node*temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}

// delete Tail
Node *DeleteTail(Node *head){
    if(head==NULL || head->next==NULL) return NULL;
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
  
    Node* newTail = temp->back;
    newTail->next = nullptr;
    temp->back = nullptr;
        delete temp;  
    return head;
}


// Delete Kth Node
// this code works finwe but not for end element but it also works 
// Node *DeleteKth(Node*head,int k){
//     if(head==NULL) return NULL;
//     if(k==1){
//         if(head->next==NULL){
//             delete head ;
//             return NULL;
//         }
//         head=head->next;
//         delete head->back;
//         return head;
//     }
//     int cnt=0;
//     Node*temp=head,*prev=NULL;
//     while(temp!=NULL){
//         cnt++;
//         if(cnt==k){
//           prev->next=temp->next;
//           temp->next->back=prev;
//           delete temp;
//           break;
//         }
//         prev=temp;
//         temp=temp->next;
//     }
//     return head;
// }
Node *DeleteKth(Node*head,int k){
    if(head==NULL) return NULL;
    int cnt=0;
    Node *temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node *prev=temp->back;
    Node *front=temp->next;

    if(prev==NULL && front==NULL) return NULL;
    else if(prev==NULL){
        return DeleteHead(head);
    }
    else if(front==NULL) return DeleteTail(head);

    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;


}

// Delete the node (Node!=Head);
void DeleteNode(Node*node){

   Node*prev=node->back;
   Node*front=node->next;
   if(front==NULL){
         prev->next=nullptr;
         node->back=nullptr;
        delete node;
        return;
   }
   
   prev->next=front;
   front->back=prev;
   node->next=node->back=nullptr;
   delete node;  

}

//insert before the head
Node *InsertBefHead(Node*head,int k){
    if(head==NULL) {
        return new Node(k);
    }

    Node*temp=new Node(k);
    temp->next=head;
    head->back=temp;
    head=temp;
    return head;
}

//Insert before tail
Node *InsertBefTail(Node*head,int k){
    if(head==NULL) {
        return new Node(k);
    }
    if(head->next==NULL){
        return InsertBefHead(head,k);
    }
    Node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node*newNode=new Node(k);
     newNode->next=temp->next;
     temp->next->back=newNode;
     temp->next=newNode;
     newNode->back=temp;
    return head;
}

//Insert befor kth position
Node *InsertBefKth(Node*head,int val,int k){
    if(head==NULL) return NULL;
    if(head!=NULL){
        if(k==1) {
            return InsertBefHead(head,val);
        }
    }
    Node*temp=head,*prev=NULL;
    int  cnt=0;
    while(temp!=NULL){
  cnt++;
  if(cnt==k){
    Node*newNode=new Node(val);
    newNode->next=temp;
    newNode->back=prev;
    prev->next=newNode;
    temp->back=newNode;
    break;

  }
  prev=temp;
  temp=temp->next;
    }
    return head;
}

// insert before Node
void insertBefNode(Node*node,int val){
    Node*newNode=new Node(val);
    Node*prev=node->back;
    prev->next=newNode;
    newNode->back=prev;
    newNode->next=node;
    node->back=newNode;
}

// Reverse the DLL
DLLNode* reverseDLL(DLLNode* head) {
    if(head==NULL || head->next==NULL) return head;
DLLNode *current=head,*last=NULL;

while(current!=NULL){
  last=current->prev;
  current->prev=current->next;
  current->next=last;
  current=current->prev;
}
return last->prev;
}

int main(){
    vector<int>arr={1,2,88};
    Node*Head=new Node(arr[0]);
    Node*prev=Head;
    for(int i=1;i<arr.size();i++){
      Node*temp=new Node(arr[i],prev,nullptr);
      prev->next=temp;
         prev=temp;
    }
    prev->next=nullptr;
  
    //traversing linked list
    // Display(Head);
    
    //delete head
    // Head=DeleteHead(Head);

    //delete Tail
    // Head=DeleteTail(Head);
   
    // delete the Kth Number node
    // Head=DeleteKth(Head,1);

    //delete the node (Node!=Head)
    // DeleteNode(Head->next->next->next); // 4

    // insert a node before head;
    // Head=InsertBefHead(Head,0);

    //insert befor tail
    // Head=InsertBefTail(Head,16);

    //insert befor kth position
    // Head=InsertBefKth(Head,3,7);

    //insert before any node
    // insertBefNode(Head->next->next->next,3);


    Display(Head);
}