
/*
Problem statement
You are given an array 'a' of 'n' integers.
A majority element in the array ‘a’ is an element that appears more than 'n' / 2 times.
Find the majority element of the array.
It is guaranteed that the array 'a' always has a majority element.
Example:
Input: ‘n’ = 9, ‘a’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]
Output: 1
Explanation: The frequency of ‘1’ is 5, which is greater than 9 / 2.
Hence ‘1’ is the majority element.
*/

//Brute force 
//TC-O(n^2);

int majorityElement(vector<int> v) {
	int n=v.size();
	// sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
			if(v[i]==v[j]){
				freq++;
			}
		}
		if(freq>n/2){
			return v[i];
		}		
	}
return -1;

	



//better Approach
//TC- O(nlogn)  SC-O(n)

// using hashing

int n=v.size();
map<int,int>hash;
for(int i=0;i<n;i++){
	hash[v[i]]++;
}
for( auto &[key,value]:hash){
	if(value>n/2){
		return key;
	}
}

return -1;



//Optimised -Moore voting algorithm
//TC- O(n) 
int n=v.size();
int count=0;
int elem;
for(int i=0;i<n;i++){
	if(count==0){
		count=1;
		elem=v[i];
	}
	else if(v[i]==elem){
		count++;
	}
	else count--;
}

int counter=0;
for(int i=0;i<n;i++){
	if(v[i]==elem) counter++;
}
if(counter>n/2) return elem;
return -1;
