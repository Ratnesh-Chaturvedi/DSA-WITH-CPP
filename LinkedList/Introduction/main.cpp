#include <bits/stdc++.h>
using namespace std;



// we can use struct also at the place of class
class Node{
    public:
    int data;
    Node * next;
    //constructor 
    public:
        Node( int data1, Node* next1){
            data=data1;
            next=next1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
        }
    
};


//traversing

void Display(Node*Head){
    Node *traverse=Head;
    int len=0;
     while(traverse!=nullptr){
        cout<<traverse->data<<"->";
        len++;
        traverse=traverse->next;
     }
     cout<<"X";
    //  cout<<'\n'<<len;

}
// add element at the end
Node *insertAtEnd(Node *head, int x) {
    Node*newNode=new Node(x);
     if(head==NULL)return newNode;
     
    Node *mover=head;
    while(mover->next!=nullptr){
        mover=mover->next;
    }
   mover->next=newNode;
    return head;
 }

 bool searchLL(Node *head,int node){
    Node*mover=head;
    while(mover){
        if(mover->data==node) return true;
        mover=mover->next;
    }
    return false;
 }
 // delete from start
 Node *deleteHead(Node *head){
    if(head==NULL) return head;
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
 }

Node *deleteTail(Node *head){
    if(head==NULL || head->next==nullptr) return NULL;
    Node*temp=head,*ptr;
    
//     while(temp->next!=nullptr){
// ptr=temp;
// temp=temp->next;
//     }
//     ptr->next=nullptr;
//     delete temp;

// alternate method
while(temp->next->next!=nullptr){
    temp=temp->next;
}
delete (temp->next); // delete the last node
temp->next=nullptr;
    return head;
}

//deleting Kth number Element

Node *deleteKth(Node *head, int k){
    if(head==NULL) return NULL;
    if(k==1){
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node*temp=head,*prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
       temp=temp->next;
    }
   
    
    return head;

}


//delete the value from the LL

Node *deleteVal(Node *head, int k){
    if(head==NULL) return NULL;
  if(head->data==k){
    Node*temp=head;
        head=head->next;
        delete temp;
        return head;
  }
    
    Node*temp=head,*prev=NULL;
    while(temp!=NULL ){
        if(temp->data==k){
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}


//inserting a node in beginning

Node *insertBeg(Node*head,int k){
     Node*temp=new Node(k);
     temp->next=head;
     head=temp;
     return head;
}

Node *insertEnd(Node *head,int k){
    if(head==NULL){
       return new Node(k);
        
    }
    Node*newNode= new Node(k);
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;

}

// Insert at any position
Node *insertPos(Node*head,int pos,int el){
    if(head==NULL){
        if(pos==1)
       return new Node(el);
    else return NULL;
    }
    if(pos==1){ 
        Node*newNode=new Node(el,head);
        head=newNode;
        return head;
    }
   int cnt=0;
  
   Node*temp=head; 
   while(temp!=NULL){
    cnt++;
    if(cnt==pos-1){
        Node*newNode=new Node(el,temp->next);
        temp->next=newNode;
        break;
    }  
    temp=temp->next;
   }
 
   return head;
}


 //insert a node before a value

 Node *insertBefNode(Node*head,int el,int val){
    if(head==NULL) return NULL;
    if(head->data==val){
return new Node(el,head);
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==val){
            Node*x=new Node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
 }
int main(){
    // Node *y= new Node(2,nullptr);
    // cout<<y<<"\n"; // this gives the memory address
    // cout<<y->data; // this gives the value

    // Node*y =new Node(16);
    // cout<<y<<"\n";
    // cout<<y->data<<"\n";  // this gives the value of that node
    // cout<<y->next; // this gives the address of the next node

    
    // if we do not use new and pointer

    // Node y=Node(2); // it will create an object
    // cout<<y.data<<"\n";
    // cout<<y.next;
    

    //Array to LL
      
    vector<int>a={2,3,4,5,6,7,9,0};
    Node *Head= new Node(a[0]);
    Node *mover=Head;
     for(int i=1;i<a.size();i++){
        Node *temp=new Node(a[i]);
        mover->next=temp;
        mover=temp;
     }
     mover->next=nullptr;
    
     //taraversing 
    //  Display(Head);

     //searching in LL
    //  cout<<searchLL(Head,1);

    // deletion in LL
    // delete from start
    // Head=deleteHead(Head);

    //deleate from End
    // Head=deleteTail(Head);
    
    // deleting Kth element 
    // Head=deleteKth(Head,10);

    //deleting the value 
    // Head=deleteVal(Head,20);


    //Inserting a node at beginning
    // Head=insertBeg(Head,16);

    //Insert at the End
    // Head=insertEnd(Head,16);

    //insert at a position
    // Head=insertPos(Head,9,2);

    //insert before a val
    Head=insertBefNode(Head,1,6);
    Display(Head);
    
}