#include <stdio.h>
#include <stdlib.h>

#define INF 999999

// Structure to represent an edge
typedef struct edge_s {
    int u;      // Start vertex
    int v;      // End vertex
    int weight; // Weight of the edge
} edge_t;

// Structure to represent a graph
typedef struct graph_s {
    int nv;        // Number of vertices
    int ne;        // Number of edges
    edge_t *edges; // Array of edges
} graph_t;

// Union-Find (Disjoint Set) data structure
typedef struct {
    int *parent;
    int *rank;
    int size;
} disjoint_set_t;

// Function to create and initialize a disjoint set
disjoint_set_t* create_set(int size) {
    disjoint_set_t *set = (disjoint_set_t *)malloc(sizeof(disjoint_set_t));
    set->parent = (int *)malloc(size * sizeof(int));
    set->rank = (int *)malloc(size * sizeof(int));
    set->size = size;
    for (int i = 0; i < size; i++) {
        set->parent[i] = i; // Each vertex is its own parent
        set->rank[i] = 0;    // Rank starts from 0
    }
    return set;
}

// Function to find the representative (root) of a set
int find(disjoint_set_t *set, int v) {
    if (set->parent[v] != v) {
        set->parent[v] = find(set, set->parent[v]);  // Path compression
    }
    return set->parent[v];
}

// Function to perform union of two sets
void union_sets(disjoint_set_t *set, int u, int v) {
    int root_u = find(set, u);
    int root_v = find(set, v);

    if (root_u != root_v) {
        // Union by rank: attach the smaller tree under the larger tree
        if (set->rank[root_u] > set->rank[root_v]) {
            set->parent[root_v] = root_u;
        } else if (set->rank[root_u] < set->rank[root_v]) {
            set->parent[root_u] = root_v;
        } else {
            set->parent[root_v] = root_u;
            set->rank[root_u]++;
        }
    }
}

// Function to compare edges based on their weight (for sorting)
int compare_edges(const void *a, const void *b) {
    edge_t *edge1 = (edge_t *)a;
    edge_t *edge2 = (edge_t *)b;
    return edge1->weight - edge2->weight;
}

// Function to perform Kruskal's algorithm to find the MST
edge_t* kruskal(graph_t *g, int *mst_weight, int *mst_size) {
    // Sort edges in non-decreasing order of their weights
    qsort(g->edges, g->ne, sizeof(edge_t), compare_edges);

    // Create disjoint sets for each vertex
    disjoint_set_t *set = create_set(g->nv);

    // Initialize the MST
    edge_t *mst = (edge_t *)malloc(g->nv * sizeof(edge_t));
    *mst_size = 0;
    *mst_weight = 0;

    // Iterate through edges and build the MST
    for (int i = 0; i < g->ne; i++) {
        edge_t edge = g->edges[i];
        // If the vertices of the edge are in different sets, add the edge to the MST
        if (find(set, edge.u) != find(set, edge.v)) {
            union_sets(set, edge.u, edge.v);
            mst[*mst_size] = edge;
            (*mst_weight) += edge.weight;
            (*mst_size)++;
        }
    }

    // Free the disjoint set structure as it's no longer needed
    free(set->parent);
    free(set->rank);
    free(set);

    return mst;
}

// Function to load a graph (stub implementation for example purposes)
graph_t* graph_load() {
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->nv = 4;  // Number of vertices
    g->ne = 5;  // Number of edges

    g->edges = (edge_t *)malloc(g->ne * sizeof(edge_t));
    g->edges[0] = (edge_t){0, 1, 10};
    g->edges[1] = (edge_t){0, 2, 6};
    g->edges[2] = (edge_t){0, 3, 5};
    g->edges[3] = (edge_t){1, 3, 15};
    g->edges[4] = (edge_t){2, 3, 4};

    return g;
}

// Function to print the MST
void print_mst(edge_t *mst, int mst_size, int mst_weight) {
    printf("Minimum Spanning Tree (MST) edges:\n");
    for (int i = 0; i < mst_size; i++) {
        printf("Edge %d-%d with weight %d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    printf("Total weight of MST: %d\n", mst_weight);
}

int main() {
    // Load the graph (could be loaded from a file or user input)
    graph_t *g = graph_load();

    // Variables to store the MST result
    int mst_weight = 0;
    int mst_size = 0;

    // Run Kruskal's algorithm
    edge_t *mst = kruskal(g, &mst_weight, &mst_size);

    // Print the MST
    print_mst(mst, mst_size, mst_weight);

    // Free the graph memory
    free(g->edges);
    free(g);
    free(mst);

    return 0;
}
