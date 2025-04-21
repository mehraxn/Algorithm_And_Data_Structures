#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define WHITE 0
#define BLACK 1

// Function prototypes
void longest_weight_path(int **g, int *color, char **vertex_id, int n);
void dfs(int **g, int *color, char **vertex_id, int n, int current, int prev_color, int current_weight, int *visited, int *max_weight, char **current_path, char **best_path, int path_index);

/**
 * Data Structures and Logic:
 * 1. The graph is represented using an adjacency matrix `g` where `g[i][j]` contains the weight of the edge from vertex `i` to vertex `j`. If no edge exists, `g[i][j]` is zero.
 * 2. Colors of vertices are stored in an array `color` where `color[i]` indicates the color (WHITE/BLACK) of vertex `i`.
 * 3. Vertex identifiers are stored in a 2D character array `vertex_id` where `vertex_id[i]` is the string identifier of vertex `i`.
 * 4. A Depth-First Search (DFS) is used to explore paths, ensuring the color alternation condition is met.
 * 5. The function tracks the path with the maximum weight using a `max_weight` variable and a `best_path` array to store vertex identifiers.
 */

void longest_weight_path(int **g, int *color, char **vertex_id, int n) {
    int *visited = (int *)calloc(n, sizeof(int)); // Track visited vertices
    int max_weight = INT_MIN;                    // Store the maximum weight
    char **current_path = (char **)malloc(n * sizeof(char *));
    char **best_path = (char **)malloc(n * sizeof(char *));

    // Initialize the best path array
    for (int i = 0; i < n; i++) {
        current_path[i] = (char *)malloc(100 * sizeof(char));
        best_path[i] = (char *)malloc(100 * sizeof(char));
    }

    // Perform DFS for each vertex as the starting point
    for (int i = 0; i < n; i++) {
        dfs(g, color, vertex_id, n, i, -1, 0, visited, &max_weight, current_path, best_path, 0);
    }

    // Display the best path
    printf("Maximum weight path with alternating colors: \n");
    for (int i = 0; i < n && best_path[i][0] != '\0'; i++) {
        printf("%s ", best_path[i]);
    }
    printf("\nTotal Weight: %d\n", max_weight);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(current_path[i]);
        free(best_path[i]);
    }
    free(current_path);
    free(best_path);
    free(visited);
}

void dfs(int **g, int *color, char **vertex_id, int n, int current, int prev_color, int current_weight, int *visited, int *max_weight, char **current_path, char **best_path, int path_index) {
    visited[current] = 1; // Mark the current vertex as visited
    strcpy(current_path[path_index], vertex_id[current]); // Add current vertex to the path

    // Check if the current path weight is greater than max_weight
    if (current_weight > *max_weight) {
        *max_weight = current_weight;
        for (int i = 0; i <= path_index; i++) {
            strcpy(best_path[i], current_path[i]);
        }
        best_path[path_index + 1][0] = '\0'; // Null-terminate the best path
    }

    // Explore adjacent vertices
    for (int i = 0; i < n; i++) {
        if (g[current][i] > 0 && !visited[i] && color[i] != prev_color) {
            dfs(g, color, vertex_id, n, i, color[current], current_weight + g[current][i], visited, max_weight, current_path, best_path, path_index + 1);
        }
    }

    visited[current] = 0; // Backtrack
}

// Example usage
int main() {
    int n = 5;

    // Example adjacency matrix
    int **g = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g[i] = (int *)calloc(n, sizeof(int));
    }

    g[0][1] = 2; g[1][2] = 3; g[2][3] = 5; g[3][4] = 1;

    // Vertex colors
    int color[] = {WHITE, BLACK, WHITE, BLACK, WHITE};

    // Vertex identifiers
    char *vertex_id[] = {"this", "is", "the", "selected", "path"};

    // Call the function
    longest_weight_path(g, color, vertex_id, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(g[i]);
    }
    free(g);

    return 0;
}
