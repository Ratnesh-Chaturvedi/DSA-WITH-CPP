// Input:
// A = [3, 1, 2]
// Output:
// 3 2 1

// Explanation: All the permutations of [1, 2, 3] are [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1], ]. Hence the next greater permutation of [3, 1, 2] is [3, 2, 1].


//optimised code
vector<int> nextGreaterPermutation(vector<int> &a) {
    // my solution

    int n=a.size();
    int idx=-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        reverse(a.begin(),a.end());
        return a;
    }

    for(int i=n-1;i>=idx;i--){
        if(a[i]>a[idx]){
            swap(a[i],a[idx]);
            break;
        }
    }
    reverse(a.begin()+idx+1,a.end());
    return a;
}