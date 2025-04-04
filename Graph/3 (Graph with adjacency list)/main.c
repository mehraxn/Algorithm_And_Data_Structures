/************************************************************
 * FILE: graph.c
 *
 * PURPOSE:
 *   Demonstrates a directed, weighted graph implementation
 *   using an adjacency list in C. This code creates a graph
 *   structure (graph_t) with a linked list of vertices, and
 *   each vertex has a linked list of edges. The graph is
 *   loaded from a file (e.g., "graph.txt").
 *
 *   This version is heavily commented: each line is annotated,
 *   and each function has an explanatory passage below it.
 *
 *   Example usage:
 *     1) Create a file "graph.txt" with the following format:
 *        - First line: number of vertices (e.g., 9)
 *        - Subsequent lines: "src dst weight"
 *     2) Compile and run:
 *        gcc graph.c -o graph
 *        ./graph
 ************************************************************/

#include <stdio.h>      // For file I/O and printing
#include <stdlib.h>     // For malloc, free, exit, etc.
#include <string.h>     // For string manipulation (not heavily used here)
#include <limits.h>     // For INT_MAX (used as a sentinel value)

//-------------------------------------------------------------
// MACROS
//-------------------------------------------------------------
#define MAX_LINE 100     // Maximum length for reading lines from file

//-------------------------------------------------------------
// ENUMERATION
//-------------------------------------------------------------
// We define three colors commonly used in graph algorithms
// (e.g., BFS/DFS). This is optional, but it's a typical approach.
enum { WHITE, GREY, BLACK };

//-------------------------------------------------------------
// FORWARD DECLARATIONS (TYPEDEFS)
//-------------------------------------------------------------
typedef struct edge_s   edge_t;   // Forward declaration of 'edge_s'
typedef struct vertex_s vertex_t; // Forward declaration of 'vertex_s'
typedef struct graph_s  graph_t;  // Forward declaration of 'graph_s'

//-------------------------------------------------------------
// EDGE STRUCTURE
//-------------------------------------------------------------
// Each edge contains the destination vertex ID, a weight,
// and a pointer to the next edge in the linked list.
struct edge_s {
    int v;              // Destination vertex ID
    int weight;         // Weight of the edge
    edge_t *next;       // Pointer to the next edge in adjacency list
};

//-------------------------------------------------------------
// VERTEX STRUCTURE
//-------------------------------------------------------------
// Each vertex contains:
//   - an ID
//   - color (for algorithms like DFS/BFS)
//   - discovery time, end processing time
//   - a pointer to a predecessor (used in searches)
//   - a pointer to the head of the edge list
//   - a pointer to the next vertex in the linked list of vertices
struct vertex_s {
    int id;             // Vertex identifier
    int color;          // Color for graph algorithms (WHITE, GREY, BLACK)
    int disc_time;      // Discovery time (for DFS, etc.)
    int endp_time;      // End processing time (for DFS, etc.)
    int scc;            // Strongly Connected Component ID (if needed)
    vertex_t *pred;     // Predecessor vertex pointer (if needed)
    edge_t   *head;     // Head of adjacency list for edges
    vertex_t *next;     // Pointer to next vertex in the main vertex list
};

//-------------------------------------------------------------
// GRAPH STRUCTURE
//-------------------------------------------------------------
// The graph contains:
//   - the number of vertices (nv)
//   - the number of edges (ne)
//   - a pointer to the linked list of all vertices (g)
struct graph_s {
    int nv;             // Number of vertices
    int ne;             // Number of edges
    vertex_t *g;        // Pointer to the head of the vertex list
};

//-------------------------------------------------------------
// FUNCTION PROTOTYPES
//-------------------------------------------------------------
graph_t  *graph_load(const char *filename);        // Load graph from file
vertex_t *graph_find(graph_t *g, int id);          // Find a vertex by ID
void      graph_dispose(graph_t *g);               // Free all graph memory
void      graph_attribute_init(graph_t *g);        // Initialize vertex attributes

// Internal (static) helper functions:
static vertex_t *new_node(graph_t *g, int id);     // Create a new vertex node
static void      new_edge(graph_t *g, int src_id,
                          int dst_id, int weight); // Create a new edge

//-------------------------------------------------------------
// FUNCTION: main
//-------------------------------------------------------------
int main(void)
{
    // 1) Load a graph from file "graph.txt"
    graph_t *g = graph_load("graph.txt");  // Call graph_load to build the graph from a file
    if (!g) {                              // Check if graph_load returned NULL (file or memory error)
        fprintf(stderr, "Error: Could not load graph from file.\n"); // Print error if graph could not be loaded
        return 1;                          // Return a non-zero value to indicate failure
    }

    // 2) Print out the adjacency list
    printf("Directed, Weighted Graph (Adjacency List):\n"); // Print a header message

    vertex_t *v = g->g;                    // Start from the head of the vertex list
    while (v) {                            // Traverse all vertices
        printf("Vertex %d:", v->id);       // Print the current vertex ID
        edge_t *e = v->head;               // Start from the head of the edge list for this vertex
        while (e) {                        // Traverse all edges of this vertex
            // Print each edge in the format: -> (v=DEST, w=WEIGHT)
            printf(" -> (v=%d, w=%d)", e->v, e->weight);
            e = e->next;                   // Move to the next edge
        }
        printf("\n");                      // New line after printing all edges for this vertex
        v = v->next;                       // Move to the next vertex
    }

    // 3) Dispose of the graph (free memory)
    graph_dispose(g);                      // Call graph_dispose to free all allocated memory

    return 0;                              // Return 0 to indicate success
}

/************************************************************
 * PASSAGE FOR FUNCTION: main
 *
 * The 'main' function serves as the entry point for the program.
 * 1) It calls 'graph_load' to read the graph definition from
 *    a file named "graph.txt".
 * 2) If the graph is successfully loaded, it prints out the
 *    adjacency list for each vertex, showing the edges (destination
 *    and weight).
 * 3) Finally, it calls 'graph_dispose' to free all memory used
 *    by the graph, then returns 0 (success).
 ************************************************************/


//-------------------------------------------------------------
// FUNCTION: graph_load
//-------------------------------------------------------------
// This function reads the number of vertices and edges from a file,
// creates the vertices, and then reads lines describing each edge.
graph_t *graph_load(const char *filename)
{
    FILE *fp = fopen(filename, "r");        // Open the file in read mode
    if (!fp) {                              // If file couldn't be opened
        fprintf(stderr, "Error opening file %s\n", filename); // Print an error message
        return NULL;                        // Return NULL to indicate failure
    }

    // Allocate memory for the graph structure
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    if (!g) {                               // If malloc returned NULL
        fprintf(stderr, "Out of memory.\n"); // Print error
        fclose(fp);                         // Close the file
        return NULL;                        // Return NULL to indicate failure
    }

    // Initialize graph fields
    g->g  = NULL;                           // Initially no vertices
    g->nv = 0;                              // Number of vertices set to 0
    g->ne = 0;                              // Number of edges set to 0

    // Read the number of vertices from the first line
    char line[MAX_LINE];                    // Buffer to store each line
    if (fgets(line, MAX_LINE, fp) != NULL) {// If we successfully read a line
        sscanf(line, "%d", &g->nv);         // Parse an integer (number of vertices)
    }

    // Create all vertices in the range [0, nv-1]
    for (int i = 0; i < g->nv; i++) {
        new_node(g, i);                    // Call new_node to create each vertex
    }

    // Read edges from subsequent lines: format "src dst weight"
    while (fgets(line, MAX_LINE, fp) != NULL) {  // Read line by line
        int src_id, dst_id, weight;              // Variables to store parsed integers
        // If line can be parsed into 3 integers: "src_id dst_id weight"
        if (sscanf(line, "%d %d %d", &src_id, &dst_id, &weight) == 3) {
            new_edge(g, src_id, dst_id, weight); // Create the edge in adjacency list
            g->ne++;                             // Increment the graph's edge count
        }
    }

    fclose(fp);                                 // Close the file

    // Initialize vertex attributes (color, times, etc.)
    graph_attribute_init(g);                    // Call to set all vertices to default values

    return g;                                   // Return the pointer to the newly created graph
}

/************************************************************
 * PASSAGE FOR FUNCTION: graph_load
 *
 * 'graph_load' takes a filename and attempts to read a graph
 * definition from that file. It:
 * 1) Opens the file for reading.
 * 2) Allocates memory for a 'graph_t' structure.
 * 3) Reads the first line to determine how many vertices (nv)
 *    the graph will have, then creates them via 'new_node'.
 * 4) Reads each subsequent line in the format "src dst weight"
 *    to build edges using 'new_edge'.
 * 5) Initializes all vertex attributes with 'graph_attribute_init'
 *    and returns the completed 'graph_t' pointer. If any error
 *    occurs, it returns NULL.
 ************************************************************/


//-------------------------------------------------------------
// FUNCTION: new_node (static helper)
//-------------------------------------------------------------
// Creates a new vertex with the given ID, initializes its fields,
// and inserts it at the head of the graph's vertex list.
static vertex_t *new_node(graph_t *g, int id)
{
    // Allocate memory for a new vertex
    vertex_t *v = (vertex_t *)malloc(sizeof(vertex_t));
    if (!v) {                               // If malloc fails
        fprintf(stderr, "Out of memory (new_node).\n"); // Print error
        return NULL;                        // Return NULL
    }

    // Initialize the new vertex's fields
    v->id        = id;                     // Set the vertex ID
    v->color     = WHITE;                  // Default color = WHITE
    v->disc_time = INT_MAX;                // Discovery time = INT_MAX (unvisited)
    v->endp_time = INT_MAX;                // End processing time = INT_MAX
    v->scc       = -1;                     // Strongly connected component index = -1
    v->pred      = NULL;                   // No predecessor yet
    v->head      = NULL;                   // No edges yet

    // Insert the new vertex at the head of the vertex list
    v->next = g->g;                        // The new vertex's next points to current head
    g->g    = v;                           // Update the graph's head to this new vertex

    return v;                              // Return the pointer to the newly created vertex
}

/************************************************************
 * PASSAGE FOR FUNCTION: new_node
 *
 * 'new_node' is a helper function that:
 * 1) Allocates memory for a new 'vertex_t'.
 * 2) Initializes its fields (ID, color, disc_time, etc.).
 * 3) Inserts the newly created vertex at the head of the
 *    graph's linked list of vertices.
 *
 * This approach ensures that vertices are stored in a singly
 * linked list, with the most recently created vertex at the front.
 ************************************************************/


//-------------------------------------------------------------
// FUNCTION: new_edge (static helper)
//-------------------------------------------------------------
// Creates a new edge in the adjacency list from src_id to dst_id
// with a given weight.
static void new_edge(graph_t *g, int src_id, int dst_id, int weight)
{
    // Find the source vertex by its ID
    vertex_t *src = graph_find(g, src_id);
    if (!src) {                             // If no vertex with src_id is found
        fprintf(stderr, "Warning: source vertex %d not found.\n", src_id);
        return;                             // Return without creating an edge
    }

    // Allocate memory for a new edge
    edge_t *e = (edge_t *)malloc(sizeof(edge_t));
    if (!e) {                               // If malloc fails
        fprintf(stderr, "Out of memory (new_edge).\n"); // Print error
        return;                             // Return without creating an edge
    }

    // Initialize edge fields
    e->v      = dst_id;                    // Destination vertex ID
    e->weight = weight;                    // Edge weight

    // Insert the new edge at the head of the source vertex's adjacency list
    e->next   = src->head;                 // The new edge's next points to current head
    src->head = e;                         // Update the source vertex's head to this new edge
}

/************************************************************
 * PASSAGE FOR FUNCTION: new_edge
 *
 * 'new_edge' links two vertices in a directed manner:
 *   src_id -> dst_id (with 'weight').
 * It finds the source vertex, creates a new 'edge_t' struct,
 * and inserts it at the head of the source vertex's adjacency
 * list. If the source vertex doesn't exist, it prints a warning.
 ************************************************************/


//-------------------------------------------------------------
// FUNCTION: graph_find
//-------------------------------------------------------------
// Finds a vertex in the graph by its ID and returns a pointer
// to that vertex. If not found, returns NULL.
vertex_t *graph_find(graph_t *g, int id)
{
    vertex_t *v = g->g;                     // Start from the head of the vertex list
    while (v) {                             // Traverse until v is NULL
        if (v->id == id) {                 // If we find a matching ID
            return v;                      // Return the pointer to that vertex
        }
        v = v->next;                       // Move to the next vertex in the list
    }
    return NULL;                            // If we exit the loop, vertex not found -> return NULL
}

/************************************************************
 * PASSAGE FOR FUNCTION: graph_find
 *
 * 'graph_find' iterates over the linked list of vertices,
 * checking each vertex's 'id' field. If it finds a match,
 * it returns that vertex's pointer. Otherwise, it returns NULL.
 * This is a linear-time operation, O(nv), where nv is the
 * number of vertices.
 ************************************************************/


//-------------------------------------------------------------
// FUNCTION: graph_dispose
//-------------------------------------------------------------
// Frees all memory used by the graph: edges first, then vertices,
// then the graph structure itself.
void graph_dispose(graph_t *g)
{
    if (!g) return;                         // If g is NULL, do nothing

    vertex_t *v = g->g;                     // Start at the head of the vertex list
    while (v) {                             // Traverse all vertices
        // Free all edges for this vertex
        edge_t *e = v->head;                // Start at the head of the edge list
        while (e) {                         // Traverse the edge list
            edge_t *tmp_e = e;             // Temporary pointer to the current edge
            e = e->next;                   // Move to the next edge
            free(tmp_e);                   // Free the current edge
        }
        // Free the vertex itself
        vertex_t *tmp_v = v;               // Temporary pointer to the current vertex
        v = v->next;                       // Move to the next vertex
        free(tmp_v);                       // Free the current vertex
    }

    free(g);                                // Finally, free the graph structure
}

/************************************************************
 * PASSAGE FOR FUNCTION: graph_dispose
 *
 * 'graph_dispose' is responsible for deallocating all memory
 * that was allocated to store the graph:
 * 1) It iterates through each vertex, freeing every edge in
 *    that vertex's adjacency list.
 * 2) It frees the vertex itself.
 * 3) Finally, it frees the main 'graph_t' structure.
 *
 * This ensures that all dynamically allocated memory is properly
 * released, preventing memory leaks.
 ************************************************************/


//-------------------------------------------------------------
// FUNCTION: graph_attribute_init
//-------------------------------------------------------------
// Resets/initializes all vertex attributes in the graph.
void graph_attribute_init(graph_t *g)
{
    vertex_t *v = g->g;                     // Start at the head of the vertex list
    while (v) {                             // Traverse all vertices
        v->color     = WHITE;               // Reset color to WHITE
        v->disc_time = INT_MAX;             // Reset discovery time to INT_MAX
        v->endp_time = INT_MAX;             // Reset end processing time to INT_MAX
        v->scc       = -1;                  // Reset strongly connected component ID to -1
        v->pred      = NULL;                // Reset predecessor pointer to NULL
        v = v->next;                        // Move to the next vertex
    }
}

/************************************************************
 * PASSAGE FOR FUNCTION: graph_attribute_init
 *
 * 'graph_attribute_init' iterates through each vertex in
 * the graph and sets all algorithm-related fields (color,
 * discovery time, etc.) to their default values. This function
 * is especially useful before running graph algorithms like
 * BFS, DFS, or others that rely on these attributes.
 ************************************************************/


/*********************************************************************
 * HOW TO USE THIS PROGRAM:
 * 1) Create a file named "graph.txt" in the same directory.
 * 2) The first line should contain the number of vertices, e.g., 9.
 * 3) Then each subsequent line should have "src dst weight".
 *    Example:
 *       9
 *       0 1 2
 *       0 2 4
 *       1 3 1
 *       2 4 7
 *       3 5 3
 *       3 6 1
 *       4 5 2
 *       5 7 5
 *       6 7 3
 *       7 8 2
 *       1 8 6
 *       2 8 1
 *
 * 4) Compile and run:
 *       gcc graph.c -o graph
 *       ./graph
 *
 * 5) The program will print out the adjacency list for each vertex,
 *    showing all directed edges with their weights.
 *********************************************************************/
