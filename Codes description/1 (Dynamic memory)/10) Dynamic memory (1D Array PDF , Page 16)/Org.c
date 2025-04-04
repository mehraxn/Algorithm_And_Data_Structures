#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main() {
    int *v1, *v2, size = N;
    int count = 0;
    FILE *file;

    // Allocate memory for the initial array
    v1 = malloc(N * sizeof(int));
    if (v1 == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    // Open the file for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        free(v1);
        return 1;
    }

    // Read the file and store values in the array
    while (fscanf(file, "%d", &v1[count]) == 1) {
        count++;
        if (count >= size) {
            // Double the size if not enough space
            size *= 2;
            v2 = realloc(v1, size * sizeof(int));
            if (v2 == NULL) {
                fprintf(stderr, "Failed to reallocate memory\n");
                free(v1);
                fclose(file);
                return 1;
            }
            v1 = v2;
        }
    }

    // Close the file
    fclose(file);

    // Use the array as needed
    for (int i = 0; i < count; i++) {
        printf("%d\n", v1[i]);
    }

    // Free the allocated memory
    free(v1);

    return 0;
}
