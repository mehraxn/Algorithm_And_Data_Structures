# README: Producer-Product Insertion and Matrix Diagonal Traversal Functions

This document provides comprehensive explanations of two functions:
1. A function that manages the relationship between producers and their products.
2. A function to traverse and display a matrix in diagonal order.

---

## Section 1: Producer-Product Insertion Function

This section explains the function that handles the insertion of a producer-product-price triple into a doubly linked list structure while maintaining data integrity.

### Problem Statement

A list of producers represents relationships between producers and their products. Each producer has:

- A unique name.
- A list of associated products, each identified by a unique ID and a price.

The function must handle the following cases:

1. **Producer is not in the list:** Add a new producer along with the product.
2. **Producer exists but product is not in their list:** Add the product to the existing producer's list.
3. **Both producer and product exist:** Update the price of the existing product.

### Data Structures

#### Product Structure

```c
typedef struct product_s {
    char *id;                 // Product identifier
    float price;              // Product price
    struct product_s *next;   // Pointer to the next product in the list
} product_t;
```

- Represents a product with:
  - `id`: A dynamically allocated string representing the product's identifier.
  - `price`: A floating-point value indicating the product's price.
  - `next`: A pointer to the next product in the producer's product list.

#### Producer Structure

```c
typedef struct producer_s {
    char *name;               // Producer name
    product_t *products;      // Pointer to the list of products
    struct producer_s *next;  // Pointer to the next producer in the list
} producer_t;
```

- Represents a producer with:
  - `name`: A dynamically allocated string representing the producer's name.
  - `products`: A pointer to the head of the product list.
  - `next`: A pointer to the next producer in the list.

### Function Signature

```c
void insert(producer_t **head, char *name, char *id, float price);
```

- **Parameters:**

  - `head`: A pointer to the pointer of the head of the producer list.
  - `name`: The name of the producer to insert or update.
  - `id`: The identifier of the product to insert or update.
  - `price`: The price of the product to insert or update.

- **Return Value:**

  - The function does not return a value but modifies the producer-product list directly.

### Function Logic

#### Case 1: Producer Does Not Exist

- If the producer is not found in the list:
  1. Allocate memory for a new producer.
  2. Initialize the producer's name and product list.
  3. Add the new producer to the end of the list.
  4. Add the product to the producer's product list.

#### Case 2: Producer Exists but Product Does Not

- If the producer exists but the product is not found in their product list:
  1. Allocate memory for a new product.
  2. Initialize the product's ID and price.
  3. Add the product to the producer's product list.

#### Case 3: Both Producer and Product Exist

- If both the producer and product exist:
  1. Update the product's price.

#### Memory Management

- Strings are dynamically allocated using `strdup`.
- All dynamically allocated memory is freed using helper functions to avoid memory leaks.

### Full Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct product_s {
    char *id;                 // Product identifier
    float price;              // Product price
    struct product_s *next;   // Pointer to the next product in the list
} product_t;

// Define the producer structure
typedef struct producer_s {
    char *name;               // Producer name
    product_t *products;      // Pointer to the product list
    struct producer_s *next;  // Pointer to the next producer in the list
} producer_t;

void insert(producer_t **head, char *name, char *id, float price) {
    // Search for the producer in the list
    producer_t *currentProducer = *head;
    producer_t *prevProducer = NULL;

    while (currentProducer && strcmp(currentProducer->name, name) != 0) {
        prevProducer = currentProducer;
        currentProducer = currentProducer->next;
    }

    // Case 1: Producer does not exist
    if (!currentProducer) {
        // Create a new producer
        producer_t *newProducer = (producer_t *)malloc(sizeof(producer_t));
        if (!newProducer) {
            fprintf(stderr, "Memory allocation failed for producer.\n");
            return;
        }

        // Initialize the producer
        newProducer->name = strdup(name);
        newProducer->products = NULL;
        newProducer->next = NULL;

        // Insert the new producer into the list
        if (!prevProducer) {
            *head = newProducer;
        } else {
            prevProducer->next = newProducer;
        }
        currentProducer = newProducer;
    }

    // Search for the product in the current producer's product list
    product_t *currentProduct = currentProducer->products;
    product_t *prevProduct = NULL;

    while (currentProduct && strcmp(currentProduct->id, id) != 0) {
        prevProduct = currentProduct;
        currentProduct = currentProduct->next;
    }

    // Case 2: Product does not exist
    if (!currentProduct) {
        // Create a new product
        product_t *newProduct = (product_t *)malloc(sizeof(product_t));
        if (!newProduct) {
            fprintf(stderr, "Memory allocation failed for product.\n");
            return;
        }

        // Initialize the product
        newProduct->id = strdup(id);
        newProduct->price = price;
        newProduct->next = NULL;

        // Insert the new product into the product list
        if (!prevProduct) {
            currentProducer->products = newProduct;
        } else {
            prevProduct->next = newProduct;
        }
        return;
    }

    // Case 3: Product exists
    // Update the product's price
    currentProduct->price = price;
}

void printList(producer_t *head) {
    while (head) {
        printf("Producer: %s\n", head->name);
        product_t *product = head->products;
        while (product) {
            printf("  Product: %s, Price: %.2f\n", product->id, product->price);
            product = product->next;
        }
        head = head->next;
    }
}

void freeList(producer_t *head) {
    while (head) {
        product_t *product = head->products;
        while (product) {
            product_t *tempProduct = product;
            product = product->next;
            free(tempProduct->id);
            free(tempProduct);
        }
        producer_t *tempProducer = head;
        head = head->next;
        free(tempProducer->name);
        free(tempProducer);
    }
}

int main() {
    producer_t *head = NULL;

    // Insert some producer-product-price triples
    insert(&head, "ProducerA", "Product1", 10.5);
    insert(&head, "ProducerA", "Product2", 15.0);
    insert(&head, "ProducerB", "Product3", 20.0);
    insert(&head, "ProducerA", "Product1", 12.0); // Update price
    insert(&head, "ProducerC", "Product4", 25.0);

    // Print the list
    printList(head);

    // Free the list
    freeList(head);

    return 0;
}
```

### Example Execution

#### Input:

Insert the following triples:

1. `ProducerA, Product1, 10.5`
2. `ProducerA, Product2, 15.0`
3. `ProducerB, Product3, 20.0`
4. `ProducerA, Product1, 12.0` (update price)
5. `ProducerC, Product4, 25.0`

#### Output:

```
Producer: ProducerA
  Product: Product1, Price: 12.00
  Product: Product2, Price: 15.00
Producer: ProducerB
  Product: Product3, Price: 20.00
Producer: ProducerC
  Product: Product4, Price: 25.00
```

### Complexity Analysis

1. **Time Complexity:**

   - Searching for a producer: \(O(n)\), where \(n\) is the number of producers.
   - Searching for a product: \(O(m)\), where \(m\) is the number of products for a producer.
   - Overall: \(O(n + m)\) per insertion.

2. **Space Complexity:**

   - Each producer and product requires additional memory for the string and pointers.

### Conclusion

This implementation effectively manages the producer-product relationship in a linked list. It handles all insertion scenarios, ensures proper memory management, and provides a robust solution for the problem statement.

---

## Section 2: Matrix Diagonal Traversal Function

This section explains the function to traverse and display a matrix in diagonal order.

### Problem Statement

Given an \(n \times n\) matrix, the function must print the matrix elements in a diagonal order as illustrated below.

#### Example Matrix

```
  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  14  15  16
```

#### Output Order:

```
1 2 5 3 6 9 4 7 10 13 8 11 14 12 15 16
```

### Function Signature

```c
void display(float **mat, int n);
```

- **Parameters:**
  - `mat`: A pointer to a dynamically allocated \(n \times n\) matrix.
  - `n`: The size of the matrix (number of rows and columns).

- **Return Value:**
  - The function does not return a value but prints the matrix elements to standard output.

### Full Implementation

```c
#include <stdio.h>
#include <stdlib.h>

void display(float **mat, int n) {
    // Traverse diagonals starting from the top row
    for (int start = 0; start < n; start++) {
        int row = 0, col = start;
        while (col >= 0 && row < n) {
            printf("%.2f ", mat[row][col]);
            row++;
            col--;
        }
    }

    // Traverse diagonals starting from the leftmost column (below the main diagonal)
    for (int start = 1; start < n; start++) {
        int row = start, col = n - 1;
        while (row < n && col >= 0) {
            printf("%.2f ", mat[row][col]);
            row++;
            col--;
        }
    }

    printf("\n");
}

int main() {
    int n = 4; // Example: Size of the matrix

    // Dynamically allocate memory for a 4x4 matrix
    float **mat = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        mat[i] = (float *)malloc(n * sizeof(float));
    }

    // Initialize the matrix with example values
    float example[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = example[i][j];
        }
    }

    // Display the matrix in diagonal order
    printf("Diagonal Order Traversal:\n");
    display(mat, n);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
```

### Explanation of the Code

1. **Diagonal Traversal Logic:**
   - For the upper half of the matrix (including the main diagonal):
     - Start each diagonal from the top row (row = 0) and iterate column by column.
     - For each diagonal, decrement the column index while incrementing the row index.
   - For the lower half of the matrix (excluding the main diagonal):
     - Start each diagonal from the leftmost column (col = n - 1) and iterate row by row.
     - For each diagonal, decrement the column index while incrementing the row index.

2. **Dynamic Allocation:**
   - The matrix is dynamically allocated to support flexible dimensions.

3. **Memory Management:**
   - The allocated memory is freed at the end to avoid memory leaks.

4. **Example Execution:**
   - Input:
     ```
     1  2  3  4
     5  6  7  8
     9 10 11 12
    13 14 15 16
     ```
   - Output:
     ```
     1 2 5 3 6 9 4 7 10 13 8 11 14 12 15 16
     ```

### Complexity Analysis

1. **Time Complexity:**
   - Traversing all elements: \(O(n^2)\), where \(n\) is the size of the matrix.

2. **Space Complexity:**
   - \(O(1)\) extra space is used, as traversal operates directly on the matrix.

### Conclusion

This solution ensures efficient traversal and adheres to the specified diagonal order. It complements the earlier function by demonstrating how to handle multidimensional data structures dynamically and efficiently.

