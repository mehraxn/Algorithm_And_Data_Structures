/*
 * Dijkstra's Single Source Shortest Path Algorithm Implementation
 *
 * This program implements Dijkstra's algorithm to find the shortest paths
 * from a source vertex to all other vertices in a weighted graph.
 *
 * Time Complexity: O(V²) where V is the number of vertices
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100    // Maximum number of vertices in the graph
#define INF INT_MAX         // Represents infinity (no path exists)

/*
 * Function: initialize_single_source
 * Purpose: Initialize distances and parent arrays for single source shortest path
 *
 * Parameters:
 *   - vertices: Total number of vertices in the graph
 *   - s: Source vertex index
 *   - dist[]: Array to store shortest distances from source
 *   - parent[]: Array to store parent vertices for path reconstruction
 *
 * Algorithm:
 *   1. Set all distances to infinity (no path known initially)
 *   2. Set all parents to -1 (no parent initially)
 *   3. Set source distance to 0 (distance from source to itself is 0)
 */
void initialize_single_source(int vertices, int s, int dist[], int parent[]) {
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;      // Initially, distance to all vertices is infinite
        parent[i] = -1;     // Initially, no vertex has a parent
    }
    dist[s] = 0; // Distance from source to itself is 0
}

/*
 * Function: extract_min
 * Purpose: Extract the unvisited vertex with the minimum distance
 *
 * Parameters:
 *   - vertices: Total number of vertices in the graph
 *   - dist[]: Array containing current shortest distances
 *   - visited[]: Array indicating whether a vertex has been visited (1 = visited, 0 = unvisited)
 *
 * visited[] Purpose:
 *   The visited array tracks which vertices have been finalized (shortest distance found).
 *   - Initially all values are 0 (unvisited).
 *   - Once a vertex is processed, it's marked as visited (1).
 *   - Only unvisited vertices are candidates for extraction.
 *
 * Returns: Index of vertex with minimum distance, or -1 if all are visited
 */
int extract_min(int vertices, int dist[], int visited[]) {
    int min = INF;
    int minIndex = -1;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    if (minIndex != -1) {
        visited[minIndex] = 1; // Mark as visited
    }

    return minIndex;
}

/*
 * Function: relax
 * Purpose: Update shortest distance to vertex v if a shorter path through u is found
 */
void relax(int u, int v, int w, int dist[], int parent[]) {
    if (dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
    }
}

/*
 * Function: sssp_Dijkstra
 * Purpose: Main implementation of Dijkstra's Single Source Shortest Path algorithm
 */
void sssp_Dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int s) {
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int visited[MAX_VERTICES];  // visited[i] = 1 if vertex i has been processed

    initialize_single_source(vertices, s, dist, parent);

    // Initially, no vertices are visited
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Processing vertices in order:\n");
    int step = 1;
    while (1) {
        int u = extract_min(vertices, dist, visited);

        if (u == -1) {
            printf("All vertices visited - algorithm complete.\n\n");
            break;
        }

        printf("Step %d: Processing vertex %d (distance = %d)\n", step++, u,
               dist[u] == INF ? -1 : dist[u]);

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != 0) {
                printf("  Relaxing edge (%d -> %d) with weight %d\n", u, v, graph[u][v]);
                relax(u, v, graph[u][v], dist, parent);
            }
        }
    }

    printf("=== RESULTS ===\n");
    printf("Shortest distances and paths from vertex %d:\n", s);
    printf("Vertex\tDistance\tPath\n");
    printf("------\t--------\t----\n");

    for (int i = 0; i < vertices; i++) {
        printf("%d\t", i);

        if (dist[i] == INF) {
            printf("INF\t\tNo path exists\n");
        } else {
            printf("%d\t\t", dist[i]);

            int path[MAX_VERTICES];
            int pathLength = 0;
            int current = i;

            while (current != -1) {
                path[pathLength++] = current;
                current = parent[current];
            }

            for (int j = pathLength - 1; j >= 0; j--) {
                printf("%d", path[j]);
                if (j > 0) printf(" -> ");
            }
            printf("\n");
        }
    }
}

/*
 * Function: printGraph
 * Purpose: Display the adjacency matrix representation of the graph
 */
void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Graph adjacency matrix (0 = no edge):\n");
    printf("   ");
    for (int i = 0; i < vertices; i++) {
        printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 0) {
                printf("  0");
            } else {
                printf("%3d", graph[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int vertices = 6;

    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    printf("===========================================\n");
    printf("Dijkstra's Single Source Shortest Path\n");
    printf("===========================================\n\n");

    printGraph(graph, vertices);

    printf("Running Dijkstra's algorithm from source vertex 0:\n");
    printf("--------------------------------------------------\n");
    sssp_Dijkstra(graph, vertices, 0);

    return 0;
}
