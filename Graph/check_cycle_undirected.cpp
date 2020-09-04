//  only differnece between is in unidirected we need to skip parent vertices

int parent[];
bool dfs(vector<int> graph[], int u, int color[], int par){
    color[u] = 1;
    for(int x: graph[u]){

        if(x == parent){
            continue;
        }
        if(color[x] == 0){
            parent[x] =  u;
            if(dfs(graph,x,color,parent[x])){
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

bool dfs_util(){
    color[] = {0};
    for(int i=0;i<n;i++){
        if(color[i]==0 && dfs(graph,i,color)){
            return true;
        }
    }
    return false;
}