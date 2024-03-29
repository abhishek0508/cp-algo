// use topological sort
// 1) Create a distance array dist[] and initialize all entries of it as minus infinite
2) Order all vertices in toplogical order.
3) Do following for every vertex u in topological order.
…..Do following for every adjacent vertex v of u
………..if (dist[v] < dist[u] + weight(u, v))
……………dist[v] = dist[u] + weight(u, v)
4) Return maximum value from dist[]