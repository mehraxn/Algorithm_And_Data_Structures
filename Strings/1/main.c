#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to manage matrix data
char **matrix_rows = NULL;    // Array of character arrays (rows)
int *row_lengths = NULL;      // Array storing length of each row
int num_rows = 0;             // Total number of rows
int matrix_capacity = 0;      // Current capacity of the matrix
void free_matrix() ;


// Function to initialize matrix arrays
int initialize_matrix(int initial_capacity) {
    matrix_rows = (char**)malloc(initial_capacity * sizeof(char*));
    row_lengths = (int*)malloc(initial_capacity * sizeof(int));

    if (!matrix_rows || !row_lengths) {
        free(matrix_rows);
        free(row_lengths);
        matrix_rows = NULL;
        row_lengths = NULL;
        return 0; // Failure
    }

    num_rows = 0;
    matrix_capacity = initial_capacity;
    return 1; // Success
}

// Function to resize matrix arrays when needed
int resize_matrix() {
    matrix_capacity *= 2;

    char **new_rows = (char**)realloc(matrix_rows, matrix_capacity * sizeof(char*));
    int *new_lengths = (int*)realloc(row_lengths, matrix_capacity * sizeof(int));

    if (!new_rows || !new_lengths) {
        return 0; // Failure
    }

    matrix_rows = new_rows;
    row_lengths = new_lengths;
    return 1; // Success
}

// Function to add a row to the matrix
int add_row(const char *segment, int length) {
    // Resize if needed
    if (num_rows >= matrix_capacity) {
        if (!resize_matrix()) {
            return 0; // Memory allocation failed
        }
    }

    // Allocate memory for the new row
    matrix_rows[num_rows] = (char*)malloc(length * sizeof(char));
    if (!matrix_rows[num_rows]) {
        return 0; // Memory allocation failed
    }

    // Copy characters to the new row
    memcpy(matrix_rows[num_rows], segment, length);
    row_lengths[num_rows] = length;
    num_rows++;

    return 1; // Success
}

// Main function to convert string to matrix
int string_to_matrix(const char *input) {
    // Handle NULL input
    if (!input) {
        return 0;
    }

    int input_len = strlen(input);

    // Initialize matrix
    if (!initialize_matrix(10)) {
        return 0;
    }

    // Handle empty string
    if (input_len == 0) {
        return 1; // Success with empty matrix
    }

    int i = 0;

    while (i < input_len) {
        // Skip consecutive periods
        while (i < input_len && input[i] == '.') {
            i++;
        }

        // If we've reached the end, break
        if (i >= input_len) {
            break;
        }

        // Find the start of the segment
        int segment_start = i;

        // Find the end of the segment (next period or end of string)
        while (i < input_len && input[i] != '.') {
            i++;
        }

        int segment_length = i - segment_start;

        // Add segment as a row if it's not empty
        if (segment_length > 0) {
            if (!add_row(&input[segment_start], segment_length)) {
                // Memory allocation failed, cleanup and return failure
                free_matrix();
                return 0;
            }
        }
    }

    return 1; // Success
}

// Function to free matrix memory
void free_matrix() {
    if (matrix_rows) {
        for (int i = 0; i < num_rows; i++) {
            free(matrix_rows[i]);
        }
        free(matrix_rows);
        matrix_rows = NULL;
    }

    if (row_lengths) {
        free(row_lengths);
        row_lengths = NULL;
    }

    num_rows = 0;
    matrix_capacity = 0;
}

// Function to print the matrix
void print_matrix() {
    if (!matrix_rows || !row_lengths) {
        printf("Matrix is NULL\n");
        return;
    }

    if (num_rows == 0) {
        printf("Matrix is empty\n");
        return;
    }

    printf("Matrix Structure:\n");
    for (int i = 0; i < num_rows; i++) {
        printf("Row %d: [", i + 1);
        for (int j = 0; j < row_lengths[i]; j++) {
            printf("'%c'", matrix_rows[i][j]);
            if (j < row_lengths[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    printf("\nTotal: %d rows\n", num_rows);
}

// Function to get matrix dimensions
void get_matrix_info(int *rows, int *max_cols) {
    *rows = num_rows;
    *max_cols = 0;

    for (int i = 0; i < num_rows; i++) {
        if (row_lengths[i] > *max_cols) {
            *max_cols = row_lengths[i];
        }
    }
}

// Function to get a specific character from the matrix
char get_matrix_element(int row, int col) {
    if (row < 0 || row >= num_rows || col < 0 || col >= row_lengths[row]) {
        return '\0'; // Invalid position
    }
    return matrix_rows[row][col];
}

// Test function to verify the implementation
void run_tests() {
    printf("=== Running Tests ===\n\n");

    // Test 1: Example from problem statement
    printf("Test 1: Example input 'a...dgdsafas.j.k..a.f'\n");
    if (string_to_matrix("a...dgdsafas.j.k..a.f")) {
        print_matrix();
    } else {
        printf("Failed to create matrix\n");
    }
    free_matrix();
    printf("\n");

    // Test 2: Empty string
    printf("Test 2: Empty string\n");
    if (string_to_matrix("")) {
        print_matrix();
    } else {
        printf("Failed to create matrix\n");
    }
    free_matrix();
    printf("\n");

    // Test 3: Only periods
    printf("Test 3: Only periods '....'\n");
    if (string_to_matrix("....")) {
        print_matrix();
    } else {
        printf("Failed to create matrix\n");
    }
    free_matrix();
    printf("\n");

    // Test 4: No periods
    printf("Test 4: No periods 'hello'\n");
    if (string_to_matrix("hello")) {
        print_matrix();
    } else {
        printf("Failed to create matrix\n");
    }
    free_matrix();
    printf("\n");

    // Test 5: Leading and trailing periods
    printf("Test 5: Leading/trailing periods '..abc.def..'\n");
    if (string_to_matrix("..abc.def..")) {
        print_matrix();
    } else {
        printf("Failed to create matrix\n");
    }
    free_matrix();
    printf("\n");

    // Test 6: Single character segments
    printf("Test 6: Single characters 'a.b.c.d'\n");
    if (string_to_matrix("a.b.c.d")) {
        print_matrix();
    } else {
        printf("Failed to create matrix\n");
    }
    free_matrix();
    printf("\n");

    // Test 7: NULL input
    printf("Test 7: NULL input\n");
    if (string_to_matrix(NULL)) {
        print_matrix();
    } else {
        printf("NULL input handled correctly - no matrix created\n");
    }
    free_matrix();
    printf("\n");

    // Test 8: Complex example with numbers and letters
    printf("Test 8: Complex input 'abc123...xyz789.hello.world..test'\n");
    if (string_to_matrix("abc123...xyz789.hello.world..test")) {
        print_matrix();

        // Demonstrate matrix access functions
        int rows, max_cols;
        get_matrix_info(&rows, &max_cols);
        printf("Matrix info: %d rows, max %d columns\n", rows, max_cols);

        printf("Element at (0,2): '%c'\n", get_matrix_element(0, 2));
        printf("Element at (1,3): '%c'\n", get_matrix_element(1, 3));
    } else {
        printf("Failed to create matrix\n");
    }
    free_matrix();
    printf("\n");
}

// Function to analyze complexity
void analyze_complexity() {
    printf("=== Complexity Analysis ===\n");
    printf("Time Complexity: O(n) where n is the length of input string\n");
    printf("- Single pass through the input string\n");
    printf("- Each character is processed exactly once\n");
    printf("- Dynamic array resizing is amortized O(1)\n\n");

    printf("Space Complexity: O(n) where n is the length of input string\n");
    printf("- In worst case, every character forms its own row\n");
    printf("- Matrix storage is proportional to input size\n");
    printf("- Additional overhead for row length tracking: O(r) where r is number of rows\n\n");
}

// Function to demonstrate matrix manipulation
void demonstrate_matrix_access() {
    printf("=== Matrix Access Demonstration ===\n");

    if (string_to_matrix("hello.world.test.123")) {
        printf("Created matrix from 'hello.world.test.123'\n");
        print_matrix();

        printf("\nAccessing individual elements:\n");
        for (int i = 0; i < num_rows; i++) {
            printf("Row %d contents: ", i);
            for (int j = 0; j < row_lengths[i]; j++) {
                printf("%c", get_matrix_element(i, j));
            }
            printf(" (length: %d)\n", row_lengths[i]);
        }

        int total_rows, max_columns;
        get_matrix_info(&total_rows, &max_columns);
        printf("\nMatrix dimensions: %d rows x %d max columns\n", total_rows, max_columns);
    }

    free_matrix();
    printf("\n");
}

int main() {
    printf("String to Matrix Converter (No Structs Version)\n");
    printf("===============================================\n\n");

    // Run comprehensive tests
    run_tests();

    // Demonstrate matrix access functions
    demonstrate_matrix_access();

    // Display complexity analysis
    analyze_complexity();

    // Interactive example
    printf("=== Interactive Example ===\n");
    char input[1000];
    printf("Enter a string to convert to matrix (or 'quit' to exit): ");

    while (fgets(input, sizeof(input), stdin)) {
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            break;
        }

        printf("\nResult for input: '%s'\n", input);
        if (string_to_matrix(input)) {
            print_matrix();

            // Show additional info
            int rows, max_cols;
            get_matrix_info(&rows, &max_cols);
            printf("Matrix info: %d rows, maximum %d columns per row\n", rows, max_cols);
        } else {
            printf("Failed to create matrix from input\n");
        }

        free_matrix();
        printf("\nEnter another string (or 'quit' to exit): ");
    }

    printf("Program terminated.\n");
    return 0;
}