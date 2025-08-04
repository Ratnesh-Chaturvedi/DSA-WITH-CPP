// 76 Minimum Window Substring

// brute 
 string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        int n=s.size(),m=t.size();
        //brute force
        int startIdx=-1;
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            unordered_map<char,int>hash;
        int cnt=0;
            for(int j=0;j<m;j++){
             hash[t[j]]++;
            }
            for(int j=i;j<n;j++){
                if(hash[s[j]]>0) cnt++;
                hash[s[j]]--;
                if(cnt==m){
                    if(len>j-i+1){
                        len=j-i+1;
                        startIdx=i;
                    }
                }
            }
        }
        return startIdx==-1?"":s.substr(startIdx,len);
    }

// optimised
 string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        int n=s.size(),m=t.size();
        //optimised
        int startIdx=-1;
        int len=INT_MAX;
        unordered_map<char,int>hash;
         int r=0,l=0;
         int cnt=0;
         for(int i=0;i<m;i++){
            hash[t[i]]++;
         }
         while(r<n){
         if(hash[s[r]]>0) cnt++;
         hash[s[r]]--;
        
        while(cnt==m){
            if(len>r-l+1){
            startIdx=l;
            }
            len=min(len,r-l+1);
            hash[s[l]]++;
            if(hash[s[l]]>0) cnt--;
            l++;
        }
        r++;
         }

        return startIdx==-1?"":s.substr(startIdx,len);
    }