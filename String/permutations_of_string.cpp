#include<bits/stdc++.h>
using namespace std;

void helper(string str, int l,int r, vector<string> &vec){
    if(l==r){
        vec.push_back(str);
        return;
    }

    for(int i=l;i<=r;i++){
        swap(str[i],str[r]);
        helper(str,l+1,r,vec);
        swap(str[i],str[r]);
    }
}

vector<string> permute(string str){
    vector<string> vec;
    helper(str,0,str.length()-1,vec);
    return vec;
}

int main(){
    vector<string> vec= permute("aaa");
    for(string str: vec){
        cout<<"str="<<str<<endl;
    }
    return 0;
}