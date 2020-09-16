// find the size of each subtree of a tree
// 
#include<bits/stdc++.h>
using namespace std;

int helper_dfs(vector<int> adj[], int u, bool visited[], vector<int> &subtree){
    int curr_size = 1;
    visited[u]=true;

    for(int x: adj[u]){
        if(!visited[x]){
            curr_size += helper_dfs(adj,x,visited,subtree);
        }
    }
    subtree[u] = curr_size;
    return curr_size;
}

vector<int> subtree_size(int n, vector<pair<int,int>> vec){
    vector<int> subtree(n,0);
    
    bool visited[n];
    memset(visited,0,sizeof(visited));
    vector<int> adj[n];

    for(int i=0;i<n;i++){
        adj[vec[i].first].push_back(vec[i].second);
        adj[vec[i].second].push_back(vec[i].first);
    }

    helper_dfs(adj,0,visited,subtree);
    return subtree;
}

int main(){
    vector<pair<int,int>> vec{{0,1},{1,2},{1,3},{2,6},{3,4},{3,5}};
    vector<int> res  = subtree_size(7,vec);
    
    for(int x: res){
        cout<<x<<" ";
    }

    cout<<endl;
    return 0;
}