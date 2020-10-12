#include<bits/stdc++.h>
using namespace std;

// At day i, we may buy stock (from previous sell status) or do nothing (from previous buy status):
// buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i]);
// Or
// At day i, we may sell stock (from previous buy status) or keep holding (from previous sell status):
// sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]); 
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int buy[n];
    int sell[n];
    buy[0] = -prices[0];
    sell[0]=0;
    for(int i=1;i<n;i++){
        buy[i] = max(buy[i-1],sell[i-1]-prices[i]-fee);
        sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
    }

    return sell[n-1];
}