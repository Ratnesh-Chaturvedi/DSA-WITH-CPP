#include <bits/stdc++.h>
using namespace std;

// void printname(int n){
//     if(n==0) return;
//     cout<<"ratnesh"<<endl;
//     n--;
//     printname(n);
// }

// print from 1 to N
void print(int n){
    if(n<1) return;
    cout<<n<<endl;
    print(n-1); 
}


// sum of first n terms
//parametried way
int sum(int i,int s){
    
    if(i<0) return s;
    sum(i-1,s+i);
}
//functional way
 int sum2(int n){
    if(n==0) return 0;
    return n+sum2(n-1);
 }

 //factorial of n
 int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
 }

 //reverse array
 void reverse(int i,int j,vector<int>&arr){
   if(i>=j) return;
   swap(arr[i],arr[j]);
   reverse(i+1,j-1,arr);   
 }
 // with one pointer
 void reverse2(int i,int n,vector<int>&arr){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverse2(i+1,n,arr);
 }

 // check the string is palindrome or not
 bool palindrome(int i,int n,string s){
    if(i>=n/2) return true;
    if(s[i]==s[n-i-1]){
        return  palindrome(i+1,n,s);
    }
    else return false;
   
 }

 // nth fibonachi number
 int fibonachi(int n){
    if(n<=1) return n;
    return fibonachi(n-1)+fibonachi(n-2);
 }
int main(){
    
    cout<<fibonachi(6);
}