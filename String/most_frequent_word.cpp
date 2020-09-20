#include<bits/stdc++.h>
using namespace std;

string frequent(vector<string> words){
    // transform(words.begin(),words.end(),words.begin(), ::tolower);

    unordered_map<string,int> umap;
    for(string w: words){
        umap[w]++;
    }

    int max = 0;
    string res = "";
    for(auto it: umap){
        if(it.second>max){
            max = it.second;
            res = it.first;
        }
    }
    return res;
}

int main(){
    vector<string> vec{"aaa" ,"bbb" ,"ccc" ,"bbb" ,"aaa" , "aaa"};
    cout<<frequent(vec)<<endl;
    return 0;
}