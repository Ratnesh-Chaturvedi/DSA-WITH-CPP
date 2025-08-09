// My brute 
    vector<double> getMedian(vector<int> &arr) {
       vector<double>ans;
       int n=arr.size();
       vector<int>temp;
       
       for(int i=0;i<n;i++){
          temp.push_back(arr[i]);
          sort(temp.begin(),temp.end());
          if(temp.size()%2==1){
                int mid=temp.size()/2;
              ans.push_back(double(temp[mid]));
          }
          else {
              int mid=temp.size()/2;
              int idx1=mid;
              int idx2=mid-1;
              double a=double((temp[idx1]+temp[idx2]))/2;
              ans.push_back(a);
          }
       }
        return ans;
    }


    // brute by using shifting instead of sorting 
       vector<double> getMedian(vector<int> &arr) {
       vector<double>ans;
       int n=arr.size();
       vector<int>temp;
       
       for(int i=0;i<n;i++){
           // finding the correct position where it should be inserted in arra
             auto pos = lower_bound(temp.begin(), temp.end(), arr[i]);
            temp.insert(pos, arr[i]);
            if(temp.size()%2==1){
                ans.push_back(temp[temp.size()/2]);
            }
            else {
                int mid=temp.size()/2;
            double a=(double)(temp[mid-1]+temp[mid])/2;
                 ans.push_back(a);
            }
       }
       return ans;
    }


    // optimsed approach
    
    vector<double> getMedian(vector<int> &arr) {
    // Max-heap for the left half
    priority_queue<int> maxheap;
    
    // Min-heap for the right half
    priority_queue<int, vector<int>, greater<int>> minheap;

    vector<double> ans;

    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];

        // Step 1: Add the number to the appropriate heap
        if (maxheap.empty() || num <= maxheap.top()) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }

        // Step 2: Balance the heaps so that maxheap is never smaller than minheap by more than 1
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }

        // Step 3: Compute the median based on heap sizes
        if (maxheap.size() == minheap.size()) {
            double median = (maxheap.top() + minheap.top()) / 2.0;
            ans.push_back(median);
        } else {
            ans.push_back(double(maxheap.top())); // maxheap will have the extra element
        }
    }

    return ans;
}
