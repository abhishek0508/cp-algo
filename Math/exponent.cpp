#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int power(int x, int y){
    int res=1;
    while(y>0){
        if(y&1){
            res = (res*x)%mod;
        }
        x = (x*x)%mod;
        y=y>>1;
    }
    return res;
}

int main(){
    cout<<power(10,4)<<endl;
    return 0;
}

