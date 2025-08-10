#include <stdio.h>
#include <stdlib.h>

typedef struct val_s {
    int num_choice;
    int *choices;
} val_t;

int mult_princ(val_t *val, int *sol, int n, int count, int pos) {
    int i;

    if (pos >= n) {
        for (i = 0; i < n; i++)
            printf("%d ", sol[i]);
        printf("\n");
        return count + 1;
    }

    for (i = 0; i < val[pos].num_choice; i++) {
        sol[pos] = val[pos].choices[i];
        count = mult_princ(val, sol, n, count, pos + 1);
    }

    return count;
}

int main() {
    int n = 3; // Number of positions
    int total_combinations;

    // Allocate memory for the val array
    val_t *val = (val_t*)malloc(n * sizeof(val_t));
    int *sol = (int*)malloc(n * sizeof(int));

    // Example 1: Choose outfit combinations
    printf("=== Example 1: Outfit Combinations ===\n");
    printf("Position 0 - Shirts: ");

    // Position 0: Shirts (choices: 1=Red, 2=Blue, 3=Green)
    val[0].num_choice = 3;
    val[0].choices = (int*)malloc(3 * sizeof(int));
    val[0].choices[0] = 1; // Red
    val[0].choices[1] = 2; // Blue
    val[0].choices[2] = 3; // Green
    for (int i = 0; i < val[0].num_choice; i++) {
        printf("%d ", val[0].choices[i]);
    }
    printf("\n");

    // Position 1: Pants (choices: 4=Black, 5=White)
    printf("Position 1 - Pants: ");
    val[1].num_choice = 2;
    val[1].choices = (int*)malloc(2 * sizeof(int));
    val[1].choices[0] = 4; // Black
    val[1].choices[1] = 5; // White
    for (int i = 0; i < val[1].num_choice; i++) {
        printf("%d ", val[1].choices[i]);
    }
    printf("\n");

    // Position 2: Shoes (choices: 6=Sneakers, 7=Boots)
    printf("Position 2 - Shoes: ");
    val[2].num_choice = 2;
    val[2].choices = (int*)malloc(2 * sizeof(int));
    val[2].choices[0] = 6; // Sneakers
    val[2].choices[1] = 7; // Boots
    for (int i = 0; i < val[2].num_choice; i++) {
        printf("%d ", val[2].choices[i]);
    }
    printf("\n\n");

    printf("All possible outfit combinations (Shirt Pants Shoes):\n");
    total_combinations = mult_princ(val, sol, n, 0, 0);
    printf("Total combinations: %d\n\n", total_combinations);

    // Clean up memory for first example
    for (int i = 0; i < n; i++) {
        free(val[i].choices);
    }

    // Example 2: Simple number combinations
    printf("=== Example 2: Simple Number Combinations ===\n");
    n = 2; // Reset to 2 positions

    // Position 0: choices 1, 2
    val[0].num_choice = 2;
    val[0].choices = (int*)malloc(2 * sizeof(int));
    val[0].choices[0] = 1;
    val[0].choices[1] = 2;

    // Position 1: choices 10, 20, 30
    val[1].num_choice = 3;
    val[1].choices = (int*)malloc(3 * sizeof(int));
    val[1].choices[0] = 10;
    val[1].choices[1] = 20;
    val[1].choices[2] = 30;

    printf("Position 0 choices: ");
    for (int i = 0; i < val[0].num_choice; i++) {
        printf("%d ", val[0].choices[i]);
    }
    printf("\n");

    printf("Position 1 choices: ");
    for (int i = 0; i < val[1].num_choice; i++) {
        printf("%d ", val[1].choices[i]);
    }
    printf("\n\n");

    printf("All possible combinations:\n");
    total_combinations = mult_princ(val, sol, n, 0, 0);
    printf("Total combinations: %d\n", total_combinations);

    // Clean up memory
    for (int i = 0; i < n; i++) {
        free(val[i].choices);
    }
    free(val);
    free(sol);

    return 0;
}