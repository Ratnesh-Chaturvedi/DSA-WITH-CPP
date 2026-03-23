// it is used for the range queries 
// it allows ->
// efficient querying on interval/range
// efficient updating on interval/range
// eg -> given a range find the sum , min,max,avg etc

// it can we stored in the array where the ith node  had 2*i+1(left child) and 2*i+2(right child)
// the root node represent the sum,min,max of the range from 0->n-1

// hence we build the tree 

// some facts
// -> it hast n leaf nodes 
// the difference between the left subtree and right subtree height is not greater than 1
// there can be either 2 child or no child 

// there can we atmost 2*n nodes in the tree 
// X = N+ N/2+ N/4+....+2+1
// 2X = 2N+ N +N/2+....+4+2
// 2X +1 = 2N +(N + N/2+N/4+....+4+2+1)
// 2X +1 = 2N + X
// X = 2N-1



// we can make the tree by using recursion where we can build the tree for left subtree and right subtree

// the leaf node has the range [l,r] where l==r -> represent only the single value 



// we represent the segtree as an array element 

// building segtree
vector<int>segTree(n*2);

// here we are taking the sum example

// space of build tree-> sc(2n)+sc(log2n) 
// time ->?
// we approximately traverse each node two times first time whwen we traverse second time when we backtrack 
//  tc- > 2*(2*n) // n->number of elem in array



// it start from i=0,left=0,right=n-1
void buildTree(int i,int left,int right){
    // base conditon 
  // when l==r leaf node no further nodes are possible
  if(left==right){
    seqTree[i]=nums[right]; // nums is the given array
    return;
  }

    int mid=(left+right)/2;
    // building left subtree
    buildTree(2*i+1,left,mid);
    // building right subtree
    buildTree(2*i+2,mid+1,right);
    // root 
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}


// segtree for updating query ->using  range sum example

// updating a idx with new value 
// idx->index to update
// val-> new val
// i->root , l=0,r=n-1
// updateTree(idx,val,i,l,r)


// time and space 
// time -> logN to find node // logN to traverse back  // height tak traverse kar rahe hai 
// time ->O(log2n)
void updateTree(int idx,int val,int i,int l,int r){
    if(l==r ){
        // idx==l
        nums[idx]=val;
        seqTree[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    // checking which side our idx will be available
    //left side
    if(idx<=mid){
        updateTree(idx,val,2*i+1,l,mid);
    }
    // right side
    else{
        updateTree(idx,val,2*i+2,mid+1,r);

    }
    segTree[i]=seqTree[2*i+1]+segtree[2*i+2];
}


// query in segment tree
// range sum query

// eg->array={1,2,43,54,565,65,43}
// queries are -> sum of the ranges -> [0,2] ,[3,6] ,[0,7] etc;
// queries => [st,end]
// our node-> [l,r]
// here three cases can we arise while taking the sum of the ranges 
// if [l,r] out of bound of the range 
// if [l,r] are entirely in the range 
// if [l,r] are partially or overlapped in the range 

//Time and space complexity->
// height -> O(log2N)
// in worst case we move to leaf node for start and end of the query
// but we can also get the values in between
// O(log2N +log2N)

// for Q queries ->O (Q*log2N)


// here i=0,l=0,r=n-1,st=query[0],end=query[1]
int rangeSumQuery(int st,int end,int i,int l,int r,vector<int>&segTree){
    // generating cases 
    //out of bound
    if(l>=end || r<=st){
        return 0; 
    }
    // entirely in the range
    if(l>=st && r<=end){
        return segTree[i];
    }
    // overlapped 
    int mid=(l+r)/2;
    // find from left side + find from right side 
    return rangeSumQuery(st,end,2*i+1,l,mid) +rangeSumQuery(st,end,2*i+2,mid+1,r);
}


// why we take segTree size 4*n

// agr number of el in array is in the 2 ki power toh toh hamrare sare element pair ho jayenge lekin nahi hai toh wo pair nahi ho pauyenge 

// so hum jo hai number of nodes*2 kar denge so ab sabhi pair ban jayenge 
// now ab jo hai total leaf nodes =2*n  

// and we take the size of segment array=2*number of leaf nodes 
// so total size = 2* (2*n) = 4*n; 



// range minimum/maximum query 
 // just take the minimum where we are doing the sum of left and right 
 int rangeMinQuery(int st,int end,int i,int l,int r,vector<int>&segTree){
    // generating cases 
    //out of bound
    if(l>end || r<st){
        return 1e9; 
    }
    // entirely in the range
    if(l>=st && r<=end){
        return segTree[i];
    }
    // overlapped 
    int mid=(l+r)/2;
    // find from left side + find from right side 
    return min( rangeMinQuery(st,end,2*i+1,l,mid,segTree) +rangeMinQuery(st,end,2*i+2,mid+1,r,segTree) );
}


// range update Query (updating all elment with in that range) // Lazy propagation  
// if we use the appraoch to update each idx individually byu using the above concept it will take queryrange*log2N time -> which is not an efficient way 

// lazy propagation mai hum ek segTree ke tarh ek array lete hai 
// baki notes mai dekh lena 

// i=0,left=0,right=n-1;
// update (start,end,val,i ,left,right,segTree,lazy)


// space -> O(4*n)->segTree + O(4*n)->lazy array
//time -> O(log2N)-> update \\ Q->no of queries 
// O(Q*log2n)


vector<int>lazy(4*n,0);
void updateQuery(int st,int end,int val,int i,int l,int r,vector<int>&segTree,vector<int>&lazy){

    // if lazy node is not 0
    if(lazy[i]!=0){
        segTree[i]+=(r-l+1)*lazy[i];
        // now update the child node by putting the values in lazy child nodes
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    // check if it is out of bound  
    if(l>end || r<st || l<r){
     return;
    }
    // within the range
    if(l<=st && r<=end){
        segTree[i]+=(r-l+1)*val;
        //update lazy child Node 
        if(l!=r){
            lazy[2*i+1]+=val;
            lazy[2*i+2]+=val;
        }
        return;
    }

    // overlapped 
    int mid=(l+r)/2;
    //go left 
    updateQuery(st,end,val,2*i+1,l,mid,segtree,lazy);
    //go right 
    updateQuery(st,end,val,2*i+2,mid+1,r,segtree,lazy);

    // update the node 
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];

}



//RANGE MAXIMUM/MINIMUM INDEX QUERY
//this time we store the index in the segment tree
 vector<int>sgTree(4*n)
 // build the tree but this time check for max idx
 void build(int i,int l,int r,vector<int>&stree,vector<int>&arr){
    if(l==r){
        // stree[i]=arr[l]; // we do this in build while we select for max element 
        stree[i]=l;
        return;
    }
    int mid=l+(r-l)/2;
    

    // we do this to find the idx
    build(2*i+1,l,mid,stree,arr);
    build(2*i+2,mid+1,r,stree,arr);
    int leftIdx=stree[2*i+1];
    int rightIdx=stree[2*i+2];
    
    if(arr[leftIdx]>=arr[rightIdx]){
        stree[i]=leftIdx;
    }
    else stree[i]=rightIdx;

 }

 // for range max idx query 
 // do same like range max element query replace only the element with index
// range-[st,end]

//TC- O(log2n)
//
 int RMIQ(int i,int l,int r,int st,int end,vector<int>&stree,vector<int>&arr){
    // out of bound 
    if(l>end || r<st) return -1;

    // in the range 
    if(l>=st && r<=end) return stree[i];

    // overlapping 
    int mid=l+(r-l)/2;
    int leftIdx=RMIQ(2*i+1,l,mid,st,end,stree,arr);
    int rightIdx=RMIQ(2*i+1,mid+1,r,st,end,stree,arr);

    // check for -1 case 
    if(leftIdx==-1) return rightIdx;
    if(rightIdx==-1) return leftIdx;

        // check for max elment idx
        if(arr[leftIdx]<=arr[rightIdx]){
            return leftIdx;
        }
        return rightIdx;
 }



 // Using RMIQ with Binary Search
 // Eg-arr->[5,3,7,4,1,6]
 // Queries=> {[0,1],[0,2],[1,3]---}
 
 // Varities of question 
 // varity 1->
 // Right range mai max element the idx 
 // Eg-> [0,1] toh ismai jo right side ke range jo hogi (r+1->n-1) tak ki usmai max element the index nikalna hia  (RMIQ)
 // so iska answer aayega -> index of 7 =2
 
 // Varity 2->
// Right range mai wo element nikalna hai jo  queried ->[i,j] such that >arr[i] && arr[j]
// wo element us query ke done index ke element se bada ho  
// RMIQ ek idx dega -> check arr[idx]>arr[i] && arr[idx]>arr[j] then this idx is a valid answer

// Varity 3-> // Binary search used in this 
// right range mai wo element jo query [i,j] ke liye >arr[i] && arr[j] which is also as left as possible 
// eg -> q=>[0,1] -> so here elements=[7,6] are valid and return the index of the element which is the leftmost =arr[2]=7; idx=2 (ans)
 
// agr ismai RMIQ laga toh sirf wo max element ka index dega ko hame pta nahi ki koi or lement bhi hai range mai condition ko follow karne wala or sayd wo left side ho max element ke index ke -> so wo sirf RMIQ se pta nahi lagaya ja sakte so is liye Binary Search lagayenge where we use (mid,left,right) and find RMIQ for (mid,left ) and if conditon RMIQ idx follows the condition then decrease the r and apply the concept of binary serach we apply as normal type 
// like idx=RMIQ(l,mid)  // if this idx is valid then move right =mid-1 
// same for right   

// for variant 3 -> see question ->  
//2940. Find Building Where Alice and Bob Can Meet

 

// Mutable range min/max update query 
// like ek range hai usmai min,and max likalo or update bhi kar do -> we use lazy propagation technique


// it is simple as we do in lazy propagation 
// build two tree min and max segTree for all ranges 

// query ->[st,end]
// we have 2 tree min  and max 

// we also build a progate function to check for the lazy propagation 

void propagate(int i, int l ,int r){
    if(lazy[i]!=0){
        segTreeMax[i]+=lazy[i];
        segTreeMin[i]+=lazy[i];
        // check that that tree has its child nodes or not
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        // reset the lazy value because it is progated successfully 
        lazy[i]=0;
    }
}

void rangeUpdate(int st,int end,int i,int l,int r){
  propagate(i,l,r)    ; // check lazy[i]!=0

  // out of bound
  if(l>end || r<st ){
    return;
  }
  // overlap
  if(l>=st && r<=end){
    lazy[i]+=val;
    progate(i,l,r);
    return ; // this is the lazy propagation so we only upate the node not its child so that it will take less time and when we reach that node than at that time we update that node values 
  }

  int mid=l+(r-l)/2;
  rangeUpdate(st,end,2*i+1,l,mid);
  rangeUpdate(st,end,2*i+2,mid+1,r);

  // updating the min segtree 
  segTreeMin[i]=min(segTreepMin[2*i+1],segTreeMin[2*i+2]);
  segTreeMax[i]=max(segTreepMax[2*i+1],segTreeMax[2*i+2]);
  
}