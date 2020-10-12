#include<bits/stdc++.h>
using namespace std;

string lcsfun(string str1, string str2){
    int n=str1.length(),m=str2.length();
    vector<vector<string>> dp(n+1,vector<string>(m+1,""));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + str1[i-1];
            }
            else{
                dp[i][j] = dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1]; 
            }
        }
    }
    return dp[n][m];
}
string shortestCommonSupersequence(string str1, string str2) {
    string lcs = lcsfun(str1,str2);
    int i=0,j=0;
    string res="";
    for(char c: lcs){
        while(c!=str1[i]){
            res += str1[i];
            i++;
        }
        while(c!=str2[j]){
            res += str2[j];
            j++;
        }
        res += c;
        i++;
        j++;
    }
    return res + str1.substr(i) + str2.substr(j);
}