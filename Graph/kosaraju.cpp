// scc
// find all scc in graph, genrally graph is directed

#include<bits/stdc++.h>
using namespace std;

stack<int> st;
void dfs(vector<int> graph[], bool visited[], int u){
    visited[u] = true;
    for(int x: graph[u]){
        if(!visited[x]){
            dfs(graph,visited,x);
        }
    }
    st.push(u);
}

void r_dfs(vector<int> graph[], bool visited[], int u, vector<int> &temp){
    visited[u]=true;
    temp.push_back(u);
    for(int x: graph[u]){
        if(!visited[x]){
            r_dfs(graph,visited,x,temp);
        }
    }

}

vector<vector<int>> scc(vector<int> graph[], vector<int> r_graph[], int n){

    bool visited[n]={false};
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(graph, visited, i);
        }
    }

    vector<vector<int>> res;
    while(!st.empty()){
        int v = st.top();
        st.pop();
        if(!visited[v]){
            vector<int> temp;
            r_dfs(r_graph,visited,v,temp);
            res.push_back(temp);
        }
    }

    return res;
}


