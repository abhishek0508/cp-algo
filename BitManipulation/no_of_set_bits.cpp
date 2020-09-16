// find no of set bits from 1 to n
int fun(int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = dp[i>>1] + (i&1); 
    }
    return dp[n];
}


