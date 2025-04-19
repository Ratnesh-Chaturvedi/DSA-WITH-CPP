

// 2220. Minimum Bit Flips to Convert Number
int minBitFlips(int start, int goal) {
    int ans=start^goal;
    // method 1
    int cnt=0;
    // for(int i=0;i<=31;i++){
    //     if(ans&(1<<i)) cnt++; 
    // }

    // method two
    while(ans!=0){
       int rem=ans%2;
       if(rem) cnt++;
       ans=ans/2;
    }

    return cnt;
}


//78. Subsets ->it has recursive solution also
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int subsets = 1 << n;  // Total number of subsets = 2^n


    vector<vector<int>> ans;

    for (int i = 0; i < subsets; i++) {
        vector<int> current;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                current.push_back(nums[j]);  
            }
        }
        ans.push_back(current);
    }

    return ans;
}


// Single Number-I
//Brute force -> By using the Map 

// Optimal
int Xor=0;
for(int i=0;i<n;i++) Xor=Xor^arr[i];
return Xor;



//137. Single Number II
//Brute force->By using map
//Better 
int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int bi=0;bi<=31;bi++){
      int cnt=0;
      for(int i=0;i<nums.size();i++){
          if(nums[i] & (1<<bi)) cnt++;
      }
      if(cnt%3==1) ans=ans | (1<<bi);
    }
    return ans;

  }

//   Optimal
int singleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
 for(int i=1;i<nums.size();i=i+3){
     if(nums[i]!=nums[i-1]) return nums[i-1];
 }
 return nums[nums.size()-1];
 
     }

     // Another Approach -> Most Optimal ->not intutive
     int ones=0,twos=0;
for(int i=0;i<nums.size();i++){
    ones=(ones^nums[i])&(~twos);
    twos=(twos^nums[i])&(~ones);
}
return ones;
    



// 260. Single Number III
// Optimal Approach
vector<int> singleNumber(vector<int>& nums) {
    long  xorVal=0;
    int n=nums.size();
    for(int i=0;i<n;i++) xorVal=xorVal^nums[i];
    int rightMostBit=(xorVal&(xorVal-1))^xorVal;
    int b1=0,b2=0;
    for(int i=0;i<n;i++){
     if(rightMostBit & (nums[i])) b1=b1^nums[i];
     else b2=b2^nums[i];
    }
    return {b1,b2};
 
     }


     // Xor of the number from 1 to N;
     int XorFrom1ToN(int n){
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
        else return n;
     }

     // Xor of the numbers between a range (L to R);
     int XorOfRangeLToR(int l,int r){
        return XorFrom1ToN(l-1)^XorFrom1ToN(r);
     }



     //29. Divide Two Integers
     int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        if( dividend>=0 && divisor<0) sign=false;
        else if(dividend<=0 && divisor>0) sign=false;
        long long  n= (dividend);
        long long d=(divisor);
        n=abs(n);
        d=abs(d);
        long quotient=0; 
         while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))) cnt++;
            quotient+=1<<cnt;
            n-=d<<cnt;
         }
         if(quotient==(1<<31) && sign) return INT_MAX;
         if(quotient == (1<<31) && !sign) return INT_MIN;
         return sign ? quotient:-quotient;
    }