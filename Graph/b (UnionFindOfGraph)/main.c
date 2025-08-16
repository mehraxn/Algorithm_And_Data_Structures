#include <stdio.h>
#include <stdlib.h>

// Forward declarations of structures
typedef struct edge_s edge_t;
typedef struct vertex_s vertex_t;
typedef struct graph_s graph_t;

/*
 * =====================
 * GRAPH STRUCTURE
 * =====================
 *
 * A graph is represented as:
 * - An array of vertices (each with adjacency lists of edges).
 * - The number of vertices (nv).
 */
struct graph_s {
    vertex_t *g;   // Pointer to array of vertices
    int nv;        // Number of vertices in the graph
};

/*
 * =====================
 * EDGE STRUCTURE
 * =====================
 *
 * An edge connects one vertex to another:
 * - weight: The cost or length of the edge.
 * - dst: The destination vertex index in the graph's vertex array.
 */
struct edge_s {
    int weight;    // Weight of the edge (e.g., distance, cost, etc.)
    int dst;       // Destination vertex index
};

/*
 * =====================
 * VERTEX STRUCTURE
 * =====================
 *
 * Each vertex stores:
 * - id: Unique identifier (index in the graph array).
 * - ne: Number of edges (degree of the vertex).
 * - color: Used for traversal (e.g., WHITE, GREY, BLACK in BFS/DFS).
 * - dist: Distance (for shortest path algorithms like BFS/Dijkstra).
 * - scc: Strongly Connected Component ID (for SCC algorithms).
 * - disc_time: Discovery time (DFS timestamp).
 * - endp_time: Finish time (DFS timestamp).
 * - pred: Predecessor (used in traversals or Union-Find structure).
 * - edges: Array of edges (adjacency list representation).
 */
struct vertex_s {
    int id;          // Vertex identifier
    int ne;          // Number of edges (adjacent vertices)
    int color;       // Traversal state (WHITE, GREY, BLACK)
    int dist;        // Distance from source (used in BFS/DFS)
    int scc;         // Strongly connected component ID
    int disc_time;   // Discovery time (DFS)
    int endp_time;   // Finish time (DFS)
    int pred;        // Predecessor vertex index (for paths/Union-Find)
    edge_t *edges;   // Array of edges (adjacency list)
};

/*
 * =====================
 * LINK STRUCTURE
 * =====================
 *
 * A "link" is used to represent an edge when sorting
 * (useful for algorithms like Kruskal's MST).
 * - src: Source vertex.
 * - dst: Destination vertex.
 * - weight: Edge weight.
 */
typedef struct {
    int src, dst, weight;  // Edge representation for sorting
} link;

/*
 * =====================
 * UNION-FIND UNION OPERATION
 * =====================
 *
 * This function is part of Kruskal's Minimum Spanning Tree algorithm.
 * It attempts to "union" two disjoint sets if their roots are different.
 *
 * Parameters:
 * - g: Pointer to the graph.
 * - edges: Array of edges (sorted by weight).
 * - i: Root of the first set.
 * - j: Root of the second set.
 * - k: Index of the current edge being considered.
 * - weight: Pointer to total MST weight (accumulator).
 * - ne: Pointer to number of edges in the MST (accumulator).
 *
 * Behavior:
 * - If i and j are different (no cycle formed):
 *   - Print the edge being added.
 *   - Update the predecessor of j to point to i (union).
 *   - Add the edge's weight to total MST weight.
 *   - Increment the number of edges in the MST.
 */
static void union_find_union(graph_t *g, link *edges,
    int i, int j, int k, int *weight, int *ne
) {
    if (i != j) {  // Only join sets if roots are different (avoids cycles)
        fprintf(stdout, "Edge %d-%d (w=%d)\n",
            edges[k].src, edges[k].dst, edges[k].weight);

        // Union operation: make vertex j's set a child of i's set
        g->g[j].pred = i;

        // Update MST weight and edge count
        *weight += edges[k].weight;
        *ne = *ne + 1;
    }
    return;
}
