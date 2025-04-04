#include <stdio.h>
#include <stdlib.h>

// Function to generate and print all subarrays
void generatePermutations(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Print the subarray from index i to j
            for (int k = i; k <= j; k++) {
                printf("%d", arr[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("All permutations of the array are:\n");
    generatePermutations(arr, n);

    return 0;
}
