// computer nCr%p

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long fact[100000];
long long power(long long x, long long y){
    long long res=1;
    // cout<<x<<" "<<y<<endl;
    while(y>0){
        if(y&1){
            res= (res*x)%mod;
        }
        x = (x*x)%mod;
        y=y>>1;
    }

    return res%mod;
}

long long modInverse(long long x){
    return power(x,mod-2);
}

long long nCr(long long n,long long r){
    fact[1]=1;
    fact[0]=1;
    for(long long i=1;i<=1000;i++){
        fact[i]=(i*fact[i-1])%mod;
    }

    long long x = ((fact[n]%mod)*(modInverse(fact[n-r])%mod))%mod;
    long long y = ((x%mod)*(modInverse(fact[r])%mod))%mod;

    return y;
}

int main(){
    cout<<nCr(10,3)<<endl;
    return 0;
}