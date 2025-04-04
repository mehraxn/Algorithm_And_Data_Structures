# Final State of Node Structures After Graph Traversal

This article shows the final state of each node's `vertex_s` structure after running both DFS and BFS traversal algorithms on our directed weighted graph starting from node 0.

## Final Node States After Traversal

### Node 0
```c
struct vertex_s {
    int id = 0;
    int color = BLACK;          // Fully explored
    int dist = 0;               // Source node in BFS
    int disc_time = 1;          // First node discovered in DFS
    int endp_time = 18;         // Last to finish since it's the root
    int pred = -1;              // Root node, no predecessor
    int scc = 0;                // First SCC component
    int *rowAdj = {0,3,0,0,4,0,0,0,0,0};
};
```

### Node 1
```c
struct vertex_s {
    int id = 1;
    int color = BLACK;          // Fully explored
    int dist = 1;               // One edge away from source
    int disc_time = 2;          // Second node discovered
    int endp_time = 13;         // Finishes after its subtree
    int pred = 0;               // Reached from node 0
    int scc = 1;                // Part of cycle with nodes 5
    int *rowAdj = {0,0,2,0,0,0,0,0,0,0};
};
```

### Node 2
```c
struct vertex_s {
    int id = 2;
    int color = BLACK;          // Fully explored
    int dist = 2;               // Two edges away from source
    int disc_time = 3;          // Third node discovered
    int endp_time = 12;         // Finishes after its subtree
    int pred = 1;               // Reached from node 1
    int scc = 2;                // Different SCC
    int *rowAdj = {0,0,0,5,0,0,3,0,0,0};
};
```

### Node 3
```c
struct vertex_s {
    int id = 3;
    int color = BLACK;          // Fully explored
    int dist = 3;               // Three edges away from source
    int disc_time = 4;          // Fourth node discovered
    int endp_time = 5;          // Finishes early (no outgoing edges)
    int pred = 2;               // Reached from node 2
    int scc = 3;                // Separate SCC (sink node)
    int *rowAdj = {0,0,0,0,0,0,0,0,0,0};
};
```

### Node 4
```c
struct vertex_s {
    int id = 4;
    int color = BLACK;          // Fully explored
    int dist = 1;               // One edge away from source
    int disc_time = 14;          // Fifth node discovered
    int endp_time = 17;         // Finishes after its subtree
    int pred = 0;               // Reached from node 0
    int scc = 4;                // Different SCC
    int *rowAdj = {0,0,0,0,0,0,0,0,2,0};
};
```

### Node 5
```c
struct vertex_s {
    int id = 5;
    int color = BLACK;          // Fully explored
    int dist = 3;               // Three edges from source via 0→1→2→6→5
    int disc_time = 7;         // Discovered during 6's exploration
    int endp_time = 8;         // Part of cycle with node 1
    int pred = 6;               // Reached from node 6
    int scc = 1;                // Same SCC as node 1 (they form a cycle)
    int *rowAdj = {0,4,0,0,0,0,0,0,0,0};
};
```

### Node 6
```c
struct vertex_s {
    int id = 6;
    int color = BLACK;          // Fully explored
    int dist = 2;               // Two edges from source via 0→2→6
    int disc_time = 6;          // Discovered after node 4
    int endp_time = 11;         // Finishes after its subtree
    int pred = 2;               // Reached from node 2
    int scc = 5;                // Different SCC
    int *rowAdj = {0,0,0,1,0,6,0,0,0,3};
};
```

### Node 7
```c
struct vertex_s {
    int id = 7;
    int color = BLACK;          // Fully explored
    int dist = 4;               // Four edges from source via path through 9
    int disc_time = 19;         // Discovered during 9's exploration
    int endp_time = 20;         // Finishes before 9
    int pred = 9;               // Reached from node 9
    int scc = 6;                // Different SCC
    int *rowAdj = {0,0,0,0,0,0,0,0,0,4};
};
```

### Node 8
```c
struct vertex_s {
    int id = 8;
    int color = BLACK;          // Fully explored
    int dist = 2;               // Two edges from source via 0→4→8
    int disc_time = 15;          // Discovered after node 6
    int endp_time = 16;         // Finishes after its subtree
    int pred = 4;               // Reached from node 4
    int scc = 7;                // Different SCC
    int *rowAdj = {0,0,0,0,0,0,0,0,0,1};
};
```

### Node 9
```c
struct vertex_s {
    int id = 9;
    int color = BLACK;          // Fully explored
    int dist = 3;               // Three edges from source via 0→4→8→9
    int disc_time = 9;          // Discovered after node 8
    int endp_time = 10;         // Finishes after its subtree
    int pred = 8;               // Reached from node 8
    int scc = 8;                // Forms cycle with nodes 6 and 7
    int *rowAdj = {0,0,0,0,0,0,7,8,0,0};
};
```

## Notes on Final States

1. **BFS Results**:
   - The `dist` field shows the shortest path (in terms of edge count) from the source node 0
   - The `pred` field forms a breadth-first spanning tree

2. **DFS Results**:
   - The `disc_time` values range from 1 to 12, indicating the order in which nodes were discovered
   - The `endp_time` values indicate when exploration of each node and its descendants was completed
   - Nodes with higher `endp_time` are ancestors in the DFS tree

3. **SCC Results**:
   - The `scc` field groups nodes that form strongly connected components
   - Nodes 1 and 5 form a cycle (same SCC)
   - Nodes 6, 7, and 9 are involved in another cycle but got separate SCC ids in this traversal
   - Node 3 is a sink node (no outgoing edges) and forms its own SCC

4. **All nodes** reached the BLACK state, indicating the entire graph was explored.

This final state illustrates how the vertex structure captures the complete results of graph traversal algorithms, providing valuable information for path finding, cycle detection, and connectivity analysis.
