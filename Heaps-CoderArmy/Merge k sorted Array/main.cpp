
// approach 1 and 2
//Brute ->take a new array and put all element of given array to new array then sort using Merge Sort or Heap sort 


// approach 3
 vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
      priority_queue<int,vector<int>,greater<int>>pq;
      for(int i=0;i<arr.size();i++){
          for(int j=0;j<arr.size();j++)
          pq.push(arr[i][j]);
      }
      vector<int>ans;
      while(!pq.empty()){
          ans.push_back(pq.top());
          pq.pop();
      }
      return ans;      
    }

    //   Approach 4
      vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      for(int i=0;i<K;i++){
          pq.push(make_pair(arr[i][0],make_pair(i,0)));
      }
      
      vector<int>ans;
      while(!pq.empty()){
          auto top=pq.top();
          ans.push_back(top.first);
          pq.pop();
          int i=top.second.first;
          int j=top.second.second;
          if(j+1<K ){
              pq.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
          }
          
      }
      return ans;
      
    }



    // Approach 5
void merge(vector<int>&arr, int st, int mid, int end) {
    // Sizes of the two subarrays
    int n1 = mid - st + 1;
    int n2 = end - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[st + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[st..end]
    int i = 0, j = 0, k = st;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive Merge Sort function
void mergeSort(vector<int>&arr, int st, int end ,int portion,int k) {
       if(portion<2) return;

int mid=st+(portion/2)*k - 1;
        // Recursively sort the first and second halves
        mergeSort(arr, st, mid,portion/2,k);
        mergeSort(arr, mid + 1, end,portion - portion/2 , k);
        // Merge the sorted halves
        merge(arr, st, mid, end);
    }

    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
       vector<int>ans;
       for(int i=0;i<K;i++){
           for(int j=0;j<K;j++) 
           ans.push_back(arr[i][j]);
       }
        
        mergeSort(ans,0,ans.size()-1,K,K);
        return ans;
    }
