#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return a;
    }
    else if(b%a==0){
        return b;
    }
    if(a>b){
        return gcd(a%b,b);
    }
    return gcd(a,b%a);
}

int main(){
    cout<<gcd(10,5)<<endl;
    return 0;
}