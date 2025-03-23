// Min Chars to Add for Palindrome

//My Brute Force - O(n^2)

bool isPalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]==s[j]){
            i++,j--;
        }
        else {
            return false;
        }
    }
    return true;
}
 int minChar(string& s) {
string ans=s;
string temp;
int n=s.size();
int size=n;
int mini=INT_MAX;

for(int i=0;i<n-1;i++){
    if(size<=0) break;
    if(isPalindrome(ans)==true){
        break;
    }
    else {
        char ch=s[size-1];
        temp=temp+ch;
        ans=temp+ans;
        size--;
    }
}
return abs(n-size);
 }


 // optimised by using KMP

 int lpsFind(string s){
    vector<int>lps(s.size(),0);
    int pre=0,suff=1;
    while(suff<s.size()){
        if(s[pre]==s[suff]){
            lps[suff]=pre+1;
            pre++;
            suff++;
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
    return lps[s.size()-1];
}

   
  
    int minChar(string& s) {
        int n=s.size();
    string temp=s;
    char ch='$';
    reverse(temp.begin(),temp.end());
    temp=s+ch+temp;
    int lps=lpsFind(temp);
   return n-lps;
}


