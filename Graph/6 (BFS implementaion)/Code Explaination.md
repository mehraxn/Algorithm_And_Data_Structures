# **README: Breadth-First Search Implementation in C**

This project is an implementation of Breadth-First Search (BFS) on a graph represented using an adjacency list in C. The code provides functionalities for loading a graph, performing BFS traversal, and printing traversal results. It also implements a queue to manage the BFS operations effectively. This README explains each function and its role in detail to give a comprehensive understanding of the entire code.

---

## **Project Structure**

The project consists of several key components:

1. **Graph Representation**: The graph is represented using vertices (`Vertex`) and edges (`Edge`). Each vertex maintains an adjacency list of edges.
2. **BFS Implementation**: The BFS algorithm is implemented to explore the graph from a given starting vertex.
3. **Queue Operations**: A custom queue is used to facilitate the BFS traversal.
4. **Memory Management**: Functions are provided to allocate and free memory for the graph and queue structures.

---

## **How to Use**

1. **Compile the code**:
   ```bash
   gcc bfs.c -o bfs
   ```
2. **Run the program with a graph file**:
   ```bash
   ./bfs <graph_file>
   ```
3. **Provide the source vertex ID** when prompted by the program.

---

## **Explanation of Each Component**

### **1. Data Structures**

#### **Vertex and Edge Structures**

- **`Edge` Structure**:
  ```c
  typedef struct Edge {
      struct Vertex *dst;     // Destination vertex of the edge
      struct Edge *next;      // Pointer to the next edge in the adjacency list
  } Edge;
  ```
  - Each edge points to a destination vertex (`dst`) and links to the next edge (`next`). This structure forms the adjacency list for a vertex.

- **`Vertex` Structure**:
  ```c
  typedef struct Vertex {
      int id;                 // Unique identifier for the vertex
      int color;              // Color used for BFS traversal (WHITE, GRAY, BLACK)
      int dist;               // Distance from the source vertex
      struct Vertex *pred;    // Predecessor vertex in the BFS tree
      Edge *adj;              // Adjacency list of edges
      struct Vertex *next;    // Pointer to the next vertex in the graph
  } Vertex;
  ```
  - Each vertex is identified by an ID (`id`), and its adjacency list (`adj`) points to its neighbors. Attributes like `color`, `dist`, and `pred` are used during BFS traversal.

- **`Graph` Structure**:
  ```c
  typedef struct Graph {
      Vertex *g;              // Pointer to the list of vertices
      int nv;                 // Number of vertices in the graph
  } Graph;
  ```
  - The graph contains a pointer to the list of vertices (`g`) and the total number of vertices (`nv`).

### **2. BFS Implementation**

#### **`graph_bfs` Function**

- **Prototype**:
  ```c
  void graph_bfs(Graph *g, Vertex *n);
  ```
- **Description**: This function implements the Breadth-First Search (BFS) algorithm on the graph, starting from a given source vertex `n`.
- **Detailed Explanation**:
  - A queue (`queue_t *qp`) is initialized to manage the vertices during traversal.
  - The source vertex is marked as discovered (`GRAY`), its distance set to `0`, and it is enqueued.
  - The function then enters a loop, where it dequeues a vertex, examines its adjacency list, and enqueues unvisited neighbors (marking them as discovered).
  - The traversal continues until all reachable vertices are processed, and the vertices are eventually marked as fully explored (`BLACK`).

### **3. Queue Operations**

#### **Queue Data Structure**

- **`Queue` Structure**:
  ```c
  typedef struct Queue {
      void **items;
      int head, tail, size, capacity;
  } queue_t;
  ```
  - The queue is implemented as a circular buffer. It maintains pointers to `items`, and indices for `head`, `tail`, and the `size` of the queue.

#### **Queue Functions**

1. **`queue_init` Function**
   - **Prototype**:
     ```c
     queue_t *queue_init(int capacity);
     ```
   - **Description**: Allocates memory for a new queue with a given `capacity`. It initializes `head`, `tail`, and `size` to `0`.

2. **`queue_put` Function**
   - **Prototype**:
     ```c
     void queue_put(queue_t *q, void *item);
     ```
   - **Description**: Adds an `item` to the queue. If the queue is full, the function simply returns without adding the item.

3. **`queue_get` Function**
   - **Prototype**:
     ```c
     void *queue_get(queue_t *q);
     ```
   - **Description**: Removes an item from the queue and returns it. If the queue is empty, it returns `NULL`.

4. **`queue_free` Function**
   - **Prototype**:
     ```c
     void queue_free(queue_t *q);
     ```
   - **Description**: Frees the memory allocated for the queue.

### **4. Graph Helper Functions**

#### **`graph_load` Function**

- **Prototype**:
  ```c
  Graph* graph_load(char *filename);
  ```
- **Description**: This function reads a graph from a file specified by `filename` and initializes the graph structure. It returns a pointer to the newly loaded graph.

#### **`graph_attribute_init` Function**

- **Prototype**:
  ```c
  void graph_attribute_init(Graph *g);
  ```
- **Description**: Initializes the BFS attributes for all vertices in the graph.
  - Each vertex is marked as unvisited (`WHITE`), its distance is set to `INT_MAX`, and its predecessor (`pred`) is set to `NULL`.

#### **`graph_find` Function**

- **Prototype**:
  ```c
  Vertex* graph_find(Graph *g, int id);
  ```
- **Description**: Searches for a vertex by `id` in the graph and returns a pointer to it. If the vertex is not found, it returns `NULL`.

#### **`graph_dispose` Function**

- **Prototype**:
  ```c
  void graph_dispose(Graph *g);
  ```
- **Description**: Frees all memory allocated for the graph.
  - It iterates through each vertex and edge, freeing their memory.
  - Finally, it frees the memory for the graph itself.

### **5. Main Function**

- **Prototype**:
  ```c
  int main(int argc, char *argv[]);
  ```
- **Description**:
  - The `main` function drives the program execution.
  - It loads the graph from a file specified as a command line argument.
  - The user is prompted to enter an initial vertex ID, which is used as the source for BFS.
  - BFS traversal is performed, and the distances and predecessors of each vertex are printed.
  - Finally, the graph is disposed of, freeing any allocated memory.

---

### **Conclusion**

This project provides a comprehensive implementation of the BFS algorithm on a graph represented by an adjacency list. The queue data structure helps manage the BFS traversal effectively, while helper functions ensure modularity and ease of memory management. The provided code is both flexible and efficient, offering a great foundation for graph traversal operations.

If you have any questions or need further clarification, feel free to reach out or experiment with different graphs to explore the BFS traversal output!

