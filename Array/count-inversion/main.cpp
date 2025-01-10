Number of Inversions

There is an integer array ‘A’ of size ‘N’.
Number of inversions in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and ‘A[i]’ > ‘A[j]’.
You must return the number of inversions in the array.
For example,
Input:
A = [5, 3, 2, 1, 4], N = 5
Output:
7
Explanation: 
The pairs satisfying the condition for inversion are (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), and (3, 4). 
The number of inversions in the array is 7.


//brute force

int numberOfInversions(vector<int>&a, int n) {
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                cnt++;
            }
        }
    }
    return cnt;
}


//Optimised by using Merge Sort



int merge(vector<int>&a,int st,int end,int mid){
    int i=st;
    int j=mid+1;
    vector<int>temp;
    int invCount=0;
    while(i<=mid && j<=end){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else {
            temp.push_back(a[j]);
            invCount+=(mid-i+1);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(a[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        a[idx+st]=temp[idx];
    }
    return invCount;
}


int  mergeSort(vector<int>&a ,int st ,int end){
if(st<end){

int mid=st+(end-st)/2;
int leftcount=mergeSort(a,st,mid);
int rightcount=mergeSort(a,mid+1,end);
int invcount=merge(a,st,end,mid);
int totalInv=leftcount+rightcount+invcount;
return totalInv;
}
return 0;
}



int numberOfInversions(vector<int>&a, int n) {
   return mergeSort(a,0,n-1);
}