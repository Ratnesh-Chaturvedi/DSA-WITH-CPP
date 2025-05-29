For ‘N’ = 4, and 
‘Arr’ = {{1, 3}, {2, 4}, {3, 5}, {6, 7}}
We can see that {1, 3} and {2, 4} overlap, so if we merge them, we get {1, 4}.
Now ‘Arr’ becomes: {{1, 4}, {3, 5}, {6, 7}}
Still, we observe that {1, 4} and {3, 5} overlap, hence we merge them into {1, 5}.
Hence, ‘Arr’ becomes {{1, 5}, {6, 7}}.

Sample Input 1:
9
1 2
1 3
1 6
3 4
4 4
4 5
5 5
6 6
6 6
Sample Output 1 :
1 6
Explanation Of Sample Input 1:
Arr after each merge
{{1, 2}, {1, 3}, {1, 6}, {3, 4}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}}
{{1, 3}, {1, 6}, {3, 4}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}}
{{1, 6}, {3, 4}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}}
{{1, 6}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}}
{{1, 6}, {4, 5}, {5, 5}, {6, 6}, {6, 6}}
{{1, 6}, {5, 5}, {6, 6}, {6, 6}}
{{1, 6}, {6, 6}, {6, 6}}
{{1, 6}, {6, 6}}
{{1, 6}}


#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	int n=arr.size();
	sort(arr.begin(),arr.end());
vector<vector<int>>ans;
	// brute force 
    for(int i=0;i<n;i++){
		int start=arr[i][0];
		int end=arr[i][1];
		if(!ans.empty() && end<=ans.back()[1]){
			continue;
		}
		for(int j=i+1;j<n;j++){
			if(arr[j][0]<=end){
				end=max(end,arr[j][1]);
			}
			else break;
		}
		ans.push_back({start,end});
	}


// Optimised

for(int i=0;i<n;i++){
	if(ans.empty() || arr[i][0]>ans.back()[1]){
		ans.push_back(arr[i]);
	}
	else {
		ans.back()[1]=max(ans.back()[1],arr[i][1]);
	}
}
	return ans;
	
}