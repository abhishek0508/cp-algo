#include<bits/stdc++.h>
using namespace std;
// thinks of state digram, finite state automata
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==0){
        return 0;
    }
    int s0[n],s1[n],s2[n];
    s0[0]=0;
    s1[0]=-prices[0];
    s2[0]=INT_MIN;
    for(int i=1;i<n;i++){
        s0[i] = max(s0[i-1],s2[i-1]);
        s1[i] = max(s1[i-1],s0[i-1]-prices[i]);
        s2[i] = s1[i-1]+prices[i];
    }
    
    return max(s0[n-1],s2[n-1]);
}