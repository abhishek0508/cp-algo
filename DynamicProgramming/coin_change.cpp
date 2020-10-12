// find min_coins needed to reach amount

#include<bits/stdc++.h>
using namespace std;
int coin_change(vector<int> coins, int amount){
    int dp[amount+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=amount;i++){
        int x = INT_MAX;
        for(int j=0;j<coins.size();j++){
            if(i>=coins[j] && dp[i-coins[j]] != INT_MAX && dp[i-coins[j]]+1<x){
                x = dp[i-coins[j]]+1;
            }
        }
        dp[i] = x;
    }
    
    if(dp[amount]==INT_MAX)
        return -1;
    return dp[amount];
}