#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE_LENGTH 256

float minDist(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        return -1.0f;
    }

    int numComponents, numGroundPoints;
    fscanf(file, "%d %d", &numComponents, &numGroundPoints);

    // Array to store the positions of ground points
    int *groundPoints = malloc(numGroundPoints * sizeof(int));
    if (!groundPoints) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        return -1.0f;
    }

    // Array to store the distances of components
    int *componentDistances = malloc(numComponents * sizeof(int));
    if (!componentDistances) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        free(groundPoints);
        fclose(file);
        return -1.0f;
    }

    // Read ground point positions
    for (int i = 0; i < numGroundPoints; i++) {
        char groundLabel[10];
        fscanf(file, "%s %d", groundLabel, &groundPoints[i]);
    }

    // Read components and calculate the minimum distance for each
    float totalMinDist = 0.0f;
    for (int i = 0; i < numComponents; i++) {
        char componentLabel[10];
        int componentPos;
        fscanf(file, "%s %d", componentLabel, &componentPos);

        // Find the minimum distance to a ground point
        int minDist = INT_MAX;
        for (int j = 0; j < numGroundPoints; j++) {
            int distance = abs(componentPos - groundPoints[j]);
            if (distance < minDist) {
                minDist = distance;
            }
        }
        totalMinDist += minDist;
    }

    // Clean up
    free(groundPoints);
    free(componentDistances);
    fclose(file);

    return totalMinDist;
}

// Example usage
int main() {
    char *fileName = "input.txt"; // Replace with the actual file name
    float result = minDist(fileName);
    if (result >= 0.0f) {
        printf("The total minimum distance is: %.2f\n", result);
    }
    return 0;
}
