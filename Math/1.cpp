#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll x, ll y){
    if(x==0){
        return y;
    }
    else if(y==0){
        return x;
    }

    if(x>y){
        return gcd(x%y,y);
    }
    return gcd(x,y%x);
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll a = arr[0];
        for(int i=1;i<n;i++){
            a = gcd(a,arr[i]);
        }

        cout<<a*n<<endl;
    }
    return 0;
}