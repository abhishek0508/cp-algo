#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int dp[s.length()+1];
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    for(int end=1;end<=s.length();end++){
        for(int start=0;start<end;start++){
            string str = s.substr(start,end-start);
            if(dp[start]==true && count(wordDict.begin(),wordDict.end(),str)){
                dp[end]=true;
                break;
            }
        }
    }
    return dp[s.length()];
}