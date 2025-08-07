

// if number of edges between root node to leaf node
// One liner 
int height = floor(log2(n));


// My appraoch 
int heapHeight(int n, int arr[]) {
    if (n == 1) return 1;

    int i = 0;
    int cnt = 0;
    while (i < n) {
        i = 2 * i + 1;
        cnt++;
    }
    return cnt - 1;
}

// by using bitwise 
int heapHeight(int n) {
    int height = 0;
    while ((1 << (height + 1)) <= n) {
        height++;
    }
    return height;
}

