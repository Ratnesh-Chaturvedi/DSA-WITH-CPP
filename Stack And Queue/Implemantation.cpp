#include <bits/stdc++.h>
using namespace std;
//Implementing Stack Using Array
const int size=5;
class  Stack{
    int top;
    int st[size];
    public:
    Stack(){
        top=-1;
    }
    void push(int x){
        if(top >=size-1){
            cout<<"full"<<"\n";
            return;
        }
        top=top+1;
        st[top]=x;
    }
    int Top(){
        if(top==-1){
            cout<<"empty"<<"\n";
            return -1;
        }
        return st[top];
    }
    int Size(){
        return top+1;
    }
    int pop(){
        if(top==-1) {
            cout<<"Underflow"<<"\n";
            return -1;
        }
        int x = st[top];
        top--;
        return x;

    }
};


class Queue{
    int front;
    int rear;
    int qu[size];
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    // if i have some space left but my rear is at end then the linear queue will give us overflow but if we implement it like  ki ham jo space bacha hai use bhi use kare toh ham else condition mai likhenge -> rear=(rear+1)%size; so wo ghum ke bafas waha aa jayega jaha space khali matlap starting wali places par
    void push(int x){
        if(rear>=size-1){
            cout<<"OverFlow"<<endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        qu[rear] = x;
        
    }

    int pop(){
        if(front==-1 || front>rear){
            cout<<"UnderFlow"<<endl;
            return -1;
        }
        int x=qu[front];
        front++;
        if (front > rear) {
            // Reset the queue
            front = rear = -1;
        }
        return x;
    }
    int Size(){
        if (front == -1 || front > rear)
        return 0;
        return rear-front+1;
    }
    int Front(){
        if(front==-1 || front>rear){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return qu[front];
    }
    int Rear(){
        if(rear==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return -1; 
        }
       return qu[rear];
    }
    
};

// Implementing using Linked List

class stackNode{
    public:
    int data;
    stackNode *next;
    int size;
    public:
    stackNode(int d){
 data=d;
 next=NULL;
    }
};

class StackLL{
   stackNode *top;
   int size;
   public:
   StackLL(){
    top=NULL;
    size=0;
   }
   void push(int d){
    stackNode *element=new stackNode(d);
    element->next=top;
    top=element;
    size++;
   }
   int pop(){
    if(top==NULL){
        return -1;
    }
    int topData=top->data;
    stackNode *temp=top;
    top=top->next;
    delete temp;
    size--;
return topData;
   }

   int Size(){
    return size;
   }
 bool isEmpty(){
    return top==NULL;
 }
 void printStack(){
    stackNode *current=top;
    while(current!=NULL){
        cout<<current->data<<endl;;
        current=current->next;
    }

 }
};

// Queue using linkedList
class queueNode{
    public:
    int data;
 queueNode *next;
 queueNode(int d){
   data=d;
   next=nullptr;
 }
    
};

class queueLL{
    int size;
    queueNode*front,*rear;
    public:
    queueLL(){
        front=rear=NULL;
        size=0;
    }
    void push(int x){
        queueNode*newNode=new queueNode(x);
        if (newNode == nullptr)  //When heap exhausted 
        cout << "Queue is Full" << endl;
        else {

            if(front==NULL ){
                front=rear=newNode;
                size++;
            }
            else {
                rear->next=newNode;
                size++;
                rear=newNode;
            }
        }
    }
    void pop(){
        if(front==NULL) {
            cout<<"EMPTY"<<endl;
        }
        else {
            cout<<front->data<<endl;
            queueNode*temp=front;
            front=front->next;
            size--;
            delete temp;
        }
    }
int  Size(){
    return size;
}
void printQueue(){
    queueNode*curr=front;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

};

int main(){
   queueLL q;
   q.push(1);
   q.push(2);
   q.push(2);
   q.push(2);
   q.push(3);
   cout<<"Print the popped element:";
 q.pop();
 cout<<endl;
   q.push(4);
   q.push(4);
   q.push(4);
   q.push(4);
   cout<<"Printing Queue elements:";
   q.printQueue();
   cout<<" Size of the Queue:";
  cout<< q.Size()<<endl;


}