#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Dequeue operation
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Graph structure
struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
};

// Create a graph with given vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // For undirected graph
}

// BFS algorithm
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();
    int visited[MAX] = {0};

    printf("BFS Traversal: ");
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Main function to test BFS
int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    BFS(graph, 0); // Start BFS from vertex 0

    return 0;
}
