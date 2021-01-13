//  only differecne between is in unidirected we need to skip parent vertices
#include<bits/stdc++.h>
using namespace std;

int parent[];

bool dfs(vector<int> graph[], int u, int color[], int p){
    color[u] = 1;
    for(int x: graph[u]){
        if(x == p){
            continue;
        }
        else if(color[x] == 0){
            parent[x] = u;
            if(dfs(graph,x,color,parent[x])){
                return true;
            }
        }
        else if(color[x] == 1){
            return true;
        }
    }
    color[u] = 2;
    return false;
}

bool dfs_util(vector<int> graph[], int n){
    int color[n] = {0};
    for(int i=0;i<n;i++){
        if(color[i]==0 && dfs(graph,i,color,-1)){
            return true;
        }
    }
}

int main(){
    
    return 0;
}