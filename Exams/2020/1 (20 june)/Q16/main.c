#include <stdio.h>

/**
 * Recursive function to generate all sequences of steps
 * that cover the specified distance.
 *
 * @param l   Array of available step lengths.
 * @param n   Size of the array `l`.
 * @param d   Remaining distance to cover.
 * @param path   Array to store the current sequence of steps.
 * @param path_len Current length of the path.
 */
void cover_recursive(int *l, int n, int d, int *path, int path_len) {
    // Base case: If the distance is exactly covered
    if (d == 0) {
        // Print the current path
        printf("{");
        for (int i = 0; i < path_len; i++) {
            printf("%d", path[i]);
            if (i < path_len - 1) {
                printf(", ");
            }
        }
        printf("}\n");
        return;
    }

    // Base case: If the distance cannot be covered
    if (d < 0) {
        return;
    }

    // Try each step length
    for (int i = 0; i < n; i++) {
        // Add the current step to the path
        path[path_len] = l[i];

        // Recur with the reduced distance
        cover_recursive(l, n, d - l[i], path, path_len + 1);
    }
}

/**
 * Wrapper function to initialize variables and call the recursive function.
 *
 * @param l   Array of available step lengths.
 * @param n   Size of the array `l`.
 * @param d   Total distance to cover.
 */
void cover(int *l, int n, int d) {
    // Allocate an array to store the current path
    int path[d]; // Maximum possible length is `d` if steps of size 1 were allowed

    // Call the recursive function
    cover_recursive(l, n, d, path, 0);
}

// Example usage
int main() {
    int l[] = {2, 6};  // Available step lengths
    int n = 2;         // Number of step lengths
    int d = 10;        // Total distance to cover

    printf("Possible step combinations to cover %d cm:\n", d);
    cover(l, n, d);

    return 0;
}
