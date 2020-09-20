// 
#include<bits/stdc++.h>
using namespace std;

int longest_character(string s){
    unordered_map<char,int> index;
    int l=0,r=0,max=0;
    while(r<s.length()){
        if(index.count(s[r])!=0){
            l = index[s[r]]+1;
            index[s[r]]=r;
        }
        else{
            index[s[r]]=r;
            if(r-l+1>max){
                max = r-l+1;
            }
        }
        r++;
    }
    return max;
}
int main(){
    cout<<longest_character("ABDEFGABEF")<<endl;
    return 0;
}