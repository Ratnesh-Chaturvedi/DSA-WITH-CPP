Missing And Repeating Numbers
Problem statement
You are given an array of ‘N’ integers where each integer value is between ‘1’ and ‘N’. Each integer appears exactly once except for ‘P’, which appears exactly twice, and ‘Q’, which is missing.
Your task is to find ‘P’ and ‘Q’ and return them respectively.

Sample Input 1:
4
1 2 3 2
Sample Output 1:
2 4

#include <bits/stdc++.h>


vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // int n=a.size();


    //better solution
  int hasharr[n+1]={0};
    int rep=-1;
    int mis=-1;
    for(int i=0;i<n;i++){
        hasharr[a[i]]++;
    }
    for(int i=1;i<n+1;i++){
         if(hasharr[i]==0){
            mis=i;
        }
        if (hasharr[i] == 2) {
            rep = i;
        }
            if(rep!=-1 && mis!=-1) break;
    }
return {rep,mis};


// optimal solution by using math
long long n=a.size();
// S-SN // x-y;
//S^2 - Sn^2 // x^2 - y^2   
long long Sn=(n*(n+1))/2;
long long S2n=(n*(n+1)*(2*n+1))/6;

long long S=0,S2=0;
for(int i=0;i<n;i++){
    S+=a[i];
    S2+=a[i]*a[i];
}

long long val1=S-Sn; // equation 1 // x-y
long long val2=S2-S2n;// equation 2 // x2 -y2 
val2=val2/val1;
long long x=(val1+val2)/2;
long long y=x-val1;

return {(int)x ,(int)y};



// another solution by using xor- bit manupulation 





}