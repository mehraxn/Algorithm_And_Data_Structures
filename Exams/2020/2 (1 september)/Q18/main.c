#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_R 10
#define MAX_C 10
#define MAX_PARTITIONS 100

// Check if two characters are equivalent (taking '*' as a wildcard)
bool is_equivalent(char a, char b) {
    return (a == b || b == '*' || a == '*');
}

// Count occurrences of each letter in a subset
void count_letters(char matrix[MAX_R][MAX_C], int rows, int cols, int *subset, int subset_size, int *letter_counts) {
    memset(letter_counts, 0, sizeof(int) * 26);

    for (int i = 0; i < subset_size; i++) {
        int r = subset[i] / cols; // Row index
        int c = subset[i] % cols; // Column index

        if (matrix[r][c] == '*') continue; // '*' acts as a wildcard
        letter_counts[matrix[r][c] - 'A']++;
    }
}

// Validate if two subsets have the same letter counts
bool validate_partition(int letter_counts[][26], int num_parts) {
    for (int i = 1; i < num_parts; i++) {
        for (int j = 0; j < 26; j++) {
            if (letter_counts[i][j] != letter_counts[0][j]) {
                return false;
            }
        }
    }
    return true;
}

// Print a solution
void print_solution(int **partitions, int num_parts, int *partition_sizes, int rows, int cols) {
    printf("{");
    for (int p = 0; p < num_parts; p++) {
        printf("{");
        for (int i = 0; i < partition_sizes[p]; i++) {
            int r = partitions[p][i] / cols;
            int c = partitions[p][i] % cols;
            printf("(%d,%d)", r, c);
            if (i < partition_sizes[p] - 1) printf(", ");
        }
        printf("}");
        if (p < num_parts - 1) printf(", ");
    }
    printf("}\n");
}

// Recursive function to find valid partitions
void find_partitions_recursive(char matrix[MAX_R][MAX_C], int rows, int cols,
                               int **partitions, int num_parts, int *partition_sizes,
                               int start, int *letter_counts, int solution_count[]) {
    if (start == rows * cols) {
        // Check if the partitions are valid
        int counts[MAX_PARTITIONS][26];
        for (int i = 0; i < num_parts; i++) {
            count_letters(matrix, rows, cols, partitions[i], partition_sizes[i], counts[i]);
        }

        if (validate_partition(counts, num_parts)) {
            // Print the solution
            print_solution(partitions, num_parts, partition_sizes, rows, cols);
            (*solution_count)++;
        }
        return;
    }

    for (int p = 0; p < num_parts; p++) {
        // Add the current cell to partition `p`
        partitions[p][partition_sizes[p]] = start;
        partition_sizes[p]++;

        find_partitions_recursive(matrix, rows, cols, partitions, num_parts, partition_sizes, start + 1,
                                  letter_counts, solution_count);

        // Backtrack
        partition_sizes[p]--;
    }
}

// Wrapper function
void find_partition(char matrix[MAX_R][MAX_C], int rows, int cols, int num_parts) {
    // Allocate memory for partitions
    int *partitions[MAX_PARTITIONS];
    int partition_sizes[MAX_PARTITIONS] = {0};
    int letter_counts[MAX_PARTITIONS][26];
    int solution_count = 0;

    for (int i = 0; i < num_parts; i++) {
        partitions[i] = (int *)malloc(rows * cols * sizeof(int));
    }

    // Start the recursive search
    find_partitions_recursive(matrix, rows, cols, partitions, num_parts, partition_sizes, 0, (int *)letter_counts, &solution_count);

    printf("Total Solutions: %d\n", solution_count);

    // Free memory
    for (int i = 0; i < num_parts; i++) {
        free(partitions[i]);
    }
}

// Example usage
int main() {
    char matrix[MAX_R][MAX_C] = {
            {'F', 'O', 'O', 'F'},
            {'O', 'F', 'O', 'F'},
            {'F', 'O', 'O', 'F'}
    };

    int rows = 3, cols = 4, num_parts = 3;

    printf("Partitions:\n");
    find_partition(matrix, rows, cols, num_parts);

    return 0;
}
