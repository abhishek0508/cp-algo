// computer nCr%p

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll fact[100000];
ll power(ll x, ll y){
    ll res=1;
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

ll modInverse(ll x){
    return power(x,mod-2);
}

ll nCr(ll n,ll r){
    fact[1]=1;
    fact[0]=1;
    for(ll i=1;i<=1000;i++){
        fact[i]=(i*fact[i-1])%mod;
    }

    ll x = ((fact[n]%mod)*(modInverse(fact[n-r])%mod))%mod;
    ll y = ((x%mod)*(modInverse(fact[r])%mod))%mod;

    return y;
}

int main(){
    cout<<nCr(10,3)<<endl;
    return 0;
}