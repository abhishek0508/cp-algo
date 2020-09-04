#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[], bool visited[], int vert, int &count, int cycle_len, int start){
    visited[vert] = true;

    if(cycle_len == 0){
        visited[vert]  = false;
        
    }


}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int cycle_len;
    cin>>cycle_len;

    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    int count=0;
    int res = 0;
    for(int i=1;i<=n;i++){
        dfs(graph,i,visited,count)
        res += count/2;
        visited[i]=true;
    }
    cout<<res<<endl;
    return 0;
}