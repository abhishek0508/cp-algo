int min_moves(vector<pair<int,int>> snakes, vector<pair<int,int>> ladder){
    
    queue<pair<int,int>> qu; // stores vertex & its distance
    
    int moves[N];

    for(int i=0;i<=N;i++){
        moves[i]=-1;
    }
    for(int i=0;i<snakes.size();i++){
        moves[snakes[i].first] = snakes[i].second;
    }

    for(int i=0;i<ladder.size();i++){
        moves[ladder[i].first] = ladder[i].second;
    }

    bool visited[N+1];
    memset(visited,0,sizeof(visited));

    qu.push({1,0}); // vertex, distance
    visited[1]=true;

    int dist;
    while(!qu.empty()){
        pair<int,int> p = qu.front();
        qu.pop();
        int v = p.first;
        dist = p.second;
        if(v == N){
            break;
        }
        for(int j=(v+1);j<=(v+6) && j<N; j++){

            if(!visited[j]){
                visited[j]=true;
                
                int curr_dist = dist+1;
                int curr_vertex = j;

                if(moves[j]!=-1){
                    curr_vertex = moves[j];
                }

                qu.push({curr_vertex,curr_dist});
            }
        }
    }
    return dist;
}