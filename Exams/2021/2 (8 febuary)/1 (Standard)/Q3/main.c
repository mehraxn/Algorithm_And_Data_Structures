#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LABEL_LENGTH 100

// Node structure for adjacency list
typedef struct Node {
    char label[MAX_LABEL_LENGTH];
    struct Node *next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    int numEdges;
    Node *adjList[MAX_NODES];
    char vertices[MAX_NODES][MAX_LABEL_LENGTH];
} Graph;

// Function to create a new node
Node *createNode(const char *label) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->label, label);
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a graph
Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, const char *src, const char *dest) {
    // Add edge src -> dest
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->vertices[i], src) == 0) break;
    }
    if (i == graph->numVertices) {
        strcpy(graph->vertices[graph->numVertices++], src);
    }
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[i];
    graph->adjList[i] = newNode;

    // Add edge dest -> src
    for (i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->vertices[i], dest) == 0) break;
    }
    if (i == graph->numVertices) {
        strcpy(graph->vertices[graph->numVertices++], dest);
    }
    graph->numEdges++;
}

// Function to print the graph
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%s: ", graph->vertices[i]);
        Node *temp = graph->adjList[i];
        while (temp) {
            printf("%s -> ", temp->label);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Helper function to compare adjacency lists
int compareAdjLists(Node *list1, Node *list2) {
    Node *temp1 = list1, *temp2 = list2;
    while (temp1 && temp2) {
        if (strcmp(temp1->label, temp2->label) != 0) {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1 == NULL && temp2 == NULL;
}

// Function to check graph isomorphism
int areIsomorphic(Graph *g1, Graph *g2) {
    if (g1->numVertices != g2->numVertices || g1->numEdges != g2->numEdges) {
        return 0; // Graphs must have the same number of vertices and edges
    }

    // Check all permutations of vertices in g2
    int *used = (int *)calloc(g2->numVertices, sizeof(int));
    int *mapping = (int *)malloc(g1->numVertices * sizeof(int));

    // Helper function to try all mappings recursively
    int mapVertices(int depth) {
        if (depth == g1->numVertices) {
            // Compare adjacency lists for this mapping
            for (int i = 0; i < g1->numVertices; i++) {
                Node *list1 = g1->adjList[i];
                Node *list2 = g2->adjList[mapping[i]];
                if (!compareAdjLists(list1, list2)) {
                    return 0;
                }
            }
            return 1; // Isomorphic
        }

        for (int i = 0; i < g2->numVertices; i++) {
            if (!used[i]) {
                used[i] = 1;
                mapping[depth] = i;
                if (mapVertices(depth + 1)) {
                    return 1;
                }
                used[i] = 0;
            }
        }
        return 0;
    }

    int result = mapVertices(0);
    free(used);
    free(mapping);
    return result;
}

// Main function
int main() {
    Graph *g1 = createGraph();
    Graph *g2 = createGraph();

    // Create example graphs
    addEdge(g1, "A", "B");
    addEdge(g1, "B", "C");
    addEdge(g1, "C", "D");
    addEdge(g1, "D", "A");
    addEdge(g1, "A", "C");

    addEdge(g2, "1", "2");
    addEdge(g2, "2", "3");
    addEdge(g2, "3", "4");
    addEdge(g2, "4", "1");
    addEdge(g2, "1", "3");

    printf("Graph G1:\n");
    printGraph(g1);

    printf("\nGraph G2:\n");
    printGraph(g2);

    if (areIsomorphic(g1, g2)) {
        printf("\nThe graphs are isomorphic.\n");
    } else {
        printf("\nThe graphs are not isomorphic.\n");
    }

    return 0;
}
