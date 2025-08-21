#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Define the node structure for the singly linked list
typedef struct node {
    char *data;           // Holds a dynamically allocated substring
    struct node *next;    // Pointer to the next node in the list
} node_t;

// Function Prototypes
float difference(float *, int);
void permutation(float *, float *, int *, float *, int, int, float *);
int *balance(float *, int);
node_t *create_node(const char *substring, int length);
node_t *split_str(char *str);
void display_list(node_t *head);
void free_list(node_t *head);

int main() {
    // Example input
    char input_str[] = "a.bb.ccc.dddd.eeeee.fffff"; // Example input string
    float array[4] = {-5, 10, -8, 7}; // Example numbers to find optimal order
    float array_second[4] = {-5, 10, -8, 7}; // Copy of array for display
    int n = 4;

    // Call balance function to find the optimal order of indices
    int *optimal_indices = balance(array, n);

    // Print the optimal order of numbers
    printf("Optimal order of numbers are :\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", array_second[optimal_indices[i]]);
    }
    printf("\n");

    free(optimal_indices); // Free the dynamically allocated memory
    return 0;
}

// Function to calculate the difference between maximum and minimum balances
float difference(float *array, int number) {
    int i;
    float sum = 0;
    float max, min;

    for (i = 0; i < number; i++) {
        if (i == 0) { // Initialize max and min with the first element
            max = array[i];
            min = array[i];
            sum += array[i];
            continue;
        }

        sum += array[i]; // Update the cumulative sum
        if (sum > max) max = sum; // Update max balance
        if (sum < min) min = sum; // Update min balance
    }

    return max - min; // Return the difference
}

// Recursive function to generate permutations and find the optimal solution
void permutation(float *numbers, float *sol, int *mark, float *final_array, int pos, int n, float *final) {
    int i;

    if (pos >= n) { // Base case: A complete permutation is generated
        float temp = difference(sol, n); // Calculate the max-min difference
        if (temp < *final) { // Update the best solution if current is better
            *final = temp;
            for (int j = 0; j < n; j++) {
                final_array[j] = sol[j]; // Copy the current permutation
            }
        }
        return;
    }

    // Recursive case: Generate permutations
    for (i = 0; i < n; i++) {
        if (mark[i] == 0) { // If the element is not used
            mark[i] = 1;    // Mark it as used
            sol[pos] = numbers[i]; // Place it in the solution
            permutation(numbers, sol, mark, final_array, pos + 1, n, final);
            mark[i] = 0; // Backtrack: Unmark the element
        }
    }
}

// Function to find the optimal order of indices that minimizes the balance difference
int *balance(float *flow, int n) {
    float *sol = (float *)malloc(n * sizeof(float));       // Temporary solution array
    float *final_array = (float *)malloc(n * sizeof(float)); // Array to store the best solution
    int *mark = (int *)calloc(n, sizeof(int));             // Array to track used elements
    float final = INT_MAX;                                 // Initialize best difference as maximum possible value

    // Generate all permutations and find the optimal solution
    permutation(flow, sol, mark, final_array, 0, n, &final);

    // Convert the best solution into indices of the original array
    int *indices = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flow[j] == final_array[i]) {
                indices[i] = j;   // Store the index of the value
                flow[j] = INT_MAX; // Mark it to avoid duplicate matches
                break;
            }
        }
    }
    // Free temporary arrays
    free(sol);
    free(final_array);
    free(mark);

    return indices; // Return the indices of the optimal order
}

// Function to create a new node with a given substring
node_t *create_node(const char *substring, int length) {
    // Allocate memory for the node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the substring and copy it
    new_node->data = (char *)malloc((length + 1) * sizeof(char));
    if (new_node->data == NULL) {
        perror("Failed to allocate memory for substring");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->data, substring, length); // Copy substring
    new_node->data[length] = '\0';             // Null-terminate the string

    new_node->next = NULL; // Initialize next pointer to NULL
    return new_node;
}

// Function to split a string into substrings using . as a delimiter
node_t *split_str(char *str) {
    node_t *head = NULL, *tail = NULL; // Head and tail pointers for the list
    char *start = str;                 // Pointer to the start of a substring
    char *current = str;               // Pointer to traverse the string

    while (*current != '\0') {
        if (*current == '.') { // Found a delimiter
            int length = current - start; // Length of the substring
            if (length > 0) { // If the substring is non-empty
                node_t *new_node = create_node(start, length);
                // Append the new node to the list
                if (head == NULL) {
                    head = tail = new_node; // First node
                } else {
                    tail->next = new_node; // Append to the list
                    tail = new_node;       // Update the tail pointer
                }
            }
            start = current + 1; // Move start to the character after '.'
        }
        current++;
    }

    // Handle the last substring (if any) after the final '.'
    if (*start != '\0') {
        node_t *new_node = create_node(start, current - start);
        if (head == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head; // Return the head of the list
}

// Function to display the list
void display_list(node_t *head) {
    node_t *current = head;
    printf("The list of substrings:\n");
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Function to free the memory used by the list
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp->data); // Free the dynamically allocated substring
        free(temp);       // Free the node itself
    }
}

// Comprehensive Passages Describing Each Function:
// node_t create_node(const char *substring, int length):
// Purpose: Creates a new node in the linked list to store a substring.
// Parameters:
// substring: The substring to be stored in the new node.
// length: Length of the substring.
// Returns: A pointer to the new node.
// Logic:
// Allocate memory for a new node_t structure.
// If memory allocation fails, print an error message and exit.
// Allocate memory for the substring inside the node.
// If memory allocation for the substring fails, free the node and exit.
// Copy the substring into the node’s data field.
// Null-terminate the string.
// Set the next pointer of the node to NULL.
// Return the pointer to the new node.

// node_t *split_str(char *str):
// Purpose: Splits the input string into substrings based on the delimiter . and stores them in a linked list.
// Parameters:
// str: The input string to be split.
// Returns: Pointer to the head of the linked list.
// Logic:
// Initialize head and tail pointers to NULL for the linked list.
// Initialize start pointer to the beginning of the string.
// Initialize current pointer to traverse the string.
// Iterate over the string character by character.
// If a . is found:
// Calculate the length of the current substring.
// If the substring is non-empty:
// Create a new node using the substring.
// If this is the first node (head is NULL), set both head and tail to the new node.
// Otherwise, append the new node to the list and update the tail pointer.
// Move start to the next character after the delimiter.
// After the loop, handle the last substring (if any) after the final ..
    // Create a new node with the final substring.
    // Update the tail pointer.
    // Return the head of the list.

// void display_list(node_t *head):
// Purpose: Displays the linked list of substrings.
// Parameters:
// head: Pointer to the head of the linked list.
// Returns: None
// Logic:
// Initialize a current pointer to traverse the list starting from head.
// Print each substring stored in the data field of the node.
// Move to the next node until the end of the list.

// void free_list(node_t *head):
// Purpose: Frees the memory allocated for the linked list.
// Parameters:
// head: Pointer to the head of the linked list.
// Returns: None
// Logic:
// Initialize a current pointer to traverse the list starting from head.
// While there are nodes in the list:
// Store the current node in a temporary pointer.
// Move the current pointer to the next node.
// Free the memory allocated for the substring stored in data.
// Free the node itself.
// The list is now fully freed and head is NULL.

// float difference(float *array, int number):
// Purpose: Calculates the difference between the maximum and minimum cumulative sum of the elements in the given array.
// Parameters:
// array: The array of floats.
// number: The size of the array.
// Returns: The difference between the maximum and minimum cumulative sum.
// Logic:
// Initialize max and min with the first element of the array.
// Initialize sum to 0.
// Traverse the array and update sum, max, and min accordingly.
// Return the difference between max and min.

// void permutation(float *numbers, float *sol, int *mark, float *final_array, int pos, int n, float *final):
// Purpose: Generates all permutations of the given numbers and finds the one with the minimum balance difference.
// Parameters:
// numbers: Array of numbers to be permuted.
// sol: Temporary array to store the current permutation.
// mark: Array to track which numbers have been used in the current permutation.
// final_array: Array to store the best permutation.
// pos: Current position in the permutation.
// n: Size of the input array.
// final: Pointer to store the minimum difference found.
// Returns: None
// Logic:
// If pos equals n, a complete permutation has been generated.
// Calculate the difference between the maximum and minimum balances for this permutation.
// If this difference is smaller than the current final, update final and final_array.
// Otherwise, backtrack and try the next possible number in the permutation.
// Mark the current number as used and continue to the next position.
// When done, unmark the number and try the next possibility.
