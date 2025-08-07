vector<int> kthLargest(int k, int arr[], int n) {
    vector<int>ans;
    priority_queue<int ,vector<int> ,greater<int>>pq; // creating min heap to store k largest elements

    // Process first k elements
    for(int i=0;i<k;i++){
        pq.push(arr[i]); // push current element into heap
        if(pq.size()==k) 
            ans.push_back(pq.top()); // if we have k elements, the top is the k-th largest
        else 
            ans.push_back(-1); // less than k elements, so k-th largest doesn't exist yet
    }
    // Process remaining elements in the stream
    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){ // if current element is greater than the smallest in heap
            pq.pop();        // remove smallest (k-th largest so far)
            pq.push(arr[i]); // insert current element to maintain top k elements
        }
        ans.push_back(pq.top()); // current k-th largest element
    }

    return ans;
}
