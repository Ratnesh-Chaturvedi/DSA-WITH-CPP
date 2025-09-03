Allocate Books // painter partition and split the arr largest sum   
// all 3 problem are exactly same

Problem statement
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.
Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]
Output: 113
Explanation: All possible ways to allocate the ‘4’ books to '2' students are:
12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.
12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.
12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.
We are getting the minimum in the last case.
Hence answer is ‘113’.


#include <bits/stdc++.h>

int allocatepages(vector<int>& arr ,int pages){
    int n=arr.size();
    int student=1;
    int stud_hold_pages=0;
    for(int i=0;i<n;i++){
        if(stud_hold_pages+arr[i]<=pages){ // assign pages to the student
            stud_hold_pages+=arr[i];
        }
        else {
            student++;                
            stud_hold_pages=arr[i];         // assign pages to new student
        }
    }
    return student;
}



int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    //assign max element for storing the max capacity
    int low=*max_element(arr.begin(),arr.end());
    //assign that if one student will be there he will get all the books
    int high=accumulate(arr.begin(),arr.end(),0);
    // brute force
    // for(int pages=low;pages<high;pages++){
    //     if(allocatepages(arr,pages)==m) return pages;
    // }
    // return -1;


//optimised
while(low<=high){
    int mid=(low+high)/2;
    if(allocatepages(arr,mid)>m){
    low=mid+1;
    }
    else 
        high=mid-1;
}
return low;
}
