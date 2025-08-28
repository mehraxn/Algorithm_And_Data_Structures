#include <stdio.h>
#include <stdlib.h>

#define WHITE 0 // Vertex has not been visited yet
#define GRAY  1 // Vertex is currently being visited
#define BLACK 2 // Vertex and all its adjacent vertices have been fully processed

// Structure representing an edge in the graph
typedef struct edge_s {
    int weight;            // Weight of the edge
    struct vertex_s *dst;  // Pointer to the destination vertex
    struct edge_s *next;   // Pointer to the next edge in the adjacency list
} edge_t;

// Structure representing a vertex in the graph
typedef struct vertex_s {
    int id;                // Unique ID of the vertex
    int color;             // Color of the vertex (WHITE, GRAY, or BLACK)
    int dist;              // Distance from the source (not used in this example)
    int disc_time;         // Discovery time (first time the vertex is visited)
    int endp_time;         // Finishing time (when all adjacent vertices are processed)
    int scc;               // Strongly Connected Component (optional, not used here)
    struct vertex_s *pred; // Predecessor vertex in the DFS tree
    edge_t *head;          // Head of the adjacency list for this vertex
    struct vertex_s *next; // Pointer to the next vertex in the graph
} vertex_t;

// Structure representing the graph
typedef struct graph_s {
    int nv;                // Number of vertices in the graph
    vertex_t *g;           // Pointer to the list of vertices in the graph
} graph_t;

// Recursive DFS function
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime) {
    edge_t *e;             // Temporary pointer to iterate through the edges of the vertex
    vertex_t *t;           // Temporary pointer to adjacent vertices
    n->color = GRAY;       // Mark the current vertex as being visited
    n->disc_time = ++currTime; // Increment and set the discovery time for the vertex
    e = n->head;           // Get the head of the adjacency list of the current vertex
    while (e != NULL) {    // Loop through all adjacent vertices
        t = e->dst;        // Get the destination vertex of the current edge
        switch (t->color) {
            case WHITE:    // If the adjacent vertex has not been visited yet
                printf("%d -> %d : T\n", n->id, t->id); // Print a Tree edge
                currTime = graph_dfs_r(g, t, currTime);   // Recursively visit the adjacent vertex
                break;
            case GRAY:     // If the adjacent vertex is being visited (cycle detected)
                printf("%d -> %d : B\n", n->id, t->id); // Print a Back edge
                break;
            case BLACK:    // If the adjacent vertex is fully processed
                if (n->disc_time < t->disc_time) {
                    printf("%d -> %d : F\n", n->disc_time, t->disc_time); // Print a Forward edge
                } else {
                    printf("%d -> %d : C\n", n->id, t->id); // Print a Cross edge
                }
                break;
        }
        e = e->next;       // Move to the next edge in the adjacency list
    }
    n->color = BLACK;      // Mark the vertex as fully processed
    n->endp_time = ++currTime; // Increment and set the finishing time
    return currTime;       // Return the current time
}

// Main DFS function
void graph_dfs(graph_t *g, vertex_t *n) {
    int currTime = 0;      // Initialize the current time to 0
    vertex_t *t1, *t2;     // Temporary pointers to vertices

    printf("List of edges:\n");
    currTime = graph_dfs_r(g, n, currTime); // Start DFS from the given vertex

    // Handle disconnected components
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        if (t1->color == WHITE) { // If a vertex has not been visited
            currTime = graph_dfs_r(g, t1, currTime); // Start DFS from this vertex
        }
    }

    // Print information about all vertices
    printf("List of vertices:\n");
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        t2 = t1->pred; // Get the predecessor of the current vertex
        printf("%2d: %2d/%2d (%d)\n", // Print vertex ID, discovery/finishing times, and predecessor ID
               t1->id, t1->disc_time, t1->endp_time,
               (t2 != NULL) ? t1->pred->id : -1);
    }
}

// Helper function to create a new vertex
vertex_t* create_vertex(int id) {
    vertex_t *v = (vertex_t *)malloc(sizeof(vertex_t)); // Allocate memory for the vertex
    v->id = id;                 // Set the vertex ID
    v->color = WHITE;           // Initialize the vertex as unvisited
    v->dist = 0;                // Initialize the distance (not used in this example)
    v->disc_time = 0;           // Initialize the discovery time
    v->endp_time = 0;           // Initialize the finishing time
    v->scc = -1;                // Strongly Connected Component ID (not used here)
    v->pred = NULL;             // No predecessor initially
    v->head = NULL;             // No edges initially
    v->next = NULL;             // No next vertex initially
    return v;                   // Return the created vertex
}

// Helper function to add an edge to a vertex
void add_edge(vertex_t *src, vertex_t *dst, int weight) {
    edge_t *e = (edge_t *)malloc(sizeof(edge_t)); // Allocate memory for the edge
    e->weight = weight;          // Set the weight of the edge
    e->dst = dst;                // Set the destination vertex
    e->next = src->head;         // Insert the edge at the head of the adjacency list
    src->head = e;               // Update the head of the adjacency list
}

// Helper function to create a graph
graph_t* create_graph() {
    graph_t *g = (graph_t *)malloc(sizeof(graph_t)); // Allocate memory for the graph
    g->nv = 0;                 // Initialize the number of vertices to 0
    g->g = NULL;               // Initialize the vertex list as empty
    return g;                  // Return the created graph
}

// Helper function to add a vertex to the graph
void add_vertex(graph_t *g, vertex_t *v) {
    v->next = g->g;            // Add the new vertex at the head of the vertex list
    g->g = v;                  // Update the head of the graph's vertex list
    g->nv++;                   // Increment the number of vertices
}

// Example usage
int main() {
    graph_t *g = create_graph(); // Create a new graph

    // Create vertices
    vertex_t *v1 = create_vertex(1);
    vertex_t *v2 = create_vertex(2);
    vertex_t *v3 = create_vertex(3);
    vertex_t *v4 = create_vertex(4);

    // Add edges with weights
    add_edge(v1, v2, 5);       // Add an edge from vertex 1 to vertex 2 with weight 5
    add_edge(v1, v3, 10);      // Add an edge from vertex 1 to vertex 3 with weight 10
    add_edge(v2, v4, 15);      // Add an edge from vertex 2 to vertex 4 with weight 15
    add_edge(v3, v4, 20);      // Add an edge from vertex 3 to vertex 4 with weight 20

    // Add vertices to the graph
    add_vertex(g, v1);         // Add vertex 1 to the graph
    add_vertex(g, v2);         // Add vertex 2 to the graph
    add_vertex(g, v3);         // Add vertex 3 to the graph
    add_vertex(g, v4);         // Add vertex 4 to the graph

    // Perform DFS
    graph_dfs(g, v1);          // Start DFS from vertex 1

    return 0;
}

/*
// Comprehensive Explanation of Functions and Code:

1. **create_vertex**
   - Allocates memory for a vertex and initializes its fields (ID, color, discovery/finishing times, etc.).
   - Returns the pointer to the created vertex.

2. **add_edge**
   - Creates and initializes a new edge from a source vertex to a destination vertex.
   - Adds the edge to the source vertex's adjacency list.

3. **create_graph**
   - Allocates memory for a graph and initializes its fields (number of vertices, vertex list).
   - Returns the pointer to the created graph.

4. **add_vertex**
   - Adds a vertex to the graph by inserting it at the head of the vertex list.
   - Increments the graph's vertex count.

5. **graph_dfs_r**
   - Recursive function to perform Depth-First Search on a graph.
   - Updates discovery and finishing times for each vertex.
   - Traverses edges and classifies them (Tree, Back, Forward, Cross).

6. **graph_dfs**
   - Initiates DFS from a given starting vertex.
   - Handles disconnected components by checking unvisited vertices.
   - Prints discovery/finishing times and predecessors for all vertices.

7. **main**
   - Demonstrates the creation of a graph, addition of vertices and edges, and execution of DFS.
   - Outputs details about edges and vertices during and after DFS.
*/
