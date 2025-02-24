#include <bits/stdc++.h>
using namespace std;

// int main(){
    // char arr[8]={'r','a','t','n','e','s','h'};
    // char arr[10];
    // cin>>arr;
    // cout<<arr;


///Declaring String 

// string s;
// cin>>s; // this will now take the words after a space 
// getline(cin,s);


//concate two string;
// string s1="ratnesh" ,s2="chaturvedi",s3=s1+s2;
// also use s3=s1.append(s2);
// cout<<s3;
//adding more content 
// s3.push_back('p');
// cout<<s3; 


// string s="ratnesh is \"good \" "; 
// string s2="\\";
// cout<<s<<s2;

// string s="ratnesh";
//reverse the string
//method 1 
// reverse(s.begin(),s.end());
//method 2
// for(int i=s.size()-1;i>=0;i--){
//     cout<<s[i];
// }

// calculating size of string without size();

// int i=0;
// int size=0;
// while(s[size]!='\0'){
//     size++;
//     i++;
// }
// cout<<size; 

// return 0;
// }



bool isPalindrome(string s,int st,int end){

    while(st<=end){
        if(s[st]==s[end]){
            st++,end--;
        }
        else return false;
    }

    return true;
}
int main(){
    string s="madama";
    cout<<isPalindrome(s,0,s.size()-1);
}