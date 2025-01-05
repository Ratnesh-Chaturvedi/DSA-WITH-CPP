// Three Sum


Problem statement
You are given an array ‘ARR’ containing ‘N’ integers.
Return all the unique triplets [ARR[i], ARR[j], ARR[k]] such that i != j, j != k and k != i and their sum is equal to zero.
Example:
Input: ‘N’ = 5 
'ARR' =  [-1, -1, 2, 0, 1] 

Output: 
-1 -1 2
-1 0 1
Explanation:
(-1 -1 +2) = (-1 +0 +1) = 0.


#include <bits/stdc++.h>

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    //Brute force
   set<vector<int>>St;
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           for(int k=j+1;k<n;k++){
               if(arr[i]+arr[j]+arr[k]==0){
                   vector<int>temp={arr[i],arr[j],arr[k]};
                   sort(temp.begin(),temp.end());
                   St.insert(temp);
               }
           }
       }
   }
   vector<vector<int>>ans(St.begin(),St.end());
   return ans;

//Better Approach -- Using hashing to find that third element in hash and if present it return it into the answer

set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hashset;
    for(int j=i+1;j<n;j++){
        int third=-(arr[i]+arr[j]);
        if(hashset.find(third)!=hashset.end()){
            vector<int>temp={arr[i],arr[j],third};
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        hashset.insert(arr[j]);
    }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;


// Optimised Approach -- 2 pointer Approach

sort(arr.begin(),arr.end());
vector<vector<int>>ans;
for(int i=0;i<n;i++){
    if (i>0 && arr[i]==arr[i-1]) continue;
    int j=i+1;
    int k=n-1;
while(j<k){
    int sum=arr[i]+arr[j]+arr[k];
    if(sum>0){
        k--;
    }
    else if(sum < 0) j++;
    else {
        vector<int>temp={arr[i],arr[j],arr[k]};
        ans.push_back(temp);
        j++;
        k--;
    while(j<k && arr[j]==arr[j+1]) j++;
    while(j<k && arr[k] == arr[k+1] ) k--;
    }
}
}

return ans;

}
