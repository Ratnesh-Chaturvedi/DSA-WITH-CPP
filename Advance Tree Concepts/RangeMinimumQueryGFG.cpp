/* The functions which
builds the segment tree */


    void build(int i,int l,int r,int arr[],int stree[]){
        if(l==r) {
            stree[i]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*i+1,l,mid,arr,stree);
        build(2*i+2,mid+1,r,arr,stree);
        stree[i]=min(stree[2*i+1],stree[2*i+2]);
    }
    int minEl(int i,int l,int r,int st,int end,int stree[]){
        if(l>end || r<st ) return 1e9;
        if(l>=st && r<=end) return stree[i];
        
        int mid=(l+r)/2;
        return min ( minEl(2*i+1,l,mid,st,end,stree),minEl(2*i+2,mid+1,r,st,end,stree));
    }


int *constructST(int arr[], int n) {
  
  int *tree=new int[4*n];
  build(0,0,n-1,arr,tree);
return tree;
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
      return minEl(0,0,n-1,a,b,st);  

}