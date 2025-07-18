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

// Function prototypes for graph operations
void graph_attribute_init(graph_t *g);
void graph_dfs(graph_t *g, vertex_t *n);
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime);
void graph_bfs(graph_t *g, vertex_t *src);
void graph_dispose(graph_t *g);

// Queue function prototypes
queue_t *queue_init(int capacity);
void queue_put(queue_t *q, vertex_t *item);
vertex_t *queue_get(queue_t *q);
int queue_empty(queue_t *q);
void queue_dispose(queue_t *q);

// Initialize graph attributes
void graph_attribute_init(graph_t *g) {
    vertex_t *n = g->g;
    while (n != NULL) {
        n->color = WHITE;
        n->disc_time = -1;
        n->endp_time = -1;
        n->dist = -1; // For BFS
        n->pred = NULL;
        n = n->next;
    }
}

// Depth-First Search (DFS)
void graph_dfs(graph_t *g, vertex_t *n) {
    int currTime = 0;
    vertex_t *t1, *t2;

    printf("DFS - List of edges:\n");
    currTime = graph_dfs_r(g, n, currTime);

    // Handle disconnected components
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        if (t1->color == WHITE) {
            currTime = graph_dfs_r(g, t1, currTime);
        }
    }

    printf("DFS - List of vertices:\n");
    for (t1 = g->g; t1 != NULL; t1 = t1->next) {
        t2 = t1->pred;
        printf("%2d: %2d/%2d (%d)\n",
               t1->id, t1->disc_time, t1->endp_time,
               (t2 != NULL) ? t2->id : -1);
    }
}

// Recursive DFS helper
int graph_dfs_r(graph_t *g, vertex_t *n, int currTime) {
    edge_t *e;
    vertex_t *t;

    n->color = GREY;
    n->disc_time = ++currTime;
    e = n->head;

    while (e != NULL) {
        t = e->dst;
        if (t->color == WHITE) {
            printf("%d -> %d : T\n", n->id, t->id);
            t->pred = n;
            currTime = graph_dfs_r(g, t, currTime);
        } else if (t->color == GREY) {
            printf("%d -> %d : B\n", n->id, t->id);
        } else if (t->color == BLACK) {
            printf("%d -> %d : C\n", n->id, t->id);
        }
        e = e->next;
    }

    n->color = BLACK;
    n->endp_time = ++currTime;
    return currTime;
}

// Breadth-First Search (BFS)
void graph_bfs(graph_t *g, vertex_t *src) {
    queue_t *q = queue_init(100); // Adjust capacity as needed
    vertex_t *n, *t;
    edge_t *e;

    printf("BFS - List of edges:\n");
    src->color = GREY;
    src->dist = 0;
    src->pred = NULL;
    queue_put(q, src);

    while (!queue_empty(q)) {
        n = queue_get(q);
        e = n->head;

        while (e != NULL) {
            t = e->dst;
            if (t->color == WHITE) {
                printf("%d -> %d\n", n->id, t->id);
                t->color = GREY;
                t->dist = n->dist + 1;
                t->pred = n;
                queue_put(q, t);
            }
            e = e->next;
        }

        n->color = BLACK;
    }

    printf("BFS - List of vertices:\n");
    for (n = g->g; n != NULL; n = n->next) {
        printf("%2d: Distance = %d, Predecessor = %d\n",
               n->id, n->dist, (n->pred != NULL) ? n->pred->id : -1);
    }

    queue_dispose(q);
}

// Queue implementation for BFS
queue_t *queue_init(int capacity) {
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->data = (vertex_t **)malloc(capacity * sizeof(vertex_t *));
    q->front = q->rear = q->size = 0;
    q->capacity = capacity;
    return q;
}

void queue_put(queue_t *q, vertex_t *item) {
    if (q->size == q->capacity) {
        printf("Queue overflow\n");
        return;
    }
    q->data[q->rear] = item;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

vertex_t *queue_get(queue_t *q) {
    if (q->size == 0) {
        printf("Queue underflow\n");
        return NULL;
    }
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

// Function to dispose of the graph
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

// Main function
int main() {
    // Initialize a graph (example)
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->g = NULL; // Replace with actual graph construction

    vertex_t *src = NULL; // Replace with source vertex setup

    // Initialize graph attributes
    graph_attribute_init(g);

    // Run BFS
    if (src != NULL) {
        graph_bfs(g, src);
    } else {
        printf("No source vertex for BFS.\n");
    }

    // Re-initialize graph for DFS
    graph_attribute_init(g);

    // Run DFS
    if (src != NULL) {
        graph_dfs(g, src);
    } else {
        printf("No source vertex for DFS.\n");
    }

    // Dispose of graph
    graph_dispose(g);

    return 0;
}
