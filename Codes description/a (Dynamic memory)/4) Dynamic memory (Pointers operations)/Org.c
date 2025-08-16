// Function 1: Using pointer arithmetic to traverse and fill an array
void fill_and_print_array_with_pointer(int n) {
    int *v, *p;
    v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill array using pointer
    for (int i = 0, p = v; i < n; i++, p++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", p);
    }

    // Print array in reverse order using pointer
    for (int i = n - 1, p--; i >= 0; i--, p--) {
        fprintf(stdout, "v[%d]: %d\n", i, *p);
    }

    free(v);
}

// Function 2: Using array notation to fill and print an array
void fill_and_print_array_with_index(int n) {
    int *v;
    v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill array using array indexing
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    // Print array in reverse order using array indexing
    for (int i = n - 1; i >= 0; i--) {
        fprintf(stdout, "v[%d] = %d\n", i, v[i]);
    }

    free(v);
}

// Function 3: Using calloc to allocate memory and filling an array
void fill_and_print_array_with_calloc(int n) {
    int *v;
    v = (int *)calloc(n, sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    // Fill array using array indexing
    for (int i = 0; i < n; i++) {
        fprintf(stdout, "v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    // Print array in reverse order using array indexing
    for (int i = n - 1; i >= 0; i--) {
        fprintf(stdout, "v[%d] = %d\n", i, v[i]);
    }

    free(v);
}
