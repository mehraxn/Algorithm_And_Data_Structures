#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void switches(int **mat, int switch_count, int bulb_count);
bool all_bulbs_on(bool *bulbs, int bulb_count);
void press_switch(int **mat, bool *bulbs, int switch_idx, int bulb_count);
void find_min_switch_set(int **mat, int switch_count, int bulb_count);

// Main function
int main() {
    int switch_count = 4;
    int bulb_count = 5;

    // Allocate and initialize the matrix
    int **matrix = (int **)malloc(switch_count * sizeof(int *));
    for (int i = 0; i < switch_count; i++) {
        matrix[i] = (int *)malloc(bulb_count * sizeof(int));
    }

    // Example input matrix
    int input[4][5] = {
            {1, 1, 0, 0, 1},
            {1, 0, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {1, 0, 0, 1, 0}
    };

    for (int i = 0; i < switch_count; i++) {
        for (int j = 0; j < bulb_count; j++) {
            matrix[i][j] = input[i][j];
        }
    }

    // Call the switches function
    switches(matrix, switch_count, bulb_count);

    // Free allocated memory
    for (int i = 0; i < switch_count; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Function to check if all bulbs are on
bool all_bulbs_on(bool *bulbs, int bulb_count) {
    for (int i = 0; i < bulb_count; i++) {
        if (!bulbs[i]) {
            return false;
        }
    }
    return true;
}

// Function to toggle the state of bulbs controlled by a switch
void press_switch(int **mat, bool *bulbs, int switch_idx, int bulb_count) {
    for (int i = 0; i < bulb_count; i++) {
        if (mat[switch_idx][i] == 1) {
            bulbs[i] = !bulbs[i];
        }
    }
}

// Function to find the minimum set of switches to turn on all bulbs
void find_min_switch_set(int **mat, int switch_count, int bulb_count) {
    int min_switches = switch_count + 1;
    int best_combo = 0;

    // Use a bitmask to represent combinations of switches
    for (int combo = 0; combo < (1 << switch_count); combo++) {
        bool bulbs[bulb_count];
        for (int i = 0; i < bulb_count; i++) {
            bulbs[i] = false; // Initially, all bulbs are off
        }

        int switches_pressed = 0;

        // Apply switches based on the current combination
        for (int i = 0; i < switch_count; i++) {
            if (combo & (1 << i)) { // Check if the i-th switch is pressed
                press_switch(mat, bulbs, i, bulb_count);
                switches_pressed++;
            }
        }

        // Check if all bulbs are on
        if (all_bulbs_on(bulbs, bulb_count)) {
            if (switches_pressed < min_switches) {
                min_switches = switches_pressed;
                best_combo = combo;
            }
        }
    }

    // Output the result
    if (min_switches <= switch_count) {
        printf("Minimum number of switches to press: %d\n", min_switches);
        printf("Switches to press: ");
        for (int i = 0; i < switch_count; i++) {
            if (best_combo & (1 << i)) {
                printf("%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("No solution exists to turn on all bulbs.\n");
    }
}

// Main function to solve the problem
void switches(int **mat, int switch_count, int bulb_count) {
    find_min_switch_set(mat, switch_count, bulb_count);
}
