

// 28. Find the Index of the First Occurrence in a String


class Solution {
    public:
    void lpsFind(vector<int>&lps,string s){
        
      int n=s.size();
     int pre=0,suff=1;
     while(suff<n){
        if(s[pre]==s[suff]){
            lps[suff]=pre+1;
            pre++;
            suff++;
        }
        else {
            if(pre==0){
                lps[suff]=0;
                suff++;
            }
            else{
                pre=lps[pre-1];
                
            }
        }
     }
    
    }
    
        int strStr(string haystack, string needle) {
            int n=haystack.size();
            int m=needle.size();
            if(n<m) return -1;
    //         for(int i=0;i<=n-m;i++){
    //             if(haystack.substr(i,m)==needle){
    //                 return i;
    //             }
    //         }
    //    return -1;
    
    // with using two pointer
    // int i=0,j=0,k=0; // i points haystack and j points needle and k point the index of the word first letter when the string are matched
    // while(i<n && j<m){
    //     if(haystack[i]==needle[j]){
    //         i++;
    //         j++;
    //     }
    //     else {
    //         i=k+1;
    //         j=0;
    //         k=i;
    //     }
    // }
    // if(j==m) return k;
    // else return -1;
    
    // using KMP algorithm
    //creating lps for the needle array
    vector<int>lps(m,0);
    lpsFind(lps,needle);
    
    int first=0;
    int second=0;
    while(first<n && second<m){
        if(haystack[first]==needle[second]){
            first++,second++;
        }
        else {
          if(second==0) first++;
          else second=lps[second-1];
    
        }
    }
    if(second==m) return first-second;
    else return -1;
     
    
    
        }
    };








    // geek for geeks   -> Search Pattern (KMP-Algorithm)
    // vector<int> search(string& pat, string& txt) {
    //     int n=pat.size();
    //   int m=txt.size();
      // this worked but showing TLE
//   vector<int>ans;
//             for(int i=0;i<=m-n;i++){
//                 if(txt.substr(i,n)==pat){
//                 ans.push_back(i);
//                 }
//             }
//         return ans;
// }


