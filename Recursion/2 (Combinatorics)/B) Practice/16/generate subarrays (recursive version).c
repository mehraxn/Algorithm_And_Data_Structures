#include <stdio.h>

// Recursive function to generate permutations
void generatePermutationsRecursive(int arr[], int start, int end) {
    if (start > end) {
        return;
    }

    // Print the current subarray
    for (int i = start; i <= end; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    // Recur for the next subarray starting from the next element
    generatePermutationsRecursive(arr, start, end - 1);
}

void generateAllPermutations(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        generatePermutationsRecursive(arr, i, n - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("All permutations of the array are:\n");
    generateAllPermutations(arr, n);

    return 0;
}
