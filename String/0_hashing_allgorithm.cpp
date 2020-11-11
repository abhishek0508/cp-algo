// string hashing algorithm
// applications
// -> number of different substring in a string
// -> search for duplicate string in array of string
// find whether a patter matches a substring

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isMatch(string txt, string pat){
    // preprocessing text
    ll n = txt.length();
    ll pre[n] = {}, hash[n] = {};
    
    ll p = 31;
    ll m = 1000000007;
    pre[0] = txt[0];
    hash[0] = 1;

    
    for(ll i=1;i<n;i++){
        pre[i] = ((pre[i-1]*p)%m + (txt[i])%m)%m;
        hash[i] = (hash[i-1]*p)%m;
    }

    for(ll i=0;i<n;i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    
    for(ll i=0;i<n;i++){
        cout<<hash[i]<<" ";
    }
    cout<<endl;


    // calculating substring's hash
    ll i,j;
    cout<<"enter index"<<endl;
    cin>>i>>j;

    cout<<"hash of substring i to j"<<endl;
    cout<<(pre[j]-pre[i-1]*hash[j-i+1])%m<<endl;

    return true;
}
int main(){
    string txt="ssd",pat="fvf";
    isMatch(txt,pat);
    // 101782
    return 0;
}