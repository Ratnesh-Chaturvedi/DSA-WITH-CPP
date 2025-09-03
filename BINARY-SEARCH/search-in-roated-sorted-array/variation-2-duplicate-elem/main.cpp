//  Search In A Rotated Sorted Array II
// Problem statement
// You are given a rotated sorted array 'a' of length 'n' and a 'key'. You need to determine if the 'key' exists in the array 'a'.
// The given sorted array is rotated from an unknown index 'x'. Such that after rotation the array became [a[x], a[x+1]...., a[n-1], a[1]..., a[x-1]], (0-based indexing). For example, if the array is [1, 2, 3, 4, 5] and x = 2 then the rotated array will be [3, 4, 5, 1, 2, 3].
// Return True if the 'key' is found in 'a'. Otherwise, return False.
// Note: Array ‘a’ may contain duplicate elements.
// Example:
// Input: a = [6, 10, 1, 3, 5], key = 3
// Output: True

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
   int n=A.size();
   int low=0;
   int high=n-1;
   while(low<=high){
       int mid=low+(high-low)/2;
       if(A[mid]==key) return true;
       // condition when low=mid=high 
       if(A[low]==A[mid] && A[mid]==A[high]){
           low++;
           high--;
           continue; // because if element are still same 
       }
       //left sorted
       if(A[low]<=A[mid]){
           if(A[low] <=key && key<= A[mid]){
               high=mid-1; // eliminate right part;
           }
           else low=mid+1; // eliminate left part;
       }
       //right sorted
       else {
           if(A[mid]<=key && key<=A[high]){
              low=mid+1; // eliminate left part;
           }
           else high=mid-1; // eliminate right part;
       }
   }
   return false;
}
