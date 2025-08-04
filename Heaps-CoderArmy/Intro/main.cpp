#include <bits/stdc++.h>
using namespace std;



// inplementation of heap 

// Max Heap

class MaxHeap{
    int *arr ; // array 
    int size ; // number of elements in the heap
    int totalSize; // totalSize of the heap
    public:
    MaxHeap(int n){
    arr=new int[n];
    size=0;
    totalSize=n;
    }

    void insert(int val){
        if(size==totalSize){
            cout<<"Heap Overflow"<<endl;
            return ;
        }
        arr[size]=val; 
        int index=size; // taking the idx where the element store 
        size++;
        // checking that the new element is at their correct postion if not swap to its correct position
        while(index > 0 && arr[index]>arr[(index-1)/2]   ){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        } 
        cout<<arr[index]<<" is inserted into the heap"<<endl;
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" "; 
        }
        cout<<endl;
    }
    void MaxHeapify(int idx){
        int largest=idx;
        int left=2*idx+1;
        int right=2*idx+2;
        // largest will store the index of the element which is largest among parent , left and right child
        if(left<size && arr[left]>arr[largest]) 
        largest=left;
        if(right<size && arr[right]>arr[largest]) 
        largest=right;
        
        if(idx!=largest) {
            swap(arr[idx],arr[largest]);
            MaxHeapify(largest);
        }
    }
    void Delete(){
        if(size==0) {
            cout<<"underflow "<<endl;
            return;
        }
        cout<<arr[0]<<" deleted from Head"<<endl;
        arr[0]=arr[size-1];
        size--;
        if(size==0){
            return;
        }
        MaxHeapify(0);
    }
};

// Min Heap
class MinHeap{
     int *arr ; // array 
    int size ; // number of elements in the heap
    int totalSize; // totalSize of the heap
    public:
    MinHeap(int n){
    arr=new int[n];
    size=0;
    totalSize=n;
    }
    void insert(int val){
         if(size==totalSize){
            cout<<"Heap Overflow"<<endl;
            return ;
        }
          arr[size]=val; 
        int index=size; // taking the idx where the element store 
        size++;
        // checking that the new element is at their correct postion if not swap to its correct position
        while(index > 0 && arr[index]<arr[(index-1)/2]   ){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        } 
        cout<<arr[index]<<" is inserted into the heap"<<endl;
    }
    void print(){
         for(int i=0;i<size;i++){
            cout<<arr[i]<<" "; 
        }
        cout<<endl;
    }
        void MinHeapify(int idx){
        int smallest=idx;
        int left=2*idx+1;
        int right=2*idx+2;
        // smallest will store the index of the element which is smallest among parent , left and right child
        if(left<size && arr[left]<arr[smallest]) 
        smallest=left;
        if(right<size && arr[right]<arr[smallest]) 
        smallest=right;
        
        if(idx!=smallest) {
            swap(arr[idx],arr[smallest]);
            MinHeapify(smallest);
        }
    }
    void Delete(){
         if(size==0) {
            cout<<"underflow "<<endl;
            return;
        }
        cout<<arr[0]<<" deleted from Head"<<endl;
        arr[0]=arr[size-1];
        size--;
        if(size==0){
            return;
        }
        MinHeapify(0);
    
    }
};


int main(){
    // MaxHeap H1(7) ; // given the size of the heap
    // H1.insert(30);
    // H1.insert(20);
    // H1.insert(16);
    // H1.print(); 
    // H1.Delete();
    // H1.Delete();
    // H1.Delete();
    // H1.Delete();
    // H1.Delete();
    // H1.print(); 
    MinHeap H2(7);
    H2.insert(30);
    H2.insert(20);
    H2.insert(0);
    H2.insert(1);
    H2.insert(16);
    H2.print();
    H2.Delete();
    H2.print(); 
}
