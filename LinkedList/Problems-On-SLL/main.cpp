// 2. Add Two Numbers 
// Add two linked list
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode*t1=l1,*t2=l2,*dummyNode=new ListNode(-1);
    ListNode *curr=dummyNode;
    int carry=0;
    int sum=0;
    while(t1!=NULL || t2!=NULL){
         sum=carry;
        if(t1) sum+=t1->val;
        if(t2) sum+=t2->val;
        ListNode*newNode=new ListNode(sum%10);
        carry=sum/10;
        curr->next=newNode;
        curr=curr->next;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(carry){
        ListNode*newNode=new ListNode(carry);
        curr->next=newNode;
    }
    return dummyNode->next;

} 

// 206 Reverse LinkedList
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;

ListNode*last=NULL,*curr=head;
while(curr!=NULL){
ListNode*front=curr->next;
curr->next=last;
last=curr;
curr=front;

}
return last;
}


//recursive method
ListNode* reverseList(ListNode* head) {
  if(head==NULL || head->next==NULL) return head;
  ListNode*newHead=reverseList(head->next) ;
  ListNode*front=head->next;
  front->next=head;
  head->next=NULL;
  return newHead;
  
}



// 328. Odd Even Linked List
//Brute force
//TC- O(2n)
//SC- O[n]
ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    vector<int>ans;

    ListNode*temp=head;
    while(  temp!=NULL && temp->next!=nullptr){
        ans.push_back(temp->val);
        temp=temp->next->next;
    }
    if(temp) ans.push_back(temp->val);
    temp=head->next;

      while(  temp!=NULL && temp->next!=nullptr){
        ans.push_back(temp->val);
        temp=temp->next->next;
    }
    if(temp) ans.push_back(temp->val);
    int i=0;
    temp=head;
    while(temp!=NULL){
        temp->val=ans[i];
        i++;
        temp=temp->next;
    }
    return head;
}

// optimised Approach
// TC- O(n) SC-O(1)
ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;

    ListNode*odd=head,*even=head->next,*evenHead=head->next;

    while(even!=NULL && even->next!=nullptr){
     odd->next=odd->next->next;
     even->next=even->next->next;
     odd=odd->next;
     even=even->next;
    }
    odd->next=evenHead;
    return head;
}


//GFG Sort a linked list of 0s, 1s and 2s
Node* segregate(Node* head) {
    Node *zeroHead=new Node(-1);
    Node *oneHead=new Node(-1);
    Node *twoHead=new Node(-1);
     Node*temp=head;
     
     Node*one=oneHead,*two=twoHead,*zero=zeroHead;
     while(temp!=NULL){
         if(temp->data==0){
             zero->next=temp;
             zero=zero->next;
         }
         else if(temp->data==1){
             one->next=temp;
             one=one->next;
         }
         else {
             two->next=temp;
             two=two->next;
         }
         temp=temp->next;
     }
     
     zero->next=oneHead->next?(oneHead->next):twoHead->next;
     one->next=twoHead->next;
     two->next=NULL;
     
     Node *newNode=zeroHead->next;
     return newNode;
    }


    // 19. Remove Nth Node From End of List
    //My code TC-O(2n) SC-O(n)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        if(head->next==nullptr) {
         if(n==1) return NULL;
        } 
        int size=0;
        ListNode*temp=head;
        while(temp!=NULL){
         size++;
         temp=temp->next;
        }
         int cnt=size-n;
         if(cnt==0){
             ListNode* newhead = head->next;
             
             delete head;
             return newhead;
         }
 
         int c=0;
         temp=head;
         while(temp!=NULL){
          c++;
          if(c==cnt) break;
          
          temp=temp->next;
         }
         ListNode*delNode=temp->next;
         temp->next=temp->next->next;
          delete delNode;
          return head;        
         
     }

     // optimised By two pointer 
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode*fast=head,*slow=head;
        for(int i=0;i<n;i++){
         fast=fast->next;
        }
        if(fast==NULL){
         ListNode*newHead=head->next;
         delete head;
         return newHead;
        }
        while(fast->next!=NULL){
         slow=slow->next;
         fast=fast->next;
        }
         ListNode*delNode=slow->next;
         slow->next=slow->next->next;
         delete delNode;
 
         return head;
     }




     //234. Palindrome Linked List
// striver Brute force By using stack
// My Brute force  without using stack
// TC-O(2n)
//SC-O(N)
     bool isPalindrome(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            if(arr[i]!=arr[j]) return false;
            i++;
            j--;
        }
        return true;
    }


    // 
    // 876. Middle of the Linked List
// My brute force
    ListNode* middleNode(ListNode* head) {
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt%2==0){
            temp=head;
            int c=0;
            while(temp!=NULL){
               c++;
               if(cnt/2==c) break;
               temp=temp->next;
            }
            return temp->next;
        }
        else {
            temp=head;
            int c=cnt/2;
            while(c--){
                temp=temp->next;
            }
            return temp; 
        }
    }

    // brute force  TC-O(n + n/2); 
    ListNode* middleNode(ListNode* head) {
        ListNode*temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int midNode=(cnt/2)+1;
        temp=head;
        while(temp!=NULL){
            midNode--;
            if(midNode==0) break;
            temp=temp->next;
        }
        return temp;
    }

    //optimised by using tortoise nadn hare (slow and fast pointer) 

    ListNode* middleNode(ListNode* head) {
        ListNode*slow=head,*fast=head;
 
        while( fast!=NULL && fast->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
        }
        return slow;
     }


     // Add 1 to a Linked List Number
//iterative method TC-O(3N) Sc-O(1)
Node *reverse(Node*head){
    if(head==NULL || head->next==NULL) return head;
    Node*prev=NULL,*curr=head;
    while(curr!=NULL){
        Node*front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
    
}
  Node* addOne(Node* head) {
  head=reverse(head);
  Node*temp=head;
  int carry=1;
  int sum=0;
  while(temp!=NULL){
      sum=carry;
      sum+=temp->data;
      temp->data=sum%10;
      carry=sum/10;
      temp=temp->next;
  }
  if(carry){
      Node*newnode=new Node(carry);
      head=reverse(head);
      newnode->next=head;
      return newnode;
  }

  head=reverse(head);
  return head;
  }


     //recursie method Tc-O(N) SC-O(n)
     int helper(Node*temp){
        if(temp==NULL) return 1;
        int carry=helper(temp->next);
        temp->data += carry;
        if(temp->data < 10){
            return 0;
        }
        temp->data=0;
        return 1;
        
        
    }
       Node* addOne(Node* head) {
        int carry=helper(head);
        if(carry==1){
            Node*newNode=new Node(1);
            newNode->next=head;
            return newNode;
        }
        return head;
       }




       // find the starting node of the loop 

// My brute force
//TC-O(n) SC-O(n)

       ListNode *detectCycle(ListNode *head) {
        ListNode*temp=head;
        unordered_map<ListNode*,int>hash;
        while(temp!=NULL){
            if(hash.find(temp)!=hash.end()){
                return temp;
            }
            hash[temp]++;
            temp=temp->next;
        }
        return NULL;
    }

    //Optimised By two pointer;
    // TC-O(N) SC-O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
           slow=slow->next;
           fast=fast->next->next;
           if(fast==slow){
               slow=head;
               while(slow!=fast){
                   slow=slow->next;
                   fast=fast->next;
               }
               return slow;
           }
        }
        return NULL;
   }

   //Sorting a LL using merge sort
// TC-O(logN*(N+N/2)) SC-O(1)
   Node *findMid(Node *head){
	Node*s=head,*f=head->next;
	while(f!=NULL && f->next!=NULL){
		s=s->next;
		f=f->next->next;
	}
	return s;
}
Node *merge(Node*list1,Node*list2){
Node*dummyNode=new Node(-1);
Node*temp=dummyNode;
while(list1!=NULL && list2!=NULL){
	if(list1->data<list2->data){
		temp->next=list1;
		temp=list1;
		list1=list1->next;
	}
	else {
		temp->next=list2;
		temp=list2;
		list2=list2->next;
	}
}
if(list1) temp->next=list1;
else temp->next=list2;

return dummyNode->next;
}
Node *sortLL(Node *head)
{
    if(head==NULL || head->next==NULL ) return head;
	Node*mid=findMid(head);
	Node*leftNode=head;
	Node*rightNode=mid->next;
	mid->next=NULL;
	leftNode=sortLL(leftNode);
	rightNode=sortLL(rightNode);
   
   return merge(leftNode,rightNode);
}



//LC-160 
// intersection of y linked list
//brute force Time Complexity: O(m*n) , SC-O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL || headA==NULL ) return NULL;
    if(headB==NULL || headB==NULL ) return NULL;
while(headA!=NULL){
ListNode*temp=headB;
while(temp!=NULL){
    if(temp==headA) return temp;
    temp=temp->next;
}
headA=headA->next;
}
    return NULL;
}

//  By Using hashing Time Complexity: O(n+m) Space Complexity: O(n)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL || headA==NULL ) return NULL;
    if(headB==NULL || headB==NULL ) return NULL;
ListNode*temp=headA;
unordered_map<ListNode*,int>mpp;
while(temp!=NULL ) {
mpp[temp]=1;
temp=temp->next;
}
temp=headB;
while(temp!=NULL){
if(mpp.find(temp)!=mpp.end()) return temp;
temp=temp->next;
}
    return NULL;
}



// another approach by using traversing 
// TC -(2N2 or 2N1) largest legnth among two ll


ListNode*collision(ListNode*t1,ListNode*t2,int d){
    while(d){
        d--;
        t1=t1->next;
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL ) return NULL;
      
         int n1=0,n2=0;
         ListNode*t1=headA,*t2=headB;
         while(t1 || t2){
            if(t1) {
                n1++;
                t1=t1->next;
                }
            if(t2) {
                n2++;
                t2=t2->next;
                }
         }
         if(n1>n2){
            return collision(headA,headB,n1-n2);
         }
        else return collision(headB,headA,n2-n1);
    }


    //Optimised 
    // TC-O(N1+N2) SC-O(1)
    
