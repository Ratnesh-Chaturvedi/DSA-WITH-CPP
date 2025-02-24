// 415. Add Strings
string addStrings(string num1, string num2) {
    int i=num1.size()-1;
    int j=num2.size()-1;
    int carry=0;
    int sum=0;
    string ans;
    if(i < j) return addStrings(num2,num1); // if num2.size()>num1.size()

    while(j>=0){
      sum=(num1[i]-'0') + (num2[j]-'0') + carry;
      carry=sum/10;
      char c='0'+sum%10;
      ans+=c;
      j--;
      i--;
    }

    while(i>=0){
      sum=(num1[i]-'0') + carry;
      carry=sum/10;
      char c='0'+sum%10;
      ans+=c;
      i--;
    }
    if(carry){
      ans+='1';
    }

    reverse(ans.begin(),ans.end());
    return ans;

  }


  //2785. Sort Vowels in a String
  string sortVowels(string s) {
    // string alpha;
    // for (int i = 0; i < s.size(); i++) {
    //     if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
    //         s[i] == 'u') {
    //         alpha += s[i];
    //     } else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
    //                s[i] == 'O' || s[i] == 'U')
    //         alpha += s[i];
    // }
    // sort(alpha.begin(), alpha.end());
    // string ans;
    // int idx = 0;
    // for (int i = 0; i < s.size(); i++) {
    //     if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
    //          s[i] == 'u') ||
    //         (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
    //          s[i] == 'U')) {
    //         ans += alpha[idx];
    //         idx++;
    //     } else
    //         ans += s[i];
    // }
    // return ans;
 
}




// Case-specific Sorting of Strings

string caseSort(string str, int n)
{
   string upper,lower;
   for(int i=0;i<n;i++){
       if(str[i]>='a' && str[i]<='z') lower+=str[i];
       else upper+=str[i];
   }
   sort(lower.begin(),lower.end());
   sort(upper.begin(),upper.end());
   string ans;
   int li=0;
   int ui=0;
   for(int i=0;i<n;i++){
       if(str[i]>='a' && str[i]<='z'){
          if(li<lower.size()){
             ans+=lower[li]; 
             li++;
          } 
          
       }
       else  {
           if(ui<upper.size()){
           ans+=upper[ui];
           ui++;
           }
       }
   }
   return ans;
}