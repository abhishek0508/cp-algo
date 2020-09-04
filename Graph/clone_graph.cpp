// deep copy
Node* cloneGraph(Node* node) {
    if(!node){
        return NULL;
    }
    
    unordered_map<Node*,Node*> umap;
    Node *copy = new Node(node->val,{});
    
    umap[node] = copy;
    queue<Node*> qu;
    qu.push(node);
    
    while(!qu.empty()){
        Node *temp = qu.front();
        qu.pop();
        for(Node *neighbour: temp->neighbors){
            if(umap.find(neighbour)==umap.end()){
                umap[neighbour] = new Node(neighbour->val,{});   
                qu.push(neighbour);
            }
            
            umap[temp]->neighbors.push_back(umap[neighbour]);
        }
        
    }

    return copy;
}