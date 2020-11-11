#include<bits/stdc++.h>
using namespace std;
// We will run a series of DFS in the graph. Initially all vertices are colored white (0).
//  From each unvisited (white) vertex, start the DFS, mark it gray (1) while entering and mark it black (2) on exit. If DFS moves to a gray vertex, then we have found a cycle
//  (if the graph is undirected, the edge to parent is not considered).
//  The cycle itself can be reconstructed using parent array.
bool dfs(vector<int> graph[], int u, int color[]){
    color[u] = 1;
    for(int x: graph[u]){
        if(color[x] == 0){
            if(dfs(graph,x,color)){
                return true;
            }
        }
        else{
            if(color[x] == 1){
                return true;
            }
        }
    }
    color[u] = 2;
    return false;
}   

bool dfs_util(vector<int> graph[], int n){
    int color[n] = {0};
    for(int i=0;i<n;i++){
        if(color[i]==0 && dfs(graph,i,color)){
            return true;
        }
    }
    return false;
}

int main(){
    return 0;
}