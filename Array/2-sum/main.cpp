#include <bits/stdc++.h>

string read(int n, vector<int> book, int target)
{
    // Brute force
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(book[i]+book[j]==target){
                return "YES";
             return {i,j} if we want index            
            }
        }
    }
    return "NO";

    // better approach TC-O(nlogn) SC-O(n)
map<int,int>hash;
for(int i=0;i<n;i++){
    int a=book[i];
    int more=target-a;

    if(hash.find(more)!=hash.end()){
        return "YES" ;
        // return {hash[more],i} // if we want index
    }
    hash[a]=i;
}
return "NO";

// Optimised - 2 pointer
 

sort(book.begin(),book.end());
 int i=0,j=n-1;
 while(i<j){
     int sum=book[i]+book[j];
     if(sum==target){
         return "YES" ;
         // return {i,j};
         break;
     }
     else if(sum>target){
         j--;
     }
     else i++;

 }
 return "NO";

}
