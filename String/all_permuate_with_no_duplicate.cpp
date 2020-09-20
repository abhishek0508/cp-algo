// print all permutation in lexicographical order also handling duplicates
// tip -> imagine tushar roy tree, look at copy, leetcode one.
// logic -> store charcter in sorted order with their count,
// now start from left and look if count of element is greater than 0, if so,
// pult that element according to level in the result array, and recurse by decreasing 
// the count array
// 
#include<bits/stdc++.h>
using namespace std;

void helper(char ch[], char res[], int count[], int level, int length, int ch_len){
    if(level == length){
        for(int i=0;i<length;i++){
            cout<<res[i];
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<ch_len;i++){
        if(count[i]==0)
            continue;
        res[level]=ch[i];
        count[i]--;
        helper(ch,res,count,level+1,length,ch_len);
        count[i]++;
    }
}

void permute(string str){
    map<char,int> mp;
    for(char c: str){
        if(mp.find(c)==mp.end()){
            mp[c]=1;
        }
        else{
            mp[c]++;
        }
    }

    char ch[mp.size()];
    int i=0;
    int count[mp.size()];
    for(auto it: mp){
        ch[i] = it.first;
        count[i] = it.second;
        i++;
    }
    char res[str.length()];

    helper(ch,res,count,0,str.length(),mp.size());
}

int main(){
    string str = "ccab";
    permute(str);
    return 0;
}