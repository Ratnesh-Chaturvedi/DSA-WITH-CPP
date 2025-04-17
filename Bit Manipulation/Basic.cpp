
// Decimal to binary 
string conv2Bin(int n){
    string bin="";
    if(n==0){
        bin="0";
        return bin;
    }
    while(n>0){
    if(n%2==1) bin+='1';
    else bin+='0';
    n=n/2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

// binary to decimal
int bin2Dec(string bin){
    int num=0;
    int p2=1;
    for(int i=bin.size()-1;i>=0;i--){
        if(bin[i]=='1') {
            num+=p2;
        }
        p2=p2*2;
    }
    return num;
}

//1's complement of a binary string
string oneComplement(string s){
    string ans="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='1' ) ans+='0';
        else ans+='1';
    }
    return ans;
}


//swap two numbers without using a third variable

int a=5,b=10;;
a=a^b;
b=a^b;
a=a^b;


// check if the ith bit is set or not
// by using left shift
//n=13 and i=2 // checking the second bit // 3rd bit according to 0th based index
if( (n & (1>>i))!=0 ) return true;
else false;

// by using rightshight
if((n>>i & i)!=0) return true;
else return false;


// Set kth bit/
int setKthBit(int n, int k) {
    int ans= ( n|(1<<k));
    return ans;
   }

   // clear the ith bit
   (n&~(1<<i))

   //toggle the ith bit(1<->0) 
   (n^(1<<i))

   // remove the last set bit
   (N&(N-1))

   //check if the number is a power of 2
   bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    if(n==1) return true;
    if((n & (n-1) )==0) return true;
    else return false;
        }

        // count no of set bits
        int SetBit(int n){
            int cnt=0;
            while(n>1){
             cnt+=n&1;
             n=n>>1;
            }
            if(n==1) cnt+=1;
            return cnt;
        }

        // another method
        cnt=0;
        while(n!=0){
            n=n&(n-1);
            cnt++;
        }
