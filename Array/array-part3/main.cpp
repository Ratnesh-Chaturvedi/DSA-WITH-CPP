 

 // Missing number in the array
 // Brute force
    // for(int i=1;i<=N;i++){
    //     int flag=0;
    //     for(int j=0;j<N-1;j++){
    //         if(a[j]==i){
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==0){
    //         return i;
    //     }
    // }

    // better Approach- by using hashing
    // map<int,int>hash;
    // for(int i=0;i<N;i++){
    //     hash[a[i]]=1;
    // }
    // for(int i=1;i<N;i++){
    //     if(hash[i]==0){
    //         return i;
    //     }
    // }
    // return N;



    
    // Optimised by using Sum
//     int sum=(N*(N+1))/2;
//     int s=0;
//     for(int i=0;i<N-1;i++){
//         s+=a[i];
//     }
// return (sum-s);

//Most Optimised by Uding XOR;
//  int XOR1=0;
//  int XOR2=0;
// 
//  for(int i=0;i<N-1;i++){
//      XOR2=XOR2^a[i];
//      XOR1=XOR1^(i+1);;    
//  }
//  return (XOR1^XOR2);


//   Maximum Consecutive Ones
// optimal approach
// int freq=0;
//     int m=INT_MIN;
//     for(int i=0;i<arr.size();i++){
//         if(arr[i]==1){
//             freq++;
//         }
//         else freq=0;
//         if(m<freq)
//         m=max(m,freq);
//     }
//     return m;




// Find the single elment where other elment occur twice 
int getSingleElement(vector<int> &arr){
	// Write your code here.	
//  brute force
// int n=arr.size();
// for(int i=0;i<n;i++){
// int num=arr[i];
// int count=0;
// for(int j=0;j<n;j++){
// if(arr[j]==num){
// 	count++;
// }
// }
// if(count==1) return num;
// }


// better solution
// we can use unordered map beacause it has O(n) TC and in worst case it can be O(n^2) but it is rearly occur so we can take it as well
// the map has size n/2 +1;
//TC- O(nlog(n/2+1)) Sc-O(n/2 +1);
// int n=arr.size();
// // find max elme;
// int m=INT_MIN;
// for(int i=0;i<n;i++){
// 	m=max(m,arr[i]);
// }
// map<int,int>hash;
// for(int i=0;i<n;i++){
// 	hash[arr[i]]++;
// }
// for(int i=0;i<n;i++){
// if(hash[arr[i]]==1)
//  return arr[i];
// }
// return -1;


// optimal using XOR

int xorr=0;
for(int i=0;i<arr.size();i++){
	xorr=xorr^arr[i];
}
return xorr;
}
