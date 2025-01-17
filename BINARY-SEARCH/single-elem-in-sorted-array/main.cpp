 Single Element in a Sorted Array
Problem statement
You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.
Return the number that appears once.
Example:
Input: 'arr' = [1,1,2,2,4,5,5]
Output: 4 
Explanation: 
Number 4 only appears once the array.
Note :
Exactly one number in the array 'arr' appears once.


int singleNonDuplicate(vector<int>& arr)
{
int n=arr.size();
	//My solution
int ans;
for(int i=0;i<n;i++){
	ans=ans^arr[i];
}
return ans;

// brute force

if(n==1 ) return arr[0];

for(int i=0;i<n;i++){
	if(i==0) {
		if(arr[i]!=arr[i+1]) return arr[i];
	}
	else if(i==n-1){
		if(arr[n-1]!=arr[n-2]) return arr[n-1];
	}
	else 
	{
		if(arr[i-1]!=arr[i] && arr[i]!=arr[i+1]) return arr[i];
	}
}

// optimised

if(n==1) return arr[0];
if(arr[0]!=arr[1]) return arr[0]; // for reducing low by one step
if(arr[n-1]!=arr[n-2]) return arr[n-1]; // for reducing hingh by one step
int low=1;
int high=n-2;
while(low<=high){
	int mid=low+(high-low)/2;
	if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
     
// 	 // we are on the left half
	else if( (mid%2==0 && arr[mid]==arr[mid+1] ) || (mid%2==1 && arr[mid]==arr[mid-1])){
		low=mid+1; // eliminate the left half
	}

	else high=mid-1; // eliminate the right half
}
return -1;

}