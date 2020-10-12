#include<bits/stdc++.h>
using namespace std;

int tree[5000000];
RecentCounter() {
    memset(tree,0,sizeof(tree));
}

void update(int pos, int ar_l, int ar_r, int index){
    // cout<<"tree[index]"<<tree[index]<<endl;
    // cout<<"ar_l="<<ar_l<<"ar_r="<<ar_r<<endl;
    if(ar_l == ar_r){
        tree[index]=1;
    }
    else{
        int mid = ar_l+(ar_r-ar_l)/2;
        if(ar_l<=pos && pos<=mid){
            update(pos,ar_l,mid,index*2+1);
        }
        else{
            update(pos,mid+1,ar_r,index*2+2);
        }
        tree[index]=tree[index*2+1]+tree[index*2+2];
    }
}
int query_tree(int l, int r,int ar_l, int ar_r, int index){
    // cout<<"tree[index]="<<tree[index]<<endl;
    // cout<<"ar_l="<<ar_l<<"ar_r="<<ar_r<<endl;
    
    if(r<ar_l || l>ar_r){
        return 0;
    }
    
    if(l<=ar_l && r>=ar_r){
        return tree[index];
    }
    
    int mid = ar_l+(ar_r-ar_l)/2;
    return query_tree(l,r,ar_l,mid,index*2+1)+query_tree(l,r,mid+1,ar_r,index*2+2);
}
int ping(int t) {
    
}
}