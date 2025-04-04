#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define the activity structure
typedef struct activity {
    char name[MAX];
    int start, stop;
    int selected;
} activity_t;

// Function prototypes
activity_t *load(const char *filename, int *n);
int cmp(const void *p1, const void *p2);
void choose(activity_t *acts, int n);
void print_activities(activity_t *acts, int n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int n;
    activity_t *activities = load(argv[1], &n);

    if (activities == NULL) {
        printf("Failed to load activities from file.\n");
        return 1;
    }

    // Sort activities by stop time
    qsort(activities, n, sizeof(activity_t), cmp);

    // Select activities
    choose(activities, n);

    // Print selected activities
    print_activities(activities, n);

    // Free allocated memory
    free(activities);

    return 0;
}

// Load activities from a file
activity_t *load(const char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fscanf(file, "%d", n); // Read number of activities
    activity_t *acts = malloc((*n) * sizeof(activity_t));
    if (!acts) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        fscanf(file, "%s %d %d", acts[i].name, &acts[i].start, &acts[i].stop);
        acts[i].selected = 0; // Initialize selected field
    }

    fclose(file);
    return acts;
}

// Comparison function for sorting activities by stop time
int cmp(const void *p1, const void *p2) {
    activity_t *a1 = (activity_t *)p1;
    activity_t *a2 = (activity_t *)p2;
    return a1->stop - a2->stop;
}

// Select the maximum number of non-overlapping activities
void choose(activity_t *acts, int n) {
    int stop = acts[0].stop;
    acts[0].selected = 1;

    for (int i = 1; i < n; i++) {
        if (acts[i].start >= stop) {
            acts[i].selected = 1;
            stop = acts[i].stop;
        }
    }
}

// Print selected activities
void print_activities(activity_t *acts, int n) {
    printf("Selected activities:\n");
    for (int i = 0; i < n; i++) {
        if (acts[i].selected) {
            printf("%s (%d, %d)\n", acts[i].name, acts[i].start, acts[i].stop);
        }
    }
}
