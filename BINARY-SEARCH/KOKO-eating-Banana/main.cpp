 Koko Eating Bananas

 Problem statement
A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.


Example:

Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7

Output: 3

Explanation: If ‘m’ = 3, then 
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 2 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 3 hour.
Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.

#include <bits/stdc++.h>

int calculateTotalHour(vector<int>&v,int mid){
   long long  totalHour=0;
    int n=v.size(); 
    for(int i=0;i<n;i++){
        totalHour+=ceil((double)v[i]/(double)mid);
    }
    return totalHour;

}


int maxElem(vector<int>& v){
    int maxi=INT_MIN;
      int n=v.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,v[i]);
    }
    return maxi;
}

int minimumRateToEatBananas(vector<int> v, int h) {
   int n=v.size();
  
  //optimised
// sort(v.begin(),v.end());  // for finding maximum
// another method to find maximum write the function
  long long low=1;
//   int high=v[n-1];
long long  high=maxElem(v);
  while(low<=high){
      long long mid=low+(high-low)/2;
      long long totalhour= calculateTotalHour( v, mid);
      if(totalhour<=h) high=mid-1;
      else low=mid+1;

  }
  return low;
}