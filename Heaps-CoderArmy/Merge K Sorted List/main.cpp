//Brute Force 
 // by using merge2List concept
    Node*merge2list(Node*l1,Node*l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        Node*dummynode=new Node(-1);
        Node*res=dummynode;
        while(l1!=NULL && l2!=NULL){
            if(l1->data<l2->data){
                res->next=l1;
                res=l1;
                l1=l1->next;
            }
            else {
                res->next=l2;
                res=l2;
                l2=l2->next;
            }
            res->next=NULL;
        }
        if(l1) res->next=l1;
        else res->next=l2;
        return dummynode->next;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        if(arr.size()==1) return arr[0];
        Node*head=arr[0];
        for(int i=1;i<arr.size();i++){
            head=merge2list(head,arr[i]);
        }
        return head;
    }



    // Better than Brute using Merge Sort Concept
       Node*merge2List(Node*l1,Node*l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        Node*dummynode=new Node(-1);
        Node*res=dummynode;
        while(l1!=NULL && l2!=NULL){
            if(l1->data<l2->data){
                res->next=l1;
                res=l1;
                l1=l1->next;
            }
            else {
                res->next=l2;
                res=l2;
                l2=l2->next;
            }
            res->next=NULL;
        }
        if(l1) res->next=l1;
        else res->next=l2;
        return dummynode->next;
    }
    
  void mergeSort(vector<Node*>&arr,int st,int end){
      if(st>=end){
          return ;
      }
      int mid=st+(end-st)/2;
      /// left side 
      mergeSort(arr,st,mid);
      //right side
      mergeSort(arr,mid+1,end);
      //merge 
      arr[st]=merge2List(arr[st],arr[mid+1]);
  }
    Node* mergeKLists(vector<Node*>& arr) {
     mergeSort(arr,0,arr.size()-1);
     return arr[0];
    }



    // Most Optimised Approach 

class Solution {
    public:
  class compare{
  public:
  bool operator()(Node*a,Node*b){
      return a->data>b->data; // for min heap 
  }
  };
    Node* mergeKLists(vector<Node*>& arr) {
      int n=arr.size();
      priority_queue<Node*,vector<Node*>,compare>pq(arr.begin(),arr.end());
  
     Node*dummyNode=new Node(-1);
     Node*top=dummyNode;
     while(!pq.empty()){
         Node *temp=pq.top();
         pq.pop();
         if(temp->next) {
             pq.push(temp->next);
         }
         top->next=temp;
         top=top->next;
     }
     return dummyNode->next;
    
    
    }
};