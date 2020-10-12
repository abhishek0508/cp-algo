#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie *left,*right;
    Trie(){
        left = NULL;
        right = NULL;
    }
};

int max_xor(vector<int> nums){
    Trie *root =  new Trie();
    Trie *temp = root;
    for(int i=0;i<nums.size();i++){
        int x = nums[i];
        temp = root;
        // cout<<"x="<<x<<endl;
        for(int i=30;i>=0;i--){
            if((x & (1<<i))){
                if(temp->left == NULL){
                    temp->left = new Trie();
                }
                temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = new Trie();
                }
                temp = temp->right;
            }
        }
    }

    int ans=0;
    temp = root;
    for(int i=30;i>=0;i--){
        if(temp->left!=NULL){
            ans = (ans | (1<<i));
            // cout<<"ans="<<ans<<endl;
            temp = temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    
    return ans;
}
int main(){

    vector<int> res{1,2,3,4};
    cout<<max_xor(res)<<endl;
    return 0;
}