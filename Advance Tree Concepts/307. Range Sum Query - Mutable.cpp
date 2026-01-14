class SGT{
    public:
    vector<int>stree,lazy;
    SGT(int n){
        stree.resize(4*n);
        lazy.resize(4*n,0);
    }
    void build(int i,int l,int r,vector<int>&arr){
        if(l==r){
            stree[i]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,arr);
        build(2*i+2,mid+1,r,arr);
        stree[i]=stree[2*i+1]+stree[2*i+2];
    }
    void updatePoint(int idx,int val,int i,int l,int r){
        if(l==r){
            // arr[idx]=val;
            stree[i]=val;
            return;
        }
          int mid=l+(r-l)/2;
          if(idx<=mid)
        updatePoint(idx,val,2*i+1,l,mid);
        else 
        updatePoint(idx,val,2*i+2,mid+1,r);
        stree[i]=stree[2*i+1]+stree[2*i+2];
    }
    int rangeSum(int i,int l,int r,int st,int end){
        // out of bound 
        if(l>end || r<st ) return 0;
        // inside the  range
        if(l>=st && r<=end){
            return stree[i];
        }
        // overlapping 
        int mid=l+(r-l)/2;
        return rangeSum(2*i+1,l,mid,st,end)+rangeSum(2*i+2,mid+1,r,st,end);
    }
};


class NumArray {
public:
SGT stree;
int n;
    NumArray(vector<int>& nums):stree(nums.size()) {
      n=nums.size();  
        stree.build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
       stree.updatePoint(index,val,0,0,n-1) ;
    }
    
    int sumRange(int left, int right) {
        return stree.rangeSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */