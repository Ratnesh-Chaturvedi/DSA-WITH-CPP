// 12. Integer to Roman
string intToRoman(int num) {
    vector<pair<int,string>>sample={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};

    string ans="";
    for(int i=0;i<sample.size();i++){
      while(num>=sample[i].first){
        ans+=sample[i].second;
        num-=sample[i].first;
      }
    }
    return ans;
}


//13. Roman to Integer

int num(char s){
    
    if(s=='I') return 1;
    else if(s=='V') return 5;
    else if(s=='X') return 10;
   else if(s=='L') return 50;
    else if(s=='C') return 100;
   else  if(s=='D') return 500;
 else if(s=='M') return 1000;
 else return 0;
      

        
}
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        int idx=0;
        while(idx<n-1){
          if((num(s[idx]) < num(s[idx+1]) ) ){
             ans-=  num(s[idx]);   
          }
          else {
            ans+=num(s[idx]);
          }
          idx++;
         }
         ans+=num(s[n-1]);
         return ans;
    }


    // Factorials of large numbers
    vector<int> factorial(int n) {
        vector<int>ans(1,1);
        while(n>1){
            int carry=0,res,size=ans.size();
            for(int i=0;i<size;i++){
                res=ans[i]*n+carry;
                carry=res/10;
                ans[i]=res%10;
            }
            while(carry){
            ans.push_back(carry%10);
            carry/=10;
            }
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }