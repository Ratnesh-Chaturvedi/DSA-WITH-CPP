// User function Template for C++

class Solution {
  public:
  void Heapify(vector<int>&arr,int idx){
      int n=arr.size();
      while(true){
          int largest=idx;
          int left=2*idx+1;
          int right=2*idx+2;
          
          if(left<n && arr[left]>arr[largest]) 
          largest=left;
          if(right<n && arr[right]>arr[largest])
          largest=right;
          
          if(largest!=idx){
              swap(arr[idx],arr[largest]);
              idx=largest;
          }
          else break;
      }
  }
  void MaxHeapBuild(vector<int>&arr){
      int n=arr.size();
      for(int i=n/2-1;i>=0;i--){
          Heapify(arr,i);
      }
  }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
   
     for(int i=0;i<m;i++) a.push_back(b[i]);
     MaxHeapBuild(a);
     return a;
        
    }
};