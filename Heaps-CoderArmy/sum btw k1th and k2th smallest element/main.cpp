long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
    // Ensure K1 is less than K2 for correct range calculation
    if (K1 > K2) swap(K1, K2);

    // Create a max heap to find the K1-th smallest element
    priority_queue<long long >maxHeap;

    // Push first K1 elements into the heap
    for(int i=0;i<K1;i++){
        maxHeap.push(A[i]);
    }

    // Maintain a max heap of size K1 to find the K1-th smallest
    for(int i=K1;i<N;i++){
        if(maxHeap.top()>A[i]){
            maxHeap.pop();
            maxHeap.push(A[i]);
        }
    }

    // After loop, maxHeap.top() is the K1-th smallest element
    long long k1small=maxHeap.top();

    // Clear the heap by assigning it a new empty heap
    maxHeap = priority_queue<long long >();

    // Push first (K2 - 1) elements into the heap to find the (K2 - 1)-th smallest
    for(int i=0;i<K2-1;i++){
        maxHeap.push(A[i]);
    }

    // Maintain max heap of size (K2 - 1) to find the (K2 - 1)-th smallest
    for(int i=K2-1;i<N;i++){
        if(maxHeap.top()>A[i]){
            maxHeap.pop();
            maxHeap.push(A[i]);
        }
    }

    // After loop, maxHeap.top() is the (K2 - 1)-th smallest = K2-th smallest element
    long long k2small=maxHeap.top();

    long long sum=0;

    // Sum all elements in the heap that are strictly greater than k1small
    while(!maxHeap.empty()){
        if(maxHeap.top()>k1small) sum+=maxHeap.top(); // ❗ This may include elements ≥ k2small
        maxHeap.pop();
    }

    return sum;
}
