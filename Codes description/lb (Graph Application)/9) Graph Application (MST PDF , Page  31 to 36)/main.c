#include <stdio.h>
#include <stdlib.h>

#define INF 999999

// Structure to represent an edge
typedef struct edge_s {
    int weight; // Weight of the edge
    int dst;    // Destination vertex of the edge
} edge_t;

// Structure to represent a vertex
typedef struct vertex_s {
    int id;        // Vertex ID
    int ne;        // Number of edges
    int color;     // Color for search algorithms (DFS, BFS, etc.)
    int dist;      // Distance for algorithms like Dijkstra or BFS
    int scc;       // Strongly Connected Component identifier
    int disc_time; // Discovery time in DFS
    int endp_time; // Finishing time in DFS
    int pred;      // Predecessor for search algorithms
    edge_t *edges; // Adjacency list (edges) for the vertex
} vertex_t;

// Structure to represent a graph
typedef struct graph_s {
    vertex_t *g;  // Array of vertices
    int nv;       // Number of vertices
} graph_t;

// Structure to represent an edge in Kruskal's algorithm
typedef struct {
    int src, dst, weight;
} link;

// Function to load the graph (stub for simplicity)
graph_t* graph_load(const char *filename) {
    // For simplicity, we're not implementing file reading here
    // Instead, we will create a simple graph with hardcoded values.
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->nv = 4; // 4 vertices

    g->g = (vertex_t *)malloc(g->nv * sizeof(vertex_t));

    // Example edges
    g->g[0].id = 0; g->g[0].ne = 2; g->g[0].edges = (edge_t *)malloc(2 * sizeof(edge_t));
    g->g[0].edges[0] = (edge_t){10, 1};
    g->g[0].edges[1] = (edge_t){6, 2};

    g->g[1].id = 1; g->g[1].ne = 2; g->g[1].edges = (edge_t *)malloc(2 * sizeof(edge_t));
    g->g[1].edges[0] = (edge_t){10, 0};
    g->g[1].edges[1] = (edge_t){15, 3};

    g->g[2].id = 2; g->g[2].ne = 2; g->g[2].edges = (edge_t *)malloc(2 * sizeof(edge_t));
    g->g[2].edges[0] = (edge_t){6, 0};
    g->g[2].edges[1] = (edge_t){4, 3};

    g->g[3].id = 3; g->g[3].ne = 2; g->g[3].edges = (edge_t *)malloc(2 * sizeof(edge_t));
    g->g[3].edges[0] = (edge_t){15, 1};
    g->g[3].edges[1] = (edge_t){4, 2};

    return g;
}

// Function to create and initialize a disjoint set
void make_set(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        g->g[i].pred = i;  // Each vertex is its own parent initially
    }
}

// Find function with path compression
int find(graph_t *g, int i) {
    if (g->g[i].pred != i) {
        g->g[i].pred = find(g, g->g[i].pred);  // Path compression
    }
    return g->g[i].pred;
}

// Union function to combine two sets
void union_sets(graph_t *g, int i, int j) {
    int root_i = find(g, i);
    int root_j = find(g, j);

    if (root_i != root_j) {
        g->g[root_j].pred = root_i; // Union by rank is not used here for simplicity
    }
}

// Function to sort edges by weight
void sort_edges(graph_t *g, link *edges, int *nl) {
    int k = 0;
    for (int i = 0; i < g->nv; i++) {
        for (int j = 0; j < g->g[i].ne; j++) {
            if (i < g->g[i].edges[j].dst) {
                edges[k].src = i;
                edges[k].dst = g->g[i].edges[j].dst;
                edges[k].weight = g->g[i].edges[j].weight;
                k++;
            }
        }
    }

    // Sorting edges by weight using a simple sorting algorithm (bubble sort)
    for (int i = 0; i < *nl - 1; i++) {
        for (int j = i + 1; j < *nl; j++) {
            if (edges[i].weight > edges[j].weight) {
                link temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

// Function to implement Kruskal's algorithm
int mst_kruskal(graph_t *g) {
    int weight = 0;
    int nl = 0;

    // Count the total number of edges
    for (int i = 0; i < g->nv; i++) {
        nl += g->g[i].ne;
    }
    nl /= 2;  // Since each edge is counted twice, divide by 2

    // Allocate memory for edges
    link *edges = (link *)malloc(nl * sizeof(link));
    sort_edges(g, edges, &nl);  // Sort the edges by weight

    // Initialize sets for vertices (each vertex is its own set initially)
    make_set(g);

    // Iterate over sorted edges and apply union-find
    for (int i = 0; i < nl; i++) {
        int u = edges[i].src;
        int v = edges[i].dst;

        // If u and v are not in the same set, add the edge to the MST
        if (find(g, u) != find(g, v)) {
            printf("Edge %d-%d (weight %d)\n", u, v, edges[i].weight);
            weight += edges[i].weight;  // Add the weight of the edge to the MST total
            union_sets(g, u, v);  // Union the sets of u and v
        }
    }

    free(edges);  // Free the allocated memory for edges
    return weight;  // Return the total weight of the MST
}

// Main function to execute Kruskal's algorithm
int main() {
    // Load the graph (from file, in this case we use hardcoded values)
    graph_t *g = graph_load("graph_data.txt");

    // Run Kruskal's algorithm to find MST
    int mst_weight = mst_kruskal(g);

    // Print the total weight of the Minimum Spanning Tree (MST)
    printf("Total weight of MST: %d\n", mst_weight);

    // Free graph memory (not implemented in detail)
    free(g);
    return 0;
}

/*
Passage Explanation (Functions used in the code):

1. **graph_load**:
   - This function loads a graph. In this case, it is a stub that creates a simple graph with hardcoded edges and vertices.
   - In a real-world application, this function would typically read graph data from a file.

2. **make_set**:
   - This function initializes each vertex to be its own parent (disjoint set) in preparation for union-find operations.

3. **find**:
   - This is the **find** function for the **disjoint set** with **path compression**. It finds the representative (root) of the set containing a vertex. If the vertex is not its own parent, it recursively finds its parent, compressing the path for efficiency.

4. **union_sets**:
   - This function connects two sets by making one set the parent of the other. It is used in the union-find structure to merge disjoint sets when adding edges to the MST.

5. **sort_edges**:
   - This function sorts all the edges by their weights in **non-decreasing order**. The edges are then processed from the smallest to the largest to find the MST.

6. **mst_kruskal**:
   - This is the main implementation of Kruskal's algorithm. It sorts the edges, processes them in order, and uses union-find to check whether adding an edge would form a cycle. If not, it adds the edge to the MST.

7. **main**:
   - The **main** function loads the graph, calls Kruskal's algorithm to find the MST, and prints the total weight of the MST.
*/
