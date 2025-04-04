#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF INT_MAX

// Node structure for the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjList;
    int* color;
    int* dtime;
    int* pred;
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
Queue* createQueue(int capacity);
void enqueue(Queue* queue, int vertex);
int dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);
void bfs(Graph* graph, int startVertex);

// Main function
int main() {
    int vertices = 5; // Example: Graph with 5 vertices
    Graph* graph = createGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    int startVertex = 0; // Start BFS from vertex 0
    bfs(graph, startVertex);

    // Print distances and predecessors
    printf("Vertex\tDistance\tPredecessor\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\t\t", i, graph->dtime[i]);
        if (graph->pred[i] == -1)
            printf("NULL\n");
        else
            printf("%d\n", graph->pred[i]);
    }

    return 0;
}

// Create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    graph->color = (int*)malloc(vertices * sizeof(int));
    graph->dtime = (int*)malloc(vertices * sizeof(int));
    graph->pred = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->color[i] = WHITE;
        graph->dtime[i] = INF;
        graph->pred[i] = -1;
    }

    return graph;
}

// Add edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since the graph is undirected, add the reverse edge
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Enqueue operation
void enqueue(Queue* queue, int vertex) {
    if (queue->size == queue->capacity) {
        printf("Queue overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = vertex;
    queue->size++;
}

// Dequeue operation
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int vertex = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return vertex;
}

// Check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

// BFS implementation
void bfs(Graph* graph, int startVertex) {
    Queue* queue = createQueue(graph->numVertices);

    graph->color[startVertex] = GRAY;
    graph->dtime[startVertex] = 0;
    graph->pred[startVertex] = -1;

    enqueue(queue, startVertex);

    while (!isQueueEmpty(queue)) {
        int u = dequeue(queue);

        Node* temp = graph->adjList[u];
        while (temp) {
            int v = temp->vertex;
            if (graph->color[v] == WHITE) {
                graph->color[v] = GRAY;
                graph->dtime[v] = graph->dtime[u] + 1;
                graph->pred[v] = u;
                enqueue(queue, v);
            }
            temp = temp->next;
        }

        graph->color[u] = BLACK;
    }

    free(queue->data);
    free(queue);
}
