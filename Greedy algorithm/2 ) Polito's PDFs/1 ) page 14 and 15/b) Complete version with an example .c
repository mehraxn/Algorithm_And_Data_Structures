#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum length for activity names
#define MAX 100

// Define the activity structure
typedef struct activity {
    char name[MAX];  // Name of the activity
    int start;       // Start time of the activity
    int stop;        // Stop time of the activity
    int selected;    // Whether the activity is selected (1 for selected, 0 for not)
} activity_t;

// Function prototypes
activity_t *load(const char *filename, int *n); // Load activities from a file
int cmp(const void *p1, const void *p2);        // Comparison function for sorting activities
void choose(activity_t *acts, int n);           // Select non-overlapping activities
void print_activities(activity_t *acts, int n); // Print selected activities

int main(int argc, char *argv[]) {
    // Check if the user provided a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int n; // Number of activities
    activity_t *activities = load(argv[1], &n); // Load activities from the file

    // Check if activities were loaded successfully
    if (activities == NULL) {
        printf("Failed to load activities from file.\n");
        return 1;
    }

    // Sort the activities by their stop time
    qsort(activities, n, sizeof(activity_t), cmp);

    // Select the maximum number of non-overlapping activities
    choose(activities, n);

    // Print the selected activities
    print_activities(activities, n);

    // Free the allocated memory for activities
    free(activities);

    return 0;
}

// Load activities from a file
activity_t *load(const char *filename, int *n) {
    FILE *file = fopen(filename, "r"); // Open the file for reading
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fscanf(file, "%d", n); // Read the number of activities
    activity_t *acts = malloc((*n) * sizeof(activity_t)); // Allocate memory for activities
    if (!acts) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read each activity from the file
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%s %d %d", acts[i].name, &acts[i].start, &acts[i].stop);
        acts[i].selected = 0; // Initialize the selected field to 0
    }

    fclose(file); // Close the file
    return acts;
}

// Comparison function for sorting activities by their stop time
int cmp(const void *p1, const void *p2) {
    activity_t *a1 = (activity_t *)p1;
    activity_t *a2 = (activity_t *)p2;
    return a1->stop - a2->stop; // Compare by stop times
}

// Select the maximum number of non-overlapping activities
void choose(activity_t *acts, int n) {
    acts[0].selected = 1; // Always select the first activity
    int stop = acts[0].stop; // Keep track of the end time of the last selected activity

    // Iterate through the activities
    for (int i = 1; i < n; i++) {
        // If the start time of the current activity is greater than or equal to the stop time
        if (acts[i].start >= stop) {
            acts[i].selected = 1; // Select the activity
            stop = acts[i].stop;  // Update the stop time
        }
    }
}

// Print the selected activities
void print_activities(activity_t *acts, int n) {
    printf("Selected activities:\n");
    for (int i = 0; i < n; i++) {
        if (acts[i].selected) {
            printf("%s (%d, %d)\n", acts[i].name, acts[i].start, acts[i].stop);
        }
    }
}

/*
Explanation of the Functions in the Code:
1. `load`: This function reads activities from a file and initializes an array of `activity_t` structures. Each activity has a name, start time, stop time, and a field to indicate if it was selected. It also dynamically allocates memory for the activities based on the number of activities specified in the file.

2. `cmp`: This is a comparator function used by `qsort` to sort activities by their stop times. The function returns a positive, zero, or negative value based on the relative stop times of two activities.

3. `choose`: This function implements the greedy algorithm to select the maximum number of non-overlapping activities. It iterates through the sorted activities and selects an activity if its start time is greater than or equal to the stop time of the previously selected activity.

4. `print_activities`: This function prints the names and time intervals of the activities that were selected. It checks the `selected` field of each activity and only prints the ones that were marked as selected.

5. `main`: This is the entry point of the program. It handles file input, calls the functions to load, sort, select, and print activities, and ensures memory cleanup after execution.

Overall, this code demonstrates a classic greedy algorithm for solving the activity selection problem, focusing on simplicity and clarity.
*/
