#include<bits/stdc++.h>
using namespace std;

stack<int> st;
void dfs(vector<int> graph[], int i, bool visited[]){
    visited[i]=true;
    for(int x: graph[i]){
        if(!visited[x]){
            dfs(graph,x,visited);
        }
    }
    st.push(i);
}

vector<int> fun(int n, vector<int> graph[]){
    bool visited[n];
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(graph,i,visited);
    }

    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
    
}

int main(){
    return 0;
}