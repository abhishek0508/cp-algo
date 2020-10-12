#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int s1=INT_MIN,s2=0,s3=INT_MIN,s4=0;
    for(int i=0;i<prices.size();i++){
        s1 = max(s1,-prices[i]);
        s2 = max(s2,prices[i]+s1);
        s3 = max(s3,s2-prices[i]);
        s4 = max(s4,prices[i]+s3);
    }
    return s4;
}

// draw 4 states, s1,s2,s3,s4 
// s1 -> buy
// s2 -> sell
// s3 -> buy
// s4 -> sell
// 