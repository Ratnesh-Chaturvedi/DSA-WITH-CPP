

// 3. Longest Substring Without Repeating Characters




class Solution {
    public:
    bool present(string s,char c){
        int n=s.size();
        if(n==0) return false;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                return true;
            }
        }
        return false;
    }
        int lengthOfLongestSubstring(string s) {
            int n=s.size();
    
    //Better Approach
    
            // int maxsize=0;
            // for(int i=0;i<n;i++){
            //    string str;    
            //    int cnt=0;
            //    for(int j=i;j<n;j++){
            //     if(present(str,s[j])==false){
            //         cnt++;
            //         str+=s[j];
            //     }
            //    else break;
            //    }
            //    maxsize=max(cnt,maxsize);
            // }
            // return maxsize;

    
            //Optimal Approach -By using Sliding window
    
            int i=0;
            int j=0;
            int cnt=0;
            vector<bool>Arr(256,0);
            while(j<n){
                while(Arr[s[j]]){       // run until the repeating element is 1;
                Arr[s[i]]=0;
                i++;
                }
                Arr[s[j]]=1;
                cnt=max(cnt,j-i+1);
                j++;
            }
    
            return cnt;
    
        }
    };



    // Smallest distinct window
    int findSubString(string& s) {
        int n=s.size();
       vector<int>uniqueEl(256,0);
       int len=n,i=0,j=0,diff=0;
       
       while(i<n){
           if(uniqueEl[s[i]]==0){
               diff++;
           }
           uniqueEl[s[i]]++;
           i++;
       }
       i=0;
       
       // ye loop isliye taki wapis se wo array ke sabhi el zero ho jaye 
       for(int i=0;i<256;i++){
           uniqueEl[i]=0;
       }
       
       while(j<n){
           
           // diff jab tak exist karega ie jab tak zero nahi hoga
           while(diff && j<n){
               if(uniqueEl[s[j]]==0)
               diff--;
               uniqueEl[s[j]]++;
               j++;
           }
           len=min(len,j-i);
           
           // diff ke value 1 na bna jaye
           while(diff!=1){
              len=min(len,j-i);
               uniqueEl[s[i]]--;
              if(uniqueEl[s[i]]==0)
              diff++;
              i++;
           }
       }
       return len;   
             
     }