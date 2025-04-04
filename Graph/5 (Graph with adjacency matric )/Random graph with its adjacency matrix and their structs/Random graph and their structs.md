# Example Directed Weighted Graph with 10 Nodes

This article provides an example of a directed weighted graph with 10 nodes and shows the corresponding `vertex_s` structure for each node after initialization.

## Graph Visualization

Below is a representation of our sample directed weighted graph with 10 nodes (0-9):
![GRAPH](https://github.com/user-attachments/assets/f9f699e9-8c6c-4a88-8e79-112d0dd3676c)


## Adjacency Matrix Representation

The adjacency matrix for this directed weighted graph:

```
    0  1  2  3  4  5  6  7  8  9
   ----------------------------- 
0 | 0  3  0  0  4  0  0  0  0  0
1 | 0  0  2  0  0  0  0  0  0  0
2 | 0  0  0  5  0  0  3  0  0  0
3 | 0  0  0  0  0  0  0  0  0  0
4 | 0  0  0  0  0  0  0  0  2  0
5 | 0  4  0  0  0  0  0  0  0  0
6 | 0  0  0  1  0  6  0  0  0  3
7 | 0  0  0  0  0  0  0  0  0  4
8 | 0  0  0  0  0  0  0  0  0  1
9 | 0  0  0  0  0  0  7  8  0  0
```

## Vertex Structures

Here's each node's `vertex_s` structure after initialization:

### Node 0
```c
struct vertex_s {
    int id = 0;
    int color = WHITE;                 // Initially all vertices are WHITE
    int dist = INT_MAX;                // Initially set to infinity
    int disc_time = -1;                // Not yet discovered
    int endp_time = -1;                // Not yet finished
    int pred = -1;                     // No predecessor yet
    int scc = -1;                      // No SCC assigned
    int *rowAdj = {0,3,0,0,4,0,0,0,0,0}; // Edges to nodes 1 (weight 3) and 4 (weight 4)
};
```

### Node 1
```c
struct vertex_s {
    int id = 1;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,2,0,0,0,0,0,0,0}; // Edge to node 2 (weight 2)
};
```

### Node 2
```c
struct vertex_s {
    int id = 2;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,0,5,0,0,3,0,0,0}; // Edges to nodes 3 (weight 5) and 6 (weight 3)
};
```

### Node 3
```c
struct vertex_s {
    int id = 3;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,0,0,0,0,0,0,0,0}; // No outgoing edges
};
```

### Node 4
```c
struct vertex_s {
    int id = 4;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,0,0,0,0,0,0,2,0}; // Edge to node 8 (weight 2)
};
```

### Node 5
```c
struct vertex_s {
    int id = 5;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,4,0,0,0,0,0,0,0,0}; // Edge to node 1 (weight 4)
};
```

### Node 6
```c
struct vertex_s {
    int id = 6;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,0,1,0,6,0,0,0,3}; // Edges to nodes 3 (weight 1), 5 (weight 6), and 9 (weight 3)
};
```

### Node 7
```c
struct vertex_s {
    int id = 7;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,0,0,0,0,0,0,0,4}; // Edge to node 9 (weight 4)
};
```

### Node 8
```c
struct vertex_s {
    int id = 8;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,0,0,0,0,0,0,0,1}; // Edge to node 9 (weight 1)
};
```

### Node 9
```c
struct vertex_s {
    int id = 9;
    int color = WHITE;
    int dist = INT_MAX;
    int disc_time = -1;
    int endp_time = -1;
    int pred = -1;
    int scc = -1;
    int *rowAdj = {0,0,0,0,0,0,7,8,0,0}; // Edges to nodes 6 (weight 7) and 7 (weight 8)
};
```

This example illustrates how each vertex in the graph is represented using the `vertex_s` structure. The `rowAdj` array for each vertex represents its outgoing edges in the adjacency matrix format, where non-zero values indicate the weight of the edge to the corresponding destination vertex.

When traversal algorithms like DFS or BFS are run on this graph, the other fields in the structure (color, dist, disc_time, etc.) would be updated as the algorithms progress.
