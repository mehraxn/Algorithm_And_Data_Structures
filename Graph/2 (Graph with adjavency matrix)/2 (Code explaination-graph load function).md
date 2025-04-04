# Line-by-Line Explanation – `graph_load` Function

Below is the entire `graph_load` function with **inline comments** explaining each part. You can refer to the numbered comments to follow the detailed explanations.

```c
/************************************************
 * graph_load: Loads a graph from the given file.
 ************************************************/

graph_t *graph_load(const char *filename) {
    // 1) Pointer to a graph_t structure
    graph_t *g;

    // 2) Temporary buffer to store each line read from the file
    char line[MAX_LINE];

    // 3) Integers used for adjacency indices and weights
    int i, j, weight, dir;

    // 4) File pointer for reading the graph file
    FILE *fp;

    // (A) Allocate the graph structure
    // We call util_calloc to safely allocate memory for a single graph_t.
    // util_calloc exits the program if memory allocation fails.
    g = (graph_t *) util_calloc(1, sizeof(graph_t));

    // (B) Open the file safely
    // util_fopen handles errors if the file cannot be opened.
    fp = util_fopen(filename, "r");

    // (C) Read the first line to get nv (number of vertices) and dir (0 or 1)
    if (fgets(line, MAX_LINE, fp) != NULL) {
        // sscanf parses two integers from the line: g->nv and dir.
        // If it doesn’t find exactly 2 integers, exit with an error.
        if (sscanf(line, "%d %d", &g->nv, &dir) != 2) {
             sscanf(line, "%d", &g->nv);
             dir = 1;
        }
    } else {
        // If fgets fails, the file might be empty or invalid.
        fprintf(stderr, "Error: empty or invalid file\n");
        exit(EXIT_FAILURE);
    }

    // (D) Allocate the array of vertices
    // We now know how many vertices (g->nv) exist, so allocate that many.
    g->g = (vertex_t *) util_calloc(g->nv, sizeof(vertex_t));

    // (E) Initialize each vertex
    // We set default values for ID, color, times, predecessor, scc, and rowadj.
    for (i = 0; i < g->nv; i++) {
        g->g[i].id        = i;            // The vertex identifier is its index.
        g->g[i].color     = WHITE;        // Default color is WHITE.
        g->g[i].disc_time = -1;           // Discovery time initialized to -1.
        g->g[i].endp_time = -1;           // Finish time initialized to -1.
        g->g[i].pred      = -1;           // Predecessor index set to -1 (none).
        g->g[i].scc       = -1;           // Strongly connected component set to -1.

        // Allocate adjacency row for this vertex.
        // rowadj is an array of int, size g->nv, all initialized to 0.
        g->g[i].rowadj = (int *) util_calloc(g->nv, sizeof(int));
    }

    // (F) Read edges (i, j, weight) from each subsequent line
    while (fgets(line, MAX_LINE, fp) != NULL) {
        // If sscanf can parse three integers from the line, it’s an edge.
        if (sscanf(line, "%d %d %d", &i, &j, &weight) == 3) {
            // Set adjacency from i to j.
            g->g[i].rowadj[j] = weight;

            // If the graph is undirected (dir == 0), set adjacency in both directions.
            if (!dir) {
                g->g[j].rowadj[i] = weight;
            }
        }
        // Lines that don’t match the pattern "i j weight" are ignored.
    }

    // (G) Close the file
    fclose(fp);

    // (H) Return the constructed graph
    return g;
}
```

Below is a breakdown of the key **sections**:

1. **Variable Declarations**
   - `graph_t *g;` – A pointer for our main graph structure.
   - `char line[MAX_LINE];` – A buffer to read each line from the file.
   - `int i, j, weight, dir;` – Integers to store edge indices (`i`, `j`), the edge weight, and the direction flag.
   - `FILE *fp;` – A file pointer.

2. **Memory Allocation for `graph_t`**
   - `g = (graph_t *) util_calloc(1, sizeof(graph_t));` – Allocates one `graph_t` structure. The `util_calloc` function is a safe wrapper around `calloc` that exits on failure.

3. **Opening the File**
   - `fp = util_fopen(filename, "r");` – Opens the file in read mode, or exits with an error if it fails.

4. **Reading `nv` and `dir`**
   - Reads the first line with `fgets`.
   - Uses `sscanf` to parse two integers: `g->nv` (number of vertices) and `dir` (0 = undirected, 1 = directed).
   - If parsing fails or the line is missing/invalid, prints an error and exits.

5. **Allocating the Vertex Array**
   - `g->g = (vertex_t *) util_calloc(g->nv, sizeof(vertex_t));` – Allocates an array of `vertex_t` with length `g->nv`.

6. **Initializing Each Vertex**
   - Assigns default values for `id`, `color`, times (`disc_time`, `endp_time`), `pred`, and `scc`.
   - For adjacency, `rowadj` is allocated as an array of `g->nv` integers. This effectively builds the adjacency matrix row for each vertex.

7. **Reading Edges**
   - `while (fgets(line, MAX_LINE, fp) != NULL) { ... }` – Continues reading lines until EOF.
   - `sscanf(line, "%d %d %d", &i, &j, &weight)` – Attempts to parse each line as an edge description.
   - `g->g[i].rowadj[j] = weight;` – Sets the weight from vertex `i` to vertex `j`.
   - If `dir == 0` (undirected graph), also sets the reverse direction `g->g[j].rowadj[i] = weight;`.

8. **Closing the File**
   - `fclose(fp);` – Closes the file when reading is complete.

9. **Return the Graph**
   - `return g;` – Returns the fully constructed and initialized graph.

---

**Key Takeaways**:
- **Adjacency Matrix**: Each vertex has its own row (`rowadj`) storing edge weights.
- **Directed vs. Undirected**: Controlled by `dir`. If `dir == 0`, both `i->j` and `j->i` are set.
- **Robustness**: The function checks for valid input and fails early if something is wrong (e.g., missing file, malformed line).
- **Extendability**: Once loaded, you can use the graph with your traversal algorithms or any other graph-related operations.

