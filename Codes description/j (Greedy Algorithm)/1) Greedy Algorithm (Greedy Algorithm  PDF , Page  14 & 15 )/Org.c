#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50  // Adjust according to the maximum name length of the activity

// Define the activity struct
typedef struct activity {
    char name[MAX];  // Activity name
    int start, stop; // Start and stop times of the activity
    int selected;    // A flag to mark whether the activity is selected
} activity_t;

// Function prototypes
int cmp(const void *p1, const void *p2);
activity_t* load(const char *filename, int *n);
void choose(activity_t *acts, int n);
void display(activity_t *acts, int n);

// Main function
int main(int argc, char *argv[]) {
    int n;
    activity_t *acts;

    // Load the activities from a file
    acts = load(argv[1], &n);

    // Sort the activities by their end time
    qsort((void *)acts, n, sizeof(activity_t), cmp);

    // Select activities based on the greedy algorithm
    choose(acts, n);

    // Display the selected activities
    display(acts, n);

    // Free the allocated memory for activities
    free(acts);

    return 0;
}

// Function to compare two activities for sorting by stop time
int cmp(const void *p1, const void *p2) {
    activity_t *a1 = (activity_t *)p1;
    activity_t *a2 = (activity_t *)p2;

    return a1->stop - a2->stop;  // Compare by stop time
}

// Function to load activities from a file
activity_t* load(const char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", n);  // Read the number of activities

    activity_t *acts = (activity_t *)malloc(*n * sizeof(activity_t));
    if (!acts) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Read each activity's details
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%s %d %d", acts[i].name, &acts[i].start, &acts[i].stop);
        acts[i].selected = 0;  // Initially, no activity is selected
    }

    fclose(file);
    return acts;
}

// Function to select activities based on the greedy algorithm
void choose(activity_t *acts, int n) {
    int stop = acts[0].stop;  // Start with the first activity's stop time
    acts[0].selected = 1;  // Select the first activity

    // Select further activities that start after the previous one ends
    for (int i = 1; i < n; i++) {
        if (acts[i].start >= stop) {
            acts[i].selected = 1;  // Select this activity
            stop = acts[i].stop;   // Update the stop time
        }
    }
}

// Function to display selected activities
void display(activity_t *acts, int n) {
    printf("Selected activities:\n");

    for (int i = 0; i < n; i++) {
        if (acts[i].selected) {
            printf("%s: [%d, %d]\n", acts[i].name, acts[i].start, acts[i].stop);
        }
    }
}
