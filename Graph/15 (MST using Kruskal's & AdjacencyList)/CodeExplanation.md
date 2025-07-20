# Kruskal's Algorithm - Minimum Spanning Tree (MST)

This document explains the implementation of **Kruskal's Algorithm** in C, using an **adjacency matrix** to represent a **weighted undirected graph**. The implementation uses the **Disjoint Set Union-Find** data structure to detect cycles efficiently.

---

## What is Kruskal's Algorithm?

Kruskal's Algorithm is a **greedy algorithm** used to find the **Minimum Spanning Tree (MST)** of a connected, undirected, and weighted graph.

### Key Characteristics:

* Greedy: Always picks the minimum weight edge available
* Avoids cycles using Union-Find (Disjoint Sets)
* Stops when (V - 1) edges are selected (where V is number of vertices)

---

## Data Structures Used

* **Adjacency Matrix**: For graph input
* **Edge List**: Extracted from the matrix
* **Disjoint Set (Union-Find)**: To track connected components and detect cycles

---

## Input Format

The graph is defined by a hardcoded adjacency matrix. A `0` indicates no edge.

```c
int matrix[MAX][MAX] = {
    {0, 10 , 6 , 5 },
    {10, 0 , 0 , 15},
    {6, 0  , 0 , 4 },
    {5, 15 , 4 , 0 }
};
```

---

## Kruskal's Algorithm - Step-by-Step

1. Extract all edges from the upper triangle of the adjacency matrix (undirected graph)
2. Sort all edges in ascending order of weight
3. Initialize disjoint sets (each vertex is its own parent)
4. Iterate over sorted edges and add to MST if it connects two disjoint sets
5. Stop when MST has (V - 1) edges

---

## Code Explanation

### Struct Definition

```c
struct Edge {
    int src, dest, weight;
};
```

Defines an edge with source, destination, and weight.

### Disjoint Set (Union-Find)

```c
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
```

Finds the root of a set and unions two sets.

### Sorting Function

```c
int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}
```

Used by `qsort` to sort edges by weight.

### Kruskal's MST Function

```c
void kruskalMST(int matrix[MAX][MAX], int n) {
    struct Edge edges[MAX * MAX];
    int edgeCount = 0;

    // Extract edges
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = matrix[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges
    qsort(edges, edgeCount, sizeof(struct Edge), compare);

    // Initialize disjoint sets
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in the Minimum Spanning Tree:\n");

    int mstWeight = 0;
    int edgesUsed = 0;

    // Build MST
    for (int i = 0; i < edgeCount && edgesUsed < n - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(setU, setV);
            edgesUsed++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}
```

### Main Function

```c
int main() {
    int n = 4;
    int matrix[MAX][MAX] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    kruskalMST(matrix, n);

    return 0;
}
```

Defines the graph and calls `kruskalMST()`.

---

## Output

```
Edges in the Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Total weight of MST: 19
```

---

## Time Complexity

* Sorting edges: **O(E log E)**
* Union-Find: **O(E)** (nearly constant with optimizations)
* Overall: **O(E log E)**

---

## Improvements

* Use path compression in `find()` for efficiency
* Accept dynamic input from file or user
* Handle disconnected graphs (Minimum Spanning Forest)

---

## Conclusion

Kruskal’s algorithm is an efficient way to compute MSTs using greedy selection and disjoint sets. This implementation processes a graph given in matrix form and builds the MST with minimal edge weights while avoiding cycles.
