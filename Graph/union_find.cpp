// only write key function & algorithms

intialize(){
    parent[i]=i;
    size[i]=1;
}

// finding the root of set/tree
int find(int x){
    while(x!=parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

// union of two sets/elements
int union_(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);
    if(size[x_parent]<size[y_parent]){
        size[y_parent] += size[x_parent];
        parent[x_parent] = y_parent;
    }
    else{
        size[x_parent] = size[y_parent];
        parent[y_parent] = x_parent;
    }
}

