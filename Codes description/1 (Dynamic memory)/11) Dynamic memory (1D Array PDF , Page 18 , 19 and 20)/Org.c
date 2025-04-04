#include <stdio.h>
#include <stdlib.h>

void read_and_store(int *ptr, int *n) {
    FILE *file;

    // Open the file named "data.txt" for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        // Error handling if file cannot be opened
        fprintf(stderr, "Failed to open file\n");
        return;
    }

    // Read the number of elements to be stored from the file
    if (fscanf(file, "%d", n) != 1) {
        // Error handling if the number of elements cannot be read
        fprintf(stderr, "Failed to read the number of elements\n");
        fclose(file);
        return;
    }

    // Allocate memory for the array based on the number of elements
    ptr = (int *)malloc(*n * sizeof(int));
    if (ptr == NULL) {
        // Error handling if memory allocation fails
        fprintf(stderr, "Failed to allocate memory\n");
        fclose(file);
        return;
    }

    // Read the elements from the file into the allocated array
    for (int i = 0; i < *n; i++) {
        if (fscanf(file, "%d", &ptr[i]) != 1) {
            // Error handling if an element cannot be read
            fprintf(stderr, "Failed to read element %d\n", i);
            free(ptr);
            fclose(file);
            return;
        }
    }

    // Close the file after reading all the values
    fclose(file);
    return;
}
