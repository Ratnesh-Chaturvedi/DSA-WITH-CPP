#include <bits/stdc++.h>
using namespace std;


int main(){

    // priority_queue<int>pq;     // Max Heap

    // pq.push(1);
    // pq.push(20);
    // pq.push(0);
    // pq.push(2);
    // pq.push(11);

    // top element -> largest
    // cout<<pq.top()<<endl;
    
    //delete element-> it will delete the top element
    // pq.pop();

    //accessing all elements
    // while(!pq.empty()){
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }


    priority_queue<int,vector<int>,greater<int>>pq ; // Min Heap 
    pq.push(1);
    pq.push(20);
    pq.push(0);
    pq.push(2);
    pq.push(11);

     // top element -> smallest
    cout<<pq.top()<<endl;

    //delete element-> it will delete the top element
    pq.pop();
     
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
 

}