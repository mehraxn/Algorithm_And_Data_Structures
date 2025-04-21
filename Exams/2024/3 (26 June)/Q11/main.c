#include <stdio.h>
#include <stdlib.h>

// Function to dynamically create a 2D matrix representing the histogram
char **array_to_histogram(int *vet, int n) {
    // Allocate memory for the rows of the matrix
    char **matrix = (char **)malloc(n * sizeof(char *));

    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed for the matrix\n");
        exit(EXIT_FAILURE);
    }

    // Iterate through the array to create each row
    for (int i = 0; i < n; i++) {
        int stars = vet[i]; // Number of stars for this row
        matrix[i] = (char *)malloc(stars * sizeof(char));

        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for row %d\n", i);
            // Free previously allocated rows before exiting
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            exit(EXIT_FAILURE);
        }

        // Fill the row with '*' characters
        for (int j = 0; j < stars; j++) {
            matrix[i][j] = '*';
        }
    }

    return matrix;
}

// Function to display the histogram
void print_histogram(char **matrix, int *vet, int n) {
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < vet[i]; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the dynamically allocated memory
void free_histogram(char **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Allocate and input the array
    int *vet = (int *)malloc(n * sizeof(int));

    if (vet == NULL) {
        fprintf(stderr, "Memory allocation failed for the array\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    // Create the histogram
    char **histogram = array_to_histogram(vet, n);

    // Print the histogram
    printf("\nHistogram:\n");
    print_histogram(histogram, vet, n);

    // Free the allocated memory
    free_histogram(histogram, n);
    free(vet);

    return 0;
}
