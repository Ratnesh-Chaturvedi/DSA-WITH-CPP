// largest and second largest number in an array
int SEClargest(vector<int>&arr,int n){
    int largest=arr[0];
    int secL=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secL=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>secL){
            secL=arr[i];
        }
    }
    return secL;
}
int SECsmallest(vector<int>&arr,int n){
    int smallest=arr[0];
    int secS=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            secS=smallest;
            smallest=arr[i];
        }
        else if(arr[i]!=smallest && arr[i]<secS){
            secS=arr[i];
        }
    }
    return secS;

}



vector<int> getSecondOrderElements(int n, vector<int> arr) {
   int Ssmallest=SECsmallest(arr,n);
   int Slargest=SEClargest(arr,n);
    return {Slargest,Ssmallest} ;
}
