#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

// Structure for an edge in the adjacency list
typedef struct Edge {
    struct Vertex *dst;     // Destination vertex
    struct Edge *next;      // Next edge in the adjacency list
} Edge;

// Structure for a vertex in the graph
typedef struct Vertex {
    int id;                 // Vertex identifier
    int color;              // Color for BFS (WHITE, GRAY, BLACK)
    int dist;               // Distance from source vertex
    struct Vertex *pred;    // Predecessor vertex in BFS tree
    Edge *adj;              // Adjacency list (edges)
    struct Vertex *next;    // Next vertex in the graph
} Vertex;

// Structure for the graph
typedef struct Graph {
    Vertex *g;              // Pointer to the list of vertices
    int nv;                 // Number of vertices
} Graph;

// Structure for the queue
typedef struct Queue {
    void **items;
    int head, tail, size, capacity;
} queue_t;

// Queue operations (initialize, add, remove, free)
queue_t *queue_init(int capacity);
void queue_put(queue_t *q, void *item);
void *queue_get(queue_t *q);
void queue_free(queue_t *q);

// Function prototypes
Graph* graph_load(char *filename);
void graph_attribute_init(Graph *g);
void graph_bfs(Graph *g, Vertex *n);
Vertex* graph_find(Graph *g, int id);
void graph_dispose(Graph *g);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <graph file>\n", argv[0]);
        return 1;
    }

    Graph *g = graph_load(argv[1]);  // Load the graph from file

    printf("Initial vertex? ");
    int i;
    scanf("%d", &i);                 // Read source vertex ID
    Vertex *src = graph_find(g, i);  // Find the source vertex

    if (src == NULL) {
        fprintf(stderr, "Vertex not found!\n");
        graph_dispose(g);
        return 1;
    }

    graph_attribute_init(g);         // Initialize graph attributes
    graph_bfs(g, src);               // Perform BFS traversal

    // Print BFS results
    printf("List of vertices:\n");
    Vertex *n = g->g;
    while (n != NULL) {
        if (n->color != WHITE) {     // Skip unvisited vertices
            printf("%2d: %d (%d)\n",
                   n->id,
                   n->dist,
                   n->pred ? n->pred->id : -1);
        }
        n = n->next;
    }

    graph_dispose(g);                // Free graph memory
    return 0;
}

// BFS Implementation
void graph_bfs(Graph *g, Vertex *n) {
    queue_t *qp;          // Queue pointer
    Vertex *d;            // Destination vertex
    Edge *e;              // Pointer to the edges of a vertex

    qp = queue_init(g->nv);   // Initialize queue with graph's vertex count
    n->color = GRAY;          // Mark source vertex as discovered (GRAY)
    n->dist = 0;              // Distance from source is 0
    n->pred = NULL;           // Source has no predecessor
    queue_put(qp, (void *)n); // Enqueue the source vertex

    // BFS Traversal
    while ((n = (Vertex *)queue_get(qp)) != NULL) { // If queue is not empty
        e = n->adj;          // Get adjacency list of current vertex
        while (e != NULL) {
            d = e->dst;      // Get destination vertex
            if (d->color == WHITE) {   // If destination vertex is unvisited (WHITE)
                d->color = GRAY;       // Mark as discovered
                d->dist = n->dist + 1; // Update distance from source
                d->pred = n;           // Set predecessor
                queue_put(qp, (void *)d); // Enqueue the vertex
            }
            e = e->next;     // Move to the next edge in adjacency list
        }
        n->color = BLACK;    // Mark current vertex as fully explored (BLACK)
    }

    queue_free(qp);          // Dispose of the queue
}

// Initialize graph attributes for BFS
void graph_attribute_init(Graph *g) {
    Vertex *n = g->g;
    while (n != NULL) {
        n->color = WHITE;   // Set all vertices as unvisited
        n->dist = INT_MAX;  // Infinite distance
        n->pred = NULL;     // No predecessor
        n = n->next;
    }
}

// Find a vertex in the graph by ID
Vertex* graph_find(Graph *g, int id) {
    Vertex *n = g->g;
    while (n != NULL) {
        if (n->id == id) return n;
        n = n->next;
    }
    return NULL;
}

// Free memory for the graph
void graph_dispose(Graph *g) {
    Vertex *n = g->g, *tmp;
    while (n != NULL) {
        Edge *e = n->adj, *etmp;
        while (e != NULL) {
            etmp = e->next;
            free(e);
            e = etmp;
        }
        tmp = n->next;
        free(n);
        n = tmp;
    }
    free(g);
}

// Queue Helper Functions
queue_t *queue_init(int capacity) {
    queue_t *q = malloc(sizeof(queue_t));
    q->items = malloc(sizeof(void *) * capacity);
    q->head = q->tail = q->size = 0;
    q->capacity = capacity;
    return q;
}

void queue_put(queue_t *q, void *item) {
    if (q->size == q->capacity) return; // Queue is full
    q->items[q->tail] = item;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}

void *queue_get(queue_t *q) {
    if (q->size == 0) return NULL; // Queue is empty
    void *item = q->items[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return item;
}

void queue_free(queue_t *q) {
    free(q->items);
    free(q);
}
