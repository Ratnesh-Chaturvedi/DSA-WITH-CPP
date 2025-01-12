//  Implement Lower Bound
// Problem statement
// You are given an array 'arr' sorted in non-decreasing order and a number 'x'. You must return the index of the lower bound of 'x'.

// Note:
// 1. For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 'arr[idx]' is not less than 'x'.If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', where 'n' is the size of array.
// 2. Try to do this in O(log(n)).
// Example:
// Input: ‘arr’ = [1, 2, 2, 3] and 'x' = 0
// Output: 0


int lowerBound(vector<int> arr, int n, int x) {
	int ans=n;
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>=x) {
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;

    // c++ stl 
	int ans=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
	return ans;
}


//  Implement Upper Bound
// Problem statement
// You are given a sorted array ‘arr’ containing ‘n’ integers and an integer ‘x’.Implement the ‘upper bound’ function to find the index of the upper bound of 'x' in the array.
// Note:
// 1. The upper bound in a sorted array is the index of the first value that is greater than a given value. 
// 2. If the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.
// 3. Try to write a solution that runs in log(n) time complexity.
// Example:
// Input : ‘arr’ = {2,4,6,7} and ‘x’ = 5,
// Output: 2
// Explanation: The upper bound of 5 is 6 in the given array, which is at index 2 (0-indexed).

int upperBound(vector<int> &arr, int x, int n){
	int ans=n;
	int low=0,high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>x){
			ans=mid;
			
			high=mid-1;
		}
		else low=mid+1;
	}	
	return ans;
// c++ stl 
int ans=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
return ans;

	}


    //  Ceil The Floor

    Problem statement
You're given a sorted array 'a' of 'n' integers and an integer 'x'.
Find the floor and ceiling of 'x' in 'a[0..n-1]'.
Note:
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.
Example:
Input: 
n=6, x=5, a=[3, 4, 7, 8, 8, 10]   
Output:
4
Explanation:
The floor and ceiling of 'x' = 5 are 4 and 7, respectively.

Sample Input 1 :
6 8
3 4 4 7 8 10
Sample Output 1 :
8 8
Explanation of sample input 1 :
Since x = 8 is present in the array, it will be both floor and ceiling.

int ceil(vector<int> &a, int n, int x){
	int ans=-1;
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(a[mid]>=x){
			ans=a[mid];
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;
}

int floor(vector<int> &a, int n, int x){
	int ans=-1;
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
                if (a[mid] <= x) {
                  ans = a[mid];
                  low = mid + 1;
                } else
                  high = mid - 1;
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {

int c=ceil(a,  n,  x);
int f=floor(a,  n,  x);
return {f,c};
}