#include <stdio.h>

// First version of show function
// This function prints the current segment of the array, even in the base case when l >= r.
void show1(int v[], int l, int r) {
    int i, c;
    // Print the current segment of the array
    printf("v = ");
    for (i = l; i <= r; i++)
        printf("%d ", v[i]);
    printf("\n");

    // Base case: if the left index is greater than or equal to the right index, return
    if (l >= r) {
        return;
    }

    // Find the midpoint of the current segment
    c = (r + l) / 2;

    // Recursively call show1 for the left and right halves
    show1(v, l, c);
    show1(v, c + 1, r);
    return;
}

// Second version of show function
// This function only prints the segment if l < r, avoiding the base case when l >= r.
void show2(int v[], int l, int r) {
    int i, c;
    // Base case: if the left index is greater than or equal to the right index, return
    if (l >= r) {
        return;
    }

    // Print the current segment of the array
    printf("v = ");
    for (i = l; i <= r; i++)
        printf("%d ", v[i]);
    printf("\n");

    // Find the midpoint of the current segment
    c = (r + l) / 2;

    // Recursively call show2 for the left and right halves
    show2(v, l, c);
    show2(v, c + 1, r);
    return;
}

// Main function to demonstrate the difference
int main() {
    // Define an array of integers
    int v[] = {1, 2, 3, 4, 5};
    int l = 0;
    int r = 4;

    // Call the first version of the show function
    printf("\n--- Output of show1 (Prints even in base case) ---\n");
    show1(v, l, r);

    // Call the second version of the show function
    printf("\n--- Output of show2 (Skips printing in base case) ---\n");
    show2(v, l, r);

    return 0;
}

/*
Summary of the Functions:

1. show1 Function:
   - This function prints the current segment of the array before checking the base case.
   - It always prints the segment, including single-element segments when l >= r.
   - This results in more lines being printed, including segments that only contain one element.

2. show2 Function:
   - This function checks the base case (l >= r) before printing anything.
   - It avoids printing single-element segments, resulting in fewer lines of output.
   - Only segments where l < r are printed, providing a different recursion behavior compared to show1.

Main Difference:
- The main difference between show1 and show2 is the order in which the base case is checked relative to the printing operation.
- show1 prints the segment regardless of the base case, while show2 only prints when l < r.
*/
