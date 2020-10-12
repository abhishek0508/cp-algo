// find if two strings are rotations of one another
// 

#include<bits/stdc++.h>
using namespace std;

vector<int> preprocesses(string pattern){
    int len=0;
    int n = pattern.length();
    vector<int> lps(n,0);
    int i=1;
    vector<int> lps(pattern.length(),0);
    while(i < pattern.length()){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string text, string pat){
    vector<int> index;
    vector<int> lps = preprocesses(pat);

    int n = text.length();
    int m = pat.length();
    int i=0,j=0;

    while(i<n){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        
        if(j==m){
            return true;
        }
        else if(i<n && text[i]!=pat[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return false;
}

bool rotations(string s1, string s2){
    string str = s1.append(s1);
    return kmp(str,s2);
}