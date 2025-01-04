Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.

A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.

Note: The floor function returns the number rounded down to the nearest integer.

Note: Return the array of majority elements in sorted order.

Example:
Input: ‘N’ = 9 ‘A’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

Output: 1

Explanation: The frequency of ‘1’ is 5, which is greater than floor(N / 3), hence ‘1’ is the majority element.


vector<int> majorityElement(vector<int> v) {
	int n=v.size();

	// brute force

	vector<int>ans;
for(int i=0;i<n;i++){
	if(ans.size()==0 || ans[0]!=v[i]){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(v[j]==v[i])cnt++;
		}
		if(cnt>(n/3)) ans.push_back(v[i]);
	}
	if(ans.size()==2) break;
}
return ans;



// Better Approach
 vector<int>ans;
	unordered_map<int,int>hash;
	int minimum=(n/3)+1;
	for(int i=0;i<n;i++){
		hash[v[i]]++;
		if(hash[v[i]]==minimum){
			ans.push_back(v[i]);
		}
	}
	return ans;



// Optimised apporach same as n/2 majority element 
// moore's voting algo
int count1=0,count2=0;
int el1=INT_MIN,el2=INT_MIN;
for(int i=0;i<n;i++){
	if(count1==0 && v[i]!=el2){
		count1=1;
		el1=v[i];
	}
	else if(count2==0 && v[i]!=el1){
		count2=1;
		el2=v[i];
	}
	else if(el1==v[i])count1++;
	else if(el2==v[i])count2++;
	else {
		count1--;
		count2--;
	}
}

vector<int>ans;
count1=0;
count2=0;
for(int i=0;i<n;i++){
	if(el1==v[i]) count1++;
	if(el2==v[i]) count2++;
}
int minimum=(int)(n/3+1);
if(count1>=minimum) ans.push_back(el1);
if(count2>=minimum) ans.push_back(el2);
sort(ans.begin(),ans.end());
return ans;





}
