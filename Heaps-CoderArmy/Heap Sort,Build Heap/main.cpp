#include <bits/stdc++.h>
using namespace std;

// Building Max/Min Heap  -- > Using the Step Down Approach
// Here is the code of MaxHeap // we can build min heap by exchanging > sign by <
//recursive Approach
// void Heapify(int arr[],int idx,int n){ 
//     int largest=idx;
//     int left=2*idx+1;
//     int right=2*idx+2;

//     if(left<n && arr[left]>arr[largest]) {
//         largest=left;
//     }
//     if(right<n && arr[right]>arr[largest]){
//        largest=right;
//     }

//     if(largest!=idx){
//         swap(arr[idx],arr[largest]);
//         Heapify(arr,largest,n);
//     }
// }

// Iterative Appoach To Build Heap
void Heapify(int arr[],int idx,int n){
    while(true){
        int largest=idx;
        int left=2*idx+1;
        int right=2*idx+2;

        if(left<n && arr[left]>arr[largest])
        largest=left;
        if(right<n && arr[right]>arr[largest])
        largest=right;

        if(largest!=idx){
            swap(arr[idx],arr[largest]);
            idx=largest; // continue to traverse down the tree
        }
        else {
            break;
        }

    }
}

void BuildHeap(int arr[],int size){
    
    for(int i=size/2-1;i>=0;i--){
        Heapify(arr,i,size);
    }
}

void printHeap(int arr[],int n){
   for(int i=0;i<n;i++){
    cout<<arr[i]<< " ";
   }
   cout<<endl;
}

// convert the DS into MaxHeap/MinHeap  // MaxHeap->Descending->If Using O(1) Space 
void HeapSort(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        Heapify(arr,0,i);
    }
}



// 
int main(){
    int arr[]={14,15,12,22,17,20,18,24,23,30,19};
    BuildHeap(arr,11);
    printHeap(arr,11);
    HeapSort(arr,11);
    printHeap(arr,11);
}

