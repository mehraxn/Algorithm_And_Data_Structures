#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX // Define infinity as the maximum integer value

// Structure to represent an edge
typedef struct edge_t {
    int src, dest, weight;  // Source vertex, destination vertex, and the weight of the edge
} edge_t;

// Structure for a priority queue element (for Prim's algorithm)
typedef struct pq_element {
    int vertex;  // The vertex in the priority queue
    int key;     // The key value (minimum edge weight) for the vertex
} pq_element;

// Structure for the priority queue (min-heap)
typedef struct min_heap {
    pq_element *arr;  // Array to store heap elements
    int *pos;         // Array to store positions of vertices in the heap
    int size;         // The current size of the heap
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

// Function to perform Prim's Algorithm to find the Minimum Spanning Tree (MST)
void mst_Prim(graph_t *G, int *w, int source) {
    int *key = (int *)malloc(G->V * sizeof(int));  // Key values for each vertex
    int *pred = (int *)malloc(G->V * sizeof(int)); // Predecessor of each vertex in the MST
    min_heap *Q = create_min_heap(G->V);  // Create a min-heap (priority queue)

    // Initialize all vertices: set key to INF and pred to NULL
    for (int v = 0; v < G->V; v++) {
        key[v] = INF;  // Initially, all vertices have an infinite key value
        pred[v] = -1;  // No predecessors initially
        Q->arr[v].vertex = v;  // Set the vertex index
        Q->arr[v].key = key[v];  // Set the key value for each vertex
        Q->pos[v] = v;  // Set the position of each vertex in the heap
    }

    key[source] = 0;  // Set the key value of the source vertex to 0
    decrease_key(Q, source, key[source]);  // Decrease the key of the source vertex to 0

    // Main loop: while the heap is not empty
    while (Q->size > 0) {
        pq_element u = extract_min(Q);  // Extract the vertex with the minimum key value
        int u_vertex = u.vertex;

        // Explore all adjacent vertices of u
        for (int v = 0; v < G->V; v++) {
            // Check if there is an edge between u and v
            if (w[u_vertex * G->V + v] != INF && Q->pos[v] < Q->size) {
                int weight = w[u_vertex * G->V + v];
                // If the edge weight is smaller than the current key value of v, update key and pred
                if (weight < key[v]) {
                    pred[v] = u_vertex;
                    key[v] = weight;
                    decrease_key(Q, v, key[v]);  // Update the position of v in the heap
                }
            }
        }
    }

    // Print the MST (Minimum Spanning Tree)
    printf("Edge \tWeight\n");
    for (int v = 0; v < G->V; v++) {
        if (pred[v] != -1) {
            printf("%d - %d \t%d\n", pred[v], v, w[pred[v] * G->V + v]);
        }
    }

    // Clean up memory
    free(key);
    free(pred);
    free(Q->arr);
    free(Q->pos);
    free(Q);
}

// Main function to test the MST function
int main() {
    // Number of vertices and edges
    int V = 5;
    int E = 7;

    // Edge list for the graph
    edge_t edges[] = {
            {0, 1, 2}, {0, 3, 6},
            {1, 2, 3}, {1, 3, 8}, {1, 4, 5},
            {2, 4, 7},
            {3, 4, 9}
    };

    // Create the graph
    graph_t G;
    G.V = V;
    G.E = E;
    G.edges = edges;

    // Initialize the weight matrix (adjacency matrix)
    int *w = (int *)malloc(V * V * sizeof(int));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                w[i * V + j] = 0;
            } else {
                w[i * V + j] = INF;  // Set all other entries to infinity (no edge)
            }
        }
    }

    // Fill in the weights from the edge list
    for (int i = 0; i < E; i++) {
        int src = G.edges[i].src;
        int dest = G.edges[i].dest;
        int weight = G.edges[i].weight;
        w[src * V + dest] = weight;
        w[dest * V + src] = weight;  // For undirected graph, update both directions
    }

    // Perform Prim's algorithm to find the MST, starting from vertex 0
    mst_Prim(&G, w, 0);

    free(w);  // Clean up the weight matrix
    return 0;
}

/*
Explanation of the functions:

- **create_min_heap**:
  - Initializes a priority queue (min-heap) to store vertices, where each vertex has a key value, used to implement Prim's algorithm.

- **swap**:
  - A helper function to swap two elements in the priority queue.

- **min_heapify**:
  - Ensures the heap property is maintained by reordering the elements in the priority queue after a change in one of the elements.

- **extract_min**:
  - Extracts the vertex with the minimum key value from the priority queue, which is the next vertex to add to the MST in Prim's algorithm.

- **decrease_key**:
  - Updates the key value of a vertex in the priority queue and reorders the heap to maintain the heap property.

- **mst_Prim**:
  - Implements Prim's algorithm. It initializes key values and predecessors for all vertices, then iteratively adds the minimum weight edge to the MST by extracting the vertex with the smallest key and updating adjacent vertices' key values.

- **main**:
  - Sets up a sample graph with an edge list and adjacency matrix, then runs Prim's algorithm starting from vertex 0. Finally, it prints the edges of the MST.

In summary, this code implements Prim's algorithm using a priority queue to find the Minimum Spanning Tree (MST) for a given graph. It uses a min-heap for efficient key updates and vertex extraction, ensuring that the MST is found in optimal time.
*/
