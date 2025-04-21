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

// Function to insert a producer-product-price triple into the list of producers
void insert(producer_t **head, char *name, char *id, float price) {
    // Search for the producer in the list
    producer_t *currentProducer = *head;
    producer_t *prevProducer = NULL;

    while (currentProducer && strcmp(currentProducer->name, name) != 0) {
        prevProducer = currentProducer;
        currentProducer = currentProducer->next;
    }

    // Case 1: Producer does not exist in the list
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

    // Case 2: Producer exists, but the product does not exist
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

    // Case 3: Producer and product already exist
    // Update the product's price
    currentProduct->price = price;
}

// Function to print the producer and product list
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

// Free the entire list
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

// Example usage
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
