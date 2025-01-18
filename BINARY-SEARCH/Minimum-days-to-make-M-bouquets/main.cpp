Problem statement
You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.
Example :
Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2

Output: 3. 

Explanation: This is because on the 3rd day: all the roses with 'arr[i]' less than equal to 3 have already bloomed, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.


Sample Input 1 :
9
1 2 1 2 7 2 2 3 1
3 2
Sample Output 1 :
3
Explanation For Sample Input 1 :
We will return 3, because:
All the roses with 'arr[i]' less than equal to 3 have already bloomed after 3 days, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.
Sample Input 2 :
4
1 1 1 1
1 1
Sample Output 2 :
1
Constraints :
1 <= n <= 10^5
1 <= arr[i] <= 10^9
1 <= k <= n
1 <= m <= 10^6

Time limit: 1 sec


#include <bits/stdc++.h>


bool PossibleDay(vector<int> &arr,int day, int k, int m){
	int cnt=0,noOfBouquet=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]<=day) {
			cnt++;
		}
		else{
			noOfBouquet+=cnt/k;
			cnt=0;
		}
	}
   noOfBouquet+=cnt/k;
   if(noOfBouquet>=m) return true;
   else return false;

}
int minOfArr(vector<int> &arr){
	int mini=INT_MAX;
	for(int i=0;i<arr.size();i++){
		mini=min(mini,arr[i]);
	}
	return mini;
}

int maxOfArr(vector<int> arr){
	int maxi=INT_MIN;
	for(int i=0;i<arr.size();i++){
		maxi=max(maxi,arr[i]);
	}
	return maxi;
}


int roseGarden(vector<int> arr, int k, int m)
{
	int n=arr.size();
	if(k*m > n) return -1;
	//brute force
	
	// for(int i=minOfArr(arr);i<=maxOfArr(arr);i++){
	// 	if(PossibleDay(arr,i,k,m)==true){
	// 		return i;
	// 	}
		
	// }

	// optimised
	int low=minOfArr(arr);
	int high=maxOfArr(arr);
	int ans=high;
	while(low<=high){
		int mid=(low+high)/2;
		if(PossibleDay(arr, mid,  k,  m)==true) {
			ans=min(ans,mid);
			high=mid-1;
		}
		else low=mid+1;
	}

return ans; // return ans ->both works

}