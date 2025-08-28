#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define constants for graph traversal states
#define MAX_LINE 100
enum {WHITE, GREY, BLACK};  // WHITE: unvisited, GREY: visited but not fully explored, BLACK: fully explored

// Forward declarations of structures
typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;
typedef struct edge_s edge_t;

// Structure representing a graph
struct graph_s {
    vertex_t *g;   // Pointer to the linked list of vertices
    int nv;        // Number of vertices in the graph
};

// Structure representing a vertex (node in the graph)
struct vertex_s {
    int id;            // Unique identifier for the vertex
    int color;         // Color used for traversal (WHITE, GREY, BLACK)
    int dist;          // Distance from the source in shortest path algorithms (e.g., BFS)
    int disc_time;     // Discovery time for DFS
    int endp_time;     // Finish time for DFS
    int pred;          // Predecessor vertex in shortest path algorithms
    int scc;           // Strongly connected component index
    edge_t *head;      // Head of the adjacency list (linked list of edges)
    vertex_t *next;    // Pointer to the next vertex in the graph's list
};

// Structure representing an edge (connection between vertices)
struct edge_s {
    vertex_t *dst;     // Destination vertex of the edge
    int weight;        // Weight of the edge
    edge_t *next;      // Next edge in the adjacency list
};

// Function prototypes (basic graph operations)
graph_t *graph_load(char *filename);
static vertex_t *new_node(vertex_t *g, int id);
static void new_edge(graph_t *g, int i, int j, int weight);
void graph_attribute_init(graph_t *g);
vertex_t *graph_find(graph_t *g, int id);
void graph_dispose(graph_t *g);

// Function to load a graph from a file
graph_t *graph_load(char *filename) {
    graph_t *g;
    char line[MAX_LINE];
    int i, j, weight, dir;
    FILE *fp;

    // Allocate memory for the graph
    g = (graph_t *) util_calloc(1, sizeof(graph_t));
    fp = util_fopen(filename, "r");

    // Read the first line for the number of vertices and directed/undirected info
    fgets(line, MAX_LINE, fp);
    if (sscanf(line, "%d%d", &g->nv, &dir) != 2) {
        sscanf(line, "%d", &g->nv);
        dir = 1;  // Default to directed graph if not specified
    }

    // Create initial structure for vertices
    for (i = g->nv - 1; i >= 0; i--) {
        g->g = new_node(g->g, i);  // Create a new vertex and link it to the graph
    }

    // Load edges from the file
    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (sscanf(line, "%d%d%d", &i, &j, &weight) != 3) {
            sscanf(line, "%d%d", &i, &j);
            weight = 1;  // Default weight is 1 if not specified
        }
        new_edge(g, i, j, weight);  // Add the edge to the graph
        if (dir == 0) {
            new_edge(g, j, i, weight);  // For undirected graph, add reverse edge
        }
    }

    fclose(fp);
    return g;  // Return the graph
}

// Function to create a new vertex node and link it to the graph
static vertex_t *new_node(vertex_t *g, int id) {
    vertex_t *v;
    v = (vertex_t *) util_malloc(sizeof(vertex_t));
    v->id = id;
    v->color = WHITE;
    v->dist = INT_MAX;
    v->scc = v->disc_time = v->endp_time = -1;
    v->pred = NULL;
    v->head = NULL;  // No edges initially
    v->next = g;     // Link the new vertex to the existing list of vertices
    return v;
}

// Function to add a new edge between two vertices (i and j) with a given weight
static void new_edge(graph_t *g, int i, int j, int weight) {
    vertex_t *src, *dst;
    edge_t *e;

    // Find the source and destination vertices by their IDs
    src = graph_find(g, i);
    dst = graph_find(g, j);

    // Create a new edge
    e = (edge_t *) util_malloc(sizeof(edge_t));
    e->dst = dst;    // Set the destination of the edge
    e->weight = weight;  // Set the weight of the edge
    e->next = src->head;  // Link the new edge to the head of the adjacency list
    src->head = e;    // Make the new edge the first edge in the adjacency list of the source
}

// Function to initialize the attributes of all vertices in the graph
void graph_attribute_init(graph_t *g) {
    vertex_t *v;
    v = g->g;
    while (v != NULL) {
        v->color = WHITE;         // Set color to WHITE (unvisited)
        v->dist = INT_MAX;        // Set distance to infinity (unreachable initially)
        v->disc_time = -1;        // Set discovery time to -1 (undefined)
        v->endp_time = -1;        // Set end time to -1 (undefined)
        v->scc = -1;              // Set SCC index to -1 (no SCC assigned)
        v->pred = NULL;           // Set predecessor to NULL (no predecessor)
        v = v->next;              // Move to the next vertex in the list
    }
    return;
}

// Function to find a vertex in the graph by its ID
vertex_t *graph_find(graph_t *g, int id) {
    vertex_t *v;
    v = g->g;
    while (v != NULL) {
        if (v->id == id) {
            return v;  // Return the vertex if the ID matches
        }
        v = v->next;  // Move to the next vertex in the list
    }
    return NULL;  // Return NULL if the vertex with the given ID is not found
}

// Function to dispose of the graph's memory (free the memory)
void graph_dispose(graph_t *g) {
    vertex_t *v;
    edge_t *e;
    v = g->g;
    while (v != NULL) {
        while (v->head != NULL) {
            e = v->head;
            v->head = e->next;  // Remove the edge from the adjacency list
            free(e);             // Free the memory for the edge
        }
        v = v->next;  // Move to the next vertex
        free(v);      // Free the memory for the vertex
    }
    free(g);         // Free the memory for the graph itself
    return;
}
