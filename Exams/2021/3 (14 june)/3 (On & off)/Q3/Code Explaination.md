# README: Producer-Product Insertion Function

This document provides a comprehensive explanation of the function that manages the relationship between producers and their products. The function handles the insertion of a producer-product-price triple into a doubly linked list structure while maintaining the integrity of the data.

## Problem Statement
A list of producers represents relationships between producers and their products. Each producer has:
- A unique name.
- A list of associated products, each identified by a unique ID and a price.

The function must handle the following cases:
1. **Producer is not in the list:** Add a new producer along with the product.
2. **Producer exists but product is not in their list:** Add the product to the existing producer's list.
3. **Both producer and product exist:** Update the price of the existing product.

## Data Structures

### Product Structure
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

### Producer Structure
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

## Function Signature
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

## Function Logic

### Case 1: Producer Does Not Exist
- If the producer is not found in the list:
  1. Allocate memory for a new producer.
  2. Initialize the producer's name and product list.
  3. Add the new producer to the end of the list.
  4. Add the product to the producer's product list.

### Case 2: Producer Exists but Product Does Not
- If the producer exists but the product is not found in their product list:
  1. Allocate memory for a new product.
  2. Initialize the product's ID and price.
  3. Add the product to the producer's product list.

### Case 3: Both Producer and Product Exist
- If both the producer and product exist:
  1. Update the product's price.

### Memory Management
- Strings are dynamically allocated using `strdup`.
- All dynamically allocated memory is freed using helper functions to avoid memory leaks.

## Full Implementation

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

## Example Execution

### Input:
Insert the following triples:
1. `ProducerA, Product1, 10.5`
2. `ProducerA, Product2, 15.0`
3. `ProducerB, Product3, 20.0`
4. `ProducerA, Product1, 12.0` (update price)
5. `ProducerC, Product4, 25.0`

### Output:
```
Producer: ProducerA
  Product: Product1, Price: 12.00
  Product: Product2, Price: 15.00
Producer: ProducerB
  Product: Product3, Price: 20.00
Producer: ProducerC
  Product: Product4, Price: 25.00
```

## Complexity Analysis

1. **Time Complexity:**
   - Searching for a producer: \(O(n)\), where \(n\) is the number of producers.
   - Searching for a product: \(O(m)\), where \(m\) is the number of products for a producer.
   - Overall: \(O(n + m)\) per insertion.

2. **Space Complexity:**
   - Each producer and product requires additional memory for the string and pointers.

## Conclusion
This implementation effectively manages the producer-product relationship in a linked list. It handles all insertion scenarios, ensures proper memory management, and provides a robust solution for the problem statement.

