#include <stdio.h>
#include <stdlib.h>

#define WHITE 0 // Unvisited
#define GREY 1  // Visiting
#define BLACK 2 // Fully visited

// Structure for an edge in the adjacency list
typedef struct Edge {
    struct Vertex *dst; // Destination vertex
    struct Edge *next;  // Pointer to the next edge
} edge_t;

// Structure for a vertex
typedef struct Vertex {
    int id;             // Unique identifier for the vertex
    int color;          // Color of the vertex (WHITE, GREY, BLACK)
    int disc_time;      // Discovery time (DFS)
    int endp_time;      // Finish time (DFS)
    int dist;           // Distance from source (BFS)
    struct Vertex *pred; // Predecessor vertex
    struct Edge *head;  // Head of the adjacency list (edges)
    struct Vertex *next; // Pointer to the next vertex
} vertex_t;

// Structure for the graph
typedef struct Graph {
    vertex_t *g; // Pointer to the list of vertices
} graph_t;

// Queue structure for BFS
typedef struct Queue {
    vertex_t **data;
    int front, rear, size, capacity;
} queue_t;

// Function Prototypes
void graph_attribute_init(graph_t *g);
void graph_dfs(graph_t *g, vertex_t *n);
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime);
void graph_bfs(graph_t *g, vertex_t *src);
void graph_dispose(graph_t *g);

queue_t *queue_init(int capacity);
void queue_put(queue_t *q, vertex_t *item);
vertex_t *queue_get(queue_t *q);
int queue_empty(queue_t *q);
void queue_dispose(queue_t *q);

// Initialize graph attributes for DFS and BFS
void graph_attribute_init(graph_t *g) {
    vertex_t *n = g->g;
    while (n != NULL) {
        n->color = WHITE;
        n->disc_time = -1; // DFS-specific
        n->endp_time = -1; // DFS-specific
        n->dist = -1;      // BFS-specific
        n->pred = NULL;    // Common attribute
        n = n->next;
    }
}

// Perform Depth-First Search
void graph_dfs(graph_t *g, vertex_t *n) {
    int currTime = 0;
    vertex_t *v;

    printf("DFS - Traversal:\n");
    currTime = graph_dfs_r(g, n, currTime);

    // Handle disconnected components
    for (v = g->g; v != NULL; v = v->next) {
        if (v->color == WHITE) {
            currTime = graph_dfs_r(g, v, currTime);
        }
    }

    // Print the vertices with discovery and finish times
    printf("DFS - Vertex Timings:\n");
    for (v = g->g; v != NULL; v = v->next) {
        printf("Vertex %d: Discovery = %d, Finish = %d\n",
               v->id, v->disc_time, v->endp_time);
    }
}

// Recursive helper for DFS
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime) {
    edge_t *e;
    vertex_t *v;

    n->color = GREY;
    n->disc_time = ++currTime;

    for (e = n->head; e != NULL; e = e->next) {
        v = e->dst;
        if (v->color == WHITE) {
            v->pred = n;
            currTime = graph_dfs_r(g, v, currTime);
        }
    }

    n->color = BLACK;
    n->endp_time = ++currTime;
    return currTime;
}

// Perform Breadth-First Search
void graph_bfs(graph_t *g, vertex_t *src) {
    queue_t *q = queue_init(100); // Adjust size if needed
    vertex_t *n, *v;
    edge_t *e;

    printf("BFS - Traversal:\n");
    src->color = GREY;
    src->dist = 0;
    queue_put(q, src);

    while (!queue_empty(q)) {
        n = queue_get(q);
        for (e = n->head; e != NULL; e = e->next) {
            v = e->dst;
            if (v->color == WHITE) {
                v->color = GREY;
                v->dist = n->dist + 1;
                v->pred = n;
                queue_put(q, v);
            }
        }
        n->color = BLACK;
    }

    // Print the vertices with their distances and predecessors
    printf("BFS - Vertex Details:\n");
    for (n = g->g; n != NULL; n = n->next) {
        printf("Vertex %d: Distance = %d, Predecessor = %d\n",
               n->id, n->dist, (n->pred != NULL) ? n->pred->id : -1);
    }

    queue_dispose(q);
}

// Free all graph memory
void graph_dispose(graph_t *g) {
    vertex_t *n = g->g;
    while (n != NULL) {
        edge_t *e = n->head;
        while (e != NULL) {
            edge_t *temp_e = e;
            e = e->next;
            free(temp_e);
        }
        vertex_t *temp_n = n;
        n = n->next;
        free(temp_n);
    }
    free(g);
}

// Queue Operations for BFS
queue_t *queue_init(int capacity) {
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->data = (vertex_t **)malloc(capacity * sizeof(vertex_t *));
    q->front = q->rear = q->size = 0;
    q->capacity = capacity;
    return q;
}

void queue_put(queue_t *q, vertex_t *item) {
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

vertex_t *queue_get(queue_t *q) {
    vertex_t *item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

int queue_empty(queue_t *q) {
    return q->size == 0;
}

void queue_dispose(queue_t *q) {
    free(q->data);
    free(q);
}

// Main Function
int main() {
    // Example setup (Graph construction and initialization)
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->g = NULL; // Replace with graph construction logic

    vertex_t *src = NULL; // Replace with the source vertex initialization

    // Initialize attributes for BFS and DFS
    graph_attribute_init(g);

    // Run BFS
    if (src != NULL) {
        graph_bfs(g, src);
    } else {
        printf("No source vertex for BFS.\n");
    }

    // Reinitialize attributes and run DFS
    graph_attribute_init(g);
    if (src != NULL) {
        graph_dfs(g, src);
    } else {
        printf("No source vertex for DFS.\n");
    }

    // Dispose of graph
    graph_dispose(g);

    return 0;
}

/*
=====================================================
Explanation of the Functions
=====================================================
1. **graph_attribute_init(graph_t *g):**
   - Resets all vertices to prepare for BFS and DFS.
   - Sets colors to WHITE, discovery/finish times to -1, and distances to -1.

2. **graph_dfs(graph_t *g, vertex_t *n):**
   - Implements Depth-First Search starting from vertex `n`.
   - Prints traversal and discovery/finish times for each vertex.
   - Calls a recursive helper function for deeper traversal.

3. **graph_dfs_r(graph_t *g, vertex_t *n, int currTime):**
   - Recursively visits connected vertices, updating discovery/finish times.

4. **graph_bfs(graph_t *g, vertex_t *src):**
   - Implements Breadth-First Search starting from the source vertex.
   - Prints vertex distances and their predecessors.

5. **graph_dispose(graph_t *g):**
   - Frees all allocated memory for the graph.

6. **Queue Operations:**
   - Implements a circular queue for BFS traversal, managing vertex processing.

=====================================================
Summary:
- This program combines DFS and BFS for a graph using an adjacency list.
- DFS explores as far as possible along a branch before backtracking.
- BFS explores all neighbors of a vertex before moving deeper.
*/
