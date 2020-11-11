#include<bits/stdc++.h>
using namespace std;
// consider undirected graph

vector<vector<int>> floyd_warshal(int n, vector<vector<int>> edges, vector<int> weights){

    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }

    for(int i=0;i<edges.size();i++){
        dist[edges[i][0]][edges[i][1]] =  weights[i];
        dist[edges[i][1]][edges[i][0]] =  weights[i];
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
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

    cout<<"enter source vertex"<<endl;
    vector<vector<int>> dist = floyd_warshal(n,edges,weights);
    // for(int x: dist){
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    return 0;
}