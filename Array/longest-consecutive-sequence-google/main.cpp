// There is an integer array ‘A’ of size ‘N’.
// A sequence is successive when the adjacent elements of the sequence have a difference of 1.
// You must return the length of the longest successive sequence.
// Note:
// You can reorder the array to form a sequence. 
// For example,
// Input:
// A = [5, 8, 3, 2, 1, 4], N = 6
// Output:
// 5
// Explanation: 
// The resultant sequence can be 1, 2, 3, 4, 5.    
// The length of the sequence is 5.




// linear search for brute force solution;
bool LS(vector<int>&a,int target){
    for(int i=0;i<a.size();i++){
        if(a[i]==target){
            return true;
        }
        
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    // brute force
    int longest=1;
    for(int i=0;i<a.size();i++){
        int count =1;
        int x=a[i];
        while (LS(a, x + 1) == true) {
          count++;
          x++;
        }
        longest=max(longest,count);
    }
    
    return longest;


    // better solution
sort(a.begin(),a.end());
int n=a.size();
int lastSmall=INT_MIN;
int count=0;
int longest=1;
for(int i=0;i<n;i++){
    if(a[i]-1==lastSmall){
        count++;
        lastSmall=a[i];
    }
    else if(a[i]!=lastSmall){
        count=1;
        lastSmall=a[i];
    }
    longest=max(longest,count);
}
return  longest;


// Optimised Approach

int n=a.size();
unordered_set<int>st;
int longest=1;
if(n==0) return 0;
for(int i=0;i<n;i++){
    st.insert(a[i]);
}

for(auto it:st){
    if(st.find(it-1)==st.end()){
    int cnt=1;
    int x=it;

    while(st.find(x+1)!=st.end()){
        cnt++;
        x=x+1;;
    }
    longest=max(longest,cnt);
    }
}

return longest;




}