// while doing bfs if i encounter vertex that has already been coloured with same aas this one
#include<bits/stdc++.h>
using namespace std;

bool check_bipartite(int n, vector<int> graph[]){
    int color[n] = {0};
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){ 
        if(color[i]==0 && !visited[i]){
            queue<pair<int,int>> qu;
            color[i] = 1;
            qu.push({i,color[i]});
            while(!qu.empty()){
                int vert = qu.front();
                qu.pop();
                for(int x: graph[vertex]){
                    if(color[x] == color[vertex]){
                        return false;
                    }
                    else if(color[x]==0 && !visited[x]){
                        visited[x]=true;
                        color[x] = 1-color[vert];
                        qu.push(x,color[x]);
                    }
                }
            }
        }
    }
    return true;
}