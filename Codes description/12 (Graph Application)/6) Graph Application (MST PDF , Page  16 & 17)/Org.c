#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX // Define infinity as the maximum integer value

// Structure to represent an edge
typedef struct edge_t {
    int src, dest, weight;
} edge_t;

// Structure to represent a graph
typedef struct graph_t {
    int V;  // Number of vertices
    int E;  // Number of edges
    edge_t *edges;  // Array of edges
} graph_t;

// Structure for a priority queue element (for Prim's algorithm)
typedef struct pq_element {
    int vertex;
    int key;
} pq_element;

// Structure for the priority queue
typedef struct min_heap {
    pq_element *arr;  // Array of elements
    int *pos;         // Position of each vertex in the heap
    int size;         // Current size of the heap
} min_heap;

// Function to create a new priority queue (min-heap)
min_heap* create_min_heap(int V) {
    min_heap *q = (min_heap *)malloc(sizeof(min_heap));
    q->arr = (pq_element *)malloc(V * sizeof(pq_element));
    q->pos = (int *)malloc(V * sizeof(int));
    q->size = V;
    return q;
}

// Function to swap two elements in the priority queue
void swap(pq_element *a, pq_element *b) {
    pq_element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the priority queue
void min_heapify(min_heap *q, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < q->size && q->arr[left].key < q->arr[smallest].key) {
        smallest = left;
    }
    if (right < q->size && q->arr[right].key < q->arr[smallest].key) {
        smallest = right;
    }
    if (smallest != idx) {
        q->pos[q->arr[smallest].vertex] = idx;
        q->pos[q->arr[idx].vertex] = smallest;

        swap(&q->arr[smallest], &q->arr[idx]);
        min_heapify(q, smallest);
    }
}

// Function to extract the minimum element from the priority queue
pq_element extract_min(min_heap *q) {
    if (q->size == 0) {
        pq_element null_element = {-1, -1}; // Return an invalid element if the heap is empty
        return null_element;
    }

    pq_element root = q->arr[0];
    pq_element last = q->arr[q->size - 1];

    q->arr[0] = last;
    q->pos[last.vertex] = 0;
    q->pos[root.vertex] = q->size - 1;

    q->size--;
    min_heapify(q, 0);

    return root;
}

// Function to decrease the key of a vertex in the priority queue
void decrease_key(min_heap *q, int vertex, int key) {
    int i = q->pos[vertex];
    q->arr[i].key = key;

    while (i && q->arr[i].key < q->arr[(i - 1) / 2].key) {
        q->pos[q->arr[i].vertex] = (i - 1) / 2;
        q->pos[q->arr[(i - 1) / 2].vertex] = i;
        swap(&q->arr[i], &q->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to perform Prim's Algorithm to find the Minimum Spanning Tree
void mst_Prim(graph_t *G, int *w, int source) {
    int *key = (int *)malloc(G->V * sizeof(int));
    int *pred = (int *)malloc(G->V * sizeof(int));
    min_heap *Q = create_min_heap(G->V);

    // Initialize all vertices
    for (int v = 0; v < G->V; v++) {
        key[v] = INF;
        pred[v] = -1;
        Q->arr[v].vertex = v;
        Q->arr[v].key = key[v];
        Q->pos[v] = v;
    }
    key[source] = 0;
    decrease_key(Q, source, key[source]);

    // Loop until the priority queue is empty
    while (Q->size > 0) {
        pq_element u = extract_min(Q);
        int u_vertex = u.vertex;

        // Explore all adjacent vertices of u
        for (int v = 0; v < G->V; v++) {
            // Check if there is an edge between u and v
            if (w[u_vertex * G->V + v] != INF && Q->pos[v] < Q->size) {
                int weight = w[u_vertex * G->V + v];
                if (weight < key[v]) {
                    pred[v] = u_vertex;
                    key[v] = weight;
                    decrease_key(Q, v, key[v]);
                }
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int v = 0; v < G->V; v++) {
        if (pred[v] != -1) {
            printf("%d - %d \t%d\n", pred[v], v, w[pred[v] * G->V + v]);
        }
    }

    // Clean up
    free(key);
    free(pred);
    free(Q->arr);
    free(Q->pos);
    free(Q);
}

