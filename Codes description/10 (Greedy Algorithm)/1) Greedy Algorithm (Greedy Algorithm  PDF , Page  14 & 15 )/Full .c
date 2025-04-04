#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50  // Maximum length of activity name

// Define the activity structure
typedef struct activity {
    char name[MAX];  // Name of the activity
    int start, stop; // Start and stop times of the activity
    int selected;    // Flag to mark whether the activity is selected
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

    // Load the activities from the file specified by the user
    acts = load(argv[1], &n);

    // Sort the activities by their stop times using qsort
    qsort((void *)acts, n, sizeof(activity_t), cmp);

    // Select activities using the greedy algorithm
    choose(acts, n);

    // Display the selected activities
    display(acts, n);

    // Free the memory allocated for activities
    free(acts);

    return 0;
}

// Function to compare two activities for sorting by stop time
int cmp(const void *p1, const void *p2) {
    activity_t *a1 = (activity_t *)p1;
    activity_t *a2 = (activity_t *)p2;

    // Compare based on stop time (ascending order)
    return a1->stop - a2->stop;
}

// Function to load activities from a file
activity_t* load(const char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", n);  // Read the number of activities

    // Allocate memory for 'n' activities
    activity_t *acts = (activity_t *)malloc(*n * sizeof(activity_t));
    if (!acts) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Read each activity's details (name, start, and stop times)
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
            stop = acts[i].stop;   // Update the stop time to the current activity's stop time
        }
    }
}

// Function to display the selected activities
void display(activity_t *acts, int n) {
    printf("Selected activities:\n");

    // Loop through the activities and print the selected ones
    for (int i = 0; i < n; i++) {
        if (acts[i].selected) {
            printf("%s: [%d, %d]\n", acts[i].name, acts[i].start, acts[i].stop);
        }
    }
}

/*
Explanation of the Code:

1. **cmp**:
   - This function is used to compare two activities based on their stop times. It is passed as a comparator to the `qsort` function to sort the array of activities.
   - The activities are sorted by their stop time in ascending order to ensure that we always select the activity that finishes the earliest, allowing us to maximize the number of non-overlapping activities.

2. **load**:
   - This function reads the activities from a file. The file should contain the number of activities followed by each activity's name, start time, and stop time.
   - It dynamically allocates memory for an array of activities and stores each activity's data.
   - The activities are initially marked as unselected (`selected = 0`).

3. **choose**:
   - This function implements the **Greedy Algorithm** for activity selection.
   - The idea behind this algorithm is to select the activity with the earliest finishing time (smallest stop time) and then select subsequent activities that do not overlap with the last selected activity.
   - For each activity, we check if it starts after the previously selected activity ends. If so, we select it and update the stop time.

4. **display**:
   - This function prints the details of the selected activities.
   - It loops through all activities and prints the name, start time, and stop time for each activity that has been marked as selected.

Example Input (`activities.txt`):

5
A 1 3
B 2 5
C 4 7
D 6 8
E 5 9

Example Output:

Selected activities:
A: [1, 3]
C: [4, 7]
D: [6, 8]

How This Relates to Dynamic Programming (DP):

While the **Activity Selection Problem** is solved here using a **Greedy Algorithm**, it's important to note that this problem is typically not solved using Dynamic Programming because it does not exhibit overlapping subproblems. Dynamic Programming is usually applied when subproblems overlap, and solving them optimally helps solve the overall problem optimally. In this case, the greedy choice property holds because by selecting the activity that finishes the earliest, we ensure that we can accommodate the maximum number of subsequent activities.

What You Need to Learn from This Code:

1. **Greedy Algorithms**:
   - This code demonstrates the use of a **Greedy Algorithm** to solve the Activity Selection Problem. Greedy algorithms are used when choosing the local optimal solution at each step leads to a globally optimal solution. Understanding this algorithm is essential for solving problems that involve making a series of decisions that build up to an overall optimal solution.

2. **Sorting**:
   - The code uses the `qsort` function to sort the activities based on their stop times. Sorting is a crucial part of many algorithms, including greedy algorithms, and understanding how to use `qsort` in C is important.

3. **Dynamic Memory Allocation**:
   - The program uses dynamic memory allocation to store the activities. The `load` function uses `malloc` to allocate memory for the array of activities, and the `free` function is used to deallocate the memory after it's no longer needed.
   - Understanding dynamic memory allocation and deallocation is a key concept in C programming.

4. **File I/O**:
   - The program reads input from a file to load the activity data. Learning how to read from files and handle file I/O operations is an important part of many programming tasks.
*/
