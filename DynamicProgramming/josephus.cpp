#include<bits/stdc++.h>
using namespace std;

// seriees if 1-2-3...
// if series is 0-1-2-3 then change base case n==0 , return 0, also return (x+k)%n+1
int josephus(int n, int k){
    if(n==1){
        return 1;
    }
    return (josephus(n-1,k)+(k-1))%n+1;
}
int main(){
    
    int n,k;
    cin>>n>>k;
    cout<<josephus(n,k)<<endl;
    return 0;
}