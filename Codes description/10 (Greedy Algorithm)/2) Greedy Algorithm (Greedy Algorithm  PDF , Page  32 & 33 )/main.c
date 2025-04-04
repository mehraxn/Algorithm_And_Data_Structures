#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size for the priority queue
#define maxN 100

// Define a structure for the item (typically used in Huffman Tree nodes)
typedef struct item {
    char letter;  // Character for Huffman coding
    int freq;     // Frequency of the character
    struct item *left, *right;  // Left and right children (for tree structure)
} Item;

// Define the structure for the priority queue (PQ)
typedef struct pq {
    Item **array;  // Array to hold items
    int size;      // Current size of the priority queue
    int capacity;  // Maximum capacity of the priority queue
    int (*compare)(Item*, Item*);  // Comparison function to order items in the queue
} PQ;

// Function prototypes
PQ* pq_init(int capacity, int (*compare)(Item*, Item*));
void pq_insert(PQ *pq, Item *item);
Item* pq_extract_max(PQ *pq);
int pq_size(PQ *pq);
void pq_display(Item *root, char *code, int index);
Item* item_new(char letter, int freq);

// Comparison function for max-priority queue (max-heap based on frequency)
int item_compare(Item *a, Item *b) {
    return b->freq - a->freq;  // Returns negative if b has higher frequency
}

// Initialize priority queue
PQ* pq_init(int capacity, int (*compare)(Item*, Item*)) {
    PQ *pq = (PQ*)malloc(sizeof(PQ));  // Allocate memory for priority queue
    pq->capacity = capacity;  // Set the capacity
    pq->size = 0;  // Initially, the queue is empty
    pq->array = (Item**)malloc(sizeof(Item*) * capacity);  // Allocate array for items
    pq->compare = compare;  // Set the comparison function
    return pq;
}

// Insert an item into the priority queue
void pq_insert(PQ *pq, Item *item) {
    if (pq->size >= pq->capacity) {  // If the queue is full, print an error
        printf("Priority Queue is full!\n");
        return;
    }
    pq->array[pq->size] = item;  // Add item to the array
    pq->size++;  // Increase the size

    // Fix the max-heap property if violated (bubble-up operation)
    int i = pq->size - 1;
    while (i > 0 && pq->compare(pq->array[i], pq->array[(i - 1) / 2]) > 0) {
        // Swap if the parent is smaller than the child
        Item *temp = pq->array[i];
        pq->array[i] = pq->array[(i - 1) / 2];
        pq->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;  // Move up the tree
    }
}

// Extract the maximum item from the priority queue
Item* pq_extract_max(PQ *pq) {
    if (pq->size == 0) {  // If the queue is empty, return NULL
        return NULL;
    }
    Item *max_item = pq->array[0];  // Get the root (max item)
    pq->size--;  // Decrease the size
    pq->array[0] = pq->array[pq->size];  // Move the last item to the root

    // Fix the max-heap property (heapify-down operation)
    int i = 0;
    while (2 * i + 1 < pq->size) {  // If there is at least one child
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Find the largest among the root, left, and right children
        if (left < pq->size && pq->compare(pq->array[left], pq->array[largest]) > 0) {
            largest = left;
        }
        if (right < pq->size && pq->compare(pq->array[right], pq->array[largest]) > 0) {
            largest = right;
        }

        if (largest != i) {  // If the largest child is not the current root
            // Swap and continue the heapify down
            Item *temp = pq->array[i];
            pq->array[i] = pq->array[largest];
            pq->array[largest] = temp;
            i = largest;  // Move down the tree
        } else {
            break;  // The heap property is restored
        }
    }
    return max_item;  // Return the max item
}

// Return the size of the priority queue
int pq_size(PQ *pq) {
    return pq->size;  // Simply return the size
}

// Create a new item (Huffman node)
Item* item_new(char letter, int freq) {
    Item *item = (Item*)malloc(sizeof(Item));  // Allocate memory for the new item
    item->letter = letter;  // Set the character
    item->freq = freq;      // Set the frequency
    item->left = item->right = NULL;  // Initialize children as NULL
    return item;  // Return the created item
}

// Display the Huffman tree using pre-order traversal (for code generation)
void pq_display(Item *root, char *code, int index) {
    if (root == NULL) return;  // If the root is NULL, return

    if (root->left == NULL && root->right == NULL) {  // If it's a leaf node
        code[index] = '\0';  // Null-terminate the Huffman code
        printf("%c: %s\n", root->letter, code);  // Print the character and its code
    } else {
        code[index] = '0';  // Left child represents '0'
        pq_display(root->left, code, index + 1);  // Recursively display the left subtree

        code[index] = '1';  // Right child represents '1'
        pq_display(root->right, code, index + 1);  // Recursively display the right subtree
    }
}

// Main function with user input and Huffman tree construction
int main() {
    PQ *pq;
    Item *tmp, *l, *r, *root;
    char letter;
    int freq;

    pq = pq_init(maxN, item_compare);  // Initialize priority queue

    // Input letters and frequencies
    for (int i = 0; i < maxN; i++) {
        printf("Enter letter & frequency: ");
        scanf(" %c %d", &letter, &freq);  // Take input for each letter and frequency
        tmp = item_new(letter, freq);  // Create a new item (Huffman node)
        pq_insert(pq, tmp);  // Insert the item into the priority queue
    }

    // Build the Huffman tree by combining the two lowest frequency nodes
    while (pq_size(pq) > 1) {
        l = pq_extract_max(pq);  // Extract the two nodes with the highest frequency
        r = pq_extract_max(pq);
        tmp = item_new('!', l->freq + r->freq);  // Create a new internal node
        tmp->left = l;  // Left child is the first extracted node
        tmp->right = r;  // Right child is the second extracted node
        pq_insert(pq, tmp);  // Insert the new internal node back into the priority queue
    }

    // The last node in the priority queue is the root of the Huffman tree
    root = pq_extract_max(pq);

    // Generate and display the Huffman codes from the Huffman tree
    char code[maxN];
    pq_display(root, code, 0);

    // Free memory (optional cleanup)
    free(pq->array);
    free(pq);

    return 0;
}

/*
 * Explanation of functions in the code:
 *
 * 1. **item_compare**: Compares two items based on their frequency. This function ensures that the priority queue operates as a max-heap, where the item with the highest frequency is given priority.
 *
 * 2. **pq_init**: Initializes a priority queue with a given capacity and comparison function. It allocates memory for the queue and sets the size to zero.
 *
 * 3. **pq_insert**: Inserts an item into the priority queue. It ensures that the max-heap property is maintained by moving the item to the correct position using a bubble-up process.
 *
 * 4. **pq_extract_max**: Removes and returns the item with the highest frequency (the root of the heap). It then reorders the queue to restore the max-heap property using a heapify-down operation.
 *
 * 5. **pq_size**: Returns the current size of the priority queue.
 *
 * 6. **item_new**: Creates a new item (node in the Huffman tree) with a given character and frequency.
 *
 * 7. **pq_display**: Displays the Huffman codes for each character in the Huffman tree using pre-order traversal. The function recursively assigns '0' or '1' based on whether the path goes left or right, respectively.
 *
 * The algorithm builds the Huffman tree by repeatedly extracting the two nodes with the lowest frequencies and combining them into a new internal node. This process continues until all nodes are merged into a single tree. Finally, the Huffman codes are generated by traversing the tree.
 */
