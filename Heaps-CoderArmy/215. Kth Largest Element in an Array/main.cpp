class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //brute force
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];

        // better  using maxHeap
        // priority_queue<int>pq;
        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);
        // }
        // int i=0;
        // while(!pq.empty()){
        //     i++;
        //    int  top=pq.top();
        //     pq.pop();
        //     if(i==k) return top;

        // }
        // return 0;

          // most Optimised using grouping of element and making there min heap;
          priority_queue<int , vector<int> , greater<int>>minH; // creating min heap

          for(int i=0;i<k;i++){
            minH.push(nums[i]);
          }
          for(int i=k;i<nums.size();i++){
            int top=minH.top();
            if(top<nums[i]){
                minH.pop();
                minH.push(nums[i]);
            }
          }
          return minH.top();
    }
};