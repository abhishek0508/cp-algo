// scc
// find all scc in graph, genrally graph is directed
dfs(vector<int> graph[], bool visited[], int u){
    visited[u] = true;
    for(int x: graph[u]){
        if(!visited[x]){
            dfs(graph,visited,x);
        }
    }

    st.push(u);
}

r_dfs(vector<int> graph[], int visited[], int u, vector<int> &temp){
    visited[u]=true;
    temp.push_back(u);
    for(int x: graph[u]){
        if(!visited[x]){
            dfs(rgraph,visited,x,temp);
        }
    }
}

vector<vector<int>> scc(){
    vector<int> graph[];
    vector<int> rgraph[];

    vector<vector<int>> res;
    while(!st.empty()){
        int v = st.top();
        st.pop();
        if(!visited[v]){
            vector<int> temp;
            dfs(rgraph,visited,v,temp);
            res.push_back(temp);
        }
    }

    return res;
}


