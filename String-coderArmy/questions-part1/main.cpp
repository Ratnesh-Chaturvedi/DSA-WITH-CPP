
//  LC-1108. Defanging an IP Address
string defangIPaddr(string address) {
    int n=address.size();
    string s;
    for(int i=0;i<n;i++){
        if(address[i]=='.'){
            s.append("[.]");
        }
        else s.push_back(address[i]);
    }
    return s;
}

// GFG- String Rotated by 2 Places
void rotateClk(string &clk){
       
    char  c1=clk[clk.size()-1];
     long long index=clk.size()-2;
     while(index>=0){
         clk[index+1]=clk[index];
         index--;
     }
     clk[0]=c1;
  }
  
  void rotateAclk(string &anticlk){
      char c1=anticlk[0];
      long long index=1,size=anticlk.size();
      while(index<size){
          anticlk[index-1]=anticlk[index];
          index++;
      }
      anticlk[size-1]=c1;
  }
  
  
   bool isRotated(string& s1, string& s2) {
      string clk=s1,anticlk=s1;
   
rotateClk(clk);
rotateClk(clk);

      if(clk==s2){
          return true;
      } 
rotateAclk(anticlk);
rotateAclk(anticlk);

       if(anticlk==s2){
          return true;
      } 
      return false;
   }

//    lC- 1832. Check if the Sentence Is Pangram
bool checkIfPangram(string sentence) {
    // set<char>s;
    // for(int i=0;i<sentence.size();i++){
    //     s.insert(sentence[i]);
    // } 
    // if(s.size()==26) return true;
    // return false;

    // method  2
    vector<bool>alpha(26,0);
    for(int i=0;i<sentence.size();i++){
        alpha[sentence[i]-'a']=1;
    }
    for(int i=0;i<26;i++){
        if(alpha[i]==0) return false;
    }
    return true;
}


//GFG-Sort a String
string sort(string s){
    
    // sort(s.begin(),s.end());
    // return s;
    
    // solved in O(n)
    vector<int>a(26,0);
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    // string ans; without using this string 
    s="";
    for(int i=0;i<26;i++){
        int n=a[i];
        while(n--){
            s+=char(i+97); // 'a'+i
        }
    }
    return s;
}



