Problem statement
You are given an array ‘NUMS’ of length ‘N’. You are also given an integer ‘TARGET’.
Return an array of all the unique quadruplets [ ‘NUMS[ a ]’, ‘NUMS[ b ]’, ‘NUMS[ c ]’, ‘NUMS[ d ]’ ] with the following conditions:
i. 0 <= a, b, c, d < ‘N’ and a, b, c, and d are distinct.
ii. NUMS[ a ] + NUMS[ b ] + NUMS[ c ] +NUMS[ d ] = TARGET

Return the array in any order.
Note:

(NUMS[ a ], NUMS[ b ], NUMS[ c ], NUMS[ d ]), (NUMS[ a ], NUMS[ d ], NUMS[ c ], NUMS[ b ]), (NUMS[ a ], NUMS[ c ], NUMS[ b ], NUMS[ d ])... all of them are treated or considered the same quadruplets.


Sample Input 1:
6 8
2 2 2 2 1 3
Sample Output 1 :
2
Explanation Of Sample Input 1:
(2+2+2+2) = (2+2+1+3) = 4.


#include "bits/stdc++.h"

vector<vector<int>> fourSum(vector<int>& a, int target) {
    int n=a.size();

//Brute force is by using 4 loops
    //Better Approach by using hashing
set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int>hashset;
            for(int k=j+1;k<n;k++){
                long long sum=a[i];
                sum+=a[j];
                sum+=a[k];
               long long forth=target-sum;
                if(hashset.find(forth)!=hashset.end()){
                    vector<int>temp={a[i],a[j],a[k],(int)forth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(a[k]);
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;


//Optimised using pointer

sort(a.begin(),a.end());
vector<vector<int>>ans;
for(int i=0;i<n;i++){
    if(i>0 && a[i]==a[i-1]) continue;
    for(int j=i+1;j<n;j++){
        if(j!=(i+1) && a[j]==a[j-1]) continue;
        int k=j+1;
        int l=n-1;
        while(k<l){
            long long sum=a[i];
                sum+=a[j];
                sum+=a[k];
                sum+=a[l];
                if(sum==target){
                    vector<int>temp={a[i],a[j],a[k],a[l]};
                    ans.push_back(temp);
                    k++;
                   while(k<l && a[k]==a[k-1]) k++;
                    while(k<l && a[l]==a[l+1]) l--;
                      l--;
               }
                else if(sum>target) l--;
                else k++;
        }
    }
}

return ans;

}