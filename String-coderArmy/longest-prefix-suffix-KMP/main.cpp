
// Longest Prefix Suffix
// brute force
int longestPrefixSuffix(string &s) {
    //
    int n=s.size();
    vector<string>prefix(n-1),suffix(n-1);
    
  for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++){
            prefix[i]+=s[j];
        }
    }
    
     for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            suffix[i]+=s[j];
        }
        reverse(suffix[i].begin(),suffix[i].end());
    }
    reverse(suffix.begin(),suffix.end());
    
    int len=0;
    for(long long  i=0;i<=n-1;i++){
        for(long long  j=0;j<=n-1;j++){
            if(prefix[i]==suffix[j]){
              int size=suffix[j].size();
                len=max(size,len);
            }
        }
    }
    return len;
    
}

// according to bhaiye i made the solution  -- But it is still Show TLE -- TC-O(n^2)
int longestPrefixSuffix(string &s) {
    //
    int n=s.size();
    string prefix,suffix;
    int i=0,j=n-1;
    int len=0;
    while(i<n-1 && j>=1){
        prefix.push_back(s[i]);
        suffix.insert(suffix.begin(),(s[j]));
      
        if(prefix==suffix){
            len=max(len,i+1);
        }
        i++;
        j--;
    }
    
    return len;

}




// optimal solution BY USING KMP ALGORITHM
// TC-O(n)
//SC-O(n)

int longestPrefixSuffix(string &s) {

    int n=s.size();
   vector<int>lps(n,0);
   
   int pre=0,suff=1;
   
   while(suff<n){
       if(s[pre]==s[suff]){
           lps[suff]=pre+1;
           suff++;
           pre++;
       }
       else{
           if(pre==0){
               lps[suff]=0;
               suff++;
           }
           else {
               pre=lps[pre-1];
           }
       }
   }
   return lps[n-1];
    
}