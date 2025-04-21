#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node_s {
    char *key;
    int n_child;
    struct node_s **child;
} node_t;

// Helper function to collect all paths from a tree
void collectPaths(node_t *root, char *currentPath, char ***paths, int *pathCount, int *pathCapacity) {
    if (!root) return;

    // Append current node's key to the path
    char newPath[1000]; // Assuming maximum path length
    if (currentPath[0] == '\0') {
        snprintf(newPath, sizeof(newPath), "%s", root->key);
    } else {
        snprintf(newPath, sizeof(newPath), "%s%s", currentPath, root->key);
    }

    // If it's a leaf node, add the path to the list
    if (root->n_child == 0) {
        if (*pathCount >= *pathCapacity) {
            *pathCapacity *= 2;
            *paths = realloc(*paths, (*pathCapacity) * sizeof(char *));
        }
        (*paths)[*pathCount] = strdup(newPath);
        (*pathCount)++;
        return;
    }

    // Recur for each child
    for (int i = 0; i < root->n_child; i++) {
        collectPaths(root->child[i], newPath, paths, pathCount, pathCapacity);
    }
}

// Comparison function for sorting strings
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to check if two trees are equivalent
int equivalent(node_t *root1, node_t *root2) {
    // Collect paths from both trees
    char **paths1 = malloc(10 * sizeof(char *));
    char **paths2 = malloc(10 * sizeof(char *));
    int pathCount1 = 0, pathCount2 = 0;
    int pathCapacity1 = 10, pathCapacity2 = 10;

    collectPaths(root1, "", &paths1, &pathCount1, &pathCapacity1);
    collectPaths(root2, "", &paths2, &pathCount2, &pathCapacity2);

    // If the number of paths is different, the trees are not equivalent
    if (pathCount1 != pathCount2) {
        return 0;
    }

    // Sort the paths for comparison
    qsort(paths1, pathCount1, sizeof(char *), compareStrings);
    qsort(paths2, pathCount2, sizeof(char *), compareStrings);

    // Compare the paths
    for (int i = 0; i < pathCount1; i++) {
        if (strcmp(paths1[i], paths2[i]) != 0) {
            // Free allocated memory
            for (int j = 0; j < pathCount1; j++) free(paths1[j]);
            for (int j = 0; j < pathCount2; j++) free(paths2[j]);
            free(paths1);
            free(paths2);
            return 0;
        }
    }

    // Free allocated memory
    for (int i = 0; i < pathCount1; i++) free(paths1[i]);
    for (int i = 0; i < pathCount2; i++) free(paths2[i]);
    free(paths1);
    free(paths2);

    return 1;
}
