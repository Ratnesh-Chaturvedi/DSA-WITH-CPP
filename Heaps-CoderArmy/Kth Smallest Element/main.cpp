

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // brute 
        // sort(arr.begin(),arr.end());
        // return arr[k-1]
        
        // Better 
        
        // priority_queue<int,vector<int>,greater<int>>pq;
        // for(int i=0;i<arr.size();i++)
        // pq.push(arr[i]);
        // int i=0;
        // while(!pq.empty()){
        //     int top=pq.top();
        //     pq.pop();
        //     i++;
        //     if(i==k) return top;
        // }
        // return 0;
        
        
        // More Optimized
        
        priority_queue<int>maxh;
        // pushing k group elemenet 
        for(int i=0;i<k;i++) maxh.push(arr[i]);
        
        for(int i=k;i<arr.size();i++){
        int top=maxh.top();
        if(arr[i]<top){  // check for min element coming or not
            maxh.pop();
            maxh.push(arr[i]);
        }
        }
        return maxh.top();
    }
};