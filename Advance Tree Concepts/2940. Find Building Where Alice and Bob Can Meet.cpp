class Solution {
public:
    // building the segement tree of the maximum element index -> because we have to find the index 
    void build (int i,int l,int r,vector<int>&stree,vector<int>&arr){
        if(l==r){
            stree[i]=l; 
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,stree,arr);
        build(2*i+2,mid+1,r,stree,arr);
        int leftIdx=stree[2*i+1];
        int rightIdx=stree[2*i+2];
        if(arr[leftIdx]>arr[rightIdx]){
            stree[i]=leftIdx;
        }
        else stree[i]=rightIdx;
    }

// finding range maximum index of the query

int rmiq(int i,int l,int r,int st,int end,vector<int>&stree,vector<int>&arr){
    // out of bound 
    if(l>end || r<st) return -1;

    // in the range
    if(l>=st && r<=end){
        return stree[i];
    }
    // overlapping 
    int mid =l+(r-l)/2;
    int leftIdx=rmiq(2*i+1,l,mid,st,end,stree,arr);
    int rightIdx=rmiq(2*i+2,mid+1,r,st,end,stree,arr);
    if(leftIdx==-1) return rightIdx;
    if(rightIdx==-1) return leftIdx;
    if(arr[rightIdx]>arr[leftIdx])
    return rightIdx;
    else return leftIdx;
}

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // in this question we have to find the leftmost idx which is greater than
        // q=[i,j] where leftmostIdx> hegiht[i] && height[j]
        
        // if i==j then the answer is i or j because both alice and bob are on the same building 

        // approaching it by using segment tree with binary search to search the leftmost idx
        int n=heights.size();
        vector<int>stree(4*n);
        build(0,0,n-1,stree,heights);    

         // now accoring to condition we can only move in right side only if the right building > left building
         
         //query=[i,j]
         // we have to follow the condtion the element should be 
         // el>height[i] && el>height[j]
         // here we can say that some conditon are possible
         // 1-> if both are on same building then -> answer will be the idx
         // 2-> if the height[j] > height[i] then answer will be the jth idx
         // 3-> height[i]>height[i] so we have to find some other building in the right side of the  range and than building index should be leftmost 
         // 4-> if we are unable to find return -1

        vector<int>qans;
        // space -> O(4*n) -> for building segment tree
        // we dont count the answer array space because we have to return ;
        // TC- >
        //  O(q)-> queries 
        // O(log2n)->Binary search // O(log2n)->RMIQ
        // Time complexity-> O(n*logn*logn)=O(n*(log2n)^2)
        for(auto it:queries){
            int maxIdx=max(it[0],it[1]);
            int minIdx=min(it[0],it[1]);
            if(it[0]==it[1]){
                qans.push_back(it[0]);
                continue;
            }
            else if(heights[maxIdx]>heights[minIdx]){
                qans.push_back(maxIdx);
                continue;
            }

                int l=maxIdx+1;
                int r=n-1;
                int resultIdx=INT_MAX;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    int queryIdx=rmiq(0,0,n-1,l,mid,stree,heights);
                    if(heights[queryIdx]>max(heights[minIdx],heights[maxIdx])){
                        resultIdx=min(queryIdx,resultIdx);
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                if(resultIdx!=INT_MAX)
                qans.push_back(resultIdx);
                else qans.push_back(-1);
            

        }
        return qans;
    }
};