// count number of digits 
// Brute force TC- log10(n)  
int cntDigit(int n){
    int cnt=0;
    while(n){
        cnt++;
        n/=10;
    }
    return  cnt;
}

// Optimal way - By usign log
int cnt=(int)(log10(n)+1);


//Print ALl Divisors
//Brute Force

for(int i=1;i<=n;i++){
    if(n%i==0) cout<<i;
}


// By Observation 
for(int i=1;i*i<=n;i++){
    if(n%i==0){
         cout<<i;
         if((n%i)!=i) cout<<i;
    }
}



//Gcd Or Hcf
//Brute force
gcd=1;
for(int i=1;i<=min(n1,n2);i++){
    if(n1%i==0 && n2%i==0) gcd=i;
}
//   or 
for(int i=min(n1,n2) ;i>=1;i++){
    if(n1%i==0 && n2%i==0) {
    gcd=i;
    break;
    }
}


//    Euclidean Algorithm - greateer%smaller and go till one of them become zero other is gcd 
int gcd(int a,int b){
    while(a>0 and b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    else return a;
}




//Prime Numbers
//check if it is prime 
//Brute force

//Prime Number only has 2 divisors

int cnt=0;
for(int i=1;i<=n;i++){
    if(n%i==0) cnt++;
}
if(cnt==2) cout<<"Yes";
else cout<<"No";

// another way
for(int i=1;i*i<=n;i++){
    if(n%i==0) {
        cnt++;
        if(n%i !=i) cnt++;
    }
    if(cnt>2) break;
}
if(cnt==2) cout<"y";
cout<<"N";

// Prime factors of a given number 

for(int i=2;i*i<n;i++){
    if(n%i==0) {
        if(isPrime(i)) ans.push_back(i);
        if(n%i!=i){
            if(isPrime(i)) ans.push_back(i);
        }
    }
}

//Optimised
//TC-O(n^1/2 + logn) 
for(int i=2;i*i<=n;i++){
       if(n%i==0){
        ans.push_back(i);
        while(n%i==0) n=n/i;
       }
}
if(n!=1) ans.push_back(n) ; // when the number itself is prime


// Power Exponentiation 
// x=2 , n=5  // 2^5=32
// stl -> pow(2,5)

//Another way
// optimal way 
//TC-O(log2N)
func(x,n){
    // m=n; ->when n is negative
    ans=1; // if x is double make initialize ans as double
    while(n>0){
        if(n%2==1){
ans=ans*x;
n=n-1;
        }
        else {
            n=n/2;
            x=x*x;
        }
    }
    // if(m<0) ans=1/ans;  //when n is negative
    return ans;
}


// Sieve of Eratosthenes - print all the prime number till a number 
int n;
vector<bool>arr(n+1,true);
//it is the solution which is accepted on Leetcode
// for(int i=2;i<=n;i++){
//     if(arr[i]){
//         for(int j=i*2;j<=n;j+=i){
//             arr[j]=false;
//         }
//     }
// }

// some optimisation
// TC- O(Nlog(LogN))
for(int i=2;i*i<=n;i++){
    if(arr[i]){
        for(int j=i*i;j<=n;j+=i){
            arr[i]=false;
        }
    }
}

// Count Prime in a range L-R-- Query based question

// brute force
// printing the number of prime between a range 
// if there are n queries
//TC-O(Q*(R-l+1)*N^1/2)
function(vector<vector<int>>queries){
    int q=queries.size();
    for(int i=0;i<q;i++){
        int left=q[i][0] ,right=q[i][1];
        int cnt=0;
        for(int i=left;i<=right;i++){
            if(isPrime(i)) cnt++;
        }
        cout<<cnt;
    }
}


// better  usign seive

function(vector<vector<int>>queries){
   seive(N) // where n is size limit
    for(int i=0;i<q;i++){
        int left=q[i][0] ,right=q[i][1];
        int cnt=0;
        for(int i=left;i<=right;i++){
            if(seive(i)) cnt++;
        }
        cout<<cnt;
    }
}
 

// optimal solution
// By using prefix sum
// TC-(Nlog(logN) + N + Q.size())
vector<int> seive(int n){
    vector<int>arr(n+1,1);
    for(int i=2;i*i<=n;i++){
        if(arr[i]){
            for(int j=i*i;j<=n;j+=i){
                arr[i]=0;
            }
        }
    }
    return arr;
}
// here we assume n=10^6
function(vector<vector<int>>queries){
   vector<int>prime=Sieve(1000000);
   int cnt=0;
     for(int i=0;i<1000000;i++){
        cnbt+=prime[i];
        prime[i]=cnt;
     }
     for(int i=0;i<queries.size();i++){
        int l=queries[i][0] ,r=queries[i][1];
        cout<<(prime[r]-prime[l-1]);
     }
 }


//  Smallest Prime Factor (SPF) | Prime Factorisation
//brute force
//TC-O(Q * N^1/2)
int primeFactor(int n){
    vector<int>ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
         ans.push_back(i);
         while(n%i==0) n=n/i;
        }
 }
 if(n!=1) ans.push_back(n)
 return ans.size();
}
function(vector<int>queries){
  
    for(int i=0;i<queries.size();i++){
        int list=primeFactor(queries[i]);
        cout<<list;
    }
}

//optimised approach
// using smallest prime factor ->like sieve
// TC- O(Nlog(lognN) + Q*log2N)
// SC- O(N)
function(vector<int>queries){
    vector<int>spf(1000000+1);
    for(int i=1;i<=1000000;i++) spf[i]==i;

    for(int i=2;i*i<=100000;i++){
        if(spf[i]==i){
         for(int j=i*i;j<=100000;j=j+i){
            if(spf[j]==j) spf[j]=i;
         }
        }
    }


    for(int i=0;i<queries.size();i++){
        int n=queries[i];
        while(n!=1){
        cout<<spj[n];
        n=n/spj[n];
        }   
    }
}