// find the min no of operations required to convert str1 to str2
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int helper(string s1, string s2, int i, int j){
    if(i==s1.length()){
        return s2.length()-j;
    }
    
    if(j==s2.length()){
        return s1.length()-i;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(s1[i]==s2[j]){
        dp[i][j] = helper(s1,s2,i+1,j+1);
    }
    else{
        dp[i][j] = 1+min(helper(s1,s2,i,j+1),min(helper(s1,s2,i+1,j),helper(s1,s2,i+1,j+1)));
    }
    
    return dp[i][j];
}
int minDistance(string word1, string word2) {
    memset(dp,-1,sizeof(dp));
    return helper(word1,word2,0,0);
}

// this can be done is O(n) space, as well, since it depends on only previous row, 
// take two vectors to do that.
