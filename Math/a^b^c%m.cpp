// a^b^c mod m = (a^b^c mod n) mod m, where n = φ(m) Euler's totient function.
// If m is prime, then n = m-1.
// Edit: as Nabb polled out, this only holds if a is coprime to m. So you would have to check this first.
// computing 

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll power(ll x, ll y, ll m){
    ll res=1;
    while(y>0){
        if(y&1){
            res=(res*x)%m;
        }
        x=(x*x)%m;
        y=y>>1;
    }
    return res;
}

ll euler(ll x){
    // n*(1-(1/p1))*(1-(1/p2))*(1-(1/p3))
    ll res = x;
    for(ll p=2;p<=sqrt(x);p++){
        if(x%p==0){
            while(x%p==0){
                x=x/p;
            }
            res = res-(res/p);
        }
    }

    if(x>1){
        res = res-(res/x);
    }
    return res;
}

ll exponent(ll a, ll b, ll c){
    long long x = power(b,c,euler(mod));
    ll res = power(a,x,mod);
    return res;
}
int main(){
    ll a=10,b=2,c=3;
    cout<<exponent(a,b,c)<<endl;
    return 0;
}

