#include <stdio.h>    // Includes standard I/O functions (printf, fopen, etc.)
#include <stdlib.h>   // Includes standard library functions (malloc, calloc, free, exit, etc.)
#include <limits.h>   // Includes INT_MAX (used for initializing distances)

// Define a maximum line length for reading from the file
#define MAX_LINE 100

// Define colors for graph algorithms (e.g., BFS/DFS)
enum { WHITE, GREY, BLACK };
// WHITE = unvisited, GREY = visiting, BLACK = visited

/*
 * Structure representing a single vertex in the graph.
 */

typedef struct vertex_s vertex_t;
typedef struct graph_s  graph_t;

struct vertex_s {
    int id;      // The integer identifier of the vertex
    int color;   // The color of the vertex (WHITE, GREY, BLACK)
    int dist;    // Distance value (used in BFS/DFS or shortest path)
    int pred;    // Predecessor vertex index
    int dtime;   // Discovery time (for DFS)
    int ftime;   // Finishing time (for DFS)
    int scc;     // Strongly connected component identifier (if needed)
};

/*
 * Structure representing the entire graph.
 * It contains:
 *   - An array of vertices (v)
 *   - A 2D adjacency matrix (rowAdj)
 *   - The number of vertices (nv)
 *   - The number of edges (ne)
 *   - A flag indicating if the graph is directed (directed)
 */
struct graph_s {
    vertex_t *v;     // Array of vertices
    int **rowAdj;    // 2D adjacency matrix for edges/weights
    int nv;          // Number of vertices
    int ne;          // Number of edges
    int directed;    // 1 if directed, 0 if undirected
};

/*************************************************************
 * Function: allocate_matrix
 * Purpose:
 *   Allocates a 2D matrix of size n x n (each element is int).
 *   Returns a pointer to the allocated matrix.
 *************************************************************/
int **allocate_matrix(int n) {
    int **matrix = (int **)calloc(n, sizeof(int *)); // Allocate an array of int* for n rows
    if (!matrix) {                                   // Check if allocation failed
        fprintf(stderr, "Error: could not allocate adjacency matrix.\n");
        exit(EXIT_FAILURE);                          // Exit if allocation fails
    }

    // For each row, allocate an array of n integers
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));   // Allocate n ints (initialized to 0)
        if (!matrix[i]) {                            // Check if allocation failed
            fprintf(stderr, "Error: could not allocate adjacency matrix row.\n");
            exit(EXIT_FAILURE);                      // Exit if allocation fails
        }
    }
    return matrix; // Return pointer to the 2D matrix
}

/*************************************************************
 * Function: free_matrix
 * Purpose:
 *   Frees the memory used by a 2D integer matrix of size n x n.
 *************************************************************/
void free_matrix(int **matrix, int n) {
    if (!matrix) return;                // If matrix is NULL, nothing to free

    for (int i = 0; i < n; i++) {
        free(matrix[i]);                // Free each row
    }
    free(matrix);                       // Free the array of row pointers
}

/*************************************************************
 * Function: graph_attribute_init
 * Purpose:
 *   Initializes the attributes of each vertex in the graph
 *   to default values (id, color, distance, etc.).
 *************************************************************/
void graph_attribute_init(graph_t *g) {
    for (int i = 0; i < g->nv; i++) {
        g->v[i].id    = i;       // Vertex identifier set to its index
        g->v[i].color = WHITE;   // Initially unvisited (WHITE)
        g->v[i].dist  = INT_MAX; // Distance set to maximum
        g->v[i].pred  = -1;      // No predecessor
        g->v[i].dtime = -1;      // Discovery time not set
        g->v[i].ftime = -1;      // Finishing time not set
        g->v[i].scc   = -1;      // SCC (if used) not set
    }
}

/*************************************************************
 * Function: graph_load
 * Purpose:
 *   Reads a graph definition from a file. The file format is:
 *       nv directed_flag
 *       i j weight
 *       i j weight
 *       ...
 *   It allocates and returns a pointer to a new graph_t object
 *   containing the adjacency matrix and vertex array.
 *************************************************************/
graph_t *graph_load(const char *filename) {
    FILE *fp = fopen(filename, "r");      // Open the file in read mode
    if (!fp) {                            // Check if file opening failed
        fprintf(stderr, "Error: cannot open file '%s'.\n", filename);
        return NULL;                      // Return NULL on error
    }

    // Allocate memory for the graph structure
    graph_t *g = (graph_t *)calloc(1, sizeof(graph_t));
    if (!g) {                             // Check if allocation failed
        fprintf(stderr, "Error: cannot allocate graph.\n");
        fclose(fp);                       // Close the file before returning
        return NULL;
    }

    // Temporary buffer to read lines from the file
    char line[MAX_LINE];

    // Read the first line (expected to contain "nv directed_flag")
    if (!fgets(line, MAX_LINE, fp)) {
        fprintf(stderr, "Error: file is empty or invalid.\n");
        free(g);                          // Free the graph structure
        fclose(fp);                       // Close file
        return NULL;
    }

    // Parse the first line to get number of vertices and directed flag
    // Example: "10 1" => 10 vertices, directed=1
    if (sscanf(line, "%d %d", &g->nv, &g->directed) != 2) {
        fprintf(stderr, "Error: invalid first line (should be 'nv directed_flag').\n");
        free(g);
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the array of vertices
    g->v = (vertex_t *)calloc(g->nv, sizeof(vertex_t));
    if (!g->v) {                          // Check if allocation failed
        fprintf(stderr, "Error: cannot allocate vertex array.\n");
        free(g);
        fclose(fp);
        return NULL;
    }

    // Initialize the vertices with default values
    graph_attribute_init(g);

    // Allocate the adjacency matrix for g->nv x g->nv
    g->rowAdj = allocate_matrix(g->nv);

    // Variables to hold i, j, and weight while reading edges
    int i, j, w;
    g->ne = 0; // Initialize edge count to 0

    // Read subsequent lines until EOF
    while (fgets(line, MAX_LINE, fp)) {
        // Parse each line as "i j w"
        if (sscanf(line, "%d %d %d", &i, &j, &w) == 3) {
            // Check that i, j are within valid range
            if (i < 0 || i >= g->nv || j < 0 || j >= g->nv) {
                fprintf(stderr, "Warning: invalid edge (%d %d %d) ignored.\n", i, j, w);
                continue; // Skip this invalid edge
            }

            // Assign the weight to the adjacency matrix cell
            g->rowAdj[i][j] = w; // Directed edge from i to j
            g->ne++;            // Increment edge count

            // If undirected, mirror the edge (j -> i)
            if (!g->directed) {
                g->rowAdj[j][i] = w;
            }
        }
    }

    fclose(fp); // Close the file
    return g;   // Return the newly created graph
}

/*************************************************************
 * Function: graph_dispose
 * Purpose:
 *   Frees all the memory associated with the graph, including
 *   the adjacency matrix and the vertex array.
 *************************************************************/
void graph_dispose(graph_t *g) {
    if (!g) return;                      // If graph is NULL, nothing to dispose
    free_matrix(g->rowAdj, g->nv);       // Free the adjacency matrix
    free(g->v);                          // Free the array of vertices
    free(g);                             // Finally, free the graph structure
}

/*************************************************************
 * Function: graph_print_matrix
 * Purpose:
 *   Prints the adjacency matrix of the graph in a formatted
 *   manner for debugging or visualization.
 *************************************************************/
void graph_print_matrix(const graph_t *g) {
    printf("Adjacency Matrix (%d vertices):\n", g->nv); // Print number of vertices

    // Loop through rows
    for (int i = 0; i < g->nv; i++) {
        // Loop through columns
        for (int j = 0; j < g->nv; j++) {
            // Print the weight stored in rowAdj[i][j]
            // (4d means 4-width integer, aligned right)
            printf("%4d ", g->rowAdj[i][j]);
        }
        printf("\n"); // New line after each row
    }
}

/*
 * Main function:
 *   - Loads the graph from a file ("graph_data.txt")
 *   - Prints some information (number of vertices, edges, etc.)
 *   - Prints the adjacency matrix
 *   - Disposes the graph
 */
int main(void) {
    // Name of the file containing the graph data
    const char *filename = "graph_data.txt";

    // Load the graph from the file
    graph_t *myGraph = graph_load(filename);
    if (!myGraph) { // If loading failed, print error and exit
        fprintf(stderr, "Graph loading failed.\n");
        return EXIT_FAILURE;
    }

    // Print basic info about the graph
    printf("Graph loaded from '%s'\n", filename);
    printf("Number of vertices: %d\n", myGraph->nv);
    printf("Directed: %s\n", myGraph->directed ? "Yes" : "No");
    printf("Number of edges read: %d\n", myGraph->ne);

    // Print the adjacency matrix
    graph_print_matrix(myGraph);

    // Free the memory used by the graph
    graph_dispose(myGraph);

    // Return success
    return 0;
}
