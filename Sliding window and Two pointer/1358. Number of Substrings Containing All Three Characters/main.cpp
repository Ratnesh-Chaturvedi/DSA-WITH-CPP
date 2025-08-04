// 1358. Number of Substrings Containing All Three Characters
    int numberOfSubstrings(string s) {
        int n=s.size();
        //Brute force
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         set<char>st;
    //         for(int j=i;j<n;j++){
    //             st.insert(s[j]);
    //             if(st.size()==3){
    //                 cnt++;
    //             }
    //         }
    //     }
    //     return cnt;
  
  // better 
//  int l=0,r=0,cnt=0;
//  unordered_map<char,int>hash;
//  while(r<n){
//     hash[s[r]]++;
// while(hash.size()==3){
//         hash[s[l]]--;
//         if(hash[s[l]]==0) hash.erase(s[l]);
//         l++;
//     cnt=cnt+n-(r);
//     }    
//     r++;
//  }
//  return cnt;


// optimised
int i=0;
vector<int>hash(3,-1);
int cnt=0;
while(i<n){
    hash[s[i]-'a']=i;
 if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
    int mini=min(hash[0],min(hash[1],hash[2]));
    cnt+=mini+1;
 }
 i++;
}
return cnt;
    }

