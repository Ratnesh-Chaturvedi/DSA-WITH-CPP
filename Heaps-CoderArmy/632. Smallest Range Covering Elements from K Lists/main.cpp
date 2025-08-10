// optimised 

class Solution {
public:
    class Node {
    public:
        int val;
        int row;
        int col;
        Node(int val, int row, int col) {
            this->val = val;
            this->row = row;
            this->col = col;
        }
    };
    class comparator {
    public:
        bool operator()(Node& a, Node& b) {
            return a.val > b.val; // for min heap;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node, vector<Node>, comparator> pq;
        int n = nums.size();
        int maxi = INT_MIN;
        int mini;
        // insert each element of first row
        for (int i = 0; i < n; i++) {
            pq.push(Node(nums[i][0], i, 0));
            maxi = max(nums[i][0], maxi);
        }
        // vector for storing ranges 
        vector<int>range(2);
        mini=pq.top().val;
        range[0]=mini;
        range[1]=maxi;

        // checking that each array has its one element in heap 
        while(pq.size()==n){
           Node temp=pq.top();
           pq.pop();
           int el=temp.val;
           int row=temp.row;
           int col=temp.col;
           
           // check for it should not be out of the range 
           if(col+1 < nums[row].size()) {
            pq.push(Node(nums[row][col+1],row,col+1));
            maxi=max(maxi,nums[row][col+1]);
            mini=pq.top().val;
            if(maxi-mini<range[1]-range[0]){
                range[0]=mini;
                range[1]=maxi;
           }
           }
        } 
      return range;
    }
};
