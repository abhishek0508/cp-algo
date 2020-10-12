// given an array of integers, find two elements whose xor is maximum
// Given an array of integers, we have to find two elements whose XOR is maximum.
// insert integers on the go and find maximum xor.
//
#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie *left;
    Trie *right;
    Trie(){
        left = NULL;
        right = NULL;
    }
};

Trie *root;
void insert(int pre){
    Trie *temp = root;
    for(int i=30;i>=0;i--){
        if((pre)&(i<<i)){
            if(!temp->left){
                temp->left = new Trie();
            }
            temp = temp->left;
        }
        else{
            if(!temp->right){
                temp->right = new Trie();
            }
            temp = temp->right;
        }
    }
}

int query(int pre){
    Trie *temp = root;
    int ans=0;

    for(int i=30;i>=0;i--){
        if(pre&(1<<i) == 0){
            if(temp->left){
                ans = ans | (1<<i);
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        else{
            if(temp->left){
                ans = ans | (1<<i);
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
    }
    return 0;
}

int max_xor_two_numbers(vector<int> nums){
    int ans=0;
    root = new Trie();
    for(int i=0;i<nums.size();i++){
        insert(nums[i]);
        ans = max(ans,nums[i]);
    }
    return ans;
}