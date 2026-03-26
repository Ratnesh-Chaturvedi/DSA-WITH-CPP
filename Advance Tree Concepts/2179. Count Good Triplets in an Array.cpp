/*
// we have to calculate how many element are there in the nums1 and nums2 wwhich are comman to a idx
    // assume we have 
    //   nums1 = [4,0,1,3,2] ,nums2 = [4,1,0,2,3]
    // so in this we  have to find kon se element hai jo kisi ek index ke respect mai left side common hai 
		
		like lke jese element 1 hai n1 ka  uska index hai 2
		 -> so we have to find the total comman elemnt in both the array we are left to that element idx 
		 -> nums1={4,0} , nums2={4}  , comman element =4  ,this is common on left side =1//
		 -> so we have total left comman element =1 
		 -> number of element on the right side common jo hai wo hoga
		 // n1->{3,2} n2={2,3} so i we choose el=1 in nums 1 so we have total triplet 3 because [4,1,2],[4,1,3] 
		 // hence we can say that left uncomman count hai and =>uncomman = i-leftcomman count
		 // we have idx -:> wich is the index of the ith elememnt in the nums2 array 
		 // so element which are present after that idx ->  n-1-idx 
		 // right common count=element after index in nums2-leftcommon count 
		 
		 // more specific 
		 leftcommoncnt=query(i,l,r,st,end,idx,stree)
		 leftuncommoncnt=i-leftcommoncount
		 elementsAfterIdxInNum2=n-i-idx;
		 rightCommonCount=elementsAfterIdxInNum2-leftUnCommonCnt
		 
		 // so we have to find only the left common count 
		 // so we can calculate the whole answer 
		 // because number of triplet  or an index i from num1-> leftcommon count*rightcommoncount 
		 
		 -> here why we use the segment tree
		 // kyuki yaha par hum hamesha ek range dekh rahe hai [0,idx] in nums 2 // where idx =map[nums1[i]] 
		 // ki ismai kitne common element hai 
		 // so jo bhi elemnt hum visit kar rahe hai nums 1 mai wo hum as a visited mark kar denge 
		 // nad har bar tree ko update kar denge ki visited mark hai ki nahi 
		 // or node mai count store hoga ki kitne nodes marks hai
		 // leaf node marks as 1 if they are visited in the nums1 array 
		 // update tree after tarversing each node in nums1
		 
		 


         */

         using ll=long long ;
class Solution {
public:


void update(ll i,ll l,ll r,ll idx,vector<ll>&stree){
    if(l==r && l==idx){
        stree[i]=1;
        return ;
    }
    ll mid=l+(r-l)/2;
    if(idx<=mid)
    update(2*i+1,l,mid,idx,stree);
    else 
    update(2*i+2,mid+1,r,idx,stree);
    stree[i]=stree[2*i+1]+stree[2*i+2];
}
ll query(int i,int l,int r,int st,int end,vector<ll>&stree){
    // out of bound 
    if(l>end || r<st) return 0;
    // in range 
    if(l>=st && r<=end){
        return stree[i];
    }
    // overlapping 
    int mid=l+(r-l)/2;
    ll left=query(2*i+1,l,mid,st,end,stree);
    ll right=query(2*i+2,mid+1,r,st,end,stree);
    return left+right;
}

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    unordered_map<int,int>hash;
    for(int i=0;i<nums2.size();i++)hash[nums2[i]]=i;
    vector<ll>stree(4*n); // intially all nodes are zero
    // build(0,0,n-1,stree);
    // root,st index of num1,end idx of num1,idx,tree 
    update(0,0,n-1,hash[nums1[0]],stree);
    long long cnt=0;
    for(int i=1;i<n;i++){
        int idx=hash[nums1[i]];
        // i,left,right,0,idx
        ll leftCommonCnt=query(0,0,n-1,0,idx,stree);
        ll leftUnCommonCnt=i-leftCommonCnt;
        ll elAfterIdxNum2=(n-1)-idx;
        ll rightCommonCnt=elAfterIdxNum2-leftUnCommonCnt;
        cnt+=leftCommonCnt*rightCommonCnt;
    update(0,0,n-1,idx,stree);
    }
    return cnt;
    }
};