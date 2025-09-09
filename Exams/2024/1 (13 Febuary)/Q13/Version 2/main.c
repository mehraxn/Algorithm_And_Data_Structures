#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int check (int *solution, int k, float *weight, float *value,
           float *current_price, float load, int *final_array, int *final_array_length) {
    float sum = 0.0f;     // FIX: weights are float; accumulate in float to avoid truncation
    float price = 0.0f;   // FIX: values are float; accumulate in float to avoid truncation

    for (int i = 0; i < k; i++)
        sum += weight[solution[i]];  // FIX: sum selected items; previous indexing used the wrong arrays/indices

    if (sum > load) return 0;

    for (int i = 0; i < k; i++)
        price += value[solution[i]]; // FIX: compute value of selected items; previous indexing was wrong

    if (price > *current_price) {
        *current_price = price;      // FIX: store the new best price found
        for (int i = 0; i < k; i++)
            final_array[i] = solution[i]; // FIX: copy the current selection into the best solution

        *final_array_length = k;
        return 1;
    } else {
        return 0;
    }
}

void arr (int *idx,                 // FIX: avoid shadowing the float* value array by using an index list
          int *solution,
          int *mark,
          int n,
          int k,
          int pos,
          float *weight,
          float *value,
          float load,
          float *current_price,
          int *final_array,
          int *final_array_length)
{
    if (pos >= k) {
        int flag = -1;
        flag = check(solution, k, weight, value, current_price, load, final_array, final_array_length);
        (void)flag;                  // FIX: silence unused-variable warning without changing logic
        return;
    }

    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            solution[pos] = idx[i];  // FIX: choose the i-th item index into the current combination
            arr(idx, solution, mark, n, k, pos + 1, weight, value, load, current_price, final_array, final_array_length); // FIX: pass all required args in recursion
            mark[i] = 0;
        }
    }
}

void load_truck (float *weight,
                 float *value,
                 int n,
                 float load)        // FIX: load capacity is a scalar, not a pointer
{
    int *final_array = (int *)malloc(n * sizeof(int));
    int counter = 0;                 // kept (unused but harmless)
    int final_array_length = 0;

    // FIX: removed a duplicate redeclaration of final_array that would have shadowed the first

    float current_price = -FLT_MAX;  // FIX: start below any achievable price; FLT_MIN is the smallest positive

    int *idx = (int *)malloc(n * sizeof(int));       // FIX: separate index array to avoid clashing with the float* value
    int *solution = (int *)malloc(n * sizeof(int));
    int *mark = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        idx[i] = i;                  // FIX: build 0..n-1 index list for combinations
    }

    for (int i = 0; i < n; i++)
        arr(idx, solution, mark, n, i, 0, weight, value, load, &current_price, final_array, &final_array_length);

    /* Results printing/return left unchanged to keep edits minimal. */
}
