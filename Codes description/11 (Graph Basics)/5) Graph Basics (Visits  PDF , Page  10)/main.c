#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define constants
#define MAX_LINE 100
enum { WHITE, GREY, BLACK };  // Colors used for graph traversal (WHITE: unvisited, GREY: visited but not fully explored, BLACK: fully explored)

// Forward declarations of structures
typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;

// Structure representing a graph
struct graph_s {
    vertex_t *g;   // Array of vertices
    int nv;        // Number of vertices in the graph
};

// Structure representing a vertex (node in the graph)
struct vertex_s {
    int id;            // Unique identifier for each vertex
    int color;         // Color used for traversal (WHITE, GREY, BLACK)
    int dist;          // Distance from the source in shortest path algorithms (e.g., BFS)
    int disc_time;     // Discovery time for DFS (used in depth-first search)
    int endp_time;     // Finish time for DFS (used in depth-first search)
    int pred;          // Predecessor vertex in shortest path algorithms (e.g., BFS)
    int scc;           // Strongly connected component index (used in SCC algorithms)
    int *rowAdj;       // Array of adjacency list (neighbors of the vertex)
};

// Queue implementation for BFS
typedef struct Queue {
    int *items;
    int front, rear, size, capacity;
} Queue;

// Create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
    queue->items = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Enqueue
void enqueue(Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = item;
    queue->size++;
}

// Dequeue
int dequeue(Queue* queue) {
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// BFS Function
void BFS(graph_t *graph, int start) {
    // Initialize all vertices
    for (int i = 0; i < graph->nv; i++) {
        graph->g[i].color = WHITE;
        graph->g[i].dist = INT_MAX;
        graph->g[i].pred = -1;
    }

    // Initialize the starting vertex
    graph->g[start].color = GREY;
    graph->g[start].dist = 0;
    graph->g[start].pred = -1;

    // Initialize the queue
    Queue *queue = createQueue(graph->nv);
    enqueue(queue, start);

    // While the queue is not empty
    while (!isEmpty(queue)) {
        int u = dequeue(queue);
        vertex_t *currentVertex = &graph->g[u];

        // Explore neighbors
        for (int i = 0; i < graph->nv; i++) {
            if (currentVertex->rowAdj[i] == 1) { // If there's an edge
                vertex_t *neighbor = &graph->g[i];
                if (neighbor->color == WHITE) {
                    neighbor->color = GREY;
                    neighbor->dist = currentVertex->dist + 1;
                    neighbor->pred = currentVertex->id;
                    enqueue(queue, i);
                }
            }
        }
        currentVertex->color = BLACK; // Mark vertex as fully explored
    }

    // Print the BFS result
    printf("Vertex\tDistance\tPredecessor\n");
    for (int i = 0; i < graph->nv; i++) {
        printf("%d\t%d\t\t%d\n", graph->g[i].id, graph->g[i].dist, graph->g[i].pred);
    }

    // Free the queue
    free(queue->items);
    free(queue);
}

// Helper function to create a graph
graph_t* createGraph(int numVertices) {
    graph_t *graph = (graph_t*)malloc(sizeof(graph_t));
    graph->nv = numVertices;
    graph->g = (vertex_t*)malloc(numVertices * sizeof(vertex_t));
    for (int i = 0; i < numVertices; i++) {
        graph->g[i].id = i;
        graph->g[i].rowAdj = (int*)calloc(numVertices, sizeof(int));
    }
    return graph;
}

// Add an edge to the graph
void addEdge(graph_t *graph, int src, int dest) {
    graph->g[src].rowAdj[dest] = 1;
    graph->g[dest].rowAdj[src] = 1; // Assuming an undirected graph
}

// Free the graph memory
void freeGraph(graph_t *graph) {
    for (int i = 0; i < graph->nv; i++) {
        free(graph->g[i].rowAdj);
    }
    free(graph->g);
    free(graph);
}

// Main function
int main() {
    int numVertices = 5;
    graph_t *graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("BFS starting from vertex 0:\n");
    BFS(graph, 0);

    freeGraph(graph);
    return 0;
}
