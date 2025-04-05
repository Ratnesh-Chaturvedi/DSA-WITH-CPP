// 25. Reverse Nodes in k-Group
//TC-O(2N) SC-O(1)
Node *reverse(Node*head){
    Node*t=head,*prev=NULL;
    while(t!=NULL){
        Node*front=t->next;
        t->next=prev;
        prev=t;
        t=front;
    }
    return prev;
}

Node* findKthNode(Node*temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;

    }
    return temp;
}
Node* kReverse(Node* head, int k) {
Node*temp=head,*prev=NULL;
while(temp!=NULL){
    Node*kthNode=findKthNode(temp,k);
    if(kthNode==NULL){
        if(prev){
            prev->next=temp;
        }
            break;
    }
    Node*nextNode=kthNode->next;
    kthNode->next=NULL;
    reverse(temp);
    if(temp==head){
        head=kthNode;
    }
    else{
        prev->next=kthNode;
    }
    prev=temp;
    temp=nextNode;
}

return head;
}



//61. Rotate List   TC-O(2N)

ListNode*findLastNode(ListNode*head,int l){
    ListNode*temp=head;
    int cnt=1;
    while(temp!=NULL){
        if(cnt==l) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode*tail=head;
        int len=1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        ListNode*newLastNode=findLastNode(head,len-k);
        head=newLastNode->next;
        newLastNode->next=NULL;
        return head;
    }


    //flattening the linked list 
    //Brute force 

    Node *flatten(Node *root) {
        vector<int>arr;
        Node*temp=root;
        while(temp!=NULL){
            arr.push_back(temp->data);
            Node*t2=temp->bottom;
            while(t2!=NULL){
                arr.push_back(t2->data);
                t2=t2->bottom;
            }
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        
        Node*newhead=new Node(arr[0]);
        temp=newhead;
        for(int i=1;i<arr.size();i++){
            Node*newnode=new Node(arr[i]);
            temp->bottom=newnode;
            temp=newnode;
        }
        return newhead;
       }

       // By using recursion

       Node*merge2list(Node*l1,Node*l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        Node*dummynode=new Node(-1);
        Node*res=dummynode;
        while(l1!=NULL && l2!=NULL){
            if(l1->data<l2->data){
                res->bottom=l1;
                res=l1;
                l1=l1->bottom;
            }
            else {
                res->bottom=l2;
                res=l2;
                l2=l2->bottom;
            }
            res->next=NULL;
        }
        if(l1) res->bottom=l1;
        else res->bottom=l2;
        return dummynode->bottom;
    }
    
    
    Node *flatten(Node *root) {
   if(root==NULL || root->next==NULL ) return root;
   Node*mergeHead=flatten(root->next);
   return merge2list(root,mergeHead);
   
    }

    // Merge K sorted linked lists 
    // TC=O(n*k +(n*k)log(n*k) +n) // where n =arr size and k=number of node in each ll
    // SC-O(2*(n*k))
    Node* mergeKLists(vector<Node*>& arr) {
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            Node*temp=arr[i];
            while(temp!=NULL){
                ans.push_back(temp->data);
                temp=temp->next;
            }
        }
        sort(ans.begin(),ans.end());
        Node*newhead= new Node(ans[0]);
        Node*temp=newhead;
        for(int i=1;i<ans.size();i++){
            Node *t=new Node(ans[i]);
            temp->next=t;
            temp=t;
            t=t->next;
        }
        temp->next=NULL;
        return newhead;
    }

    //optimised 
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


    //more optimise by using priority queue
    Node* mergeKLists(vector<Node*>& arr) {
        if(arr.size()==1) return arr[0];
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
        for(int i=0;i<arr.size();i++){
            if(arr[i])
            pq.push({arr[i]->data,arr[i]});
        }
        Node*dummyNode=new Node(-1);
        Node*temp=dummyNode;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it.second->next)
            pq.push({it.second->next->data,it.second->next});
            temp->next=it.second;
            temp=temp->next;
        }
        return dummyNode->next;
    }



//138. Copy List with Random Pointer
    // Approach 1 using Hashing
    //TC-O(2n) SC-O(2n)
    Node* copyRandomList(Node* head) {
        Node*temp=head;
        unordered_map<Node*,Node*>mpp;
        while(temp!=NULL){
         Node*newNode=new Node(temp->val);
         mpp[temp]=newNode;
         temp=temp->next;
        } 
        temp=head;
        while(temp!=NULL){
         Node*copyNode=mpp[temp];
         copyNode->next=mpp[temp->next];
         copyNode->random=mpp[temp->random];
         temp=temp->next;
        }
        return mpp[head];
     }


     // Approach 2- TC-O(3N) SC-O(N);
     Node* copyRandomList(Node* head) {
        //creating the copy nodes in the middle;
       Node*temp=head;
       while(temp!=NULL){
        Node*copyNode=new Node(temp->val);
        copyNode->next=temp->next;
        temp->next=copyNode;
        temp=temp->next->next;
    }
   //connecting random  pointer
   temp=head;
   while(temp!=NULL){
     Node*copyNode=(temp->next);
     if(temp->random){
        copyNode->random=temp->random->next;
     }
     else copyNode->random=NULL;
     temp=temp->next->next;
   }

   // conneting next pointer
     Node*dummy =new Node(-1) , *res=dummy;
     temp=head;
     while(temp!=NULL){
        res->next=temp->next;
        temp->next=temp->next->next;

        res=res->next;
        temp=temp->next;
     }
     return dummy->next;
    }


    // desing  browser History

    #include<bits/stdc++.h>

 

class Node {
    public:
        string data;
        Node* next;
Node* back;
        Node() : data(0), next(nullptr), back(nullptr){};
        Node(string x) : data(x), next(nullptr), back(nullptr) {}
        Node(string x, Node* next, Node* random) : data(x), next(next), back(random) {}
};

class Browser
{
    Node* currentPage;
    public:
    Browser(string &homepage)
    {
        currentPage = new Node(homepage);
    }
    void visit(string &url)
    {

        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage=newNode;
    }
    string back(int steps)
    {

        while(steps) {
            if(currentPage->back) {
                currentPage = currentPage->back;
            } else{  break;}
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while(steps) {
            if (currentPage->next) {
                currentPage = currentPage->next;
            } else{   break; }    steps--;
  }
  return currentPage->data;

  }

};