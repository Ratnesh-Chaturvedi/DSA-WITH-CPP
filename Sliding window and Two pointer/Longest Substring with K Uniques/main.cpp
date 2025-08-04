
// Longest Substring with K Uniques
int longestKSubstr(string &s, int k) {
       int len=-1;
       unordered_map<char,int>mpp;
       int l=0,r=0;
       int n=s.size();
       while(r<n){
           mpp[s[r]]++;
           if(mpp.size()>k){
               mpp[s[l]]--;
               if(mpp[s[l]]==0) mpp.erase(s[l]);
               l++;
           }
           if(mpp.size()==k)
           len=max(len,r-l+1);
           r++;
       }
      
        return len;
    }

    