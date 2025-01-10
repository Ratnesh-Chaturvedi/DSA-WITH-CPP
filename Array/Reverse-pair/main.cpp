Problem statement
School is organizing a team contest. You are given an array ‘SKILL’ containing the skill level of ‘N’ candidates.



Two candidates(having index ‘i’ and ‘j’) can pair up to form a team if for index i < j, SKILL[i] > 2*SKILL[j].

Your task is the return the count of all the possible pairs to take part in the contest.



Example:
Input: ‘N’ = 5
‘SKILL’ = [4, 1, 2, 3, 1] 

Output: 3
Explanation:
Possible pairs are (4,1), (4,1), (3,1).


Sample Input 1:
5
4 1 2 3 1
Sample Output 1 :
3
Explanation Of Sample Input 1:
Possible pairs are (4,1), (4,1), and (3,1).
Sample Input 2:
4 
100 49 201 100
Sample Output 2 :
2




void  merge(vector<int>&a,int st,int end,int mid){
    int i=st,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
              temp.push_back(a[j]);
            j++;
        } 
    }
    while(i<=mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(a[j]);
        j++;

    }
    for(int idx=0;idx<temp.size();idx++){
        a[idx+st]=temp[idx];
    }
}

// function for counting pairs

int countPair(vector<int>a,int low,int mid,int high){
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && a[i]>2*a[right]) right++; 
        cnt+=right-(mid+1);
    }
    return cnt;
}


int mergeSort(vector<int>&a,int st,int end){
    int cnt=0;
    if(st<end){
        int mid=st+(end-st)/2;
cnt+=mergeSort(a,st,mid);
cnt+=mergeSort(a,mid+1,end);
cnt+=countPair(a,st,mid,end);
merge(a,st,end,mid);
    }
    return cnt;
}


int team(vector <int> & skill, int n)
{
    //Brute force
    // int cnt=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if((skill[i])>2*skill[j]){
    //             cnt++;
    //         }
    //     }
    // }
    // return cnt;


    //Optimal approach by using merge sort 
   int cnt= mergeSort(skill,0,n-1);
   return cnt;
}
