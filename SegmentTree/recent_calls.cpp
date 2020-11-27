#include<bits/stdc++.h>
using namespace std;
int build_tree(vector<int> &tree,vector<int> arr, int ar_l,int ar_r, int index){
    if(ar_l == ar_r){
        tree[index]=arr[ar_l];
        return tree[index];
    }

    int mid = ar_l + (ar_r-ar_l)/2;
    tree[index] = build_tree(tree,arr,ar_l,mid,index*2+1) + build_tree(tree,arr,mid+1,ar_r,index*2+2);
    return tree[index];
}
int query_tree(vector<int> tree, vector<int> arr, int ar_l, int ar_r, int q_l, int q_r, int index){
    if(q_l<=ar_l && q_r>=ar_r){
        return tree[index];
    }

    if(q_l>ar_r || q_r<ar_l){
        return 0;
    }

    int mid = ar_l + (ar_r-ar_l)/2;
    return query_tree(tree,arr,ar_l,mid,q_l,q_r,index*2+1)+query_tree(tree,arr,mid+1,ar_r,q_l,q_r,index*2+2);
}
void update_tree(vector<int> &tree, vector<int> arr, int ar_l, int ar_r,int update_index, int diff, int index){
    if(update_index<ar_l || update_index>ar_r){
        // cout<<"Invalid Input";
        return;
    }

    tree[index] += diff;
    if(ar_l != ar_r){
        int mid = ar_l + (ar_r-ar_l)/2;
        update_tree(tree,arr,ar_l,mid,update_index,diff,index*2+1);
        update_tree(tree,arr,mid+1,ar_r,update_index,diff,index*2+2);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int x = log2(n);
        int sz = 2*pow(2,x+1)-1;
        cout<<sz<<endl;

        vector<int> tree(sz);
        build_tree(tree,arr,0,n-1,0);

        for(int i=0;i<sz;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
        
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            cout<<query_tree(tree,arr,0,n-1,l,r,0)<<endl;
        }

        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            int index,val;
            cin>>index>>val;
            int diff = val-arr[index];
            arr[index] = val;
            update_tree(tree,arr,0,n-1,index,diff,0);
        }

        for(int i=0;i<sz;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}