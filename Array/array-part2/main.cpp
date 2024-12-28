
// P-move all zeroes to end of array

    //brute force
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            ans.push_back(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==0)
        ans.push_back(a[i]);
    }
    return ans;
 
     //Optimised by two pointer
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
if(j==-1) return a;
    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[j],a[i]);
            j++;
        }
    }
    return a;
// 




// Merge two sorted array
// Brute force
    int n1=a.size();
    int n2=b.size();
    set<int>ansSet;
    for(int i=0;i<n1;i++){
        ansSet.insert(a[i]);
    }
      for(int i=0;i<n2;i++){
        ansSet.insert(b[i]);
    }
    vector<int>Un;
    for(auto it:ansSet){
        Un.push_back(it);
    }
return Un;



// Optimised
vector<int> mergeSortedArrays(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            i++;
        } else {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n1) {
        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < n2) {
        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    return ans;
}


// Intersection of two sorted array
// Brute force
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int>ans;
	int visited[m]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i]==arr2[j] && visited[j]==0){
				ans.push_back(arr1[i]);
				visited[j]=1;
				break;
			}
			if(arr1[i]<arr2[j]) break;
		}
	}
	return ans;
}


//Optimised - two pointer
	int i=0,j=0;
	vector<int>ans;
	while(i<n && j<m){
		if(arr1[i]>arr2[j]){
			j++;
		}
		else if(arr1[i]<arr2[j]){
			i++;
		}
		else{
			ans.push_back(arr1[i]);
			i++,j++;
		}
	}
	return ans;


// union of two sorted array
    // Brute force
    int n1=a.size();
    int n2=b.size();
    set<int>ansSet;
    for(int i=0;i<n1;i++){
        ansSet.insert(a[i]);
    }
      for(int i=0;i<n2;i++){
        ansSet.insert(b[i]);
    }
    vector<int>Un;
    for(auto it:ansSet){
        Un.push_back(it);
    }
return Un;




//optimised

vector < int > sortedArray(vector < int > a, vector < int > b) {
    vector<int>ans;
    int n1=a.size();
    int n2=b.size();
int i=0,j=0;
while(i<n1 && j<n2){
   if(a[i]<=b[j]){
       if(ans.back()!=a[i] || ans.size()==0){
           ans.push_back(a[i]);
       }
       i++;
   }
   else {
       if(ans.back()!=b[j] || ans.size()==0){
           ans.push_back(b[j]);
       }
       j++;
   }
}
while(i<n1){
    if(ans.size()==0 || ans.back()!=a[i]){
        ans.push_back(a[i]);
    }
    i++;
}
while(j<n2){
    if(ans.size()==0 || ans.back()!=b[j]){
        ans.push_back(b[j]);
    }
    j++;
}
return ans;
}