// using segMent tree


class SGT {
    public:
    vector<int>segTree;
    SGT(int n){
        segTree.resize(4*n);
    }
    void buildSegTree(int i,int left,int right,vector<int>&arr){
        if(left==right){
            segTree[i]=arr[left];
            return ;
        }
        int mid=left+(right-left)/2;
        // left
        buildSegTree(2*i+1,left,mid,arr);
        // right
        buildSegTree(2*i+2,mid+1,right,arr);

        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }

    int rangeSum(int i,int left,int right,int st,int end){
        // out of bound 
        if(left>end || right<st ) return 0;

        // lies in the range
        if(left>=st && right<=end ){
            return segTree[i];
        }
        // overlapping 
        int mid=left+(right-left)/2;
        return rangeSum(2*i+1,left,mid,st,end)+rangeSum(2*i+2,mid+1,right,st,end);
    }
    
};

class NumArray {
public:
SGT sgTree;
int n;
    NumArray(vector<int>& nums):sgTree(nums.size()) {
         n=nums.size();
        
        sgTree.buildSegTree(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {
        return sgTree.rangeSum(0,0,n-1,left,right);
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */