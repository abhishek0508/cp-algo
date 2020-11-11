#include<bits/stdc++.h>
using namespace std;
// consider undirected graph

vector<int> prims(int n, vector<vector<int>> edges, vector<int> weights){
    // return shortest distance from source to all other vertices
    // pair<int,int> -> weights,second vectex
    vector<pair<int,int>> adj[n];
    vector<int> dist(n,INT_MAX);

    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({weights[i],edges[i][1]});
        adj[edges[i][1]].push_back({weights[i],edges[i][0]});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    // take any vertex as source
    int src = 0;
    dist[src]=0;
    pq.push({0,src});

    int parent[n] = {-1};
    int visited[n] = {0};

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();

        visited[p.second] = 1;

        for(pair<int,int> x: adj[p.second]){
            if(visited[x.second]==0  && dist[x.second] > x.first ){
                dist[x.second]=x.first;
                pq.push({dist[x.second],x.second});
                parent[x.second] = p.second;
            }
        }
    }

    return dist;
}

int main(){
    int n,m;
    cout<<"Enter no of vertices & no of edges"<<endl; 
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<int> weights;

    cout<<"enter edges"<<endl;
    for(int i=0;i<m;i++){
        int x,y,w;
        vector<int> temp;
        cin>>x>>y>>w;
        temp.push_back(x);
        temp.push_back(y);
        edges.push_back(temp);
        weights.push_back(w);
    }

    vector<int> dist = prims(n,edges,weights);
    for(int x: dist){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}