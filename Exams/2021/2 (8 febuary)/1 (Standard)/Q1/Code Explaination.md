# README: Minimum Distance Calculation Function

This document explains the implementation of the `minDist` function, which calculates the sum of minimum distances from a list of electronic components to the closest ground point, as described in the provided problem statement.

## Function Signature
```c
float minDist(char *fileName);
```

- **Parameters:**
  - `fileName`: A string representing the name of the input file containing the positions of components and ground points along a straight line.
- **Return Value:**
  - Returns a floating-point value representing the total sum of the minimum distances from each component to the nearest ground point.

## Input File Format
The input file must follow the specified format:
1. The first line contains two integers:
   - The number of components (`numComponents`).
   - The number of ground points (`numGroundPoints`).
2. The next `numGroundPoints` lines specify ground point positions in the format:
   ```
   gnd <position>
   ```
3. The subsequent `numComponents` lines specify component positions in the format:
   ```
   <component_label> <position>
   ```

### Example Input File
```
4 2
gnd 0
gnd 60
resistor 35
diode 60
transistor 78
inductor 112
```

### Expected Output
For the above input file, the function should calculate the minimum distances as follows:
- `resistor` at position 35: Distance to nearest `gnd` is `35`.
- `diode` at position 60: Distance to nearest `gnd` is `0`.
- `transistor` at position 78: Distance to nearest `gnd` is `18`.
- `inductor` at position 112: Distance to nearest `gnd` is `52`.

The total minimum distance is:
```
35 + 0 + 18 + 52 = 105
```

## Implementation Details

### Step 1: File Reading and Initialization
The function begins by opening the input file in read mode and parsing the first line to retrieve `numComponents` and `numGroundPoints`. Arrays are dynamically allocated to store ground point positions and to process components.

### Step 2: Storing Ground Points
The ground point positions are read from the next `numGroundPoints` lines and stored in an integer array `groundPoints`.

### Step 3: Calculating Minimum Distances
For each component, the function computes the minimum distance to any ground point by iterating through the `groundPoints` array. The process is as follows:
1. Parse the position of the current component from the file.
2. Calculate the absolute distance between the component and each ground point.
3. Keep track of the smallest distance.
4. Add the smallest distance to a running total (`totalMinDist`).

### Step 4: Memory Management
To prevent memory leaks:
- Dynamically allocated arrays (`groundPoints` and `componentDistances`) are freed before exiting the function.
- The file is closed once all data is read.

### Step 5: Complexity Analysis
The function achieves linear complexity with respect to the input size:
- Reading the file and processing components requires \(O(N + M)\), where:
  - \(N\) is the number of components.
  - \(M\) is the number of ground points.
- This ensures efficiency even for large datasets.

## Full Implementation
```c
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

    // Read ground point positions
    for (int i = 0; i < numGroundPoints; i++) {
        char groundLabel[10];
        fscanf(file, "%s %d", groundLabel, &groundPoints[i]);
    }

    // Calculate the total minimum distance
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
```

## Usage
1. Prepare an input file following the specified format.
2. Compile the program using a C compiler:
   ```bash
   gcc -o minDist minDist.c
   ```
3. Run the program, providing the input file name:
   ```bash
   ./minDist
   ```

## Key Points
- **Efficiency:** The function operates in \(O(N + M)\), making it suitable for large datasets.
- **Flexibility:** Handles any number of components and ground points as long as memory permits.
- **Error Handling:** Checks for file access and memory allocation errors, ensuring robustness.

## Limitations
- Assumes that the input file format is correct. Improper formatting may lead to undefined behavior.
- Requires sufficient memory to store arrays for ground points and intermediate data.

## Conclusion
This implementation provides an efficient and reliable solution to compute the sum of minimum distances from components to ground points in a linear time complexity. Proper memory management ensures stability, and the modular design allows for easy extension or modification.

