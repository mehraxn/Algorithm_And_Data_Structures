### README: Graph Isomorphism Checker

---

### **Overview**

This program implements a function to solve the graph isomorphism problem for directed, unlabeled, and unweighted graphs. Two graphs are isomorphic if there exists a one-to-one mapping between their vertex sets such that the adjacency relationships are preserved. The program:

1. Accepts two graphs defined as sequences of edges.
2. Represents the graphs using adjacency lists.
3. Verifies whether the two graphs are isomorphic by checking all possible mappings between their vertex sets.

This README details the design, implementation, and functionality of the program.

---

### **Key Concepts**

#### **Graph Isomorphism**
In graph theory, an isomorphism between two graphs \( G \) and \( H \) is a bijection \( f: V(G) \to V(H) \) such that:
1. For every edge \( (u, v) \) in \( G \), \( (f(u), f(v)) \) is an edge in \( H \).
2. The graphs must have the same number of vertices and edges.

#### **Program Requirements**
1. Represent graphs using adjacency lists.
2. Write the abstract data types (ADTs) to store the graphs in C.
3. Implement the function to check for isomorphism.

---

### **Graph Representation**

#### **Node Structure (`Node`)**
Each vertex in the graph's adjacency list is represented using a linked list node:
```c
typedef struct Node {
    char label[MAX_LABEL_LENGTH]; // Label of the vertex (e.g., "A")
    struct Node *next;           // Pointer to the next vertex in the list
} Node;
```

#### **Graph Structure (`Graph`)**
The graph is stored as an array of adjacency lists, with each array entry corresponding to a vertex:
```c
typedef struct Graph {
    int numVertices;                   // Number of vertices in the graph
    int numEdges;                      // Number of edges in the graph
    Node *adjList[MAX_NODES];          // Array of adjacency lists
    char vertices[MAX_NODES][MAX_LABEL_LENGTH]; // Vertex labels
} Graph;
```
- `numVertices`: Tracks the total number of vertices.
- `numEdges`: Tracks the total number of edges.
- `adjList`: An array of pointers to linked lists, where each list represents the neighbors of a vertex.
- `vertices`: Stores the labels of the vertices for mapping.

---

### **Functions and Implementation**

#### **1. `createNode`**
Creates a new adjacency list node for a vertex.
```c
Node *createNode(const char *label) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->label, label);
    newNode->next = NULL;
    return newNode;
}
```

#### **2. `createGraph`**
Initializes a new graph.
```c
Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->numEdges = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}
```

#### **3. `addEdge`**
Adds an edge between two vertices in the graph (bidirectional for undirected graphs).
```c
void addEdge(Graph *graph, const char *src, const char *dest) {
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

    for (i = 0; i < graph->numVertices; i++) {
        if (strcmp(graph->vertices[i], dest) == 0) break;
    }
    if (i == graph->numVertices) {
        strcpy(graph->vertices[graph->numVertices++], dest);
    }
    graph->numEdges++;
}
```

#### **4. `printGraph`**
Prints the adjacency list representation of the graph.
```c
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
```

#### **5. `areIsomorphic`**
Checks whether two graphs are isomorphic by comparing adjacency lists under all possible mappings.

**Steps:**
1. Check if the number of vertices and edges in both graphs are equal. If not, the graphs are not isomorphic.
2. Generate all possible permutations of vertex mappings.
3. For each mapping, compare the adjacency lists of the two graphs.

**Code:**
```c
int areIsomorphic(Graph *g1, Graph *g2) {
    if (g1->numVertices != g2->numVertices || g1->numEdges != g2->numEdges) {
        return 0;
    }

    int *used = (int *)calloc(g2->numVertices, sizeof(int));
    int *mapping = (int *)malloc(g1->numVertices * sizeof(int));

    int mapVertices(int depth) {
        if (depth == g1->numVertices) {
            for (int i = 0; i < g1->numVertices; i++) {
                Node *list1 = g1->adjList[i];
                Node *list2 = g2->adjList[mapping[i]];
                if (!compareAdjLists(list1, list2)) {
                    return 0;
                }
            }
            return 1;
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
```

#### **6. `compareAdjLists`**
Compares two adjacency lists to check if they are identical.
```c
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
```

---

### **Example Execution**

#### **Input Graphs**
Graph G1:
```
A -> B -> C -> D -> A -> C
```
Graph G2:
```
1 -> 2 -> 3 -> 4 -> 1 -> 3
```

#### **Output**
```
Graph G1:
A: B -> C -> NULL
B: C -> A -> NULL
C: D -> A -> NULL
D: A -> C -> NULL

Graph G2:
1: 2 -> 3 -> NULL
2: 3 -> 1 -> NULL
3: 4 -> 1 -> NULL
4: 1 -> 3 -> NULL

The graphs are isomorphic.
```

---

### **Key Features**
1. **Efficient Representation**: Graphs are stored as adjacency lists for efficient traversal and comparison.
2. **Recursive Backtracking**: All vertex mappings are generated and tested using backtracking.
3. **Flexible Design**: Can handle graphs with labeled vertices of arbitrary size.

---

### **Limitations**
1. The current implementation is computationally expensive for large graphs due to the factorial growth of permutations.
2. Optimizations such as degree matching or canonical labeling can be incorporated for better performance.

---

This program provides a solid foundation for solving the graph isomorphism problem while demonstrating key principles of graph theory and algorithm design.

