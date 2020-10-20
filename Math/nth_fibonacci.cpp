#include<bits/stdc++.h>
using namespace std;
#define ll long long

// here recurrence realtion is fib(n) = 4*fib(k-1)-2fib(k-2)

vector<vector<ll>> power(vector<vector<ll>> t, ll x){

    vector<vector<ll>> res(t.size(),vector<ll>(t.size(),0));

    // change this for fiboannci
    res[0][0]=0;
    res[0][1]=1;
    res[1][0]=-2;
    res[1][1]=4;

    ll temp1=0,temp2=0,temp3=0,temp4=0;
    
    while(x>0){
        if(x&1){
            temp1 = res[0][0]*t[0][0]+res[0][1]*t[1][0];
            temp2 = res[0][0]*t[0][1]+res[0][1]*t[1][1];
            temp3 = res[1][0]*t[0][0]+res[1][1]*t[1][0];
            temp4 = res[1][0]*t[0][1]+res[1][1]*t[1][1];

            res[0][0] = temp1;
            res[0][1] = temp2;
            res[1][0] = temp3;
            res[1][1] = temp4;
        }
        
        temp1 = t[0][0]*t[0][0]+t[0][1]*t[1][0];
        temp2 = t[0][0]*t[0][1]+t[0][1]*t[1][1];
        temp3 = t[1][0]*t[0][0]+t[1][1]*t[1][0];
        temp4 = t[1][0]*t[0][1]+t[1][1]*t[1][1];

        t[0][0] = temp1;
        t[0][1] = temp2;
        t[1][0] = temp3;
        t[1][1] = temp4;

        x = x>>1;
    }

    return res;

}
ll nth_term_recurrence(ll n,ll k){
    // k is the no of terms on which previous term depends
    // if k=2, then initial k terms must already by defined, f0=1,f1=1
    vector<ll> f1(k);
    // change this fibonacci
    f1[0]=1;
    f1[1]=2;

    // now declare k*k matrix, whose last row is constants multiplied to each previous term
    // like fib(n) = 1*fib(n-1)+1*fib(n-2)
    // like fib(n) = c1*fib(n-1)+c2*fib(n-2)
    // last row will be c1,c2,...
    // all other rows i+1 element will 1 all other will be 0

    vector<vector<ll>> t(k,vector<ll>(k,0));

    // change this for fibonacci
    t[0][0]=0;
    t[0][1]=1;
    t[1][0]=-2;
    t[1][1]=4;

    if(n==1){
        return 1;
    }

    if(n==2){
        return 2;
    }


    // formula for fn = (t^(n-1))*(f1)
    // here f1 = [1,1]
    // t = [[0,1],[1,1]]

    t = power(t,n-2);

    cout<<t[0][0]<<" "<<t[0][1]<<endl;
    cout<<t[1][0]<<" "<<t[1][1]<<endl;

    ll res=0;
    for(int i=0;i<k;i++){
        res = res + t[0][i]*f1[i];
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // nth term of recurrence relation whose each term depends on previous k terms
        // here in fibonacci k = 2
        cout<<nth_term_recurrence(n,2)<<endl;
    }
    return 0;
}