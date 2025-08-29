// Function to find the Minimum Spanning Tree (MST) using Prim's Algorithm
int mst_prim(graph_t *g) {
    int i, j, min, weight = 0; // Initialize variables:
    // i, j: Loop indices and vertex indices.
    // min: The index of the current vertex with the smallest distance.
    // weight: The total weight of the MST.
    int *fringe;  // Array to keep track of which vertex is connected to the MST. Stores predecessors.
    edge_t *e;    // Pointer used to traverse the adjacency list of a vertex.

    // Allocate memory for the fringe array to store predecessor information for each vertex.
    // This array keeps track of the tree structure by noting which vertex is connected to which.
    fringe = (int *)util_malloc(g->nv * sizeof(int));

    // Initialize the fringe array with vertex indices.
    // At the start, every vertex is its own predecessor (not yet connected).
    for (i = 0; i < g->nv; i++) {
        fringe[i] = i; // Assign each vertex to itself as a placeholder for now.
    }

    // Print a heading for the MST edge list to follow.
    printf("List of edges making an MST:\n");

    // Set the starting vertex for Prim's Algorithm (arbitrarily choose vertex 0).
    min = 0; // Start with the first vertex.
    g->g[min].dist = 0;  // Set the "distance" (cost to connect) for the source vertex to 0.

    // Main loop of Prim's Algorithm.
    // This loop runs until there are no more vertices to process (min == -1).
    while (min != -1) {
        i = min;  // Select the vertex with the minimum distance to the MST.

        // Update the predecessor for this vertex in the fringe array.
        g->g[i].pred = fringe[i];

        // Add the distance of this vertex to the MST weight.
        weight += g->g[i].dist;

        // If this vertex is not the starting vertex (distance != 0), print the edge to its predecessor.
        if (g->g[i].dist != 0) {
            printf("Edge %d-%d (w=%d)\n", fringe[i], i, g->g[i].dist);
        }

        // Prepare to find the next vertex with the minimum distance.
        min = -1; // Reset min to -1 (will be updated later).

        // Traverse the adjacency list of the current vertex `i` to examine its neighbors.
        e = g->g[i].head;  // Get the head of the adjacency list for vertex `i`.
        while (e != NULL) {
            j = e->dst;  // Destination vertex of the edge.

            // If the destination vertex `j` is not already connected to the MST (pred == -1):
            if (g->g[j].pred == -1) {
                // Update the distance to the MST if this edge provides a shorter connection.
                if (e->weight < g->g[j].dist) {
                    g->g[j].dist = e->weight; // Update the minimum weight to reach vertex `j`.
                    fringe[j] = i; // Update the fringe to indicate that vertex `j` is connected via `i`.
                }
            }
            // Move to the next edge in the adjacency list.
            e = e->next;
        }

        // Find the next vertex with the smallest distance that has not yet been added to the MST.
        for (j = 0; j < g->nv; j++) {
            // Only consider vertices not yet added to the MST (pred == -1).
            if (g->g[j].pred == -1) {
                // Update `min` if we find a vertex with a smaller distance.
                if (min == -1 || g->g[j].dist < g->g[min].dist) {
                    min = j; // Update `min` to the vertex with the smallest distance.
                }
            }
        }
    }

    // Free the memory allocated for the fringe array as it is no longer needed.
    free(fringe);

    // Return the total weight of the MST to the caller.
    return weight;
}

/*
Key Concepts Explained in Comments:

// Prim’s Algorithm:
// - Builds an MST by starting with one vertex and repeatedly adding the smallest edge
//   that connects a new vertex to the existing tree.

// Fringe Array:
// - Tracks which vertex is connected to each other in the growing MST.
// - Used to print the edges in the MST.

// Distance (dist):
// - Represents the minimum weight of an edge connecting a vertex to the MST.

// Predecessor (pred):
// - Keeps track of which vertex connects to another in the MST.

// Adjacency List Traversal:
// - The `head` pointer of each vertex points to a linked list of edges, used to explore neighboring vertices.

// Edge Selection:
// - Only unconnected vertices (with `pred == -1`) are considered for adding to the MST.
*/
