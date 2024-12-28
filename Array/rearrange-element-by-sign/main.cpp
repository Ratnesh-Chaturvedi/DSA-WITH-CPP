

//variety 1
//Problem
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

//  Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
// Explanation:
// The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
// The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

// Brute force
int n=a.size();
vector<int>pos;
vector<int>neg;
for(int i=0;i<n;i++){
    if(a[i]>0) pos.push_back(a[i]);
    else neg.push_back(a[i]);
}
for(int i=0;i<n/2;i++){
    a[2*i]=pos[i];
    a[2*i+1]=neg[i];
}

// return a;

//optimised 
 vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        int posIdx=0,negIdx=1;
        for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans[posIdx]=arr[i];
            posIdx+=2;
        }
        else {
        ans[negIdx]=arr[i];
        negIdx+=2;
        }
        }
        return ans;
    }



    //Variety 2 - where positive!=negative so arrange the extra positive or negative element after rearranging the positve and negative element;

     
// not not optimised but for extra remaining element
int n=a.size();
vector<int>pos,neg;
for(int i=0;i<n;i++){
    if(a[i]>0){
        pos.push_back(a[i]);
    }
    else{
        neg.push_back(a[i]);
    }
}
if(pos.size()>neg.size()){
   for(int i=0;i<neg.size();i++){
       a[2*i]=pos[i];
       a[2*i+1]=neg[i];
   }
   int index=neg.size()*2;
   for(int i=neg.size();i<pos.size();i++){
       a[index]=pos[i];
       index++;
   }
}

else{
    for(int i=0;i<pos.size();i++){
        a[2*i]=pos[i];
        a[2*i+1]=neg[i];
    }
    int index=pos.size()*2;
    for(int i=pos.size();i<neg.size();i++){
        a[index]=neg[i];
        index++;
    }
}
return a;
}