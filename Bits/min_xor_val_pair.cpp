#include<bits/stdc++.h>
using namespace std;
class Trie{
    public:
    int value;
    Trie *child[2];
    Trie(int x){
        value=x;
    }
    Trie(){
        for(int i=0;i<2;i++){
            this->child[i] = NULL;
        }
    }
};

Trie *root;
void insert(int x){
    Trie *temp = root;
    for(int i=31;i>=0;i--){
        int bit = x & (1<<i);
        if(!temp->child[bit]){
            temp->child[bit] = new Trie();
        }
        temp = temp->child[bit];
    }
    temp->value = x;
}

int find(int x){
    Trie *temp = root;
    for(int i=31;i>=0;i--){
        int bit = x & (i<<i);
        if(temp->child[bit]){
            temp = temp->child[bit];
        }
        else{
            temp = temp->child[1-bit];
        }
    }
    return x^temp->value;
}

int min_xor_pair(vector<int> arr){
    root = new Trie();
    insert(arr[0]);
    int min_xor=INT_MAX;
    for(int i=1;i<arr.size();i++){
        min_xor = min(min_xor,find(arr[i]));
        insert(arr[i]);
    }
    return min_xor;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<min_xor_pair(arr)<<endl;
    return 0;
}

