// 409. Longest Palindrome

int longestPalindrome(string s) {
    vector<int>lower(26,0),upper(26,0);
    int isOdd=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z'){
            lower[s[i]-'a']++;
        }
        else upper[s[i]-'A']++;
    }
    int  n=0;

    for(int i=0;i<26;i++){
    
     if(lower[i]%2==0){
        n+=lower[i];
     }
     else {
        n+=lower[i]-1;
        isOdd=1;
        }
       if(upper[i]%2==0){
        n+=upper[i];
       }
       else {
        n+=upper[i]-1;
        isOdd=1;}
    }


return n+isOdd;
}




// 1859. Sorting the Sentence

string sortSentence(string s) {
      
    vector<string>s1(10); // bcoz given 
    int index=0;
    int cnt=0; // count numbser of words 
     string temp;
    while(index<s.size()){
      if(s[index]==' '){
        int pos=temp[temp.size()-1]-'0';// it gives the index where the word store
        temp.pop_back(); // it removes the last numberic digit
        s1[pos]=temp;// store the temp at the required given position
        temp.clear(); // clear the string to store another word
        cnt++;// count the words 
      }
      else {
          temp+=s[index];
      }
          index++;
    } 
    // again because the last place of index is out of string
    int pos=temp[temp.size()-1]-'0';// it gives the index where the word store
        temp.pop_back(); // it removes the last numberic digit
        s1[pos]=temp;// store the temp at the required given position
        temp.clear(); // clear the string to store another word
        cnt++;// count the words 
      
     for(int i=1;i<=cnt;i++){
      temp+=s1[i];
      temp+=' ';
     }
     temp.pop_back(); // because it store an extra space at last
     return temp;
  }