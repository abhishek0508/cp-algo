// 
#include<bits/stdc++.h>
using namespace std;

void remove(string str,string &res){
    string s = "";
    bool flag=false;
    for(int i=0;i<str.length()-1;i++){
        if(str[i]==str[i+1]){
            flag=true;
            continue;
        }
        else{
            if(flag==false){
                s += str[i];
            }
            else{
                string sub = s;
                if(i+1<str.length())
                    sub = sub + str.substr(i+1);
                remove(sub,res);
            }
        }
    }

    if(s+str[str.length()-1] == str && res=="")
        res=str;
    // return str;
}

int main(){
    string str = "abcccdddeeebfffff";
    string res="";
    remove(str,res);
    cout<<res<<endl;
    return 0;
}